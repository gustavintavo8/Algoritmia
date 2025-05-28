// EJERCICIO 2 - VUELTA ATRAS (BACKTRACKING)
//   Examen practicas de laboratorio 14/12/22
//  Gonzalo Puga Fernández - UO277906

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

// prototipos de las funciones backtracking
void DESCOMPONER_BACK_TODAS(int, int, int, int *);
void DESCOMPONER_BACK_UNA(int, int, int, int *, bool *);
void DESCOMPONER_BACK_OPTIMA(int, int, int, int *, int *, int *, int*);

// prototipos de las funciones auxiliares que utiliza backtracking: correcto, valor, tratar
void tratar(int *, int);
int valor(int *x, int k, int*);
int suma(int *x, int k);

// Función main
int main()
{
    int numero_a_descomponer, sumandos, tamanio_vector,i;
    int *vector;
    int *x, *x_mejor, v_mejor;
    bool flag;

    do
    {
        printf("Introduce el tamanio del vector: ");
        scanf("%d", &tamanio_vector);
    } while (tamanio_vector < 0);

    // reserva dinamica de memoria para vectores de pesos y beneficios
    vector = (int *)malloc(tamanio_vector * sizeof(int));

    printf("\n\nIntroduce los valores del vector\n", tamanio_vector);
    for (i = 1; i <= tamanio_vector; i++)
    {
        do
        {
            printf("\nPeso[%d]= ", i);
            scanf("%d", &vector[i - 1]);
        } while (vector[i - 1] <= 0);
    }
    do
    {
        printf("\nIntroduce el numero a descomponer: ");
        scanf("%d", &numero_a_descomponer);
    } while (numero_a_descomponer <= 0);

    do
    {
        printf("\nIntroduce el numero de sumandos: ");
        scanf("%d", &sumandos);
    } while (sumandos > numero_a_descomponer);

    //
    // Los vectores x y x_mejor tienen tama�o M+1
    //

    x = (int *)malloc((sumandos + 1) * sizeof(int));
    x_mejor = (int *)malloc((sumandos + 1) * sizeof(int));

    // invocamos a OPTIMA de BACKTRACKING
    printf("\n\nSOLUCION OPTIMA:\n");
    v_mejor = INT_MIN;
    DESCOMPONER_BACK_OPTIMA(numero_a_descomponer, sumandos, 1, x, x_mejor, &v_mejor,vector);
    //DESCOMPONER_BACK_TODAS(numero_a_descomponer, sumandos, 1, x, x_mejor, &v_mejor,vector);

    // mostrar la solucion (secuencia de decisiones optima y beneficio maximo)
    tratar(x_mejor, sumandos);
    printf("\t\tEl producto maximo de la descomposicion es: %d\n", v_mejor);

    // liberar memoria
    free(x);
    // free(x_mejor);
    free(x_mejor);
    free(vector);

    return 0;
}

// funcion que muestra por pantalla la secuencia de decisiones x
void tratar(int *x, int n)
{
    int i;
    printf("\n\t< ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf(">");
}

/*
   Función que retorna el sumatorio de x
*/
int suma(int *x, int k)
{
    int suma = 0;
    for (int i = 0; i <= k; i++)
    {
        suma = suma + x[i];
    }
    return suma;
}

int valor(int *x, int k, int *vector)
{
    int i, total = 0;
    for (i = 1; i <= k; i++)
    {
        total = total * x[i] *vector[i-1];
    }
    return total;
}

void DESCOMPONER_BACK_OPTIMA(int numero_a_descomponer, int sumandos, int k, int *x, int *x_mejor, int *v_mejor, int *vector)
{
    // TAREA A REALIZAR POR EL ALUMNO
    int i, aux;
    x[k] = -1;
    while (x[k] < numero_a_descomponer - sumandos + 1)
    {
        x[k] = x[k] + 1;
        if (k == sumandos && suma(x, k) == numero_a_descomponer)
        {
            aux = valor(x, k,vector); // Función objetivo
            if (aux > *v_mejor)
            {
                *v_mejor = aux;
                memcpy(x_mejor, x, (sumandos + 1) * sizeof(int));
            }
        }
        if (k < sumandos && suma(x, k) <= numero_a_descomponer)
        {
            DESCOMPONER_BACK_OPTIMA(numero_a_descomponer, sumandos, k + 1, x, x_mejor, v_mejor,vector);
        }
    }
}

void DESCOMPONER_BACK_TODAS(int fila, int columna, int k, int *vector)
{
   // TAREA A REALIZAR POR EL ALUMNO
   vector[k] = 0; // Preparar recorrido nivel_k

   while (k > 0)
   {
      if (vector[k] < fila - columna + 1) // si existe hermano_nivel_k
      {
         vector[k] = vector[k] + 1; // Siguiente hermano_nivel_k
         if (k == columna && suma(vector, k) == fila)
            tratar(vector, columna);
         if (k < columna && suma(vector, k) <= fila)
         {
            k = k + 1;
            vector[k] = 0;
         }
      }
      else
         k = k - 1;
   }
   // free(x);
}