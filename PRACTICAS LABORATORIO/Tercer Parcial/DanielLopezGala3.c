// --------------------------------------------------------------------------
//
//          Daniel López Gala - UO281798 - 53779550F
//
// ---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int FUNCTION(int, int, int *);
void FUNCTION_BACKTRACKING(int, int, int *, int, int *, int *, int *);
int DIVIDE(int[][3], int, int, int);

int addition(int *, int);
void process(int *, int);
int aux(int A[][3], int, int, int);

int main()
{
    int A[3][3] = {{1, 8, 9},
                   {11, 14, 16},
                   {25, 20, 23}};
    ////// DIVIDE AND CONQUER START
    printf("DIVIDE AND CONQUER: %d\n", DIVIDE(A, 0, 3, 2));


    ////// DIVIDE AND CONQUER END

    int M, N, i;
    int *R;

    do
    {
        printf("Input the M: ");
        scanf("%d", &M);
    } while (M < 0);

    do
    {
        printf("\nInput the N:  ");
        scanf("%d", &N);
    } while (N < 0);

    R = (int *)malloc(M * sizeof(int));

    printf("\n\nFill R for the %d object\n", M);
    for (i = 1; i <= M; i++)
    {
        do
        {
            printf("\nObject[%d]= ", i);
            scanf("%d", &R[i - 1]);
        } while (R[i - 1] <= 0);
    }

    printf(" and the optimal solution is : %d\n", FUNCTION(N, M, R));
    printf("\n\n");

    int *x, *x_best, v_best;
    x = (int *)malloc((M + 1) * sizeof(int));
    x_best = (int *)malloc((M + 1) * sizeof(int));
    printf("\n\nOPTIMAL SOLUTION:\n");
    v_best = INT_MIN;
    FUNCTION_BACKTRACKING(N, M, R, 0, x, x_best, &v_best);
    
    process(x_best,M);

    // release memory
    free(R);
    
    return 0;
}

int FUNCTION(int N, int M, int *R)
{
    // Maximum results matrix.
    int **Rmax;
    // Decision matrix.
    int **Dec;
    // Final decisions vector.
    int *X;
    // Auxiliar variable to compute the maximum;
    int costmax;

    ////// ALLOCATE MEMORY
    X = (int *)malloc(M * sizeof(int));
    // M + 1 Cols
    // N + 1tColumns.
    Rmax = (int **)malloc((M + 1) * sizeof(int *));
    for (int i = 0; i < (M + 1); i++)
    {
        Rmax[i] = (int *)malloc((N + 1) * sizeof(int));
    }
    Dec = (int **)malloc((M + 1) * sizeof(int *));
    for (int i = 0; i < (M + 1); i++)
    {
        Dec[i] = (int *)malloc((N + 1) * sizeof(int));
    }
    ////// END ALLOCATE MEMORY

    ////// FILL THE MATRIX WITH THE BASE CASE.
    // 0 for position [0][0] and -INF for the rest of the first Col.
    Rmax[0][0] = 0;
    Dec[0][0] = 0;
    for (int j = 1; j <= N; j++)
    {
        Rmax[0][j] = INT_MIN;
        Dec[0][j] = 0;
    }
    ////// END FILLING THE MATRIX

    ////// ALGORITHM
    // 1. Col's loop (i)
    // 2.tColumn's loop (j)
    // 3. Decision's loop. (k)

    // Starting from the second Col as the first one is already initialized
    for (int i = 1; i < (M + 1); i++)
    {
        for (int j = 0; j < (N + 1); j++)
        {
            Rmax[i][j] = INT_MIN;

            // K is the condition of the subindex, being (N - M + 1) the limit.
            // Xm = Dec[i][j]
            for (int k = 0; k <= (N - M + 1); k++)
            {
                if (Rmax[i - 1][j - k] != INT_MIN)
                {
                    costmax = Rmax[i - 1][j - k] + R[i] * k;
                }
                else
                {
                    costmax = INT_MIN;
                }
                if (Rmax[i][j] > INT_MIN)
                {
                    Rmax[i][j] = costmax;
                    Dec[i][j] = k;
                }
            }
        }
    }

    ////// END ALGORITHM

    ////// SOLUTION
    int i = M;
    int j = N;

    while (i > 0)
    {
        X[i - 1] = Dec[i][j];
        j = j - X[i - 1] * R[i - 1];
        i--;
    }
    ////// END SOLUTION

    ////// DISPLAY OPTIMUM SEQUENCE OF DECISIONES
    printf("\n<");
    for (int k = 0; k < M; k++)
    {
        printf("%d ", X[k]);
    }
    printf(">");

    int res = Rmax[M - 1][N - 1];
    ////// END DISPLAY OPTIMUM SEQUENCE OF DECISIONES

    ////// RELEASE MEMORY
    free(X);
    for (int k = 0; k < (M + 1); k++)
        free(Rmax[k]);
    free(Rmax);
    for (int k = 0; k < (M + 1); k++)
        free(Dec[k]);
    free(Dec);
    ////// END RELEASE MEMORY

    return res;
}

//
// BACKTRACKING
//

int addition(int *x, int k)
{
    int i, sum = 0;
    for (i = 1; i <= k; i++)
    {
        sum = sum + x[i];
    }
    return sum;
}

void process(int *x, int k)
{
    int i;
    printf("\n\t< ");
    for (i = 1; i <= k; i++)
    {
        printf("%d ", x[i]);
    }
    printf(">");
}

int value(int *x, int k)
{
    int i, prod = 1;
    for (i = 1; i <= k; i++)
    {
        prod = prod * x[i];
    }
    return prod;
}

void FUNCTION_BACKTRACKING(int M, int N, int *R, int k, int *x, int *x_best, int *v_best)
{
    int aux;
    x[k] = 0;
    while (x[k] <= N)
    {

        x[k] = x[k] + 1;

        if (k == M && addition(x, k) < N)
        {
            aux = value(x, k) * R[k];
            if (aux > *v_best)
            {
                *v_best = aux;
                memcpy(x_best, x, (M + 1) * sizeof(int));
            }
        }
        if (k < M && addition(x, k) <= N)
            FUNCTION_BACKTRACKING(M, N, R, k + 1, x, x_best, v_best);
    }
}

int DIVIDE(int A[][3], int startCol, int endCol, int f) {
    int m, p1, p2;

    if(startCol == endCol)
    {
        return 1;
    }
    else
    {
        m = (startCol + endCol) / 2;

        p1 = DIVIDE(A, startCol, m, f);
        p2 = DIVIDE(A, m + 1, endCol, f);
    }
    return aux(A, startCol, endCol, f) * p1 * p2;
}

int aux(int A[][3], int startCol, int endCol, int f)
{

    for (int i = 0; i <= f; i++)
    {
        int tmp = INT_MAX;
        for (int j = startCol; j <= endCol; j++)
        {
            if (A[i][j] < tmp)
            {
                tmp = A[i][j];
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}