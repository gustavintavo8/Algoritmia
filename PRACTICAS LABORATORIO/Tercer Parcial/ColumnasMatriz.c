//
//  ALGORITMIA
//
//  CONTROL PRACTICO (M + 1): ESQUEMAS ALGORITMICOS
//
//  GRUPO PL6 (MODELO-B)
//
//  Fecha: 10 de diciembre de 2021
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

// prototipos de funciones
int Programacion_Dinamica_PL6_B(int, int, int[1 + 4][1 + 2]);
void Backtracking_PL6_B(int, int, int[1 + 4][1 + 2], int, int*, int*, int);
//int Divide_y_Venceras_PL6_B(...);

// prototipos de funciones auxiliares

int main()
{

    // datos del problema para Programacion Dinamica y Vuelta Atras
    int N = 4;
    int M = 3;
    int D[1 + 4][1 + 2] = {{0, 0, 0},
                           {0, 14, 6},
                           {0, 10, 3},
                           {0, 8, 9},
                           {0, 6, 10}};

    // datos del problema para Divide y Venceras
    int A[3][5] = {{9, 7, 5, 4, 3},
                   {20, 12, 8, 5, 2},
                   {28, 25, 9, 2, 1}};

    // Programacion Dinamica
    // rellenar por el alumno
    printf(" and the optimum solution is : %d\n", Programacion_Dinamica_PL6_B(N, M, D));
    printf("\n\n");



    // Vuelta Atras (Backtracking)

    // Divide y Venceras
    // rellenar por el alumno

    return 0;
}

// definiciones de funciones

int Programacion_Dinamica_PL6_B(int N, int M, int A[1 + 4][1 + 2])
{
    // N: 4 filas.
    // M: Columnas de matriz solución.
    // A: Matriz N+1

    // Guarda resultados máximos.
    int **Rmax;
    // Matriz de decisiones.
    int **Dec;
    // Vector de decisiones finales.
    int *X;

    X = (int *)malloc(N * sizeof(int));
    Rmax = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i < (N + 1); i++)
    {
        Rmax[i] = (int *)malloc((M + 1) * sizeof(int));
    }
    Dec = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i < (N + 1); i++)
    {
        Dec[i] = (int *)malloc((M + 1) * sizeof(int));
    }

    ////// BASE CASE
    for (int j = 0; j < (M + 1); j++)
    {
        Rmax[0][j] = 0;
        Dec[0][j] = 0;
    }
    for (int j = 1; j < (M + 1); j++)
    {
        Rmax[j][0] = Rmax[j - 1][0] + A[j][2];
        Dec[j][0] = 2;
    }
    ////// END BASE CASE

    ////// ALGORITHM
    // 1. Row's loop (i)
    // 2. Column's loop (j)
    // 3. Decision's loop (Not necessary in this example). (k)

    //
    for (int i = 1; i < (N + 1); i++)
    {
        for (int j = 1; j < (M + 1); j++)
        {
            int option1 = Rmax[i - 1][j - 1] + A[i][1];
            int option2 = Rmax[i - 1][j] + A[i][2];
            if (option1 > option2)
            {
                Rmax[i][j] = option1;
                Dec[i][j] = 1;
            }
            else
            {
                Rmax[i][j] = option2;
                Dec[i][j] = 2;
            }
        }
    }
    ////// END ALGORITHM

    ////// SOLUTION
    int i = N;
    int j = M;
    while (i > 0)
    {
        X[i - 1] = Dec[i][j];
        if (Dec[i][j] == 2)
        {
            // Fila anterior misma columna
            // Escogiste la 2.
            i--;
        }
        else
        {
            // Fila anterior y columna anterior.
            // Si escogiste el 1.
            i--;
            j--;
        }
    }
    ////// END SOLUTION

    ////// DISPLAY THE OPTIMUM SEQUENCE OF DECISIONS
    printf("\n<");
    for (int k = 0; k < N; k++)
    {
        printf("%d ", X[k]);
    }
    printf(">");
    //////

    int res = Rmax[N][M];

    // RELEASE MEMORY
    free(X);
    for (int k = 0; k < (N + 1); k++)
        free(Rmax[k]);
    free(Rmax);
    for (int k = 0; k < (N + 1); k++)
        free(Dec[k]);
    free(Dec);

    return res;
}

// void Backtracking_PL6_B(int N, int M, int A[1 + 4][1 + 2], int *x, int *x_best, int *v_best, int k)
// {
//     int aux;
//     x[k] = 0;
//     while(x[k] < 2) 
//     {
//         x[k] = x[k] + 1;
//         if()
//     }
// }

// int Divide_y_Venceras_PL6_B()
// {
// }
