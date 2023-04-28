#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int seguir = 's';
    int controllerFromText = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char nombreArchivo[50];

    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(controllerFromText == 0){
                getValidStringEntrada("\nNombre del archivo: ", "\nError. Reintente", nombreArchivo);
                if(controller_loadFromText(nombreArchivo, listaEmpleados)==0){
                    controllerFromText = 1;
                }
            }
            else{
                if(controllerFromText == 1){
                    printf("\nLa lista ya fue cargada en modo texto.\n\n");
                }
            }
            system("pause");
            break;
        case 2:
            if(controllerFromText == 1){
                controller_ListEmployee(listaEmpleados);
            }
            else{
                printf("\nNo se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 3:
            if(controllerFromText == 1){
                controller_sueldos(listaEmpleados);
            }
            else{
                printf("\nNo se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 4:
            if(controllerFromText == 1){

                controller_ListEmployeeSueldo(listaEmpleados);
            }
            else{
                printf("\nNo se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 5:
            if(controllerFromText == 1){
                controller_saveAsText("info.csv",listaEmpleados);
                controller_saveAsBinary("info.dat",listaEmpleados);
            }
            else{
                printf("\nNo se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 6:
            if(controllerFromText == 1){
                  controller_freeLinkedList(listaEmpleados);
            }
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta, reintente.\n\n");
            system("pause");
            system("cls");
        }
    }
    while(seguir == 's');
    return 0;
}
