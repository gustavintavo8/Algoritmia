// --------------------------------------------------------------------------
//
//  ALGORITMIA: IMPLEMENTACION DEL ALGORITMO "MOCHILA 0/1" Y
//
//              DEL ALGORITMO "DESCOMPONER UN NUMERO N EN M SUMANDOS"
//
//
//  SESION 3.2 DE PRACTICAS (ESQUEMAS ALGORITMICOS - PROGRAMACION DINAMICA)
//
//  Fechas: del 18 al 24 de noviembre de 2022
//
//  Copyright: Nahuel Costa & Raquel Cortina
//
//
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int MOCHILA_programacion_dinamica (int *, int *, int, int);
int DESCOMPONER_programacion_dinamica(int,int);

// EMBARCADEROS (OPCIONAL)
//int EMBARCADEROS_programacion_dinamica(int, int **);

int main(){
int n,C,i;
int *P;
int *B;

do{
    printf("Introduce la capacidad de la mochila: ");
    scanf("%d",&C);
} while(C<0);

do{
    printf("\nIntroduce el numero de objetos:  ");
    scanf("%d",&n);
} while(n<0);

// reserva dinamica de memoria para vectores de pesos y beneficios
P=(int *)malloc((n+1)*sizeof(int));
B=(int *)malloc((n+1)*sizeof(int));

printf("\n\nIntroduce los pesos de los %d objetos\n",n);
for (i=1;i<=n;i++){
   do {
    printf("\nPeso[%d]= ", i);
    scanf("%d",&P[i]);
   } while(P[i]<=0);
}

printf("\n\nIntroduce los beneficios de los %d objetos\n",n);
for (i=1;i<=n;i++){
    do {
        printf("\nBeneficio[%d]= ", i);
        scanf("%d",&B[i]);
    } while(B[i]<=0);
   }

//
// La funcion MOCHILA_programacion_dinamica recibe:
// - los vectores P y B con los pesos y beneficios de los objetos,
// - el numero de objetos, n, y
// - la capacidad de la mochila, C
//

printf(" y el beneficio maximo es: %d\n",MOCHILA_programacion_dinamica(P,B,n,C));
printf("\n\n");


// liberar memoria
free(P);
free(B);

//
// DESCOMPOSICION DE N EN M SUMANDOS
//
int N,M;

do{
    printf("Introduce el numero a descomponer: ");
    scanf("%d",&N);
} while(N<=0);

do{
    printf("\nIntroduce el numero de sumandos en los que se va a descomponer:  ");
    scanf("%d",&M);
} while(M<=0||M>N);

printf(" y producto maximo es:%d\n",DESCOMPONER_programacion_dinamica(N,M));
printf("\n\n");


//
// EMBARCADEROS [OPCIONAL]
//

int n;
printf("Introduce el numero de embarcaderos: ");
scanf("%d",&n);

// reserva dinámica de memoria para la matriz de costes C
// realizar por el alumno

/*
C=(int **)malloc((n+1)*sizeof(int *));

for (int i=0;i<=n;i++){
    C[i]=(int *)malloc((n+1)*sizeof(int));
}
*/

// lectura de la matriz C de costes
// realizar por el alumno


printf("\n\nEl coste final del recorrido es %d\n",EMBARCADEROS_programacion_dinamica(n,C));


return 0;
}

int MOCHILA_programacion_dinamica (int *P, int *B, int n, int C){
    int **Bmax;
    int **Dec;
    int *X;

    // reserva dinamica de memoria para X, esto es, el vector de decisiones
    // realizar por el alumno

    X=(int *)malloc((n+1)*sizeof(int));

    // reserva dinamica de memoria de las matrices Bmax y Dec
    // realizar por el alumno

    Bmax=(int **)malloc((n+1)*sizeof(int *));
    Dec=(int **)malloc((n+1)*sizeof(int *));

    for(int i=0;i<=n;i++){
        Bmax[i]=(int *)malloc((C+1)*sizeof(int));
        Dec[i]=(int *)malloc((C+1)*sizeof(int));
    }

    // inicializar las matrices con los resultados de los problemas triviales
    // realizar por el alumno

    for(int c=0;c<=C;c++){
        Bmax[0][c]=0;
        Dec[0][c]=0;
    }
    
    // rellenar las matrices por filas en sentido ascendente
    // realizar por el alumno

    for(int j=1;j<=n;j++){
        for (int c=0; c<=C; c++){
            if (c<P[j]){
                Bmax[j][c]=Bmax[j-1][c];
                Dec[j][c]=0;
            }
            else{
                if (Bmax[j-1][c] >= Bmax[j-1][c-P[j]]+B[j]){
                    Bmax[j][c]=Bmax[j-1][c];
                    Dec[j][c]=0;
                }
                else{
                    Bmax[j][c]=Bmax[j-1][c-P[j]]+B[j];
                    Dec[j][c]=1;
                }
            }
        }
    }

    // solucion
    // realizar por el alumno

    int j=n;
    int c=C;

    while(j>0){
        X[j]=Dec[j][c];
        c=c-X[j]*P[j];
        j=j-1;
    }

    // mostrar por pantalla la secuencia de decisiones optima
    // realizar por el alumno

    printf("\n");
    printf("La secuencia de decisiones optima es: ");

    for(int i=1;i<=n;i++){
        if (i==n){
            printf("%d]",X[i]);
        }
        else{
            if (i==1){
                printf("[%d,",X[i]);
            }
            else{
                printf("%d,",X[i]);
            }
        } 
    }

    // liberar memoria
    // realizar por el alumno
    
    for(int i=0;i<=n;i++){
        free(Bmax[i]);
        free(Dec[i]);
    }
    free(Bmax);
    free(Dec);   
    free(X);

    // retornar el beneficio maximo
    // realizar por el alumno
    return Bmax[n][C];
}


int DESCOMPONER_programacion_dinamica(int N, int M){
    int **Pmax;
    int **Dec;
    int *S;

    // reserva dinamica de memoria para Sumandos, esto es, el vector de decisiones
    // realizar por el alumno

    S=(int *)malloc((M+1)*sizeof(int));

    // reserva dinamica de memoria de las matrices Pmax y Dec
    // realizar por el alumno

    Pmax=(int **)malloc((M+1)*sizeof(int *));
    Dec=(int **)malloc((M+1)*sizeof(int *));

    for(int i=0;i<=M;i++){
        Pmax[i]=(int *)malloc((N+1)*sizeof(int));
        Dec[i]=(int *)malloc((N+1)*sizeof(int));
    }

    // inicializar las matrices con los resultados de los problemas triviales
    // realizar por el alumno

    for(int n=1;n<=N;n++){
        Pmax[1][n]=n;
        Dec[1][n]=n;
    }

    // rellenar las matrices por filas en sentido ascendente
    // realizar por el alumno

    for (int j=2;j<=M;j++){
        for (int n=j;n<=N;n++){
            Pmax[j][n]=1;
            for (int Sj=1;Sj<=n-j+1;Sj++){
                int p = Pmax[j-1][n-Sj]*Sj;
                if (p>=Pmax[j][n]){
                    Pmax[j][n]=p;
                    Dec[j][n]=Sj;
                }
            }
        }
    }

    // solucion
    // realizar por el alumno

    int j=M;
    int n=N;

    while (j>0){
        S[j]=Dec[j][n];
        n=n-S[j];
        j--;
    }

    // mostrar por pantalla la secuencia de decisiones optima
    // realizar por el alumno

    printf("\n");
    printf("La secuencia de decisiones optima es: ");

    for(int i=1;i<=M;i++){
        if (i==M){
            printf("%d]",S[i]);
        }
        else{
            if (i==1){
                printf("[%d,",S[i]);
            }
            else{
                printf("%d,",S[i]);
            }
        } 
    }

    // liberar memoria
    // realizar por el alumno

    for (int i=0;i<=M;i++){
        free(Pmax[i]);
        free(Dec[i]);
    }
    free(Pmax);
    free(Dec);
    free(S);

    // retornar el producto maximo
    // realizar por el alumno
    return Pmax[M][N];
}


// [OPCIONAL] 
int embarcaderos_programacion_dinamica(int n, int **C){
    int *Costemin;
    int *Dec;
    int *X;

    // reserva dinamica de memoria para el vector de decisiones

    X=(int *)malloc((n+1)*sizeof(int));

    // reserva dinamica de memoria de los vectores Costemin y Dec

    Costemin=(int *)malloc((n+1)*sizeof(int));
    Dec=(int *)malloc((n+1)*sizeof(int));

    // inicializar las matrices con los resultados de los problemas triviales

    Costemin[n] = 0;
    Dec[n] = n;

    // rellenar los vectores de los problemas no triviales

    for (int j=n-1;j>=1;j++){
        Costemin[j]=INT_MAX;
        for (int k=j+1;k<=n;k++){
            if (Costemin[j] > C[j][k]+Costemin[k]){
                    Costemin[j] = C[j][k] + Costemin[k];
                    Dec[j] = k;
            }
        }
    }

    // solucion

    X[1]=0;
    int j=1;

    while(X[j]!=n){
        j++;
        X[j] = Dec[X[j-1]];
    }

    // mostrar por pantalla la secuencia de decisiones optima
    // realizar por el alumno

    printf("\n");
    printf("La secuencia de decisiones optima es: ");

    for(int i=1;i<=n;i++){
        if (i==n){
            printf("%d]",X[i]);
        }
        else{
            if (i==1){
                printf("[%d,",X[i]);
            }
            else{
                printf("%d,",X[i]);
            }
        } 
    }

    // liberar memoria

    free(Costemin);
    free(Dec);
    free(X);

    // retornar el coste minimo

    return Costemin[1];
}