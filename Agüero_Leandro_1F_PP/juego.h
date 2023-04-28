#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct{
    int idJuego;
    char descripcion[51];
    int importe;
    int isEmpty;
}eJuego;

#endif // JUEGO_H_INCLUDED

int juego_findEmptyPlaceJuego(eJuego* pJuego, int length);
int juego_initJuego(eJuego* pJuego,int length);
int juego_addJuego(eJuego* pJuego, int length,char* descripcion, int importe);
int juego_findJuegoById(eJuego* pJuego,int length,int id);
int juego_removeJuego(eJuego* pJuego,int length,int id);
int juego_sortJuego(eJuego* pJuego,int length);
int juego_printJuego(eJuego* pJuego,int length);
int juego_updateJuego(eJuego* pJuego, int length,char* descripcion, int importe, int id);
int juego_bubbleSortEfficient(eJuego* pJuego, int lengthJuego);



