// ---------------------------------------------------------------------------------
//
// ALGORITMIA: PRACTICA DE DISENIO DE ALGORITMOS RECURSIVOS
//
// Se recoge la implementacion en C del algoritmo recursivo que calcula la
// potencia n-esima de a donde a>=0 y n>=0
//
// Copyright: Nahuel Costa & Raquel Cortina
//
// Fecha: 17 de octubre de 2022
//
// ---------------------------------------------------------------------------------
//
// Completar con las tareas indicadas para el alumno en la sesion 2.1 de practicas
//
//----------------------------------------------------------------------------------

#include <stdio.h>

//
// Prototipos de funciones
//
int POTENCIA(int, int);
int POTENCIA_entresijos(int, int);

// Prototipos de las funciones a realizar por el alumno
int MCD(int, int);
int MCD_entresijos(int, int);
int Potencia_3(int);
int Potencia_3_entresijos(int);
int factorial(int);
int numero_cifras(int);
int suma_cifras(int);
int semifactorial(int);
int fibonacci(int);
int contar_pares_vector(int[], int);
int contar_coincidencias_matriz(int,int,int,int,int[5][5]);
void imprimir_vector(int[], int);

//
// Programa principal
//

int main()
{
  int n, a;

  printf("\t\t CALCULO LA POTENCIA n-ESIMA DE UN NUMERO\n\n");

  // leer la base
  do
  {
    printf(" Introduce la base a (a>=0): ");
    scanf("%d", &a);
  } while (a < 0);

  // leer el exponente
  do
  {
    printf(" Introduce el exponente n (n>=0): ");
    scanf("%d", &n);
  } while (n < 0);

  printf("\n\n");
  printf(" --------\n");
  printf(" POTENCIA\n");
  printf(" --------\n");

  printf(" La potencia %d-esima de %d es: %d \n\n\n", n, a, POTENCIA(a, n));

  printf(" ---------------------------------------------\n");
  printf(" POTENCIA mostrando el funcionamiento interno \n");
  printf(" ---------------------------------------------\n");

  printf(" \n Se muestra el proceso interno: sucesivas llamadas a la funcion, resultado en el caso base y \n");
  printf(" resultados parciales hasta alcanzar el resultado final");

  printf("\n\n\n DESCENSO en la cadena de llamadas ... (se aplica la FUNCION SUCESOR hasta alcanzar caso base)\n\n");

  printf("\n\nLa potencia %d-esima de %d es: %d \n\n", n, a, POTENCIA_entresijos(a, n));

  // Invocacion de las funciones a realizar por el alumno

  // Invocaciones de las funciones potencia_3 y potencia_3_entresijos

  printf("\n\n");
  printf(" --------\n");
  printf(" Potencia_3\n");
  printf(" --------\n");
  printf(" La potencia 3-esima de %d es: %d \n\n\n", a, Potencia_3(a));

  printf(" -----------------------------------------------------\n");
  printf(" POTENCIA 3-esima mostrando el funcionamiento interno \n");
  printf(" -----------------------------------------------------\n");

  printf(" \n Se muestra el proceso interno: sucesivas llamadas a la funcion, resultado en el caso base y \n");
  printf(" resultados parciales hasta alcanzar el resultado final");

  printf("\n\n\n DESCENSO en la cadena de llamadas ... (se aplica la FUNCION SUCESOR hasta alcanzar caso base)\n\n");

  printf("\n\nLa potencia 3-esima de %d es: %d \n\n", a, Potencia_3_entresijos(a));

  // Invocaciones de las funciones MCD y MCD_entresijos

  printf("\n\n");
  printf(" --------\n");
  printf(" MCD\n");
  printf(" --------\n");
  printf(" El MCD de %d y %d es: %d \n\n\n", a, n, MCD(a, n));

  printf(" -----------------------------------------------------\n");
  printf(" MCD mostrando el funcionamiento interno \n");
  printf(" -----------------------------------------------------\n");

  printf(" \n Se muestra el proceso interno: sucesivas llamadas a la funcion, resultado en el caso base y \n");
  printf(" resultados parciales hasta alcanzar el resultado final");

  printf("\n\n\n DESCENSO en la cadena de llamadas ... (se aplica la FUNCION SUCESOR hasta alcanzar caso base)\n\n");

  printf(" El MCD de %d y %d es: %d \n\n\n", a, n, MCD_entresijos(a, n));

  // Invocaciones de las funciones: factorial, numero_cifras, suma_cifras, semifactorial y fibonacci

  printf("\n\n");
  printf(" --------\n");
  printf(" Factorial\n");
  printf(" --------\n");
  printf(" El factorial de %d es: %d \n\n\n", a, factorial(a));

  printf("\n\n");
  printf(" --------\n");
  printf(" numero_cifras\n");
  printf(" --------\n");
  printf(" El numero de cifras  de %d es: %d \n\n\n", a, numero_cifras(a));

  printf("\n\n");
  printf(" --------\n");
  printf(" suma_cifras\n");
  printf(" --------\n");
  printf(" La suma de las cifras de de %d es: %d \n\n\n", a, suma_cifras(a));

  printf("\n\n");
  printf(" -------------\n");
  printf(" Semifactorial\n");
  printf(" -------------\n");
  printf(" El semifactorial de %d es: %d \n\n\n", a, semifactorial(a));

  printf("\n\n");
  printf(" ---------\n");
  printf(" Fibonacci\n");
  printf(" ---------\n");
  printf(" El numero %d en la secuencia de fibonacci es: %d \n\n\n", a, fibonacci(a));

  // Invocaciones de las funciones: contar_pares_vector y contar_coincidencias_matriz

  // contar_pares_vector

  int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; // Vector de 20 números, con 10 números pares
  printf("\n\n");
  printf(" -------------------\n");
  printf(" Contar pares vector\n");
  printf(" -------------------\n");
  imprimir_vector(vector, 20);
  printf("");
  printf(" El numero de pares en el vector es de %d pares \n\n\n", contar_pares_vector(vector, 20));
  // contar_coincidencias_matriz

  int matriz[5][5] = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {10, 9, 8, 7, 6},
      {5, 4, 3, 2, 1},
  };
  printf("\n\n");
  printf(" -------------------------------------\n");
  printf(" Contar numero de coincidencias matriz\n");
  printf(" -------------------------------------\n");
  printf(" El numero de coincidencias de %d en la matriz es de %d \n\n\n", a, contar_coincidencias_matriz(a, 0, 0, 0, matriz));
  //  [OPCIONAL] Invocaciones de las funciones: suma_vector y simetria_matriz

  return 0;
}

//
// Definiciones de funciones
//

// Potencia
int POTENCIA(int a, int n)
{
  if (n == 0)
    return 1;
  else
    return POTENCIA(a, n - 1) * a;
}

// Potencia_detalles
int POTENCIA_entresijos(int a, int n)
{
  int p;
  if (n == 0)
  {
    printf("\tpotencia(%d,%d)\n\n", a, n);
    p = 1;
    printf("\n\n CASO BASE y su resultado\n\n");
    printf("\tpotencia(%d,%d) ---> resultado = %d\n\n", a, n, p);
    printf("\n\n ASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
    return p;
  }
  else
  {
    printf("\tpotencia(%d,%d)\n", a, n);
    p = POTENCIA_entresijos(a, n - 1) * a;
    printf("\tpotencia(%d,%d) ---> resultado = %d\n", a, n, p);
    return p;
  }
}

//
// Definicion de las funciones a realizar por el alumno
//

// Potencia_3
// Completar por el alumno
// ...
int Potencia_3(int n)
{
  if (n == 0)
  {
    return 1;
  }

  if (n == 1)
  {
    return 3;
  }

  if (n > 1)
  {
    return 2 * Potencia_3(n - 1) + 3 * Potencia_3(n - 2);
  }
}

// Potencia_3_entresijos
// Completar por el alumno
// ...
int Potencia_3_entresijos(int n)
{
  int p;
  if (n == 0)
  {
    p = 1;
    printf("\tPotencia_3_entresijos (%d)\n\n", n);
    printf("\n\n CASO BASE y su resultado\n\n");
    printf("\tPotencia_3_entresijos (%d) ---> resultado = %d\n\n", n, p);
    printf("\n\n ASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
    return p;
  }
  if (n == 1)
  {
    p = 3;
    printf("\tPotencia_3_entresijos (%d)\n\n", n);
    printf("\n\n CASO BASE y su resultado\n\n");
    printf("\tPotencia_3_entresijos (%d) ---> resultado = %d\n\n", n, p);
    printf("\n\n ASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
    return p;
  }
  printf("\tPotencia_3_entresijos (%d)\n\n", n);
  p = 2 * Potencia_3_entresijos(n - 1) + 3 * Potencia_3_entresijos(n - 2);
  printf("\tPotencia_3_entresijos (%d) ---> resultado = %d\n", n, p);
  return p;
}

// MCD
// Completar por el alumno
// ...
int MCD(int a, int b)
{
  if (a == b)
  {
    return a;
  }
  if (a > b)
  {
    return MCD(a - b, b);
  }
  if (a < b)
  {
    return MCD(a, b - a);
  }
}

// MCD_entresijos
// Completar por el alumno
// ...
int MCD_entresijos(int a, int b)
{
  int p;
  if (a == b)
  {
    p = a;
    printf("\tMCD_entresijos (%d,%d)\n\n", a, b);
    printf("\n\n CASO BASE y su resultado\n\n");
    printf("\tMCD_entresijos (%d,%d) ---> resultado = %d\n\n", a, b, p);
    printf("\n\n ASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
    return p;
  }
  if (a > b)
  {
    printf("\tMCD_entresijos (%d,%d)\n\n", a, b);
    p = MCD_entresijos(a - b, b);
    printf("\tMCD_entresijos (%d,%d) ---> resultado = %d\n", a, b, p);
    return p;
  }
  if (a < b)
  {
    printf("\tMCD_entresijos (%d,%d)\n\n", a, b);
    p = MCD_entresijos(a, b - a);
    printf("\tMCD_entresijos (%d,%d) ---> resultado = %d\n", a, b, p);
    return p;
  }
}
// factorial
// Completar por el alumno
// ...
int factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  return factorial(n - 1) * n;
}

// numero_cifras
// Completar por el alumno
// ...
int numero_cifras(int n)
{
  if (n < 10)
  {
    return 1;
  }
  return numero_cifras(n / 10) + 1;
}

// suma_cifras
// Completar por el alumno
// ...
int suma_cifras(int n)
{
  if (n < 10)
    return n;
  else
    return suma_cifras(n / 10) + n % 10;
}

// semifactorial
// Completar por el alumno
// ...
int semifactorial(int n)
{
  if (n == 0)
    return 1;
  else if (n == 1)
    return 1;
  else
    return semifactorial(n - 2) * n;
}

// fibonacci
// Completar por el alumno
// ...
int fibonacci(int n)
{
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// contar_pares_vector
// Completar por el alumno
// ...
int contar_pares_vector(int v[], int n)
{
  if (n == 0)
  {
    return n;
  }
  if (v[n - 1] % 2 == 0)
  {
    return contar_pares_vector(v, n - 1) + 1;
  }
  else
    return contar_pares_vector(v, n - 1);
}
// contar_coincidencias_matriz
// Completar por el alumno
// ...
int contar_coincidencias_matriz(int numero_a_buscar, int coincidencias, int fila, int columna, int matriz[5][5])
{
  if (fila >= 4)
  {
    return coincidencias;
  }

  if (columna >= 5)
  {
    printf("\n");
    contar_coincidencias_matriz(numero_a_buscar, coincidencias, fila + 1, 0, matriz);
  }
  else
  {
    if (matriz[fila][columna] == numero_a_buscar)
    {
      coincidencias = coincidencias + 1;
    }

    printf(" %d", matriz[fila][columna]);

    contar_coincidencias_matriz(numero_a_buscar, coincidencias, fila, columna + 1, matriz);
  }
}

// [OPCIONAL] suma_vector
// Completar por el alumno
// ...

// [OPCIONAL] simetria_matriz
// Completar por el alumno
// ...

void imprimir_vector(int v[], int n)
{
  printf("{");
  for (int i = 0; i < n - 1; i++)
  {
    printf(" %d,", v[i]);
  }
  printf(" %d }\n", v[n - 1]);
}