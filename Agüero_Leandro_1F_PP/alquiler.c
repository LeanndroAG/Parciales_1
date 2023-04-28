#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alquiler.h"
#include "inputs.h"
#include "juego.h"
#include "cliente.h"
#include "control.h"
#define OCUPADO 0
#define LIBRE 1
static int nextId();

static int nextId(){
    static int lastId = -1;
    lastId++;
    return lastId;
}


int alquiler_findEmptyPlaceAlquiler(eAlquiler* pAlquiler, int length){
    int retorno = -1;
    int i;
    if( pAlquiler != NULL && length > 0 )
    {
        retorno = -2;
        for(i=0; i < length ; i++)
        {
            if(pAlquiler[i].isEmpty == LIBRE)
            {
            retorno = i;
            break;
            }
        }
    }
    return retorno;
}

int alquiler_initAlquiler(eAlquiler* pAlquiler,int length){
    int retorno = -1;
    int i;
    if(pAlquiler != NULL && length > 0)
    {
        retorno = 0;
        for(i=0; i < length; i++)
        {
            pAlquiler[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int alquiler_addAlquiler(eAlquiler* pAlquiler, int length,int idCliente,int idJuego,int dia,int mes,int anio){
    int retorno = -1;
    int index;
    int id;

    if(pAlquiler != NULL && length > 0)
    {
        retorno = -2;
        index = alquiler_findEmptyPlaceAlquiler(pAlquiler,length);
        if(index >= 0){
            retorno = 0;
            id=nextId();
            pAlquiler[index].idAlquiler=id;
            pAlquiler[index].idJuego=idJuego;
            pAlquiler[index].idCliente=idCliente;
            pAlquiler[index].fecha.dia=dia;
            pAlquiler[index].fecha.mes=mes;
            pAlquiler[index].fecha.anio=anio;
            pAlquiler[index].isEmpty=OCUPADO;
        }
    }
    return retorno;
}

/*********************************************/

int alquiler_printAlquiler(eAlquiler* pAlquiler,int length, eJuego* pJuego, int lengthJuego, eCliente* pCliente, int lengthCliente){
    int retorno = -1;
    int i,j,k;

    if(pAlquiler != NULL && length > 0){
        retorno = 0;
        printf("\n| %-10s| %-10s| %-10s | %-8s | %-8s| %-10s | %-6s\n","APELLIDO","NOMBRE","TELEFONO","JUEGO","IMPORTE", "FECHA", "ID A");
        printf("--------------------------------------------------------------------------------\n");
        for(i=0 ;i < length; i++){
            if(pAlquiler[i].isEmpty == 0){
                for(j=0 ;j < lengthCliente; j++){
                    if(pAlquiler[i].idCliente == pCliente[j].idCliente && pCliente[j].isEmpty == 0){
                        for(k=0 ;k < lengthJuego; k++){
                            if(pAlquiler[i].idJuego == pJuego[k].idJuego && pJuego[k].isEmpty == 0){
                                printf("| %-10s| %-10s| %-10s | %-8s | %-8d| %-2d/%-2d/%-d | %-4d\n",
                                pCliente[j].apellido,
                                pCliente[j].nombre,
                                pCliente[j].telefono,
                                pJuego[k].descripcion,
                                pJuego[k].importe,
                                pAlquiler[i].fecha.dia,
                                pAlquiler[i].fecha.mes,
                                pAlquiler[i].fecha.anio,
                                pAlquiler[i].idAlquiler);
                            }
                        }
                    }
                }

            }
        }
    }
    return retorno;
}

float alquiler_totalAlquiler(eAlquiler* pAlquiler, int lengthAlquiler,eJuego* pJuego,int lenghtJuego){
    int retorno = -1;
    int i,indexJuego;
    float total=0;

    for(i=0 ;i < lengthAlquiler; i++)
    {
        if(pAlquiler[i].isEmpty == OCUPADO)
        {
            indexJuego = juego_findJuegoById(pJuego,lenghtJuego,pAlquiler[i].idJuego);
            total = total + pJuego[indexJuego].importe;
            retorno = total;
        }
    }
    return retorno;
}

float alquiler_avarageAlquiler(eAlquiler* pAlquiler, int lengthAlquiler,eJuego* pJuego,int lenghtJuego){
    int i;
    float totalJuego = 0;
    int contJuego = 0;

    for(i=0 ;i < lengthAlquiler; i++)
    {
        if(pAlquiler[i].isEmpty == OCUPADO)
        {
            totalJuego = alquiler_totalAlquiler(pAlquiler,lengthAlquiler,pJuego,lenghtJuego);
            contJuego++;
        }
    }
    return totalJuego / (float)contJuego;
}


int alquiler_notExceededAlquiler(eAlquiler* pAlquiler, int lengthAlquiler,eJuego* pJuego,int lengthJuego){
    int i,indexJuego,auxImporte,avarageAux;
    int notExceeded=0;

    avarageAux = alquiler_avarageAlquiler(pAlquiler,lengthAlquiler,pJuego,lengthJuego);

    for(i=0 ;i < lengthAlquiler; i++)
    {
        if(pAlquiler[i].isEmpty == OCUPADO)
        {
            indexJuego = juego_findJuegoById(pJuego,lengthJuego,pAlquiler[i].idJuego);
            auxImporte = pJuego[indexJuego].importe;
            if(auxImporte <= avarageAux)
            {
                notExceeded++;
            }
        }
    }
    return notExceeded;
}

int alquiler_printClientesXjuego(eAlquiler* pAlquiler, int lengthAlquiler, int idJuego, eCliente* pCliente, int lengthCliente){
    int retorno = -1;
    int i,j;

    for(i = 0 ;i < lengthAlquiler; i++){
        if(pAlquiler[i].isEmpty == OCUPADO && idJuego == pAlquiler[i].idJuego){
            for(j = 0 ;j < lengthCliente; j++){
                if(pAlquiler[i].idCliente == pCliente[j].idCliente){

                    print1Cliente(pCliente[j]);
                    /*printf("\n| %-12s| %-12s| %-25s |%-10s | %-3s\n","APELLIDO","NOMBRE","DOMICILIO","TELEFONO","ID C");
                    printf("--------------------------------------------------------------------------------\n");
                    printf("| %-12s| %-12s| %-25s |%-10s | %-3d\n\n",
                    pCliente[j].nombre,
                    pCliente[j].apellido,
                    pCliente[j].domicilio,
                    pCliente[j].telefono,
                    pCliente[j].idCliente);*/
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int alquiler_printJuegosXcliente(eAlquiler* pAlquiler, int lengthAlquiler, eJuego* pJuego, int lengthJuego, int idCliente){
    int retorno = -1;
    int i,j;

    for(i = 0 ;i < lengthAlquiler; i++){
        if(pAlquiler[i].isEmpty == OCUPADO && idCliente == pAlquiler[i].idCliente){
            for(j = 0 ;j < lengthJuego; j++){
                if(pAlquiler[i].idJuego == pJuego[j].idJuego){
                    print1Juego(pJuego[j]);
                    /*printf("\n| %-10s | %-25s| %-3s\n","IMPORTE","DESCRIPCION","ID J");
                    printf("--------------------------------------------------------------------------------\n");
                    printf("| %-10d | %-25s| %-3d\n\n",
                    pJuego[j].importe,
                    pJuego[j].descripcion,
                    pJuego[j].idJuego);
                    retorno = 0;*/
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int alquiler_clienteWithMoreAlquileres(eAlquiler* pAlquiler, int lengthAlquiler ,eCliente* pCliente, int lengthCliente)
 {
     int retorno=-1,i, maximoAlquiler=0;
     int cantidadAlquileres[lengthAlquiler]; // Uso el indice para el id de y el valor como acumulador
     int auxId;

     for(i=0;i<lengthAlquiler;i++)
     {
         cantidadAlquileres[i] = 0;
     }

     if(pAlquiler != NULL && lengthAlquiler > 0 && pCliente != NULL && lengthCliente > 0)
     {
         for(i=0;i<lengthAlquiler;i++)
         {
             if(pAlquiler[i].isEmpty == OCUPADO)
             {
                 cantidadAlquileres[pAlquiler[i].idCliente]++;
             }
         }
         for(i=0;i<lengthAlquiler;i++)
         {
             if(cantidadAlquileres[i] > maximoAlquiler)
             {
                 maximoAlquiler = cantidadAlquileres[i];
             }
         }
         for(i=0;i<lengthAlquiler;i++)
         {
            if(cantidadAlquileres[i] == maximoAlquiler)
            {
                auxId = cliente_findClienteById(pCliente, lengthCliente, i);
                printf("\n|%-12s| %-12s| %-12s| %-15s |%-10s | %-3s\n","ALQUILERES","APELLIDO","NOMBRE","DOMICILIO","TELEFONO","ID C");
                printf("--------------------------------------------------------------------------------\n");
                printf("|%-12d| %-12s| %-12s| %-15s |%-10s | %-3d\n\n",maximoAlquiler,pCliente[auxId].nombre,pCliente[auxId].apellido,pCliente[auxId].domicilio,pCliente[auxId].telefono,pCliente[auxId].idCliente);
            }
         }
        retorno = 0;
     }
     return retorno;
 }

 int alquiler_juegoWithLessAlquileres(eAlquiler* pAlquiler, int lengthAlquiler ,eJuego* pJuego, int lengthJuego){
     int retorno=-1,i, menorAlquiler=0;
     int cantidadAlquileres[lengthAlquiler];
     int auxId;
     int flag = 1;

     for(i=0;i<lengthAlquiler;i++)
     {
         cantidadAlquileres[i] = 0;
     }

     if(pAlquiler != NULL && lengthAlquiler > 0 && pJuego != NULL && lengthJuego > 0)
     {
         for(i=0;i<lengthAlquiler;i++)
         {
             if(pAlquiler[i].isEmpty == OCUPADO)
             {
                 cantidadAlquileres[pAlquiler[i].idJuego]++;
             }
         }
         for(i=0;i<lengthAlquiler;i++)
         {
             if(menorAlquiler > cantidadAlquileres[i] || flag == 1)
             {
                menorAlquiler = cantidadAlquileres[i];
                flag = 0;
                break;
             }
             flag = 1;
         }
         for(i=0;i<lengthAlquiler;i++)
         {
            if(cantidadAlquileres[i] == menorAlquiler)
            {
                auxId = juego_findJuegoById(pJuego, lengthJuego, i);
                printf("\n|%-12s| %-15s| %-7s| %-4s\n","ALQUILERES","JUEGO","IMPORTE","ID J");
                printf("--------------------------------------------------------------------------------\n");
                printf("|%-12d| %-15s| %-7d| %-4d\n\n",menorAlquiler,pJuego[auxId].descripcion,pJuego[auxId].importe,pJuego[auxId].idJuego);
            }
         }
        retorno = 0;
     }
     return retorno;
 }

 int printClienteXfecha(eAlquiler *pAlquiler, int lengthAlquiler, eJuego *pJuego, int lengthJuego, eCliente *pCliente, int lengthCliente, int dia, int mes, int anio){
    int retorno = -1;
    int i, j, k;
    for (i=0; i<lengthAlquiler; i++){
        if (pAlquiler[i].isEmpty == OCUPADO && pAlquiler[i].fecha.dia == dia && pAlquiler[i].fecha.mes == mes && pAlquiler[i].fecha.anio == anio){
            for (j=0; j<lengthCliente; j++){
                if (pAlquiler[i].idCliente == pCliente[j].idCliente && pCliente[j].isEmpty == OCUPADO){
                    for (k=0; k<lengthJuego; k++){
                        if (pAlquiler[i].idJuego == pJuego[k].idJuego && pJuego[k].isEmpty == OCUPADO){
                            printf("\n| %-12s| %-12s| %-12s |%-12s\n","APELLIDO","NOMBRE","JUEGO","TELEFONO");
                            printf("--------------------------------------------------------------------------------\n");
                            printf("| %-12s| %-12s| %-12s |%-12s\n\n",
                                    pCliente[j].nombre,
                                    pCliente[j].apellido,
                                    pJuego[k].descripcion,
                                    pCliente[j].telefono);
                                    retorno = 0;
                                    break;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int printJuegoXfecha(eAlquiler* pAlquiler, int lengthAlquiler, eJuego* pJuego, int lengthJuego, eCliente* pCliente, int lengthCliente, int dia, int mes, int anio){
    int retorno = -1;
    int i, j, k;
    for (i=0; i<lengthAlquiler; i++){
        if (pAlquiler[i].isEmpty == OCUPADO && pAlquiler[i].fecha.dia == dia && pAlquiler[i].fecha.mes == mes && pAlquiler[i].fecha.anio == anio){
            for (j=0; j<lengthCliente; j++){
                if (pAlquiler[i].idCliente == pCliente[j].idCliente && pCliente[j].isEmpty == OCUPADO){
                    for (k=0; k<lengthJuego; k++){
                        if (pAlquiler[i].idJuego == pJuego[k].idJuego && pJuego[k].isEmpty == OCUPADO){
                            printf("\n| %-12s| %-7s| %-24s \n","JUEGO","IMPORTE","CLIENTE");
                            printf("--------------------------------------------------------------------------------\n");
                            printf("| %-12s| %-7d| %-12s - %-12s\n\n",
                                    pJuego[k].descripcion,
                                    pJuego[k].importe,
                                    pCliente[j].nombre,
                                    pCliente[j].apellido);
                                    retorno = 0;
                                    break;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

