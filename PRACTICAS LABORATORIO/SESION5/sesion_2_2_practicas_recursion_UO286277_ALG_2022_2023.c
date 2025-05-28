// -----------------------------------------------------------------------------------------------------
//
// ALGORITMIA: SESION 2 DE PRACTICAS DE DISENIO DE ALGORITMOS RECURSIVOS
//
//     - En este fichero figuran las implementaciones de una serie de funciones recursivas vistas en clase
//
//
//     - La tarea para el alumno consiste:
//                   - en realizar las implementaciones de las transformaciones a iterativo de dichas funciones
//                   - en implementar la funcion TABLEROS (recursiva e iterativa)
//
//
// Copyright: Nahuel Costa & Raquel Cortina
//
// Fecha: 24 de octubre de 2022
//
// ---------------------------------------------------------------------------------
//
// Completar con las tareas indicadas para el alumno en la sesion 2.2 de practicas
//
//----------------------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>

#define ELEMENTOS 6
#define ORDEN 4

// Prototipos
int POTENCIA_recursiva(int, int);
int POTENCIA_iterativa(int, int);

int MCD_recursiva(int, int);
int MCD_iterativa(int, int);

int TABLEROS_recursiva(int,int);
int TABLEROS_iterativa(int,int);

int iSUMA_VECTOR_recursiva_backward(int[], int);
int SUMA_VECTOR_iterativa_backward(int[], int);

int iSUMA_VECTOR_recursiva_forward(int[], int, int);
int SUMA_VECTOR_iterativa_forward(int[], int, int);

int iCAPICUA_VECTOR_recursiva(int[], int, int);
bool CAPICUA_VECTOR_iterativa(int[], int, int);

float iMEDIA_ARITMETICA_VECTOR_recursiva(float[], int);
float MEDIA_ARITMETICA_VECTOR_iterativa(float[], int);

bool iSIMETRICA_MATRIZ_recursiva(int[][ORDEN], int);
bool banda_simetrica(int[][ORDEN], int);
bool SIMETRICA_MATRIZ_iterativa (int [][ORDEN],int);

//OPCIONALES
int iCONTAR_PARES_VECTOR(int [], int);
int iCONTAR_COINCIDENCIAS_MATRIZ(int [][ORDEN], int, int);

// Funcion Principal
int main()
{
  int a, n, b, m;

  // POTENCIA n-ESIMA DE a
  a = 2;
  n = 5;
  printf(" ---------------------\n");
  printf(" POTENCIA n-ESIMA de a\n");
  printf(" ----------------------");
  printf("\n\n La potencia %d-esima de %d es: %d  (version recursiva)\n\n", n, a, POTENCIA_recursiva(a, n));
  printf("\n\n La potencia %d-esima de %d es: %d (version iterativa)\n\n", n, a, POTENCIA_iterativa(a, n));

  // MAXIMO COMUN DIVISOR
  a = 48;
  b = 60;
  printf(" --------------------\n");
  printf(" MAXIMO COMUN DIVISOR\n");
  printf(" --------------------");
  printf("\n\n El maximo comun divisor de %d y %d es: %d  (version recursiva)\n\n", a, b, MCD_recursiva(a, b));
  printf("\n\n El maximo comun divisor de %d y %d es: %d  (version iterativa)\n\n", a, b, MCD_iterativa(a, b));

  // TABLEROS
  n=5;
  m=2;
  printf(" --------\n");
  printf(" TABLEROS\n");
  printf(" --------");
  printf("\n\n El numero de formas de colocar un tablero de %d x %d sobre uno de %d x %d es: %d  (version recursiva)\n\n",m,m,n,n,TABLEROS_recursiva(n,m));
  printf("\n\n El numero de formas de colocar un tablero de %d x %d sobre uno de %d x %d es: %d  (version iterativa) \n\n",m,m,n,n,TABLEROS_iterativa(n,m));

  // SUMA VECTOR
  int V[ELEMENTOS] = {1, 2, 3, 3, 2, 1};

  printf(" -----------\n");
  printf(" SUMA VECTOR\n");
  printf(" -----------");
  printf("\n\n La suma de los elementos del vector es: %d  (version recursiva backward)\n\n", iSUMA_VECTOR_recursiva_backward(V, ELEMENTOS));
  printf("\n\n La suma de los elementos del vector es: %d  (version iterativa backward)\n\n", SUMA_VECTOR_iterativa_backward(V, ELEMENTOS));
  printf("\n\n La suma de los elementos del vector es: %d  (version recursiva forward)\n\n", iSUMA_VECTOR_recursiva_forward(V, ELEMENTOS, 1));
  printf("\n\n La suma de los elementos del vector es: %d  (version iterativa)\n\n", SUMA_VECTOR_iterativa_forward(V, ELEMENTOS, 1));

  // CAPICUA VECTOR
  int W[ELEMENTOS] = {1, 2, 3, 3, 2, 1};

  printf(" -------\n");
  printf(" CAPICUA\n");
  printf(" -------");
  if (iCAPICUA_VECTOR_recursiva(W, 1, ELEMENTOS))
    printf("\n\n El vector es capicua  (version recursiva)\n\n");
  else
    printf("\n\n El vector no es capicua  (version recursiva)\n\n");
  if (CAPICUA_VECTOR_iterativa(W, 1, ELEMENTOS))
    printf("\n\n El vector es capicua  (version iterativa) \n\n");
  else
    printf("\n\n El vector no es capicua  (version iterativa)\n\n");

  // MEDIA ARITMETICA VECTOR
  float X[ELEMENTOS] = {9.45, 3.56, 2.78, 1.23, 6.45, 5.67};

  printf(" -----------------------\n");
  printf(" MEDIA ARITMETICA VECTOR\n");
  printf(" ------------------------");
  printf("\n\n La media aritmetica de los elementos del vector es: %8.2f  (version recursiva)\n\n", iMEDIA_ARITMETICA_VECTOR_recursiva(X, ELEMENTOS));
  printf("\n\n La media aritmetica de los elementos del vector es: %8.2f  (version iterativa)\n\n",MEDIA_ARITMETICA_VECTOR_iterativa(X, ELEMENTOS));

  // SIMETRICA MATRIZ
  int M[][ORDEN] = {{1, 2, 5, 7},
                    {2, 8, 6, 9},
                    {5, 6, 9, 2},
                    {7, 9, 2, 1}};

  printf(" ----------------\n");
  printf(" MATRIZ SIMETRICA\n");
  printf(" ----------------");

  if (iSIMETRICA_MATRIZ_recursiva(M, ORDEN))
    printf("\n\n LA MATRIZ ES SIMETRICA (version recursiva)\n\n");
  else
    printf("\n\n LA MATRIZ NO ES SIMETRICA (version recursiva)\n\n");

  if (SIMETRICA_MATRIZ_iterativa(M,ORDEN))  printf("\n\n LA MATRIZ ES SIMETRICA (version iterativa)\n\n");
  else printf("\n\n LA MATRIZ NO ES SIMETRICA (version iterativa)\n\n");

  //CONTAR PARES VECTOR
  int Y[ELEMENTOS] = {1, 2, 3, 3, 4, 1};
  printf(" -------------------\n");
  printf(" CONTAR PARES VECTOR\n");
  printf(" -------------------");
  printf("\n\n El numero de pares del vector es: %d  (version iterativa)\n\n", iCONTAR_PARES_VECTOR(Y, ELEMENTOS));

  //CONTAR COINCIDENCIAS MATRIZ
  int N[][ORDEN] = {{1, 2, 2, 7},
                    {2, 5, 6, 9},
                    {5, 6, 8, 2},
                    {3, 9, 2, 1}};
  printf(" ---------------------------\n");
  printf(" CONTAR COINCIDENCIAS MATRIZ\n");
  printf(" ---------------------------");
  printf("\n\n El numero de coincidencias de 2 de la matriz es: %d  (version iterativa)\n\n", iCONTAR_COINCIDENCIAS_MATRIZ(N, ORDEN, 2));
  return 0;
}

// Definiciones de funciones

int POTENCIA_recursiva(int a, int n)
{
  if (n == 0)
    return 1;
  else
    return POTENCIA_recursiva(a, n - 1) * a;
}

int POTENCIA_iterativa(int a, int ninicial)
{
  int n, p;

  // inicializacion
  n = ninicial;

  // bucle descenso
  while (n > 0)
    n--; // el bucle de descenso se puede sustituir por la sentencia n=0 que nos "situa" directamente en el caso base

  p = 1;

  // bucle ascenso
  while (n != ninicial)
  {
    n++;
    p = p * a;
  }
  return p;
}

int MCD_recursiva(int a, int b)
{
  if (a == b)
    return a;
  else if (a > b)
    return MCD_recursiva(a - b, b);
  else
    return MCD_recursiva(a, b - a);
}

// COMPLETAR POR EL ALUMNO
int MCD_iterativa(int a_inicial, int b_inicial)
{
  int a=a_inicial;
  int b=b_inicial;

  while (a != b)
  {
    if (a > b)
    {
      a = a - b;
    }
    else
    {
      b = b - a;
    }
  }
  return a;
}

// COMPLETAR POR EL ALUMNO
int  TABLEROS_recursiva(int n, int m)
{
  if (m == 1)
    return (n*n);
  else if (m > 1)
    return TABLEROS_recursiva(n-1, m-1);
}

// COMPLETAR POR EL ALUMNO
int TABLEROS_iterativa(int n_inicial, int m_inicial)
{

  // inicializacion
  int n = n_inicial;
  int m = m_inicial;
  int p = 1;

  // bucle descenso
  while (m > 1)
    m--;

  // bucle ascenso
  while (m != m_inicial)
  {
    m++;
    n--;
    p = p * (n * n);
  }
  return p;
}

int iSUMA_VECTOR_recursiva_backward(int V[], int j)
{
  if (j == 1)
    return V[j - 1];
  else
    return iSUMA_VECTOR_recursiva_backward(V, j - 1) + V[j - 1];
}

//  COMPLETAR POR EL ALUMNO
int SUMA_VECTOR_iterativa_backward(int V[], int j_inicial)
{
  //inicializacion
  int j = j_inicial;

  //bucle descenso
  while (j > 1)
  {
    j = j - 1;
  }

  int suma = V[j - 1];

  //bucle ascenso
  while (j != j_inicial)
  {
    j = j + 1;
    suma = suma + V[j - 1];
  }

  return suma;
}

int iSUMA_VECTOR_recursiva_forward(int V[], int n, int j)
{
  if (j == n)
    return V[j - 1];
  else
    return iSUMA_VECTOR_recursiva_forward(V, n, j + 1) + V[j - 1];
}

//  COMPLETAR POR EL ALUMNO
int SUMA_VECTOR_iterativa_forward(int V[], int n, int j_inicial)
{
  //inicializacion
  int j = j_inicial;

  //bucle ascenso
  while (j != n)
  {
    j = j + 1;
  }

  int suma = V[j - 1];

  //bucle descenso
  while (j != j_inicial)
  {
    j = j - 1;
    suma = suma + V[j - 1];
  }

  return suma;
}

int iCAPICUA_VECTOR_recursiva(int V[], int i, int j){
  if (i==j) return true;
  else if (i==j-1) return (V[i-1]==V[j-1]);
  else return iCAPICUA_VECTOR_recursiva(V,i+1,j-1)&& (V[i-1]==V[j-1]);
}


//  COMPLETAR POR EL ALUMNO
bool CAPICUA_VECTOR_iterativa(int V[], int i_inicial, int j_inicial)
{
  // inicializacion
  int i = i_inicial;
  int j = j_inicial;

  // bucle descenso
  while (i < (j-1))
  {
    i = i + 1;
    j = j - 1;
  }

  bool capicua;
  if (i==j) capicua = true;
  else if (i==j-1) capicua = (V[i-1]==V[j-1]);


  // bucle ascenso
  while (i != i_inicial)
  {
    i = i - 1;
    j = j + 1;
    capicua = capicua && (V[i - 1] == V[j - 1]);
  }

  return capicua;
}


float iMEDIA_ARITMETICA_VECTOR_recursiva(float V[], int j)
{
  if (j == 1)
    return V[j - 1];
  else
    return (iMEDIA_ARITMETICA_VECTOR_recursiva(V, j - 1) * (j - 1) + V[j - 1]) / j;
}

// COMPLETAR POR EL ALUMNO
float MEDIA_ARITMETICA_VECTOR_iterativa(float V[], int j_inicial)
{
  //inicializacion
  int j = j_inicial;

  //bucle descenso
  while (j > 1)
  {
    j = j - 1;
  }

  float media = V[j - 1];

  //bucle ascenso
  while (j != j_inicial)
  {
    j = j + 1;
    media = (media * (j - 1) + V[j - 1]) / j;
  }

  return media;
}

bool iSIMETRICA_MATRIZ_recursiva(int A[][ORDEN], int k)
{
  if (k == 1)
    return true;
  else
    return iSIMETRICA_MATRIZ_recursiva(A, k - 1) && banda_simetrica(A, k);
}

bool banda_simetrica(int A[][ORDEN], int k)
{
  int i = 0;
  bool iguales = true;

  while (i < k - 1 && iguales)
  {
    i++;
    if (A[i - 1][k - 1] != A[k - 1][i - 1])
      iguales = false;
  }

  return iguales;
}

// COMPLETAR POR EL ALUMNO
bool SIMETRICA_MATRIZ_iterativa (int A[][ORDEN], int k_inicial)
{
  //inicializacion
  int k = k_inicial;
  bool iguales = true;

  //bucle descenso
  while (k > 1)
  {
    k = k - 1;
  }

  //bucle ascenso
  while (k != k_inicial)
  {
    k = k + 1;
    int i = 0;
    while (i < k - 1 && iguales)
    {
      i++;
      if (A[i - 1][k - 1] != A[k - 1][i - 1])
        iguales = false;
    }
  }

  return iguales;
}

//OPCIONALES
int iCONTAR_PARES_VECTOR(int V[], int j_inicial){

    // inicializacion
    int j=j_inicial;
    int cont=0;

    // bucle ascenso
    while (j>0){
          if (V[j-1]%2==0) cont++;
          j--;
    }

    return cont;
}

int iCONTAR_COINCIDENCIAS_MATRIZ(int A[][ORDEN], int k_inicial, int n_inicial){

    // inicializacion
    int k=k_inicial;
    int n=n_inicial;
    int cont=0;

    // bucle descenso
    while (k>0){
      n=n_inicial;
        while (n>0){
          if (A[k-1][n-1]==A[k-1][n_inicial-1]) cont++;
            n--;
          }
          k--;
    }
    return cont;
}