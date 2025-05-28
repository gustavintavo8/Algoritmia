/* PROGRAMA EN EL QUE SE DEFINE DINÁMICAMENTE UN VECTOR UTILIZANDO UN PUNTERO A ENTERO
y SE LE PASA A UNA FUNCIÓN COMO PARÁMETRO */

#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void lee_vector (int *, int);
void escribe_vector (int *, int);
int suma_vector (int *, int);

// Programa Principal
int main ()  {
    int n;
    printf("Dame el numero de elementos: \n");
    scanf("%d",&n);

    // definimos una variable de tipo puntero a int y reservamos memoria para n enteros
    int *mi_vector = (int*) malloc(n*sizeof(int));

    // Leemos el vector
    lee_vector (mi_vector,n);

    // Mostramos el contenido del vector
    escribe_vector (mi_vector,n);

    //Invocamos a la función que suma las componentes del vector
    printf("\n\nLa suma de los elementos del vector es: %d\n\n",suma_vector (mi_vector,n));

    // Liberamos el espacio reservado para el vector
    free(mi_vector);
    return 0;
}

//
// Funciones
//

void lee_vector (int *V, int n){
    int i;
    for (i=0;i<n;i++)
        {
            printf("Dame el elemento [%d] :  ",i+1);
            scanf("%d",&V[i]);
            // otra opcion
            //scanf("%d",V+i);
            printf("\n\n");
       }
    }

void escribe_vector (int *V, int n){
    int i,aux;
    printf("V = {");
    for (i=0;i<n;i++)
    {
             printf("  %d",V[i]);
            // otra opcion
            //printf("%d\t",*(V+i));
     }
    printf(" }\n\n");
    }

int suma_vector (int *V, int n)
{
 int i,suma=0;
 for (i=0;i<n;i++)
        suma+=V[i];
 return suma;
 }
