#include <stdio.h>

int main (){
int x, y;
printf ("Introduce un entero: ");
scanf ("%d", &x);
//solucion 1
while (getchar () != '\n');
//solucion 2
//fflush(stdin);
printf ("Introduce un segundo entero: ");
scanf ("%d", &y);
printf ("Los valores introducidos son: %d y %d\n", x, y);
return 0;
}
