//Programacion dinamica
//Funcion Objetivo: Maximizar el sumatorio desde i=1 hasta n de D[i]*X[i]
//Restricciones: (Ni)(xi = 1 : 1<=i<=N) <= M y (Ai)(xi € {1,2} : 1<=i<=N)
//Definicion Recursiva: 0 si j=0
//                      F(j-1,m) + D[j][2] si j>0 y m=0
//                      max(F(j-1,m-1) + D[j][1],F(j-1,m) + D[j][2]) si j>0 y m>0
//Datos de entrada: N,M: enteros, D[1..n][1..2]:matriz de enteros
//Datos de salida: secuencia de decisiones optima X[1..n] y valor asociado
//Ejemplo: N=4, M=3, D[1..4][1..2] = {{14,6},{10,3},{8,9},{6,10}}
//Solucion: X[1..4] = {1,1,2,2} Valor asociado: 43

// Incluimos las bibliotecas necesarias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaramos la funcion max
int max(int a, int b) {
  if (a > b) {
    return a;
    } else {
        return b;
        }
}

// Declaramos la función que implementa el algoritmo de programación dinámica
int dinamica(int N, int M, int D[N][2], int X[N]) {
  // Creamos la matriz F de tamaño NxM para almacenar las soluciones a los
  // subproblemas
  int F[N][M];

  // Inicializamos la primera columna de la matriz F con 0
  for (int i = 0; i < N; i++) {
    F[i][0] = 0;
  }

  // Iteramos a través de las filas y columnas de la matriz F
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < M; j++) {
      // Si el número de ítems disponibles es igual a 0, el valor de la celda
      // es igual al valor de la celda superior
      if (M == 0) {
        F[i][j] = F[i - 1][j];
        } else {
            // Si el número de ítems disponibles es mayor que 0, el valor de la
            // celda es igual al máximo entre el valor de la celda superior y el
            // valor de la celda superior izquierda más el valor de la celda
            // actual
            F[i][j] = max(F[i - 1][j], F[i - 1][j - 1] + D[i][1]);
            }
        }
    }

    // Iteramos a través de las filas de la matriz F
    for (int i = 0; i < N; i++) {
      // Si el valor de la celda actual es igual al valor de la celda superior
      // izquierda más el valor de la celda actual, el ítem se selecciona
      if (F[i][M - 1] == F[i - 1][M - 2] + D[i][1]) {
        X[i] = 1;
        } else {
            // Si el valor de la celda actual es igual al valor de la celda
            // superior, el ítem no se selecciona
            X[i] = 0;
            }
        }

        // Retornamos el valor de la celda inferior derecha de la matriz F
        return F[N - 1][M - 1];
}

// Función principal
int main() {
  // Declaramos las variables necesarias
  int N, M, D[N][2], X[N];

  // Leemos los datos de entrada
  printf("Introduzca el número de ítems: ");
  scanf("%d", &N);
  printf("Introduzca el número de ítems disponibles: ");
  scanf("%d", &M);
  printf("Introduzca los valores de los ítems: ");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &D[i][j]);
    }
  }

  // Llamamos a la función que implementa el algoritmo de programación dinámica
  int valor = dinamica(N, M, D, X);

  // Mostramos el resultado
  printf("La secuencia de decisiones optima es: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", X[i]);
  }
  printf("y el valor asociado es: %d", valor);

  return 0;
}