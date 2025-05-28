//
// ALGORITMIA: PRACTICA DE DIVIDE Y VENCERAS
//
// MAXIMO_VECTOR - PRODUCTO_VECTOR - EXAMEN RECURSION NOVIEMBRE 2020
//
// Copyright: Nahuel Costa & Raquel Cortina
//
// Fecha: 11 de noviembre de 2022
//
// -----------------------------------------------------------------------------------------------------------------------------------------------
//
// TAREAS.-
//
// Programa en el que se pide el tamanio del vector (n>=1), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de las funciones
// MAXIMO_VECTOR y PRODUCTO_VECTOR, que deben seguir el esquema de divide y venceras, se buscará el elemento de mayor
// valor en el vector y se calculará el producto de los elementos del vector respectivamente.
//
// Programa en el que se pide el numero de filas y de columnas de la matriz (n,m>=1), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de la funcion
// EXAMEN_RECURSION_NOVIEMBRE_2020, que debe seguir el esquema de divide y venceras, se resolverá el problema 1 del examen del tema 2 (curso 2020/2021):
//
// "Dada una matriz de enteros A[1..n][1..m] siendo n≥1 y m≥1, diseñar una función recursiva que retorne cierto si se cumple que
//  todo elemento de la matriz es el doble del elemento situado a su izquierda, y falso en caso contrario"
//
//-------------------------------------------------------------------------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototipos de funciones maximo y producto
int lee_vector(int *, int);
int escribe_vector(int *, int);
int maximo_vector_DyV(int *,int, int);
int producto_vector_DyV(int *,int, int);

// prototipos de la funcion EXAMEN RECURSION NOVIEMBRE 2020 y funciones auxiliares
void lee_matriz (int **, int, int);
void escribe_matriz (int **, int, int);
bool EXAMEN_RECURSION_NOVIEMBRE_2020 (int **, int, int, int);
// incluir mas prototipos si fuera necesario


// programa principal
int main() {

    int n,m,x;
    int *V;

    do{
       printf("\nIntroduce el numero de elementos del vector para obtener el maximo y el producto (>=1): ");
       scanf("%d",&n);} while (n<1);

    // reservamos dinamicamente memoria
    V = (int*) malloc(n*sizeof(int));

    // leemos los elementos del vector
    lee_vector(V,n);

    // mostramos los elementos del vector
    escribe_vector (V,n);

    printf("\nEl maximo de los elementos del vector es %d\n\n",maximo_vector_DyV(V,0,n-1));
    printf("\nEl producto de los elementos del vector es %d\n\n",producto_vector_DyV(V,0,n-1));

    //liberamos memoria
    free(V);

    // PROBLEMA 2 DEL EXAMEN RECURSION NOVIEMBRE 2020

    do {
        printf("Introduce el numero de filas: ");
        scanf("%d",&n);} while (n<1);

    do {
        printf("Introduce el numero de columnas: ");
        scanf("%d",&m);} while (m<1);

    // definimos una variable de tipo puntero a puntero a int y reservamos memoria para n filas
    int **M = (int**) malloc(n*sizeof(int*));

    // reservamos espacio para las columnas
    for(int i=0;i<n;i++)
            M[i] = (int*) malloc(m*sizeof(int));

    // leemos los elementos de la matriz
    lee_matriz (M,n,m);


    printf("\n\nLa matriz introducida es:\n\n");

    // mostramos el contenido de la matriz
    escribe_matriz (M,n,m);

    // invocamos a la funcion del examen 2020
    
    if (EXAMEN_RECURSION_NOVIEMBRE_2020(M,n,0,m-1)) printf("Si se cumple que todo elemento de la matriz es el doble del elemento situado a su izquierda\n\n");
    else printf("No se cumple que todo elemento de la matriz es el doble del elemento situado a su izquierda\n\n");
    
    // liberamos el espacio reservado para las columnas
    for (int i=0;i<n;i++) free(M[i]);

    // liberamos el espacio reservado para las filas
    free(M);

    return 0;
}

//
// Definiciones de funciones
//

// Funcion para leer las componentes del vector
int lee_vector(int *V, int n){
    for (int i=0;i<n;i++) {
        printf("\nDame el valor de la componente %d: ",i+1);
    scanf("%d",V+i);
    }
    return 0;
}

// Funcion para escribir las componentes del vector
int escribe_vector(int *V, int n){
    printf("\nEl vector introducido es: [ ");
    for (int i=0;i<n;i++) {
        printf("%d ",*(V+i));
    }
    printf("]\n");
    return 0;
}


void lee_matriz (int **M, int n, int m){
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++){
            printf("Dame el elemento [%d,%d] :  ",i+1,j+1);
            scanf("%d",&M[i][j]);
            // otra opcion
            //scanf("%d",M[i]+j);
            // y otra opcion
            //scanf("%d",*(M+i)+j);
        }
    }

void escribe_matriz (int **M, int n, int m){
    int i,j,aux;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++){
            printf("%d\t",M[i][j]);
            // otra opcion
            //printf("%d\t",*(M[i]+j));
            // y otra opcion
            //printf("%d\t",*(*(M+i)+j));
        };
    printf("\n\n");
    }
}


// Funcion que proporciona el maximo del vector siguiendo el esquema de Divide y Venceras

int maximo_vector_DyV(int *V, int inicio, int fin){
  int maximo1, maximo2, mitad;

  // caso trivial
  if (inicio==fin) return V[inicio];

  // caso no trivial
  else {
        // dividir
        mitad=(inicio+fin)/2;

        // resolver
        maximo1 = maximo_vector_DyV(V,inicio,mitad);
        maximo2 = maximo_vector_DyV(V,mitad+1, fin);

        // combinar
        if (maximo1>maximo2) return maximo1;
        else if (maximo1==maximo2) return maximo1;
        else return maximo2;
    }
}


// Funcion que proporciona el producto de los elementos del vector siguiendo el esquema de Divide y Venceras

int producto_vector_DyV(int *V, int inicio, int fin){
    int producto1, producto2, mitad;

    // caso trivial
    if (inicio==fin) return V[inicio];

    //caso no trivial
    else{
        //dividir
        mitad = (inicio+fin)/2;

        //resolver
        producto1 = producto_vector_DyV(V,inicio,mitad);
        producto2 = producto_vector_DyV(V,mitad+1,fin);

        //combinar
        if (producto1==0 || producto2==0) return 0;
        else return producto1*producto2;
    }
}

// Funcion que soluciona el problema 1 del examen del tema 2, siguiendo el esquema de Divide y Venceras

bool EXAMEN_RECURSION_NOVIEMBRE_2020(int **M, int n, int inicio_columnas, int fin_columnas){
    int mitad_columnas;

    // caso base
    if (inicio_columnas == fin_columnas) return true;

    //caso no base
    else{
        //dividir
        mitad_columnas = (inicio_columnas+fin_columnas)/2;

        //resolver
        if (EXAMEN_RECURSION_NOVIEMBRE_2020(M,n,0,mitad_columnas) && EXAMEN_RECURSION_NOVIEMBRE_2020(M,n,mitad_columnas+1,fin_columnas)){
            for (int i=0;i<n-1;i++){
                if (M[i][mitad_columnas] != 2*M[i][mitad_columnas+1]) return false;
            }
            return true;
        }
        else return false;
    }
}