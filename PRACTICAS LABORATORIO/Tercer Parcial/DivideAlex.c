//
//  ALGORITMIA
//
//  CONTROL PRACTICO 3: ESQUEMAS ALGORITMICOS
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
void Backtracking_PL6_B(int[][3], int, int, int, int *, int *, int *);
int Divide_y_Venceras_PL6_B(int[][5], int, int, int);

// prototipos de funciones auxiliares
void tratar(int *, int);
bool correcto(int *, int[][3], int, int);
int valor(int *, int[][3], int);
int aux(int[][5], int, int, int);

int main()
{

    // datos del problema para Programacion Dinamica y Vuelta Atras
    int N = 4;
    int M = 3;
    int D[1 + 4][1 + 2] = {{0, 0, 0},
                           {0, 14, 61},
                           {0, 50, 3},
                           {0, 8, 99},
                           {0, 100, 1000}};

    // datos del problema para Divide y Venceras
    int A[3][5] = {{9, 7, 5, 4, 3},
                   {20, 12, 8, 5, 2},
                   {28, 27, 9, 2, 1}};

    /*
int A[3][5]={{9,7,1,4,3},
             {20,12,8,5,2},
             {28,25,9,2,1}};

*/

    //
    // invocaciones a las funciones
    //

    // Programacion Dinamica
    // rellenar por el alumno

    // Vuelta Atras (Backtracking)
    //invocamos a OPTIMA de BACKTRACKING

    // Divide y Venceras
    // rellenar por el alumno

    printf("%d", Divide_y_Venceras_PL6_B(A, 0, 4, 2));

    return 0;
}

// definiciones de funciones

//int Programacion_Dinamica_PL6_B (int C, int N, int A[1+5][1+2]){
// rellenar por el alumno
//}

int Divide_y_Venceras_PL6_B(int A[][5], int iniCol, int finCol, int fil)
{
    // rellenar por el alumno

    int m, p1, p2;

    if (iniCol == finCol)
    {
        return 1;
    }
    else
    {
        m = (iniCol + finCol) / 2;

        p1 = Divide_y_Venceras_PL6_B(A, iniCol, m, fil);
        p2 = Divide_y_Venceras_PL6_B(A, m + 1, finCol, fil);
    }
    return aux(A, iniCol, finCol, fil) * p1 * p2;
}

int aux(int A[][5], int iniCol, int finCol, int fil)
{

    for (int i = 0; i <= fil; i++)
    {
        int temp = INT_MAX;
        for (int z = iniCol; z <= finCol; z++)
        {
            if (A[i][z] < temp)
            {
                temp = A[i][z];
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}