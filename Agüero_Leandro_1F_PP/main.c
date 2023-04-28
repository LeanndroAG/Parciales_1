#include <stdio.h>
#include <stdlib.h>
#include "alquiler.h"
#include "juego.h"
#include "cliente.h"
#include "inputs.h"
#include "control.h"
#define CANTIDAD_CLIENTE 200
#define CANTIDAD_JUEGO 20
#define CANTIDAD_ALQUILER (CANTIDAD_CLIENTE * CANTIDAD_JUEGO)
int main()
{

    eCliente pCliente[CANTIDAD_CLIENTE];
    eJuego pJuego[CANTIDAD_JUEGO];
    eAlquiler pAlquiler[CANTIDAD_ALQUILER];
    int menu=0;
    char mensajeMenu[]="\n MENU\
                        \n --------------------\
                        \n 1-Alta de juego.\
                        \n 2-Baja de juego.\
                        \n 3-Modificar juego.\
                        \n 4-Listar juegos.\
                        \n --------------------\
                        \n 5-Alta de cliente.\
                        \n 6-Baja de cliente.\
                        \n 7-Modificar cliente.\
                        \n 8-Listar clientes.\
                        \n --------------------\
                        \n 9-Alta de Alquiler.\
                        \n10-Listar alquileres.\
                        \n11-Informes.\
                        \n --------------------\
                        \n12-Salir.\n\
                        \nOpcion: ";
    char mensajeErrorMenu[]="Opcion invalida.\n";

    cliente_initCliente(pCliente,CANTIDAD_CLIENTE);
    juego_initJuego(pJuego,CANTIDAD_JUEGO);
    alquiler_initAlquiler(pAlquiler,CANTIDAD_ALQUILER);
    do{
        system("cls");
        if(utn_getEntero(&menu,mensajeMenu,mensajeErrorMenu,1,12,0) == 0){
                switch(menu){
                    case 1:
                            control_addJuego(pJuego,CANTIDAD_JUEGO);
                            break;
                    case 2:
                            control_removeJuego(pJuego,CANTIDAD_JUEGO);
                            break;
                    case 3:
                            control_updateJuego(pJuego,CANTIDAD_JUEGO);
                            break;
                    case 4:
                            control_printAndSortJuego(pJuego,CANTIDAD_JUEGO);
                            break;
                    case 5:
                            control_addCliente(pCliente,CANTIDAD_CLIENTE);
                            break;
                    case 6:
                            control_removeCliente(pCliente,CANTIDAD_CLIENTE);
                            break;
                    case 7:
                            control_updateCliente(pCliente,CANTIDAD_CLIENTE);
                            break;
                    case 8:
                            control_printAndSortCliente(pCliente,CANTIDAD_CLIENTE);
                            break;
                    case 9:
                            control_addAlquiler(pAlquiler,CANTIDAD_ALQUILER,pCliente,CANTIDAD_CLIENTE,pJuego,CANTIDAD_JUEGO);
                            break;
                    case 10:
                            control_printAlquiler(pAlquiler,CANTIDAD_ALQUILER,pJuego,CANTIDAD_JUEGO,pCliente,CANTIDAD_CLIENTE);
                            break;
                    case 11:
                            control_menuInformes(pAlquiler,CANTIDAD_ALQUILER,pJuego,CANTIDAD_JUEGO,pCliente,CANTIDAD_CLIENTE);
                            break;
                }
            }
            else{
                continue;
            }
    }while(menu != 12);
    return 0;
}
