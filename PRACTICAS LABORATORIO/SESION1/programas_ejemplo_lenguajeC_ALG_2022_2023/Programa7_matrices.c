// ESTE PROGRAMA DECLARA E INICIALIZA DOS MATRICES, LAS RECORRE MOSTRANDO SUS ELEMENTOS POR FILAS Y POR COLUMNAS
#include <stdio.h>

int main ()

{
int i, j;

// Declaramos una matriz y la inicializamos en la misma declaración
float M1[2][3]={{1.,2.,3.},
                {4.,5.,6.}};

// Al declarar una matriz, ésta debe tener todas las dimensiones acotadas, salvo la primera
/*
int M2[][2]={{8,6},
             {3,7},
             {2,9}};
 */

// Tambien puede hacerse de este modo
int M2[][2]={8,6,3,7,2,9};

// Recorremos la matriz M1 por filas
printf("Matriz M1 por filas:\n\n");
for (i=0;i<2;i++)
 {
   printf("Fila %d",i);
   for (j=0;j<3;j++)
        printf("\t%.2f",M1[i][j]);
   printf("\n");
 }
 printf("\n");

// Recorremos la matriz M1 por columnas
printf("Matriz M1 por columnas:\n\n");
 for (j=0;j<3;j++)
 {
   printf("Columna %d",j);
   for (i=0;i<2;i++)
        printf("\t%.2f",M1[i][j]);
   printf("\n");
 }
 printf("\n");

// Recorremos la matriz M2 por filas
printf("Matriz M2 por filas:\n\n");
 for (i=0;i<3;i++)
 {
   printf("Fila %d",i);
   for (j=0;j<2;j++)
        printf("\t%d",M2[i][j]);
   printf("\n");
 }
 printf("\n");

// Recorremos la matriz M2 por columnas
printf("Matriz M2 por columnas:\n\n");
 for (j=0;j<2;j++)
 {
   printf("Columna %d",j);
   for (i=0;i<3;i++)
        printf("\t%d",M2[i][j]);
   printf("\n");
 }
 printf("\n");

printf("\n\n");

return 0;
}
