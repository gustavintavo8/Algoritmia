// ----------------------------------------------------------------------------------------------------------
//
// ALGORITMIA: PRACTICA DE DIVIDE Y VENCERAS
//
// Implementacion en C de MERGESORT
//
// Copyright: Raquel Cortina
//
// Fecha: 27 de octubre de 2022
//
// -----------------------------------------------------------------------------------------------------------
//
// Programa en el que se pide el tamanio del vector (n>=0), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de la funcion
// MERGESORT, que sigue el esquema de divide y venceras, se ordena el vector en sentido ascendente.
//
//------------------------------------------------------------------------------------------------------------



#include <stdio.h>
#include <stdlib.h>


// prototipos de funciones
int lee_vector (int *, int );
int escribe_vector (int *, int );
void Mergesort(int *, int , int );
void mezcla(int *, int , int , int );

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

    // invocacion a Mergesort
    Mergesort(V,0,n-1);

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
int lee_vector (int *V, int n){
    int i;
    for (i=0;i<n;i++){
        printf("Dame el elemento [%d] :  ",i+1);
        scanf("%d",&V[i]);
        }
    return 0;
}

// Funcion para escribir los elementos del vector
int escribe_vector(int *V, int n){
    int i;
    printf("\nV = [ ");
    for (i=0;i<n;i++){
        printf("%d ",V[i]);
    }
    printf("]\n\n\n");
    return 0;
}

// Funcion que mezcla las secciones [inicio..m] y [m+1..fin] del vector v.
// Estas secciones ya estan ordenadas
void mezcla(int *V, int inicio, int m, int fin){
     int a,b,c,k;
     int tam=fin-inicio+1;
     int *AUX;

     // reservar dinamicamente memoria para el vector AUX
     AUX = (int *)malloc(tam*sizeof(int));

     // variables para recorrer las secciones [i..m] y [m+1..j] del vector v y el vector auxiliar
     // a permite recorrer la seccion [i..m] de V
     // b permite recorrer la seccion [m+1..j] de V
     // c permite recorrer el vector auxiliar
     a=inicio;
     b=m+1;
     c=0;
     while ((a<=m) && (b<=fin)){
           while ((V[a]<=V[b])&&(a<=m)) {AUX[c]=V[a];a++;c++;}
           while ((V[b]<=V[a])&&(b<=fin)) {AUX[c]=V[b];b++;c++;}
     }


     // una vez finalizado el recorrido de una de las dos secciones de V, habra que
     // trasladar el resto de la otra seccion de V al vector auxiliar
     if (a>m)
        for (k=b;k<fin+1;k++) {AUX[c]=V[k];c++;}
     else
         for (k=a;k<m+1;k++) {AUX[c]=V[k];c++;}

    // trasladar el resultado de la mezcla del vector auxiliar a la seccion [i..j] del vector V
    for (c=0;c<fin-inicio+1;c++) V[c+inicio]=AUX[c];

    // liberar el vector auxiliar
    free(AUX);
}


// Mergesort
void Mergesort(int *V, int inicio, int fin){
     int m;
     if (inicio<fin){
        m=(inicio+fin)/2;
        Mergesort(V,inicio,m);
        Mergesort(V,m+1,fin);
        mezcla(V,inicio,m,fin);
     }
}



