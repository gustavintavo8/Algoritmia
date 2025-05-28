#include <stdio.h>

int main (){
int x;
char c;
printf ("Introduce un entero: ");
scanf ("%d", &x);
//solucion 1
while (getchar () != '\n');
//solucion 2
//fflush(stdin);
printf ("Introduce un caracter: ");
scanf ("%c", &c);
printf ("Los valores introducidos son: %d y %c\n", x, c);
return 0;
}
