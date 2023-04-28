#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char domicilio[51];
    char telefono[21];
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int cliente_findEmptyPlaceCliente(eCliente* pCliente, int length);
int cliente_initCliente(eCliente* pCliente,int length);
int cliente_addCliente(eCliente* pCliente, int length,char* nombre,char* apellido,char* domicilio,char* telefono);
int cliente_findClienteById(eCliente* pCliente,int length,int id);
int cliente_removeCliente(eCliente* pCliente,int length,int id);
int cliente_sortCliente(eCliente* pCliente,int length);
int cliente_printCliente(eCliente* pCliente,int length);
int cliente_updateCliente(eCliente* pCliente,int length,char* nombre,char* apellido,char* domicilio,char*telefono,int id);
int cliente_insertion(eCliente* pCliente,int length);
