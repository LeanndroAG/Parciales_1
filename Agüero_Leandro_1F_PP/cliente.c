#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "cliente.h"
#define OCUPADO 0
#define LIBRE 1

static int nextId();

static int nextId(){
    static int lastId = -1;
    lastId++;
    return lastId;
}


int cliente_findEmptyPlaceCliente(eCliente* pCliente, int length){
    int retorno = -1;
    int i;
    if( pCliente != NULL && length > 0 )
    {
        retorno = -2;
        for(i=0; i < length ; i++)
        {
            if(pCliente[i].isEmpty == LIBRE)
            {
            retorno = i;
            break;
            }
        }
    }
    return retorno;
}

int cliente_initCliente(eCliente* pCliente,int length){
    int retorno = -1;
    int i;
    if(pCliente != NULL && length > 0)
    {
        retorno = 0;
        for(i=0; i < length; i++)
        {
            pCliente[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int cliente_addCliente(eCliente* pCliente, int length,char* nombre,char* apellido,char* domicilio,char* telefono){
    int retorno = -1;
    int index;
    int id;

    if(pCliente != NULL && length > 0)
    {
        retorno = -2;
        index = cliente_findEmptyPlaceCliente(pCliente,length);
        if(index >= 0)
        {
            retorno = 0;
            id=nextId();
            strcpy(pCliente[index].nombre,nombre);
            strcpy(pCliente[index].apellido,apellido);
            strcpy(pCliente[index].domicilio,domicilio);
            strcpy(pCliente[index].telefono,telefono);
            pCliente[index].idCliente=id;
            pCliente[index].isEmpty=OCUPADO;
            }
    }
    return retorno;
}

int cliente_findClienteById(eCliente* pCliente,int length,int id){
    int retorno = -1;
    int i;
    if(pCliente != NULL && length > 0)
    {
        retorno = -2;
        for(i=0 ; i < length ; i++)
        {
            if(pCliente[i].isEmpty == OCUPADO && pCliente[i].idCliente == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_removeCliente(eCliente* pCliente,int length,int id){
    int retorno = -1;
    int index;
    index = cliente_findClienteById(pCliente, length, id);
    if( index >= 0)
    {
        retorno = 0;
        pCliente[index].isEmpty = LIBRE;
    }
    return retorno;
}

int cliente_sortCliente(eCliente* pCliente,int length){
    int retorno = - 1;
    int flagSwap;
    int i;
    eCliente auxiliar;
        if(pCliente != NULL && length > 0)
        {
            retorno = 0;
            do{
                flagSwap = 0;
                for(i=0 ;i < length - 1; i++){
                    if(pCliente[i].isEmpty == OCUPADO && pCliente[i+1].isEmpty == OCUPADO )
                    {
                        if((stricmp(pCliente[i].apellido,pCliente[i+1].apellido)) > 0)
                        {
                            auxiliar = pCliente[i];
                            pCliente[i] = pCliente[i+1];
                            pCliente[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                        else if((stricmp(pCliente[i].apellido,pCliente[i+1].apellido) == 0) && (stricmp(pCliente[i].nombre,pCliente[i+1].nombre) > 0))
                        {
                            auxiliar = pCliente[i];
                            pCliente[i] = pCliente[i+1];
                            pCliente[i+1] = auxiliar;
                            flagSwap = 2;
                        }
                    }
                }
            }while(flagSwap);
        }
    return retorno;
}

int cliente_printCliente(eCliente* pCliente,int length){
    int retorno = -1;
    int i;
    if(pCliente != NULL && length > 0)
    {
        retorno = 0;
        printf("\n| %-10s| %-10s| %-30s |%-10s | %-3s\n","APELLIDO","NOMBRE","DOMICILIO","TELEFONO","ID C");
        printf("--------------------------------------------------------------------------------\n");
        for(i=0; i < length; i++){
            if(!pCliente[i].isEmpty)
            {
                printf("| %-10s| %-10s| %-30s |%-10s | %-3d\n",pCliente[i].apellido, pCliente[i].nombre, pCliente[i].domicilio, pCliente[i].telefono, pCliente[i].idCliente);
            }
        }
    }
    return retorno;
}


int cliente_updateCliente(eCliente* pCliente, int length,char* nombre,char* apellido,char* domicilio,char*telefono, int id){
    int retorno = -1;
    int index;

    index = cliente_findClienteById(pCliente,length, id);
    if(index >= 0){
        retorno = 0;
        strcpy(pCliente[index].nombre,nombre);
        strcpy(pCliente[index].apellido,apellido);
        strcpy(pCliente[index].domicilio,domicilio);
        strcpy(pCliente[index].telefono,telefono);
    }
    return retorno;
}


int cliente_insertion(eCliente* pCliente,int length)
{
	eCliente auxiliar;
    int j, i;
	for(i = 1 ;i < length; i++) {
		auxiliar = pCliente[i];
		j = i;
		while(j > 0 && strcmp(auxiliar.apellido , pCliente[j - 1].apellido) < 0)
        {
			pCliente[j] = pCliente[j - 1];
			j--;
		}
		pCliente[j] = auxiliar;
	}
	cliente_printCliente(pCliente,length);
	return 0;
}
