#include "headers.h"

int sumar(int num1, int num2)
{
    int resultado;
    resultado=num1+num2;
    return resultado;
}

int resta(int num1, int num2){
    int producto;
    producto=num1-num2;
    return producto;
}

int multiplicacion(int num1,int num2){
    int producto;
    if (num1==0 || num2==0){
        producto=0;
    }else{
        producto=num1*num2;
    }

    return producto;
}

float division(int num1, int num2){
    float producto;
    if (num1==0 || num2==0){
        producto=0;
    }else{
        producto=(float)num1/num2;
    }

    return producto;
}

int factorial(int numero){
    int x;
    int producto;
    int acumulador;
    acumulador=1;
    producto=acumulador;

    if (numero<0){
        producto=0;
    }else {
        for (x=0;x<numero-1;x++){
        acumulador*=(numero-x);
        producto=acumulador;
    }
    }

    return producto;
}
