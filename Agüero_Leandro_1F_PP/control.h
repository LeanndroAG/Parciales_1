#include "cliente.h"
#include "juego.h"
#include "alquiler.h"

#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

int control_addCliente(eCliente* pCliente, int length);
int control_removeCliente(eCliente* pCliente, int length);
int control_updateCliente(eCliente* pCliente, int length);
int control_printAndSortCliente(eCliente* pCliente, int length);

int control_addJuego(eJuego* pJuego, int length);
int control_removeJuego(eJuego* pJuego, int length);
int control_updateJuego(eJuego* pJuego, int length);
int control_printAndSortJuego(eJuego* pJuego, int length);

int control_addAlquiler(eAlquiler* pAlquiler,int length,eCliente* pCliente,int lengthCliente,eJuego* pJuego,int lengthJuego);
int control_printAlquiler(eAlquiler* pAlquiler,int length, eJuego* pJuego, int lengthJuego, eCliente* pCliente, int lengthCliente);

int control_printClientesXjuego(eAlquiler* pAlquiler,int lengthAlquiler,eJuego* pJuego,int lengthJuego,eCliente* pCliente,int lengthCliente);
int control_printJuegosXcliente(eAlquiler* pAlquiler,int lengthAlquiler,eJuego* pJuego,int lengthJuego,eCliente* pCliente,int lengthCliente);

int control_clienteWithMoreAlquileres(eAlquiler* pAlquiler, int lengthAlquiler, eCliente* pCliente, int lengthCliente);
int control_juegoWithLessAlquileres(eAlquiler* pAlquiler, int lengthAlquiler, eJuego* pJuego, int lengthJuego);

int control_printJuegoXfecha(eAlquiler* pAlquiler, int lengthAlquiler, eCliente* pCliente, int lengthCliente, eJuego* pJuego, int lengthJuego);
int control_printclienteXfecha(eAlquiler* pAlquiler, int lengthAlquiler, eCliente* pCliente, int lengthCliente, eJuego* pJuego, int lengthJuego);

int control_insertion(eCliente* pCliente, int length);
int control_bubbleSortEfficient(eJuego* pJuego, int length);

void control_menuInformes(eAlquiler* pAlquiler, int lengthAlquiler,eJuego* pJuego,int lengthJuego,eCliente* pCliente,int lengthCliente);

void print1Juego(eJuego pJuego);
void print1Cliente(eCliente pCliente);

#endif // CONTROL_H_INCLUDED

