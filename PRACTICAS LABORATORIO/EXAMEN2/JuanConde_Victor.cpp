/*
    Test: "PL2"
    Model: "B"
    Author: "Victor Juan Conde"
    UO: "uo263762"
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


bool AuxExamPL2B(int A[3][4],int n, int m, int k) {
    for(int j=0; j<=m-1; j++) {
        if(A[k-1][j] == k*j) return true;
    }
    return false;
}


bool iExamPL2B(int A[3][4],int n, int m, int k) {
    //printf("n=%d\nm=%d\nk=%d\n----------------\n",n,m,k);
    bool p;
    if(k==1) {
        p = AuxExamPL2B(A,n,m,k);
        //printf("En k=%d --> p=%d\n",k,p);
        return p;
    } else {
        p = iExamPL2B(A,n,m,k-1) && AuxExamPL2B(A,n,m,k);
        //printf("En k=%d --> p=%d\n",k,p);
        return p;
    }
}


bool iExamPL2B_ITERATIVA(int A[3][4],int n_inicial, int m_inicial, int k_inicial) {
    //Inicializar variables
    int n=n_inicial;
    int m=m_inicial;
    int k=k_inicial;
    bool p;

    //Bucle de bajada
    while (k > 1) {
        k--;
    }

    //Caso Base
    for (int j = 0; j <= m-1; j++) {

            if(A[k-1][j] == k*j) {
                p = true;
            }

            else{
                p = false;
            }

    }

    while (k != k_inicial) {
        k++;
        for (int j = 0; j <= m-1; j++) {

            if(A[k-1][j] == k*j) {
                p = p && true;
            }

            else{
                p = p && false;
            }

        }
    }

    return p;
}

int main() {
    /*
    int A[3][4] = {
        {999,1,0,0},
        {999,2,0,0},
        {999,3,0,0}};
    */
    int A[3][4] = {
        {1,1,7,3},
        {5,8,5,2},
        {7,3,9,1}};
    int n = 3;
    int m = 4;
    int k = 3;

    printf("############# Test PL2 Modelo B #############\n");
    printf("\tRecursivo: %d\n",iExamPL2B(A,n,m,k));
    printf("#########################\n");
    printf("\tIterativo: %d\n",iExamPL2B_ITERATIVA(A,n,m,k));
}
