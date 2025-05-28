//Programacion dinamica
//Funcion Objetivo: Maximizar el sumatorio desde i=1 hasta n de D[i]*X[i]
//Restricciones: (Ni)(xi = 1 : 1<=i<=N) <= M y (Ai)(xi € {1,2} : 1<=i<=N)
//Definicion Recursiva: F(j,m) es el valor de la solucion optima para el subproblema (j,m). LLamada inicial: F(N,M)
//Definicion Recursiva: 0 si j=0
//                      F(j-1,m) + D[j][2] si j>0 y m=0
//                      max(F(j-1,m-1) + D[j][1],F(j-1,m) + D[j][2]) si j>0 y m>0
//Datos de entrada: N,M: enteros, D[1..n][1..2]:matriz de enteros
//Datos de salida: secuencia de decisiones optima X[1..n] y valor asociado
//Ejemplo: N=4, M=3, D[1..4][1..2] = {{14,6},{10,3},{8,9},{6,10}}
//Solucion: X[1..4] = {1,1,2,2} Valor asociado: 43

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(){
    int N,M;
    int **D;
    int **F;
    int *X;
    int i,j;
    
    printf("Introduzca el numero de elementos: ");
    scanf("%d",&N);

    printf("Introduzca el numero de elementos que se pueden seleccionar: ");
    scanf("%d",&M);

    D = (int **)malloc(N*sizeof(int *));
    for(i=0;i<N;i++){
        D[i] = (int *)malloc(2*sizeof(int));
    }

    F = (int **)malloc(N*sizeof(int *));
    for(i=0;i<N;i++){
        F[i] = (int *)malloc(M*sizeof(int));
    }

    X = (int *)malloc(N*sizeof(int));

    printf("Introduzca los valores de la matriz D: \n");
    for(i=0;i<N;i++){
        for(j=0;j<2;j++){
            scanf("%d",&D[i][j]);
        }
    }

    printf("y la secuencia de decisiones optima es: %d\n", DINAMICA(N,M,D,F));
    printf("\n\n");

    for(i=0;i<N;i++){
        free(D[i]);
        free(F[i]);
    }

    free(D);
    free(F);
    free(X);

    return 0;
}

int DINAMICA(int n, int m, int **D, int **F){
    int i,j;
    int max;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(i==0){
                F[i][j] = 0;
            }
            else{
                if(j==0){
                    F[i][j] = F[i-1][j] + D[i][1];
                }
                else{
                    max = F[i-1][j-1] + D[i][0];
                    if(max < F[i-1][j] + D[i][1]){
                        max = F[i-1][j] + D[i][1];
                    }
                    F[i][j] = max;
                }
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",F[i][j]);
        }
        printf("\n");
    }

    return F[n-1][m-1];
}