/*

Francisco Cantariño

Ezekiel 25:17

And I will execute great vengeance upon them with furious rebukes;
and they shall know that I am the Lord, when I shall lay my vengeance upon them.
*/


#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main()
{
    int numero1;
    int numero2;
    int opcion;
    opcion=0;
    numero1=0;
    numero2=0;
    int productoSuma;
    int productoResta;
    int productoMultiplicacion;
    float productoDivision;
    int productoFactorialA;
    int productoFactorialB;
    productoSuma=0;
    productoResta=0;
    productoMultiplicacion=0;
    productoDivision=0;
    productoFactorialA=0;
    productoFactorialB=0;

    while (opcion!=5){
        printf("\nEl numero A es: %d",numero1);
        printf("\nEl numero B es: %d",numero2);
        printf("\nElija una opcion: \n1-Ingresar primer operando \n2-Ingresar segundo operando \n3-Realizar operaciones \n4-Informar resultados \n5-Salir \n");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            printf("Ingrese el primer operando ");
            scanf(" %d", &numero1);
            break;
        case 2:
            printf("Ingrese el segundo operando ");
            scanf(" %d", &numero2);
            break;
        case 3:
            productoSuma=sumar(numero1, numero2);
            productoResta=resta(numero1, numero2);
            productoMultiplicacion=multiplicacion(numero1, numero2);
            productoDivision=division(numero1, numero2);
            productoFactorialA=factorial(numero1);
            productoFactorialB=factorial(numero2);
            break;
        case 4:
            printf("\nLa suma de los numeros es: %d", productoSuma);
            printf("\nLa resta de los numeros es: %d", productoResta);
            if (productoMultiplicacion==0){
                printf("\n0 no puede ser multiplicado o multiplicar.");
            }else{
                printf("\nLa multiplicacion de los numeros es: %d", productoMultiplicacion);
            }
            if (productoDivision==0){
                printf("\n0 no puede ser dividido o multiplicar.");
            }else{
                printf("\nLa division de los numeros es: %.2f", productoDivision);
            }
            if (productoFactorialA==0){
            printf("\nNo se puede sacar el factorial del numero A");
            }else{
            printf("\nEL resultado del factorial de A es: %d", productoFactorialA);
            }
            if (productoFactorialB==0){
            printf("\nNo se puede sacar el factorial del numero B");
            }else{
            printf("\nEL resultado del factorial de B es: %d", productoFactorialB);
            }
            break;
        case 5:
            break;
        }
    }
    return 0;
}
