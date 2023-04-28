#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "juego.h"
#define OCUPADO 0
#define LIBRE 1

static int nextId();
static int nextId(){
    static int lastId = -1;
    lastId++;
    return lastId;
}


int juego_findEmptyPlaceJuego(eJuego* pJuego, int length){
    int retorno = -1;
    int i;
    if( pJuego != NULL && length > 0 )
    {
        retorno = -2;
        for(i=0; i < length ; i++)
        {
            if(pJuego[i].isEmpty == LIBRE)
            {
            retorno = i;
            break;
            }
        }
    }
    return retorno;
}

int juego_initJuego(eJuego* pJuego,int length){
    int retorno = -1;
    int i;
    if(pJuego != NULL && length > 0)
    {
        retorno = 0;
        for(i=0; i < length; i++)
        {
            pJuego[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int juego_addJuego(eJuego* pJuego, int length,char* descripcion, int importe){
    int retorno = -1;
    int index;
    int id;

    if(pJuego != NULL && length > 0)
    {
        retorno = -2;
        index = juego_findEmptyPlaceJuego(pJuego,length);
        if(index >= 0)
        {
            retorno = 0;
            id=nextId();
            strcpy(pJuego[index].descripcion,descripcion);
            pJuego[index].importe=importe;
            pJuego[index].idJuego=id;
            pJuego[index].isEmpty=OCUPADO;
        }
    }
    return retorno;
}

int juego_findJuegoById(eJuego* pJuego,int length,int id){
    int retorno = -1;
    int i;
    if(pJuego != NULL && length > 0)
    {
        retorno = -2;
        for(i=0 ;i < length; i++)
        {
            if(pJuego[i].isEmpty == OCUPADO && pJuego[i].idJuego == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int juego_removeJuego(eJuego* pJuego,int length,int id){
    int retorno = -1;
    int index;
    index = juego_findJuegoById(pJuego, length, id);
    if( index >= 0)
    {
        retorno = 0;
        pJuego[index].isEmpty = LIBRE;
    }
    return retorno;
}

int juego_sortJuego(eJuego* pJuego,int length){
    int retorno = - 1;
    int flagSwap;
    int i;
    eJuego auxiliar;
        if(pJuego != NULL && length > 0)
        {
            retorno = 0;
            do{
                flagSwap = 0;
                for(i = 0 ;i < length - 1; i++){
                    if(pJuego[i].isEmpty == OCUPADO && pJuego[i+1].isEmpty == OCUPADO )
                    {
                        if((pJuego[i].importe) > (pJuego[i+1].importe))
                        {
                            auxiliar = pJuego[i];
                            pJuego[i] = pJuego[i+1];
                            pJuego[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                        else if(((pJuego[i].importe) == (pJuego[i+1].importe)) && (stricmp(pJuego[i].descripcion, pJuego[i+1].descripcion) > 0))
                        {
                            auxiliar = pJuego[i];
                            pJuego[i] = pJuego[i+1];
                            pJuego[i+1] = auxiliar;
                            flagSwap = 2;
                        }
                    }
                }
            }while(flagSwap);
        }
    return retorno;
}

int juego_printJuego(eJuego* pJuego,int length){
    int retorno = -1;
    int i;
    if(pJuego != NULL && length > 0)
    {
        retorno = 0;
        printf("| %-10s | %-25s| %-3s\n","IMPORTE","DESCRIPCION","ID J");
        printf("--------------------------------------------------------------------------------\n");
        for(i=0; i < length; i++){
            if(pJuego[i].isEmpty == OCUPADO)
            {
                printf("| %-10d | %-25s| %-3d\n",pJuego[i].importe, pJuego[i].descripcion, pJuego[i].idJuego);
            }
        }
    }
    return retorno;
}

int juego_updateJuego(eJuego* pJuego, int length, char* descripcion, int importe, int id){
    int retorno = -1;
    int index;

    index=juego_findJuegoById(pJuego,length, id);
    if(index >= 0){

        retorno = 0;
        strcpy(pJuego[index].descripcion,descripcion);
        pJuego[index].importe=importe;
    }
    return retorno;
}


int juego_bubbleSortEfficient(eJuego* pJuego, int length){
    int i;
    int flagSwap = 1;
    eJuego auxiliar;
    while(flagSwap == 1){
        flagSwap = 0;
        for (i = 1 ;i < length; i++){
            if (pJuego[i].importe > pJuego[i-1].importe){
                auxiliar = pJuego[i];
                pJuego[i] = pJuego[i-1];
                pJuego[i-1] = auxiliar;
                flagSwap = 1;
            }
        }
    }
    juego_printJuego(pJuego,length);
    return 0;
}
