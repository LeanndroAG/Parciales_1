#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include <conio.h>

int menuPrincipal()
{
    system("cls");
    int opcion;
    printf("-- MENU-- \n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Mostrar empleados cargados.\n");
    printf("3. Calcular sueldos con funcion map.\n");
    printf("4. Mostrar empleados con sueldo.\n");
    printf("5. Almacenar archivo \"info.csv\" y \"info.dat\" con sueldos.\n\n");
    printf("6. Salir\n\n");
    opcion = getValidInt("Ingrese opcion: ", "Error de ingreso, reintente.\n");
    return opcion;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *  \param path char*
 *  \param pArrayListEmployee LinkedList*
 *  \return int
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    if((pArchivo = fopen(path, "r")) != NULL){
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
        retorno = 0;
    }
    else{
        printf("\n - Archivo: \"%s\" no encontrado.\n\n", path);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    if((pArchivo = fopen(path, "rb")) != NULL){
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
    }
    else{
        if((pArchivo = fopen(path, "wb")) != NULL){
            printf("\n - Archivo inexistente. Se creo uno con el nombre \"%s\"\n\n", path);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *  \param pArrayListEmployee LinkedList*
 *  \return int retorno 0 ok
 */
 /*
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i;
    Employee* this;
    system("cls");
    printf(" -- LISTA DE EMPLEADOS --\n\n");
    printf("      ID |      Nombre  | Hs. Trabajadas\n\n");
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee, i);
        employee_printData(this);
        retorno = 1;
    }
    printf("\n");
    return retorno;
} */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* this;
    system("cls");
    printf(" -- LISTA DE EMPLEADOS --\n\n");
    if(pArrayListEmployee != NULL){
        for(i = 0; i < ll_len(pArrayListEmployee); i++){
            if(i%50 == 0){
                printf("PRESIONE CUALQUIER TECLA PARA IMPRIMIR DE A 100 EMPLEADOS\n");
                getch();
                this = (Employee*)ll_get(pArrayListEmployee,i);
                employee_printData(this);
                retorno = 0;
            }
           else{
                this = ll_get(pArrayListEmployee,i);
                employee_printData(this);
            }
        }
    }
    printf("\n");
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *  \param path char*
 *  \param pArrayListEmployee LinkedList*
 *  \return int
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* this;
    int retorno = -1;
    int i;
    char nombre[51];
    int id;
    int horasTrabajadas;
    float sueldo;
    pArchivo = fopen(path, "w");
    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        rewind(pArchivo);
        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(this,&id);
            employee_getNombre(this, nombre);
            employee_getHorasTrabajadas(this, &horasTrabajadas);
            employee_getSueldo(this, &sueldo);
            fprintf(pArchivo, "%d,%s,%d,%.2f\n", id, nombre, horasTrabajadas, sueldo);
        }
        printf("\n - Archivo guardado.\n\n");
        retorno = 0;

    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    int lecturas;
    int i;
    pArchivo = fopen(path, "wb");
    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        rewind(pArchivo);
        for(i=0; i<ll_len(pArrayListEmployee); i++){
            Employee* this = (Employee*)ll_get(pArrayListEmployee,i);
            lecturas = fwrite(this, sizeof(Employee), 1, pArchivo);
            retorno = 0;
            if(lecturas != 1){
                printf("\nError.\n");
            }
        }
        printf("\n - Archivo guardado.\n\n");
    }
    else{
        printf("\nNo se pudo acceder al archivo.\n");
    }
    fclose(pArchivo);
    return retorno;
}

int controller_freeLinkedList(LinkedList* pArrayListEmployee){
    int retorno = -1;
    int i;
    if(pArrayListEmployee != NULL){
        for(i=0; i<ll_len(pArrayListEmployee); i++){
            ll_remove(pArrayListEmployee, i);
        }
        ll_deleteLinkedList(pArrayListEmployee);
        retorno = 0;
    }
    printf("\n  - Lista eliminada.\n");
    return retorno;
}

void controller_sueldos(LinkedList* pArrayListEmployee){
    if(ll_map(pArrayListEmployee, em_calcularSueldo) == -1){
        printf("\n  - Error al calcular sueldos.\n\n");
    }
    else{
        printf("\n  - Se calcularon los sueldos correctamente.\n\n");
    }
}

/** \brief Listar empleados con suledo cargado
 *  \param pArrayListEmployee LinkedList*
 *  \return int
 */
/*
int controller_ListEmployeeSueldo(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i;
    Employee* this;

    system("cls");
    printf(" -- LISTA DE EMPLEADOS --\n\n");
    printf("      ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
    for(i=0; i<ll_len(pArrayListEmployee); i++) {
        this = (Employee*)ll_get(pArrayListEmployee, i);
        employee_printDataSueldo(this);
        retorno = 1;
    }
    printf("\n");
    return retorno;
}*/

int controller_ListEmployeeSueldo(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* this;

    system("cls");
    printf(" -- LISTA DE EMPLEADOS --\n\n");
    if(pArrayListEmployee != NULL){
        for(i = 0; i < ll_len(pArrayListEmployee); i++){
            if(i%100 == 0){
                printf("PRESIONE CUALQUIER TECLA PARA IMPRIMIR DE A 100 EMPLEADOS\n");
                getch();
                this = (Employee*)ll_get(pArrayListEmployee,i);
                employee_printDataSueldo(this);
                retorno = 0;
            }
           else{
                this = ll_get(pArrayListEmployee,i);
                employee_printDataSueldo(this);
            }
        }
    }
    printf("\n");
    return retorno;
}
