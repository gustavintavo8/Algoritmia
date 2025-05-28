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
int Programacion_Dinamica_PL6_B (int , int , int [1+4][1+2]);
void Backtracking_PL6_B (int[][3], int, int, int, int*, int*, int*);
//int Divide_y_Venceras_PL6_B(...);


// prototipos de funciones auxiliares
void tratar(int*, int);
bool correcto(int*, int[][3], int, int);
int valor(int*, int[][3],int);
  



int main(){

// datos del problema para Programacion Dinamica y Vuelta Atras
int N=4;
int M=3;
int D[1+4][1+2]={{0,0,0},
                 {0,1994,61},
                 {0,1,3},
                 {0,901,99},
                 {0,100,1000}};


// datos del problema para Divide y Venceras
int A[3][5]={{9,7,5,4,3},
             {20,12,8,5,2},
             {28,25,9,2,1}};

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

int *x_mejor,v_mejor;

int x[4]={8,8,8,8};

x_mejor=(int *)malloc(N*sizeof(int));

printf("\n\nSOLUCION OPTIMA:\n"); 
v_mejor=INT_MIN;
Backtracking_PL6_B(D,N,M,0,x,x_mejor,&v_mejor);

tratar(x_mejor,N);
printf("\t\tEl sumatorio maximo de la descomposicion es: %d\n", v_mejor);


free(x_mejor);

// Divide y Venceras
// rellenar por el alumno

return 0;
}


// definiciones de funciones

//int Programacion_Dinamica_PL6_B (int C, int N, int A[1+5][1+2]){
// rellenar por el alumno
//}


void Backtracking_PL6_B(int D[][3], int N, int M, int k, int *x, int *x_mejor, int *v_mejor){
    int i,aux;
    x[k]=0;   // PREPARA RECORRIDO NIVEL K  
    while(x[k]<2){  // MIENTRAS EXISTA HERMANO NIVEL K  (N-M+1 --> NUMERO DE SOLUCIONES DEL ARBOL)
          // SIGUIENTE HERMANO NIVEL K
          x[k]=x[k]+1;
        if(x[N-1]!=8 && correcto(x,D,N,M)){ // si solucion(x,k) y correcto(x,k)
            aux = valor(x,D,N);
            if(aux>*v_mejor){
                *v_mejor=aux;
                memcpy(x_mejor,x,N*sizeof(int));
            }
        }
        if(k<N-1 || x[N-1]==8) Backtracking_PL6_B(D,N,M,k+1,x,x_mejor,v_mejor);  // si no es solucion(x,k) y correcto(x,k)  --> RECURSIVO
        
    }
}


void tratar(int *x, int N){
   
    printf("\n\t< ");
    for(int i=0;i<N;i++){
        printf("%d ",x[i]);
    }
    printf(">");
}

bool correcto(int *x, int S[][3], int N, int M){
    int contador = 0;
    bool salir=false;
    for(int i=0; i<N ; i++){
            if(x[i] == 1){
            contador++;
        }
    }
    if(contador < M ) {
        return true;
    }
    else{
        return false;
    }
}


int valor(int *x,int S[][3], int N){
   int sum = 0;
   for(int i=0; i<N; i++){
       sum = sum + S[i+1][x[i]];
   }
   return sum;
   
}

//int Divide_y_Venceras_PL6_B(...){
// rellenar por el alumno
//}