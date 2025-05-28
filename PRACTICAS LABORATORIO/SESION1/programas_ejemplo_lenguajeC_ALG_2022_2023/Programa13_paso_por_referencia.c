/* En este caso SI se intercambian los valores de n y m fuera de la función CAMBIA */

#include <stdio.h>

// Prototipos de funciones
void CAMBIA (int *, int *);

// Funcion principal
int main()
{
 int n=10,m=5;
 CAMBIA (&n, &m);
 printf("\n\n En MAIN: n=%d y m=%d \n\n",n,m) ;
 return 0;
}


// Funcion que intercambia los valores de n e m
void CAMBIA (int *n, int *m)
{
  int aux;
  aux=*m;
  *m=*n;
  *n=aux;
  printf("\n\n Dentro de la funcion CAMBIA: n=%d y m=%d \n\n",*n,*m) ;
}
