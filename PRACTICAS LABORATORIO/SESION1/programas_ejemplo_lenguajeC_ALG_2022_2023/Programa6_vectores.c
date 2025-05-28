// ESTE PROGRAMA MUESTRA CÓMO PASAR COMO PARÁMETRO UN VECTOR DE TAMAÑO FIJO A UNA FUNCIÓN
#include <stdio.h>

// La directiva #define define una macro. Cada ocurrencia del identificador ELEMENTOS en
// el código fuente es reemplazado por 6
#define ELEMENTOS 6

// Al pasar como parámetro un vector unidimensional, no tiene por que tener la
// dimension acotada

// prototipos de funciones
void lee_vector (int []);
void escribe_vector (int []);
int suma_vector (int []);

int main ()
{
//Declaramos un vector de tamaño fijo
int mi_vector[ELEMENTOS];

//Invocamos a la función de lectura de las componentes del vector
lee_vector (mi_vector);

//Invocamos a la función de escritura de las componentes del vector
escribe_vector (mi_vector);

//Invocamos a la función que suma las componentes del vector
printf("\n\nLa suma de los elementos del vector es: %d\n\n",suma_vector (mi_vector));

return 0;
}

//
// Funciones
//

void lee_vector (int V[])
{
 int i;
 for (i=0;i<ELEMENTOS;i++){
        printf("Dame el elemento [%d] :  ",i+1);
        scanf("%d",&V[i]);
        }
 printf("\n\n");
 }

void escribe_vector (int V[])
{
 int i;
 printf("V = {");
 for (i=0;i<ELEMENTOS;i++)
        printf("  %d",V[i]);
 printf(" }\n\n");
 }

 int suma_vector (int V[])
{
 int i,suma=0;
 for (i=0;i<ELEMENTOS;i++)
        suma+=V[i];
 return suma;
 }

