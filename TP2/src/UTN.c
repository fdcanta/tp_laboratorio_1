/*
 * UTN.c
 *
 *  Created on: 12 may. 2021
 *      Author: Legion
 */

#include "UTN.h"

int conseguirEntero(int* numero, char* mensaje, char* mensajeError){
    int retorno;
    char numeroAuxiliar[30];
    retorno=-1;
    printf("%s", mensaje);
    scanf("%[^\n]", numeroAuxiliar);
    limpiarBuffer();
    if(validarSoloEntero(numeroAuxiliar)!=-1){
        *numero=atoi(numeroAuxiliar);
        retorno=0;
    }else{
        printf("%s", mensajeError);
    }
    return retorno;
}

int conseguirEnteroConParametros(int* pValor,char* mensaje, char* mensajeError, int minimo, int maximo, int intentos){
    int retorno;
    int numero;
    retorno=-1;
    int i;
    char numeroAuxiliar[30]={" "};
    for(i=0;i<intentos;i++){
        printf("%s", mensaje);
        scanf("%[^\n]", numeroAuxiliar);
        limpiarBuffer();
        if(validarSoloEntero(numeroAuxiliar)!=-1){
            numero=atoi(numeroAuxiliar);
            if(numero<minimo||numero>maximo){
            printf("%s", mensajeError);

            }else{
                *pValor=numero;
                retorno++;
                break;
            }
        }else{
            printf("%s", mensajeError);
        }
    }
    return retorno;
}

int validarSoloEntero(char* numeros){
    int retorno;
    int i;
    retorno=0;
    if(strlen(numeros)>0){
        for (i=0;i<strlen(numeros);i++){
            if(isdigit(numeros[i])==0){
                retorno=-1;
                break;
            }
        }
    }else{
        retorno=-1;
    }
    return retorno;
}

int conseguirNumeroDecimal(float* numero, char* mensaje, char* mensajeError){
    int retorno;
    char numeroAuxiliar[30]={" "};
    retorno=-1;
    printf("%s", mensaje);
    scanf("%[^\n]", numeroAuxiliar);
    limpiarBuffer();
    if(validarSoloDecimales(numeroAuxiliar)!=-1){
        *numero=atof(numeroAuxiliar);
        retorno=0;
    }else{
        printf("%s", mensajeError);
    }
    return retorno;
};



int conseguirNumeroDecimalConParametros(float* pValor,char* mensaje, char* mensajeError, int minimo, int maximo, int intentos){
    int retorno;
    retorno=-1;
    int i;
    float numero;
    char numeroAuxiliar[30]={" "};
    for(i=0;i<intentos;i++){
        printf("%s", mensaje);
        scanf("%[^\n]", numeroAuxiliar);
        limpiarBuffer();
        if(validarSoloDecimales(numeroAuxiliar)!=-1){
            numero=atof(numeroAuxiliar);
            if(numero<minimo||numero>maximo){
            printf("\n%s", mensajeError);
            }else{
                *pValor=numero;
                retorno=0;
                break;
            }
        }else{
            printf("\n%s", mensajeError);
        }
    }
    return retorno;
}

int validarSoloDecimales(char* numeros){
    int retorno;
    int i;
    int puntos;
    retorno=0;
    puntos=0;
    if(strlen(numeros)!=0){
        for(i=0;i<strlen(numeros);i++){
            if(isdigit(numeros[i])==0&&numeros[i]!='.'){
                retorno=-1;
                break;
            }
            if(numeros[i]=='.'){
                puntos++;
            }
        }
        if(puntos>1){
            retorno=-1;
        }
    }else{
        retorno=-1;
    }
    return retorno;
}

int conseguirCadenaCaracteres(char* auxiliar, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos){
    int retorno;
    retorno=-1;
    int i;
    for(i=0;i<intentos;i++){
        printf("%s", mensaje);
        scanf("%[^\n]", auxiliar);
        limpiarBuffer();
        if(verificarCadenaSoloAlfabeto(auxiliar)==0){
            if(strlen(auxiliar)<minimo||strlen(auxiliar)>maximo){
            printf("%s", mensajeError);
            }else{
                retorno=0;
                break;
            }
        }else{
            printf("%s", mensajeError);
        }


    }
    return retorno;
}

int verificarCadenaSoloAlfabeto(char* cadena){
    int i;
    int retorno;
    retorno=0;
    if(strlen(cadena)>0){
        for(i=0;i<strlen(cadena);i++){
            if(isdigit(cadena[i])!=0){
                retorno=-1;
                break;
            }
        }
    }else{
        retorno=-1;
    }

    return retorno;
}




int ordenarEnteros(int* lista, int orden){
    int retorno;
    int i;
    int j;
    int numeroAuxiliar;
    retorno=-1;
    switch(orden){
        case 1:
            for(i=0;i<TAM;i++){
                for(j=0;j<TAM;j++){
                    if(lista[i]<lista[j]){
                        numeroAuxiliar=lista[i];
                        lista[i]=lista[j];
                        lista[j]=numeroAuxiliar;
                    }
                }
            }
            retorno=0;
        break;
        case 2:
            for(i=0;i<TAM;i++){
                for(j=0;j<TAM;j++){
                    if(lista[i]>lista[j]){
                        numeroAuxiliar=lista[i];
                        lista[i]=lista[j];
                        lista[j]=numeroAuxiliar;
                    }
                }
            }
            retorno=0;
    }
    return retorno;
}

int ordenarDecimales(float* lista, int orden){
    int retorno;
    int i;
    int j;
    float numeroAuxiliar;
    retorno=-1;
    switch(orden){
        case 1:
            for(i=0;i<TAM;i++){
                for(j=0;j<TAM;j++){
                    if(lista[i]<lista[j]){
                        numeroAuxiliar=lista[i];
                        lista[i]=lista[j];
                        lista[j]=numeroAuxiliar;
                    }
                }
            }
            retorno=0;
        break;
        case 2:
            for(i=0;i<TAM;i++){
                for(j=0;j<TAM;j++){
                    if(lista[i]>lista[j]){
                        numeroAuxiliar=lista[i];
                        lista[i]=lista[j];
                        lista[j]=numeroAuxiliar;
                    }
                }
            }
            retorno=0;
    }
    return retorno;
}

void limpiarBuffer(){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

