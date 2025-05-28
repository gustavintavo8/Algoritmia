// ---------------------------------------------------------------------------------
//
// ALGORITMIA: PRACTICA DE DIVIDE Y VENCERAS
//
// Implementacion en C del algoritmo recursivo que calcula la potencia n-esima de a
//
// Copyright: Raquel Cortina
//
// Fecha: 27 de octubre de 2022
//
// ---------------------------------------------------------------------------------
//
// Programa que calcula recursivamente la potencia n-esima de a, donde a>=0 y n>=0
//
//----------------------------------------------------------------------------------

#include <stdio.h>

// prototipos de funciones
int   POTENCIA_DyV (int, int);

// programa principal
int main() {
 int n,a;
 printf("\n\n CALCULO LA POTENCIA n-ESIMA DE UN NUMERO \n\n ");

 // leer la base
 do{
 printf("\nIntroduce un numero a (a>=0): ");
 scanf("%d",&a);
 }while(a<0);

 // leer el exponente
 do{
 printf("\nIntroduce un exponente n (n>=0): ");
 scanf("%d",&n);
 }while(n<0);

 printf("\nLa potencia %d-esima de %d es %d\n\n", n,a, POTENCIA_DyV(a,n));
 return 0;
}

int   POTENCIA_DyV (int a, int n){
  int p;
  if (n==0) return 1;  // caso trivial
  else { // caso no trivial
	    p = POTENCIA_DyV(a, n/2);
	    if (n%2==0) return p*p;
	    else return p*p*a;
       }
}
