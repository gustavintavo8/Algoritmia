// Aritmetica de punteros

#include <stdio.h>

// funcion principal
int main()
{
    int a, b, *pa, *pb;
    a=6;
    b=4;
    pa=&a;
    pb=&b;

    printf( "\na = %d \t &a = %p \t *pa = %d \t pa = %p \t &pa = %p\n\n", a, &a, *pa, pa, &pa);

    printf( "\nb = %d \t &b = %p \t *pb = %d \t pb = %p \t &pb = %p\n\n", b, &b, *pb, pb, &pb);


    // la variable a se incrementa en 1 unidad
    //*pa+=1  o  *pa=*pa+1;
    *pa=*pa+1;
    printf("\n-----------\n");
    printf("  *pa=*pa+1\n");
    printf("-----------\n");
    printf("\na = %d \t &a = %p \t *pa = %d \t pa = %p \t &pa = %p\n\n", a, &a, *pa, pa, &pa);


    // la variable b se incrementa en 1 unidad
    (*pb)++;
    printf("\n-----------\n");
    printf("  (*pb)++\n");
    printf("-----------\n");
    printf("\nb = %d \t &b = %p \t *pb = %d \t pb = %p \t &pb = %p\n\n", b, &b, *pb, pb, &pb);



    // pb se incrementa en 1 unidad --> observar ahora el valor al que apunta pb y cual es el valor de pb
     pb++;
     printf("-----------\n");
     printf("  pb++\n");
     printf("-----------\n");
     printf("\nb = %d \t &b = %p \t *pb = %d \t pb = %p \t &pb = %p\n\n", b, &b, *pb, pb, &pb);

    // operaciones no válidas con punteros --> no se pueden ni sumar, ni multiplicar ni dividir dos punteros

    // printf("pa+pb --> %d", pa+pb);
    printf("\npa-pb --> %d\n", pa-pb);
   //  printf ("pa*pb --> %d", pa*pb);
   //  printf ("pa/pb --> %d", pa/pb);


    // Es posible comparar dos punteros en una operacion de relacion

    if (pa == pb) printf("\nEl valor de pa y pb coinciden\n\n");
    else printf("\nEl valor de pa y pb no coinciden\n\n");

    return 0;
}
