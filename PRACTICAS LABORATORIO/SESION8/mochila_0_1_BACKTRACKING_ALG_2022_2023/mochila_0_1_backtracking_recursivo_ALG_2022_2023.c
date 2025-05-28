// -------------------------------------------------------------------
//
//  ALGORITMIA: IMPLEMENTACION DEL PROBLEMA DE LA MOCHILA 0/1
//
//              SEGUN BACKTRACKING (VUELTA ATRAS) - version recursiva
//
//              En esta version, los vectores de pesos y de beneficios
//              (asi como x y x_mejor) tienen n+1 elementos, de 0 a n.
//              Ignoramos la posicion 0, por lo que, por ejemplo, el
//              peso del objeto k esta en P[k]
//
//              k representa los objetos: 1, 2, ..., n
//              De hecho, cuando k=n tendremos una solucion completa
//
//  SESION 3.3 DE PRACTICAS (ESQUEMAS ALGORITMICOS - BACKTRACKING)
//
//  Copyright: Nahuel Costa & Raquel Cortina
//
//  Fechas: del 28 de noviembre al 2 de diciembre de 2022
//
// -------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// prototipos de funciones
int peso(int *,int *,int);
int valor(int *,int *,int);
void tratar (int *, int);

void mochila_TODAS(int *, int , int , int , int *);
void mochila_UNA(int *, int , int , int , int *, bool *);
void mochila_OPTIMA(int *, int *, int , int , int , int *, int *, int *);

// funcion main
int main(){
int n,C,i;
int *x,*x_mejor,v_mejor,*P, *B;
bool flag;

printf ("\n\tIntroduce la capacidad de la mochila: ");
scanf("%d",&C);

printf ("\n\tIntroduce el numero de objetos: ");
scanf("%d",&n);

//
// Los vectores P, B, x y x_mejor tendran tama�o n+1 con objeto de
// "utilizar" el sector [1..n] e ignorar la posici�n 0, de ese modo la
// implementaci�n es exactamente igual que el algoritmo visto en clase
//

P=(int *)malloc((n+1)*sizeof(int));
B=(int *)malloc((n+1)*sizeof(int));
x=(int*)malloc((n+1)*sizeof(int));
x_mejor=(int *)malloc((n+1)*sizeof(int));

printf ("\n\n\t\t PESOS\n\n");

for(i=1;i<=n;i++){
   printf ("\n\tIntroduce el peso del objeto %d: ",i);
   scanf("%d",&P[i]);
}

printf ("\n\n\t\t BENEFICIOS\n\n");

for(i=1;i<=n;i++){
   printf ("\n\tIntroduce el beneficio del objeto %d: ",i);
   scanf("%d",&B[i]);
}

// invocamos a TODAS_LAS_FACTIBLES
printf("\n\n\tTODAS LAS SOLUCIONES FACTIBLES\n");
mochila_TODAS(P,n,C,1,x);

// invocamos a UNA_FACTIBLE
printf("\n\n\tUNA TUPLA FACTIBLE:\n");
flag=true;
mochila_UNA(P,n,C,1,x,&flag);

// invocamos a OPTIMA
printf("\n\n\tSOLUCION OPTIMA:\n");
v_mejor=INT_MIN;
mochila_OPTIMA(P,B,n,C,1,x,x_mejor,&v_mejor);

// mostrar la solucion (secuencia de decisiones optima y beneficio maximo)
tratar(x_mejor,n);
printf("\t\tBeneficio optimo: %d\n\n\n\n", v_mejor);

// liberacion de memoria
free(x);
free(x_mejor);
free(P);
free(B);
return 0;
}

// funcion que calcula el peso asociado a la secuencia de decisiones x
int peso(int *P,int *x,int k){
int i, total=0;
for (i=1;i<=k;i++){
   total=total+x[i]*P[i];
  }
return total;
}

// funcion que calcula el valor asociado a la secuencia de decisiones x
int valor(int *B,int *x,int n){
int i, total=0;
for (i=1;i<=n;i++){
   total=total+x[i]*B[i];
  }
return total;
}

// funcion que muestra por pantalla la secuencia de decisiones x
void tratar (int *x, int n){
int i;
printf("\n\t< ");
for (i=1;i<=n;i++){
   printf("%d ",x[i]);
   }
printf(">");
}



// funcion backtracking que proporciona TODAS LAS SOLUCIONES FACTIBLES
void mochila_TODAS(int *P, int n, int C, int k, int *x){
  x[k]=-1;    // preparar_recorrido_nivel_k
  while (x[k]<1){  // mientras exista_hermano_nivel_k
        x[k]=x[k]+1; // siguiente_hermano_nivel_k
        if (k==n && (peso(P,x,k)<=C)) tratar(x,n); // si solucion(x,k) y correcto(x,k)
        if (k<n && (peso(P,x,k)<=C)) mochila_TODAS(P,n,C,k+1,x);// si no es solucion(x,k) y correcto(x,k)
       }
}






// funcion backtracking que proporciona UNA SOLUCION FACTIBLE
void mochila_UNA(int *P, int n, int C, int k, int *x, bool *flag){
  x[k]=-1;
  while (x[k]<1 && *flag==true){
        x[k]=x[k]+1;
        if (k==n && peso(P,x,k)<=C){
                                        *flag=false;
                                        tratar(x,n);
                                   }
        if (k<n && peso(P,x,k)<=C) mochila_UNA(P,n,C,k+1,x,flag);
       }
}



// funcion backtracking que proporciona la SOLUCI�N �PTIMA
void mochila_OPTIMA(int *P, int *B, int n, int C, int k, int *x, int *x_mejor, int *v_mejor){
  int i,aux;
  x[k]=-1;
  while (x[k]<1){
                   x[k]=x[k]+1;
                   if (k==n && peso(P,x,k)<=C){
                                                aux=valor(B,x,n); // funcion objetivo
                                                if (aux > *v_mejor){
                                                                    *v_mejor=aux;
                                                                    //opcion 1
                                                                    //for(i=1;i<=n;i++)
                                                                    //  x_mejor[i]=x[i];

                                                                    //opcion 2
                                                                    //void *memcpy(void *s1, const void *s2, size_t n);
                                                                    //memcpy copia los primeros n bytes del area de memoria apuntada por
                                                                    //s2 al area de memoria apuntada por s1
                                                                    memcpy(x_mejor,x,(n+1)*sizeof(int));
                                                                    }
                                              }
                   if (k<n && peso(P,x,k)<=C) mochila_OPTIMA(P,B,n,C,k+1,x,x_mejor,v_mejor);
               }
}

