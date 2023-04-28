#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "inputs.h"
#include "control.h"
#include "juego.h"
#include "cliente.h"
#include "alquiler.h"

int flagCliente = 0;
int flagJuego = 0;
int flagAlquiler = 0;

int control_addCliente(eCliente* pCliente, int length){

    char nombre[51];
    char apellido[51];
    char domicilio[51];
    char telefono[21];
    int retorno = -1;

    system("cls");
    printf("================\n");
    printf("ALTA DE CLIENTE\n");
    printf("================\n\n");
    if(cliente_findEmptyPlaceCliente(pCliente,length) >= 0){
        if(!utn_getValidStringLetras(nombre,"Nombre: ","Error.\n", "OVERFLOW.\n", 51, 3))
            if(!utn_getValidStringLetras(apellido, "Apellido: ", "Error.\n", "OVERFLOW.\n", 51, 3))
                if(!utn_getValidStringAlfaNumericos(domicilio,"Domicilio: ", "Error.\n", "OVERFLOW.\n", 51, 3))
                    if(!utn_getValidStringNumeros(telefono, "Telefono: ", "Error.\n","OVERFLOW.\n",21, 3)){
                            retorno = cliente_addCliente(pCliente,length, nombre, apellido, domicilio, telefono);
                            flagCliente++;
                            printf("-------------\n");
                            printf("ALTA COMPLETA\n");
                    }
    }
    else{
        printf("No hay lugar.\n");
    }
    getch();
    return retorno;
}

int control_removeCliente(eCliente* pCliente, int length){

    int id;
    int retorno = -1;
    char respuesta;

    system("cls");
    printf("================\n");
    printf("BAJA DE CLIENTE\n");
    printf("================\n\n");
    if(flagCliente!=0){
        retorno = utn_getEntero(&id, "ID: ", "Error.\n", 0,200,3);
        if(retorno == 0){
                retorno = cliente_findClienteById(pCliente,length,id);
                if(retorno >= 0){
                    print1Cliente(pCliente[retorno]);
                    printf("Eliminar cliente?: S/N\n");
                    respuesta = getch();
                    if(respuesta !='s'){
                       printf("Operacion cancelada.\n");
                    }
                    else{
                        retorno = cliente_removeCliente(pCliente, length, id);
                        flagCliente--;
                        printf("----------------------------\n");
                        printf("EL CLIENTE HA SIDO ELIMINADO\n");
                    }
                }
                else{
                    printf("ID invalido.\n");
                }
        }
    }
    else{
        printf("Primero debe cargar un cliente.\n");
    }
    getch();
    return retorno;
}

int control_updateCliente(eCliente* pCliente, int length){

    char nombre[51];
    char apellido[51];
    char domicilio[51];
    char telefono[21];
    int id;
    int retorno = -1;
    char respuesta;

    system("cls");
    printf("==================\n");
    printf("MODIFICAR CLIENTE\n");
    printf("==================\n\n");
    if(flagCliente != 0){
        retorno = utn_getEntero(&id, "ID: ", "Error.\n", 0,200,3);
        if(retorno == 0){
                retorno = cliente_findClienteById(pCliente,length,id);
                if(retorno >= 0){
                    print1Cliente(pCliente[retorno]);
                    printf("Modificar cliente?: S/N\n");
                    respuesta = getch();
                    if(respuesta !='s'){
                       printf("Operacion cancelada.\n");
                    }
                    else{
                        if(!utn_getValidStringLetras(nombre,"\nNombre: ","Error.\n", "OVERFLOW.\n", 51, 3))
                            if(!utn_getValidStringLetras(apellido, "Apellido: ", "Error.\n", "OVERFLOW.\n", 51, 3))
                                if(!utn_getValidStringAlfaNumericos(domicilio,"Domicilio: ", "Error.\n", "OVERFLOW.\n", 51, 3))
                                    if(!utn_getValidStringNumeros(telefono, "Telefono: ", "Error.\n","OVERFLOW.\n",21, 3)){
                                        retorno = cliente_updateCliente(pCliente,length, nombre, apellido, domicilio, telefono, id);
                                        printf("-----------------------------\n");
                                        printf("EL CLIENTE HA SIDO MODIFICADO\n");
                                    }
                    }
                }
                else{
                printf("ID Invalido.\n");
                }
            }
    }
    else{
        printf("Primero debe cargar un cliente.\n");
    }
    getch();
    return retorno;
}

int control_printAndSortCliente(eCliente* pCliente, int length){
    int retorno = -1;
    system("cls");
    printf("================\n");
    printf("LISTAR CLIENTES\n");
    printf("================\n\n");
    if(flagCliente != 0){
        retorno = cliente_sortCliente(pCliente, length);
        if(retorno == 0){
            retorno = cliente_printCliente(pCliente, length);
        }
    }
    else{
        printf("Primero debe cargar un cliente.\n");
    }
    getch();
    return retorno;
}

int control_addJuego(eJuego* pJuego, int length){

    char descripcion[51];
    int importe;
    int retorno = -1;
    system("cls");
    printf("==============\n");
    printf("ALTA DE JUEGO\n");
    printf("==============\n\n");
    if(juego_findEmptyPlaceJuego(pJuego,length) >= 0){
        if(!utn_getValidStringLetras(descripcion,"Descripcion: ","Error.\n","OVERFLOW.\n",51,3)){
            if(!utn_getEntero(&importe,"Importe: ","Error.\n",300,10000,3)){
                    retorno = juego_addJuego(pJuego,length, descripcion, importe);
                    flagJuego++;
                    printf("-------------\n");
                    printf("ALTA COMPLETA\n");
            }
        }
    }
    else{
        printf("No hay lugar.\n");
    }
    getch();
    return retorno;
}

int control_removeJuego(eJuego* pJuego, int length){

    int id;
    int retorno = -1;
    char respuesta;

    system("cls");
    printf("==============\n");
    printf("BAJA DE JUEGO\n");
    printf("==============\n\n");
    if(flagJuego != 0){
        retorno = utn_getEntero(&id, "ID: ", "Error. \n", 0, 20, 3);
        if(retorno == 0){
            retorno = juego_findJuegoById(pJuego,length,id);
            if(retorno >= 0){
                print1Juego(pJuego[retorno]);
                printf("Eliminar juego?: S/N\n");
                respuesta = getch();
                if(respuesta !='s'){
                    printf("Operacion cancelada.\n");
                }
                else{
                    retorno = juego_removeJuego(pJuego, length, id);
                    flagJuego--;
                    printf("--------------------------\n");
                    printf("EL JUEGO HA SIDO ELIMINADO\n");
                }
            }
            else{
                printf("ID invalido.\n");
            }
        }
    }
    else{
        printf("Primero debe cargar un juego.\n");
    }
    getch();
    return retorno;
}

int control_updateJuego(eJuego* pJuego, int length){

    char descripcion[51];
    int importe;
    int id;
    int retorno = -1;
    char respuesta;

    system("cls");
    printf("================\n");
    printf("MODIFICAR JUEGO\n");
    printf("================\n\n");
    if(flagJuego != 0){
        retorno = utn_getEntero(&id, "ID: ", "Error.\n", 0,20,3);
        if(retorno == 0){
            retorno = juego_findJuegoById(pJuego,length,id);
            if(retorno >= 0){
                print1Juego(pJuego[retorno]);
                printf("Modificar juego?: S/N\n");
                    respuesta = getch();
                    if(respuesta !='s'){
                       printf("Operacion cancelada.\n");
                    }
                    else{
                        if(!utn_getValidStringLetras(descripcion,"\nDescripcion: ","Error.\n", "OVERFLOW.\n", 51, 3))
                            if(!utn_getEntero(&importe,"Importe: ","Error. Rango de 500 a 10000.\n",500,10000, 3)){
                                retorno = juego_updateJuego(pJuego,length, descripcion, importe, id);
                                printf("---------------------------\n");
                                printf("EL JUEGO HA SIDO MODIFICADO\n");
                            }
                        }
            }
            else{
                printf("ID Invalido.\n");
            }
        }
    }
    else{
        printf("Primero debe cargar un juego.\n");
    }
    getch();
    return retorno;
}

int control_printAndSortJuego(eJuego* pJuego, int length){
    int retorno = -1;
    system("cls");
    printf("==============\n");
    printf("LISTAR JUEGOS\n");
    printf("==============\n\n");
    if(flagJuego != 0){
        retorno = juego_sortJuego(pJuego,length);
        if(retorno == 0){
            retorno = juego_printJuego(pJuego,length);
        }
    }
    else{
        printf("Primero debe cargar un juego.\n");
    }
    getch();
    return retorno;
}

int control_addAlquiler(eAlquiler* pAlquiler,int length,eCliente* pCliente,int lengthCliente,eJuego* pJuego,int lengthJuego){

    int retorno = -1;
    int idJuego;
    int idCliente;
    int dia, mes, anio;

    system("cls");
    printf("================\n");
    printf("ALTA DE ALQUILER\n");
    printf("================\n\n");

    if(flagCliente !=0 && flagJuego !=0){
        if(alquiler_findEmptyPlaceAlquiler(pAlquiler,length) >= 0){
            juego_sortJuego(pJuego,lengthJuego);
            juego_printJuego(pJuego,lengthJuego);
            utn_getEntero(&idJuego,"\nID juego: ","Error. Rango valido: 0 - 20.\n",0,20,3);
            retorno = juego_findJuegoById(pJuego,lengthJuego,idJuego);
            if( retorno >= 0){
                cliente_sortCliente(pCliente,lengthCliente);
                cliente_printCliente(pCliente,lengthCliente);
                utn_getEntero(&idCliente,"\nID cliente: ","Error. Rango valido: 0 - 200.\n",0,200,3);
                retorno = cliente_findClienteById(pCliente,lengthCliente,idCliente);
                if(retorno >= 0){
                    flagAlquiler++;
                    printf("--------------------\n");
                    printf("Fecha de alquiler\n");
                    printf("--------------------\n");
                    utn_getEntero(&dia, "Dia: ", "Error.\n", 1,31,1000);
                    utn_getEntero(&mes, "Mes: ", "Error.\n", 1,12,1000);
                    utn_getEntero(&anio, "Anio: ", "Error.\n", 2015,2018,1000);
                    retorno = alquiler_addAlquiler(pAlquiler,length,idCliente,idJuego,dia,mes,anio);
                    printf("--------------------\n");
                    printf("Alquiler completo.\n");
                }
                else{
                    printf("El cliente no existe.\n");
                }
            }
            else{
                printf("El juego no existe.\n");
            }
        }
        else{
            printf("No hay lugar.\n");
        }
    }
    else{
        printf("Primero debe cargar datos.\n");
    }
    getch();
    return retorno;
}

int control_printAlquiler(eAlquiler* pAlquiler,int length, eJuego* pJuego, int lengthJuego, eCliente* pCliente, int lengthCliente){
    int retorno;
    float auxTotal;
    float auxAvarage;
    int auxNotExceeded;
    system("cls");
    printf("=================\n");
    printf("LISTAR ALQUILERES\n");
    printf("=================\n\n");

    if(flagCliente != 0 && flagJuego != 0 && flagAlquiler != 0){
        retorno = alquiler_printAlquiler(pAlquiler,length,pJuego,lengthJuego,pCliente,lengthCliente);
        auxTotal = alquiler_totalAlquiler(pAlquiler, length, pJuego,lengthJuego);
        auxAvarage = alquiler_avarageAlquiler(pAlquiler,length,pJuego,lengthJuego);
        auxNotExceeded = alquiler_notExceededAlquiler(pAlquiler, length, pJuego,lengthJuego);
        printf("\n-------------------------------------\n");
        printf("\nTotal: %.2f\t |  Promedio: %.2f\n", auxTotal, auxAvarage);
        printf("\n-------------------------------------\n");
        printf("\nNo superan el promedio: %d\n", auxNotExceeded);
        printf("\n-------------------------------------\n");
    }
    else{
        printf("Primero debe cargar datos.\n");
    }
    getch();
    return retorno;
}

int control_printClientesXjuego(eAlquiler* pAlquiler,int lengthAlquiler,eJuego* pJuego,int lengthJuego,eCliente* pCliente,int lengthCliente){
    int retorno = -1;
    int idJuego;
    system("cls");
    printf("===========================================\n");
    printf("CLIENTES QUE ALQUILARON EL SIGUIENTE JUEGO.\n");
    printf("===========================================\n\n");
    if(flagCliente != 0 && flagJuego != 0 && flagAlquiler != 0){
        printf("\nJuegos: \n");
        juego_printJuego(pJuego,lengthJuego);
        utn_getEntero(&idJuego,"\nID de juego: ", "Error.\n",0,20,1000);
        fflush(stdin);
        retorno = juego_findJuegoById(pJuego,lengthJuego,idJuego);
        if(retorno >= 0){
            printf("\nClientes que alquilaron el juego: \n");
            retorno = alquiler_printClientesXjuego(pAlquiler,lengthAlquiler,idJuego,pCliente,lengthCliente);
            if(retorno != 0){
                printf("\nEl juego aun no ha sido alquilado.\n");
            }
        }
        else{
            printf("ID invalido.\n");
        }
    }
    else{
        printf("Primero debe cargar datos.\n");
    }
    getch();
    return retorno;
}

int control_printJuegosXcliente(eAlquiler* pAlquiler,int lengthAlquiler,eJuego* pJuego,int lengthJuego,eCliente* pCliente,int lengthCliente){
    int retorno = -1;
    int idCliente;
    system("cls");
    printf("===========================================\n");
    printf("JUEGOS ALQUILADOS POR EL SIGUIENTE CLIENTE.\n");
    printf("===========================================\n\n");
    if(flagCliente != 0 && flagJuego != 0 && flagAlquiler != 0){
        printf("\nClientes: \n");
        cliente_printCliente(pCliente,lengthCliente);
        utn_getEntero(&idCliente,"\nID de cliente: ", "Error.\n",0,200,1000);
        fflush(stdin);
        retorno = cliente_findClienteById(pCliente,lengthCliente,idCliente);
        if(retorno >= 0){
            printf("\nJuegos alquilados por el cliente ingresado: \n");
            retorno = alquiler_printJuegosXcliente(pAlquiler,lengthAlquiler,pJuego,lengthJuego,idCliente);
            if(retorno != 0){
                printf("\nEl cliente aun no ha alquilado.\n");
            }
        }
        else{
            printf("ID invalido.\n");
        }
    }
    else{
        printf("Primero debe cargar datos.\n");
    }
    getch();
    return retorno;
}

int control_clienteWithMoreAlquileres(eAlquiler* pAlquiler, int lengthAlquiler, eCliente* pCliente, int lengthCliente){
    int retorno = -1;
    system("cls");
    printf("============================\n");
    printf("CLIENTES CON MAS ALQUILERES.\n");
    printf("============================\n\n");
    if(flagCliente != 0 && flagJuego != 0 && flagAlquiler != 0){
        retorno = alquiler_clienteWithMoreAlquileres(pAlquiler,lengthAlquiler,pCliente,lengthCliente);
    }
    else{
        printf("Primero debe cargar datos.\n");
    }
    getch();
    return retorno;
}

int control_juegoWithLessAlquileres(eAlquiler* pAlquiler, int lengthAlquiler, eJuego* pJuego, int lengthJuego){
    int retorno = -1;
    system("cls");
    printf("============================\n");
    printf("JUEGOS CON MENOS ALQUILERES.\n");
    printf("============================\n\n");
    if(flagCliente != 0 && flagJuego != 0 && flagAlquiler != 0){
        retorno = alquiler_juegoWithLessAlquileres(pAlquiler,lengthAlquiler,pJuego,lengthJuego);
    }
    else{
        printf("Primero debe cargar datos.\n");
    }
    getch();
    return retorno;
}

int control_printJuegoXfecha(eAlquiler* pAlquiler, int lengthAlquiler, eCliente* pCliente, int lengthCliente, eJuego* pJuego, int lengthJuego){
    int retorno = -1;
    int dia, mes, anio;
    system("cls");
    printf("=============================\n");
    printf("ALQUILER DE JUEGOS POR FECHA.\n");
    printf("=============================\n\n");
    if(flagCliente != 0 && flagJuego != 0 && flagAlquiler != 0){
        printf("--------------------\n");
        printf("Fecha de alquiler\n");
        printf("--------------------\n");
        utn_getEntero(&dia, "Dia: ", "Error.\n", 1,31,1000);
        utn_getEntero(&mes, "Mes: ", "Error.\n", 1,12,1000);
        utn_getEntero(&anio, "Anio: ", "Error.\n", 2015,2018,1000);
        retorno = printJuegoXfecha(pAlquiler, lengthAlquiler, pJuego,lengthJuego,pCliente,lengthCliente, dia, mes, anio);
        if(retorno != 0){
            printf("\nFecha invalida.");
        }
    }
    else{
        printf("Primero debe cargar datos.\n");
    }
    getch();
    return retorno;
}

int control_printclienteXfecha(eAlquiler* pAlquiler, int lengthAlquiler, eCliente* pCliente, int lengthCliente, eJuego* pJuego, int lengthJuego){
    int retorno = -1;
    int dia, mes, anio;
    system("cls");
    printf("===============================\n");
    printf("ALQUILER DE CLIENTES POR FECHA.\n");
    printf("===============================\n\n");
    if(flagCliente != 0 && flagJuego != 0 && flagAlquiler != 0){
        printf("--------------------\n");
        printf("Fecha de alquiler\n");
        printf("--------------------\n");
        utn_getEntero(&dia, "Dia: ", "Error.\n", 1,31,1000);
        utn_getEntero(&mes, "Mes: ", "Error.\n", 1,12,1000);
        utn_getEntero(&anio, "Anio: ", "Error.\n", 2015,2018,1000);
        retorno = printClienteXfecha(pAlquiler,lengthAlquiler,pJuego,lengthJuego, pCliente,lengthCliente,dia,mes,anio);
    }
    else{
        printf("Primero debe cargar datos.\n");
    }
    getch();
    return retorno;
}

int control_bubbleSortEfficient(eJuego* pJuego, int length){
    int retorno = -1;
    system("cls");
    printf("===========================\n");
    printf("BUBBLE SORT EFFICIENT JUEGO\n");
    printf("===========================\n\n");
    if(flagJuego != 0){
        retorno = juego_bubbleSortEfficient(pJuego, length);
    }
    else{
        printf("Primero debe cargar un cliente.\n");
    }
    getch();
    return retorno;
}
int control_insertion(eCliente* pCliente, int length){
    int retorno = -1;
    system("cls");
    printf("=================\n");
    printf("INSERTION CLIENTE\n");
    printf("=================\n\n");
    if(flagCliente != 0){
        retorno = cliente_insertion(pCliente, length);
    }
    else{
        printf("Primero debe cargar un cliente.\n");
    }
    getch();
    return retorno;
}

void control_menuInformes(eAlquiler* pAlquiler, int lengthAlquiler,eJuego* pJuego,int lengthJuego,eCliente* pCliente,int lengthCliente){
    int menu=0;
    char mensajeMenu[]="\n1-Listar clientes que alquilaron un juego determinado.\
                        \n2-Listar juegos que fueron alquilados por un cliente determinado.\
                        \n3-Clientes con mas alquileres.\
                        \n4-Juegos menos alquilados.\
                        \n5-Juegos alquilados en una fecha determinada.\
                        \n6-Clientes que alquilaron juegos en una fecha determinada.\
                        \n7-Burbujeo Eficiente.\
                        \n8-Insertion.\
                        \n --------------------\
                        \n9-Regresar.\n\
                        \nOpcion: ";
    char mensajeErrorMenu[]="Opcion invalida.\n";
    system("cls");
    printf("=========\n");
    printf("INFORMES\n");
    printf("=========\n\n");
    if(flagCliente != 0 && flagJuego != 0 && flagAlquiler != 0){
        while(menu != 9){
            system("cls");
            printf("=========\n");
            printf("INFORMES\n");
            printf("=========");
            if(utn_getEntero(&menu,mensajeMenu,mensajeErrorMenu,1,9,0)==0){
                    switch(menu){
                        case 1:
                                control_printClientesXjuego(pAlquiler,lengthAlquiler,pJuego,lengthJuego,pCliente,lengthCliente);
                                break;
                        case 2:
                                control_printJuegosXcliente(pAlquiler,lengthAlquiler,pJuego,lengthJuego,pCliente,lengthCliente);
                                break;
                        case 3:
                                control_clienteWithMoreAlquileres(pAlquiler,lengthAlquiler,pCliente,lengthCliente);
                                break;
                        case 4:
                                control_juegoWithLessAlquileres(pAlquiler,lengthAlquiler,pJuego,lengthJuego);
                                break;
                        case 5:
                                control_printJuegoXfecha(pAlquiler, lengthAlquiler, pCliente, lengthCliente, pJuego,lengthJuego);
                                break;
                        case 6:
                                control_printclienteXfecha(pAlquiler, lengthAlquiler, pCliente, lengthCliente, pJuego,lengthJuego);
                                break;
                        case 7:
                                control_bubbleSortEfficient(pJuego,lengthJuego);
                                break;
                        case 8:
                                control_insertion(pCliente,lengthCliente);
                                break;
                }
            }
            else{
                continue;
            }
        }
    }
    else{
        printf("Primero debe cargar un cliente.\n");
    }
    getch();
}

void print1Juego(eJuego pJuego){
    printf("\n| %-10s | %-25s| %-3s\n","IMPORTE","DESCRIPCION","ID J");
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-10d | %-25s| %-3d\n\n", pJuego.importe, pJuego.descripcion, pJuego.idJuego);
}

void print1Cliente(eCliente pCliente){
    printf("\n| %-12s| %-12s| %-25s |%-10s | %-3s\n","APELLIDO","NOMBRE","DOMICILIO","TELEFONO","ID C");
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-12s| %-12s| %-25s |%-10s | %-3d\n\n", pCliente.nombre,pCliente.apellido,pCliente.domicilio,pCliente.telefono,pCliente.idCliente);
}
