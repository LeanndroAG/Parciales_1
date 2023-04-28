#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

static char getChar(char* pBuffer){
    return scanf("%c", pBuffer);
}
static int getInt(int* pBuffer){
    return scanf("%d", pBuffer);
}

int utn_getEntero(int* pEntero, char* mensaje, char* eMensaje, int min, int max, int reIntentos){
    int retorno=-1;
    int bufferInt;
    if(pEntero != NULL && mensaje != NULL && eMensaje != NULL && min <= max && reIntentos >=0){
        do{
            reIntentos--;
            printf("%s", mensaje);
            fflush(stdin);
            if( (getInt(&bufferInt) == 1) && (bufferInt >= min && bufferInt <= max) ){
                  *pEntero = bufferInt;
                  retorno=0;
                  break;
            }
            else{
                printf("%s", eMensaje);
            }
        }while(reIntentos>=0);
    }
    return retorno;
}

int utn_getCaracter(char* pCaracter, char* mensaje, char* eMensaje, int min, int max, int reIntentos){
    int retorno=-1;
    char bufferChar;
    if(pCaracter != NULL && mensaje != NULL && eMensaje != NULL && min <= max && reIntentos >=0){
        do{
            reIntentos--;
            printf("%s", mensaje);
            if( (getChar(&bufferChar)==1)&&(bufferChar >= min && bufferChar <= max) ){
                    *pCaracter=bufferChar;
                    retorno=0;
                    break;
            }
            else{
                fflush(stdin);
                printf("%s", eMensaje);
            }
        }while(reIntentos>0);
    }
    return retorno;
}


/***************************/

int utn_esSoloLetras(char* str){
    int i = 0;
    int retorno = 0;
    if(str != NULL){
        while(str[i] != '\0'){
            if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
                break;
            }
            i++;
            if(str[i]=='\0'){
                retorno = 1;
            }
        }
    }
    return retorno;
}

void utn_getString(char* input,char* mensaje){
    int cantidad;
    char buffer[256];
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);
    cantidad = strlen(buffer);
    buffer[cantidad-1] = '\0';
    strcpy(input,buffer);
}

int utn_getStringLetras(char* input,char* mensaje){
    char aux[256];
    utn_getString(aux,mensaje);
    if(utn_esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
 }

int utn_getValidStringLetras(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos){
    int i;
    int retorno=-1;
    char buffer[1024];

    if(input != NULL && mensaje != NULL && eMensaje != NULL && eMensajeLargo != NULL && reIntentos >=0){
        for(i=0;i<reIntentos;i++)
        {
            if (!utn_getStringLetras(buffer,mensaje))
            {
                printf ("%s",eMensaje);
                continue;
            }
            if(strlen(buffer) >= maxLargo)
            {
                printf ("%s",eMensajeLargo);
                fflush(stdin);
                continue;
            }
            retorno=0;
            strcpy(input,buffer);
            break;
        }
    }
    return retorno;
}


/**********************************************/

int utn_esNumerico(char* str){
    int i=0;
    int retorno=0;
    if(str != NULL){
        while(str[i] != '\0'){
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            i++;
            if(str[i]=='\0'){
                retorno = 1;
            }
        }
    }
    return retorno;
}

int utn_getStringNumeros(char* input,char* mensaje){
     char aux[256];
     utn_getString(aux,mensaje);
     if(utn_esNumerico(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
 }

int utn_getValidStringNumeros(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos){
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<reIntentos;i++)
    {
        if (!utn_getStringNumeros(buffer,mensaje))
        {
            printf ("%s",eMensaje);
            continue;
        }
        if(strlen(buffer) >= maxLargo)
        {
            printf ("%s",eMensajeLargo);
            fflush(stdin);
            continue;
        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}


/***************************************/

int utn_esAlfaNumero(char* str){
     int i=0;
     int retorno = 0;
     while(str[i] != '\0'){
         if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')){
             break;
         }
         i++;
         if(str[i]=='\0'){
            retorno = 1;
         }
    }
    return retorno;
}

int utn_getStringAlfaNumericos(char* input,char* mensaje){
     char aux[256];
     utn_getString(aux,mensaje);
     if(utn_esAlfaNumero(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
 }


int utn_getValidStringAlfaNumericos(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos){
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<reIntentos;i++)
    {
        if (!utn_getStringAlfaNumericos(buffer,mensaje))
        {
            printf ("%s",eMensaje);
            continue;
        }
        if(strlen(buffer) >= maxLargo)
        {
            printf ("%s",eMensajeLargo);
            fflush(stdin);
            continue;
        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}
