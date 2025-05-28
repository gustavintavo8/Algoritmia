//Examen 2 PL Algoritmia 09/11/2022
//Gonzalo Puga Fernández - UO277906

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool AuxExam(int A[4][3], int V[3], int n, int m, int k)
{
    for (int j = 0; j <= n-1; j++)
    {
        //printf("AuxExamen => k=%d numero=%d\n" , k-1 , A[j][k-1]);
        if (A[j][k-1] % 2 == 0)
        {
            return true;
        }
    }
    return false;
}

bool iExam(int A[4][3], int V[3], int n, int m, int k)
{
    bool p;
    //printf("iExam n=%d, m=%d, k=%d\n", n,m,k);
    //printf("k=%d\n",k);
    if (k == 1)
    {
        p = AuxExam(A, V, n, m, k);
         //if(p){ printf("p=true\n");}
         //else {printf("p=false\n");}
        return p;
    }
    else
    {
        p = iExam(A, V, n, m, k - 1) && AuxExam(A, V, n, m, k);
         //if(p){ printf("paux=true\n");}
         //else {printf("paux=false\n");}
        return p;
    }
}

bool iExamIterativo(int A[4][3], int V[3], int n_inicial, int m_inicial, int k_inicial)
{
    // Inicialización
    int n = n_inicial;
    int m = m_inicial;
    int k = k_inicial;
    bool p;

    // Bucle de descenso hasta el caso base
    while (k > 1)
    {
        k--;
    }

    // Caso base
    for (int j = 0; j <= n-1; j++)
    {
        if (A[j][k-1] % 2 == 0)
        {
            p = true;
        }

        else
        {
            p = false;
        }
    }

    // Bucle de subida
    while (k != k_inicial)
    {
        k++;
        for (int j = 0; j <= n-1; j++)
        {
            if (A[j][k-1] % 2 == 0)
            {
                p = p && true;
            }
            else
            {
                p = p && false;
            }
        }
    }

    return p;
}


int main()
{
    printf("\n\n\tGonzalo Puga Fernandez - UO277906\t\n");

    int A[4][3] = {
        {9, 1, 6},
        {3, 6, 2},
        {1, 7, 7},
        {5, 4, 9}};

    int V[3] = {1, 2, 2};

    int n = 4;
    int m = 3;
    int k = 3;

    printf("\t----------------------------------\n");
    printf("\t\tiExam\t\n");

    if (iExam(A, V, n, m, k))
    {
        printf("\tEl resultado de iExam es true\n");
    }
    else
    {
        printf("\t\tEl resultado de iExam es false\n");
    }

    printf("\t----------------------------------\n");
    printf("\t\tiExamIterativo\t\n");
    if (iExamIterativo(A, V, n, m, k))
    {
        printf("\tEl resultado de iExamIterativo es true\n");
    }
    else
    {
        printf("\t\tEl resultado de iExamIterativo es false\n");
    }
}
