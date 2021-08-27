#include <stdio.h>
#include <stdlib.h>

// Proto
unsigned long long factorial (int num);



int main()
{
    unsigned long long fac = factorial(20);
    printf("Factorial: %llu", fac);
    return 0;
}

/* 1. Calcular el factorial de un n�mero en forma recursiva. */

unsigned long long factorial (int num){
    // Si hemos llegado a 1, detenemos la recursi�n
    if (num <= 1)
    {
        return 1;
    }
    return num * factorial(num - 1); // Restar 1
}
