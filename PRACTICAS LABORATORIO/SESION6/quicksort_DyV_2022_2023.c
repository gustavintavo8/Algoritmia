// ----------------------------------------------------------------------------------------------------------
//
// ALGORITMIA: PRACTICA DE DIVIDE Y VENCERAS
//
// Implementacion en C de QUICKSORT
//
// Copyright: Raquel Cortina
//
// Fecha: 27 de octubre de 2022
//
// -----------------------------------------------------------------------------------------------------------
//
// Programa en el que se pide el tamanio del vector (n>=0), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de la funcion
// QUICKSORT, que sigue el esquema de divide y venceras, se ordena el vector en sentido ascendente.
//
//------------------------------------------------------------------------------------------------------------


#include <stdlib.h>
#include <stdio.h>

// prototipos de funciones
void escribe_vector(int *V, int n);
void lee_vector(int *V, int n);
int Partir(int *V, int inicio, int fin);
void Quicksort(int *V, int inicio, int fin);


// programa principal
int main(){
    int n;
    int *V;

    do{
       printf("\nIntroduce la dimension del vector (>=0): ");
       scanf("%d",&n);
       } while (n<0) ;

    // reservar dinamicamente memoria
    V = (int*) malloc(n*sizeof(int));

    lee_vector (V,n);

    printf("\n\nVector introducido es:\n\n");
    escribe_vector (V,n);

    // invocacion a Quicksort
    Quicksort(V,0,n-1);

    printf("\n\nVector ordenado es:\n\n");
    escribe_vector (V,n);

    //liberar memoria
    free(V);
    return 0;
}

//
// Definiciones de funciones
//

// Funcion para leer los elementos del vector
void lee_vector(int *V, int n){
     printf("\n");
     for(int i=0;i<n;i++){
             printf("Dame el elemento %d: ",i+1);
             scanf("%d", &V[i]);
     }

}

// Funcion para escribir los elementos del vector
void escribe_vector(int *V, int n){
     printf("\n\t");
     printf("[ ");
     for(int i=0;i<n;i++)
        printf("%d ",V[i]);
     printf("]");
     printf("\n\n");
}

//
// Funcion auxiliar utilizada por QUICKSORT: Partir
// La funcion Partir escoge como pivote el primer elemento, V[inicio],
// y a continuacion, situa los elementos menores que el pivote a la izquierda
// y los mayores que pivote a la derecha. Cuando acaba el proceso, el pivote se situa
// entre las dos secciones y esa seria su posicion definitiva.
//
int Partir(int *V, int inicio, int fin){
    int i,j;
    int pivote;
    int aux;

    // eleccion del pivote (el primer elemento)
    pivote = V[inicio];

    i=inicio+1;
    j=fin;
    while (i<=j){
        while(V[i]<=pivote && i<=j) i++;
        while(V[j]>=pivote && i<=j) j--;

        if (i<j){aux=V[i];V[i]=V[j];V[j]=aux;}
    }
    aux=V[inicio];
    V[inicio]=V[j];
    V[j]=aux;
    // se devuelve la posicion definitiva del pivote (j), sabiendo por tanto que los elementos de la seccion [inicio..j-1] son menores que el pivote
    // y que los elementos de la seccion [j+1..fin] son mayores que el pivote
    return j;
}

// Quicksort
void Quicksort(int *V, int inicio, int fin){
     int posicion_pivote;
     if(inicio < fin){
        posicion_pivote=Partir(V, inicio, fin);
        // se devuelve la posicion definitiva del pivote, sabiendo por tanto que los elementos de
        // la seccion [inicio..posicion_pivote-1] son menores que el pivote
        // y que los elementos de la seccion [posicion_pivote+1..fin] son mayores que el pivote
        Quicksort(V, inicio, posicion_pivote-1);
        Quicksort(V, posicion_pivote+1, fin);
     }
}
