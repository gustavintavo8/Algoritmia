#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool AuxExamPL6B(int A[3][4], int B[3][4], int n, int m, int k)
{
    int productoA = 1;
    int productoB = 1;

    for (int i = 0; i <= n-1; i++){
        productoA = A[i][k-1]*productoA;
        productoB = B[i][k-1]*productoB;
    }

    if (productoA == productoB){
        return true;
    }

    return false;
}

int iExamPL6B(int A[3][4], int B[3][4], int n, int m, int k)
{
    int b;
    //printf("iExam n=%d, m=%d, k=%d\n", n,m,k);
    //printf("k=%d\n",k);
    while (k <= m+1){

        if (k == m + 1){
        b = 0;
         //if(b){ printf("b=0\n");}
         //else {printf("b=1\n");}
        return b;
        }

    else{
        b = iExamPL6B(A, B, n, m, k + 1) + AuxExamPL6B(A, B, n, m, k);
         //if(b){ printf("baux=0\n");}
         //else {printf("baux=1\n");}
        return b;
    }
    }
    return b;
}

int iExamIterativo(int A[3][4], int B[3][4], int n_inicial, int m_inicial, int k_inicial)
{
    // Inicialización
    int n = n_inicial;
    int m = m_inicial;
    int k = k_inicial;
    int b;

    // Bucle de descenso hasta el caso base
    while (k > m+1)
    {
        k++;
    }

    // Caso base
    b = 0;

    // Bucle de subida
    while (k != k_inicial)
    {
        k--;
        int productoA = 1;
        int productoB = 1;

        for (int i = 0; i <= n-1; i++){
            productoA = A[i][k-1]*productoA;
            productoB = B[i][k-1]*productoB;
        }

        if (productoA == productoB){
            b = 0;
        }

        else{
            b = 1;
        }

    return b;
    }
}

int main()
{
    printf("\n\n\tGustavo Sobrado Aller - UO286277\t\n");

    int A[3][4] = {
        {2, 4, 1, 2},
        {3, 3, 3, 2},
        {6, 2, 1, 5}
    };

    int B[3][4] = {
        {1, 7, 1, 5},
        {6, 9, 5, 4},
        {6, 1, 1, 1}
    };

    int n = 3;
    int m = 4;

    printf("\t----------------------------------\n");
    printf("\t\tiExam\t\n");

    if (iExamPL6B(A, B, n, m, 1))
    {
        printf("\tEl resultado de iExam es 0\n");
    }
    else
    {
        printf("\tEl resultado de iExam es 1\n");
    }

    printf("\t----------------------------------\n");
    printf("\t\tiExamIterativo\t\n");
    
    if (iExamIterativo(A, B, n, m, 1))
    {
        printf("\tEl resultado de iExamIterativo es 0\n");
    }
    else
    {
        printf("\tEl resultado de iExamIterativo es 1\n");
    }
}
