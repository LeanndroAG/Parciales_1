#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

int utn_getEntero(int* input, char* mensaje, char* eMensaje, int min, int max, int reIntentos);
int utn_getCaracter(char* pCaracter, char* mensaje, char* eMensaje, int min, int max, int reIntentos);

int utn_esSoloLetras(char* str);
int utn_esNumerico(char* str);
int utn_esAlfaNumero(char* str);

void utn_getString(char* input,char* mensaje);
int utn_getStringLetras(char* input,char* mensaje);
int utn_getStringNumeros(char* input,char* mensaje);
int utn_getStringAlfaNumericos(char* input,char* mensaje);

int utn_getValidStringLetras(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos);
int utn_getValidStringNumeros(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos);
int utn_getValidStringAlfaNumericos(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos);

#endif // INPUTS_H_INCLUDED


