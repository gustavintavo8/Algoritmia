// ESTE PROGRAMA DECLARA E INICIALIZA VARIOS VECTORES Y LOS RECORRE MOSTRANDO SUS ELEMENTOS
#include <stdio.h>


int main ()  {

// Declaramos varios vectores y los inicializamos en la misma declaración
float V1[5]={1.,2.,3.,4.,5.};

int V2[5]={1001,1002,1003,1004,1005};

// El tamaño de V3 esta implicito
int V3[]={1,2,3,4,5};

// todo el vector V4 se inicializa a 0
int V4[5]={0};

// los restantes elementos de V5 se inicializan a 0
int V5[5]={1,2,3};

// Mostraremos las componentes de V1
printf("\n\nEl vector V1 tiene las componentes: ");
for (int i=0; i<5; i++)
   printf("%.2f ",V1[i]);

// Mostraremos las componentes de V2
printf("\n\nEl vector V2 tiene las componentes: ");
for (int i=0; i<5; i++)
   printf("%d ",V2[i]);

// Mostraremos las componentes de V3
printf("\n\nEl vector V3 tiene las componentes: ");
for (int i=0; i<5; i++)
   printf("%d ",V3[i]);

// Mostraremos las componentes de V4
printf("\n\nEl vector V4 tiene las componentes: ");
for (int i=0; i<5; i++)
   printf("%d ",V4[i]);

// Mostraremos las componentes de V5
printf("\n\nEl vector V5 tiene las componentes: ");
for (int i=0; i<5; i++)
   printf("%d ",V5[i]);

printf("\n\n");
// La siguiente sentencia producira un error, pues no se pueden asignar vectores, aun siendo del mismo tamaño
// Quitar el comentario y  comprobar dicho error
// V2=V3;

return 0;
}
