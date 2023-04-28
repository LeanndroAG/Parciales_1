#include "juego.h"
#include "cliente.h"
#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int idAlquiler;
    int idJuego;
    int idCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;

#endif // ALQUILER_H_INCLUDED

int alquiler_findEmptyPlaceAlquiler(eAlquiler* pAlquiler, int length);
int alquiler_initAlquiler(eAlquiler* pAlquiler,int length);
int alquiler_addAlquiler(eAlquiler* pAlquiler, int length,int idCliente,int idJuego,int dia,int mes,int anio);
int alquiler_printAlquiler(eAlquiler* pAlquiler,int length, eJuego* pJuego, int lengthJuego, eCliente* pCliente, int lengthCliente);

/******/

float alquiler_totalAlquiler(eAlquiler* pAlquiler, int lengthAlquiler,eJuego* pJuego,int lengthJuego);
float alquiler_avarageAlquiler(eAlquiler* pAlquiler, int lengthAlquiler,eJuego* pJuego,int lengthJuego);
int alquiler_notExceededAlquiler(eAlquiler* pAlquiler, int lengthAlquiler,eJuego* pJuego,int lengthJuego);

/******/

int alquiler_printClientesXjuego(eAlquiler* pAlquiler, int lengthAlquiler, int idJuego, eCliente* pCliente, int lengthCliente);
int alquiler_printJuegosXcliente(eAlquiler* pAlquiler, int lengthAlquiler, eJuego* pJuego, int lengthJuego, int idCliente);

/******/

int alquiler_clienteWithMoreAlquileres(eAlquiler* pAlquiler, int lengthAlquiler ,eCliente* pCliente, int lengthCliente);
int alquiler_juegoWithLessAlquileres(eAlquiler* pAlquiler, int lengthAlquiler ,eJuego* pJuego, int lengthJuego);

/*******/
int printJuegoXfecha(eAlquiler* pAlquiler, int lengthAlquiler, eJuego* pJuego, int lengthJuego, eCliente* pCliente, int lengthCliente, int dia, int mes, int anio);
int printClienteXfecha(eAlquiler* pAlquiler, int lengthAlquiler, eJuego* pJuego, int lengthJuego, eCliente* pCliente, int lengthCliente, int dia, int mes, int anio);
