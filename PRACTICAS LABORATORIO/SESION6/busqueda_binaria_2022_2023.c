// ------------------------------------------------------------------------------------------------
//
// ALGORITMIA: PRACTICA DE DIVIDE Y VENCERAS
//
// Implementacion en C del algoritmo "BUSQUEDA BINARIA"
//
// Copyright: Raquel Cortina
//
// Fecha: 27 de octubre de 2022
//
// ------------------------------------------------------------------------------------------------------
//
// Programa en el que se pide el tamanio del vector (n>=0), se reserva dinamicamente memoria,
// se leen sus elementos. Estos se deben introducir en sentido ascendente. Los elementos se
// muestran por pantalla y seguidamente, a traves de la funcion recursiva BUSQUEDA BINARIA que sigue
// el esquema de divide y venceras, se busca un valor x en el vector devolviendose la posicion que
// ocupa (si es que esta) o la posicion que deberia ocupar (si es que no esta). El vector puede ser vacio.
//
//--------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// prototipos de funciones
int lee_vector_orden_ascendente(int*, int);
int escribe_vector(int*, int);
bool busqueda_binaria (int*,int,int,int, int* );


// programa principal
int main() {
    int n,x;
    int pos;
    int *V;
    do{
       printf("\nDame el tamanio del vector de n (n>=0): ");
       scanf("%d",&n);} while (n<0) ;

    // reservar dinamicamente memoria
    V = (int*) malloc(n*sizeof(int));

    lee_vector_orden_ascendente(V,n);

    escribe_vector (V,n);

    printf("\nIntroduce el valor a buscar en el vector: \n\n");
    scanf("%d",&x);

    if (busqueda_binaria(V,0,n-1,x,&pos))
       printf("\n\nEl valor %d esta en la posicion %d del vector\n\n",x,pos);
    else printf("\n\nEl valor %d no esta en el vector. \n\nDeberia ocupar la posicion %d del vector\n\n",x,pos);

     //liberar memoria
    free(V);
    return 0;
}

//
// Definiciones de funciones
//

// Funcion para leer las n componentes del vector v.
// Las componentes leidas deben estar en sentido creciente
int lee_vector_orden_ascendente(int *V, int n){
    int i=0, ant=INT_MIN;
    while (i<n){
        printf("\nDame el valor de la componente %d: ",i+1);
        scanf("%d",&V[i]);
        if (V[i]>ant) {ant=V[i];i=i+1;}
        else printf("\nDato erroneo, \n\nel valor introducido debe ser mayor que el anterior\n\n");
    }
    return 0;
}

// Funcion para escribir las n componentes del vector v
int escribe_vector(int *V, int n){
    printf("\nEl vector es: [ ");
    for (int i=0;i<n;i++) {
        printf("%d ",*(V+i));
    }
    printf("]\n");
    return 0;
}


// Funcion que busca el valor x en el vector v devolviendo la posicion que ocupa
// (si es que esta) o la posicion que deberia ocupar (si es que no esta)
bool busqueda_binaria (int *V, int inicio, int fin, int x, int *pos){
  int mitad;
  if (inicio>fin) { // caso trivial
                   *pos=inicio+1;
                   return false;
                  }
  else { // caso general
       mitad=(inicio+fin)/2;
       if (x==V[mitad]) {*pos=mitad+1;return true;}
       else {
            if (x<V[mitad]) return busqueda_binaria(V,inicio,mitad-1,x,pos);
            else return busqueda_binaria(V,mitad+1,fin,x,pos);
            }
       }
}

