// DIVIDE Y VENCERAS - Función que dado un vector V proporcione el mayor elemento de entre los divisibles por 5
//  Examen practicas de laboratorio 14/12/22
// Gonzalo Puga Fernández - UO277906

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototipos de funciones maximo y producto
int lee_vector(int *, int);
int escribe_vector(int *, int);
int maximo_vector_DyV(int *, int, int);
// incluir mas prototipos si fuera necesario

// Programa principal
int main()
{
    int filas;
    int *vector;
    do
    {
        printf("\nIntroduce el numero de elementos del vector para obtener el maximo de entre los divisibles por 5(>=1): ");
        scanf("%d", &filas);
    } while (filas < 1);

    // reservamos dinamicamente memoria
    vector = (int *)malloc(filas * sizeof(int));

    // leemos los elementos del vector
    lee_vector(vector, filas);

    // mostramos los elementos del vector
    escribe_vector(vector, filas);

    printf("\nEl maximo de los elementos del vector de los divisibles por 5 es %d\n\n", maximo_vector_DyV(vector, 0, filas - 1));
}

// Funcion para leer las componentes del vector
int lee_vector(int *vector, int ncomponentes)
{
    for (int i = 0; i < ncomponentes; i++)
    {
        printf("\nDame el valor de la componente %d: ", i + 1);
        scanf("%d", vector + i);
    }
    return 0;
}

// Funcion para escribir las componentes del vector
int escribe_vector(int *vector, int ncomponentes)
{
    printf("\nEl vector introducido es: [ ");
    for (int i = 0; i < ncomponentes; i++)
    {
        printf("%d ", *(vector + i));
    }
    printf("]\n");
    return 0;
}

// Funcion que proporciona el maximo del vector de los divisibles entre 5 siguiendo el esquema de Divide y Venceras

int maximo_vector_DyV(int *vector, int inicio, int fin)
{
    int maximo1, maximo2, mitad;

    // caso trivial
    if (inicio == fin)
        return vector[inicio];

    // caso no trivial
    else
    {
        // dividir vector
        mitad = (inicio + fin) / 2;

        // resolver
        maximo1 = maximo_vector_DyV(vector, inicio, mitad);
        maximo2 = maximo_vector_DyV(vector, mitad + 1, fin);

        int resultado;
        if (maximo1 % 5 == 0 && maximo2 % 5 == 0)
        {
            if (maximo1 > maximo2)
                resultado = maximo1;
            else
                resultado = maximo2;
        }
        else if (maximo1 % 5 == 0 && maximo2 % 5 != 0)
        {
            resultado = maximo1;
        }
        else if (maximo1 % 5 != 0 && maximo2 % 5 == 0)
        {
            resultado = maximo2;
        }
        return resultado;
    }
}