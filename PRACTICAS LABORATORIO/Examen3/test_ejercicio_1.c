#include <stdio.h>
#include <stdlib.h>

int MOCHILA_programacion_dinamica(int *, int *, int, int);
int DESCOMPONER_programacion_dinamica(int, int, int *);
void imprimir_por_pantalla(int **, int, int);

int main()
{
    int numero_a_descomponer, sumandos, tamanio_vector, i;
    int *vector;

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
        printf("Introduce el numero a descomponer: ");
        scanf("%d", &numero_a_descomponer);
    } while (numero_a_descomponer <= 0);

    do
    {
        printf("\nIntroduce el numero de sumandos en los que se va a descomponer:  ");
        scanf("%d", &sumandos);
    } while (sumandos <= 0 || sumandos > numero_a_descomponer);

    printf("\n\n\n y producto maximo es:%d\n", DESCOMPONER_programacion_dinamica(numero_a_descomponer, sumandos, vector));
    printf("\n\n");
}

void imprimir_por_pantalla(int **matriz, int filas, int columnas)
{
    int i, j, aux;
    printf("\t");
    for (int k = 0; k < columnas; k++)
    {
        printf("%d\t", k);
    }
    printf("\n\n");
    for (i = 0; i < filas; i++)
    {
        printf("%d\t", i);
        for (j = 0; j < columnas; j++)
        {
            printf("%d\t", matriz[i][j]);
            // otra opcion
            // printf("%d\t",*(M[i]+j));
            // y otra opcion
            // printf("%d\t",*(*(M+i)+j));
        };
        printf("\n\n");
    }
}

int DESCOMPONER_programacion_dinamica(int numero_a_descomponer, int sumandos, int *vector)
{
    int **matriz_producto_maximo;
    int **matriz_decisiones;
    int *secuencia_decisiones_optima;

    sumandos++;
    numero_a_descomponer++;

    // reserva dinamica de memoria para Sumandos, esto es, el vector de decisiones
    // realizar por el alumno
    secuencia_decisiones_optima = (int *)malloc(sumandos * sizeof(int));

    // reserva dinamica de memoria de las matrices Pmax y Dec
    // realizar por el alumno
    matriz_producto_maximo = (int **)malloc(sumandos * sizeof(int *));
    for (int i = 0; i < sumandos; i++)
    {
        matriz_producto_maximo[i] = (int *)malloc(numero_a_descomponer * sizeof(int));
    }

    matriz_decisiones = (int **)malloc(sumandos * sizeof(int *));
    for (int i = 0; i < sumandos; i++)
    {
        matriz_decisiones[i] = (int *)malloc(numero_a_descomponer * sizeof(int));
    }

    // inicializar las matrices con los resultados de los problemas triviales
    // realizar por el alumno
    for (int i = 1; i < numero_a_descomponer; i++)
    {
        matriz_producto_maximo[1][i] = i;
        matriz_decisiones[1][i] = i;
    }

    // rellenar las matrices por filas en sentido ascendente
    // realizar por el alumno
    for (int j = 2; j < sumandos; j++)
    {
        for (int n = j; n < numero_a_descomponer; n++)
        {
            matriz_producto_maximo[j][n] = 1;
            for (int Sj = 1; Sj < n - j + 1; Sj++)
            {
                int p = matriz_producto_maximo[j - 1][n - Sj] * Sj * vector[Sj - 1];
                if (p >= matriz_producto_maximo[j][n])
                {
                    matriz_producto_maximo[j][n] = p;
                    matriz_decisiones[j][n] = Sj;
                }
            }
        }
    }

    printf("Dec:\n");
    imprimir_por_pantalla(matriz_decisiones, sumandos, numero_a_descomponer);
    printf("Pmax:\n");
    imprimir_por_pantalla(matriz_producto_maximo, sumandos, numero_a_descomponer);
    // solucion
    // realizar por el alumno
    int j = sumandos;
    int n = numero_a_descomponer;
    j--;
    n--;

    printf("j=%d n=%d\n", j, n);
    while (j > 0)
    {
        printf("Secuencia de decisiones[%d] = %d de la matriz de decisiones[%d][%d]\n", j, matriz_decisiones[j][n], j, n);
        secuencia_decisiones_optima[j] = matriz_decisiones[j][n];
        n = n - secuencia_decisiones_optima[j];
        j = j - 1;
    }
    int resultado = matriz_producto_maximo[sumandos - 1][numero_a_descomponer - 1];
    int resultado2 = 1;

    for (int i = 1; i < sumandos; i++)
    {
        resultado2 = resultado2 * secuencia_decisiones_optima[i] * vector[i - 1];
    }
    printf("El resultado2 es %d\n", resultado2);

    // mostrar por pantalla la secuencia de decisiones optima
    // realizar por el alumno
    for (int i = 0; i < sumandos; i++)
    {
        printf("x%d: %d\t", i, secuencia_decisiones_optima[i]);
        printf("Vector=%d, decisiones=%d\n", vector[i], secuencia_decisiones_optima[i]);
    }
    printf("\n");
    printf("\n");

    // liberar memoria
    // realizar por el alumno
    for (int i = 0; i < sumandos - 0; i++)
    {
        free(matriz_decisiones[i]);
        free(matriz_producto_maximo[i]);
    }
    free(matriz_decisiones);
    free(matriz_producto_maximo);
    // retornar el producto maximo
    // realizar por el alumno
    return resultado;
}
