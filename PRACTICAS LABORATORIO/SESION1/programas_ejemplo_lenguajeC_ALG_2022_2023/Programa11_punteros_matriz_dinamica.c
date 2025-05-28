/* PROGRAMA EN EL QUE SE DEFINE DINÁMICAMENTE UNA MATRIZ UTILIZANDO UN PUNTERO A PUNTERO
y SE LE PASA A UNA FUNCIÓN COMO PARÁMETRO */

#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void lee_matriz (int **, int, int);
void escribe_matriz (int **, int, int);
int suma_matriz (int **, int, int);


// funcion principal
int main ()  {
    int n,m;
    printf("Dame el numero de filas: ");
    scanf("%d",&n);
    printf("Dame el numero de columnas: ");
    scanf("%d",&m);

    // definimos una variable de tipo puntero a puntero a int y reservamos memoria para n filas
    int **mi_matriz = (int**) malloc(n*sizeof(int*));

    //reservamos espacio para las columnas
    for(int i=0;i<n;i++)
            mi_matriz[i] = (int*) malloc(m*sizeof(int));

    // Leemos la matriz
    lee_matriz (mi_matriz,n,m);


    printf("\n\nLa matriz introducida es:\n\n");

    // Mostramos el contenido de la matriz
    escribe_matriz (mi_matriz,n,m);

    //Invocamos a la función que suma las componentes de la matriz
    printf("\n\nLa suma de los elementos de la matriz es: %d\n\n",suma_matriz(mi_matriz,n,m));

    // Liberamos el espacio reservado para las columnas
    for (int i=0;i<n;i++) free(mi_matriz[i]);

    // Liberamos el espacio reservado para las filas
    free(mi_matriz);

    return 0;
}

//
// Funciones
//

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

int suma_matriz (int **M, int n, int m)
{
 int i,j,suma=0;
 printf("\n");
 for (i=0;i<n;i++)
 {
   for (j=0;j<m;j++)
        suma+=M[i][j];
   printf("\n");
 }
 printf("\n");
 return suma;
}
