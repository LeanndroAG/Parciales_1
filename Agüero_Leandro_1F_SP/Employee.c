#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* this = malloc(sizeof(Employee));
    if(this == NULL){
        printf("No hay lugar para crear nuevo empleado.\n");
        exit(EXIT_FAILURE);
    }
    else{
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

Employee* employee_newParametros(char* id, char* nombre, char* horasTrabajadas){
    int idAux,horasTrabajadasAux;
    Employee* this = employee_new();
    idAux = atoi(id);
    horasTrabajadasAux = atoi(horasTrabajadas);

    if(this != NULL){
        employee_setId(this,idAux);
        employee_setNombre(this, nombre);
        employee_setHorasTrabajadas(this, horasTrabajadasAux);
    }
    return this;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno=1;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this != NULL && strlen(nombre) > 0){
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno=1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        *sueldo = this->sueldo;
        retorno=1;
    }
    return retorno;
}

void employee_printData(Employee* this)
{
    int id;
    char nombre[51];
    int horasTrabajadas;
    employee_getId(this, &id);
    employee_getNombre(this, nombre);
    employee_getHorasTrabajadas(this, &horasTrabajadas);
    printf("Id: %5d | Nombre: %10s | Horas trabajadas: %5d |\n", id, nombre, horasTrabajadas);
}

void employee_printDataSueldo(Employee* this)
{
    int id;
    char nombre[51];
    int horasTrabajadas;
    float sueldo;
    employee_getId(this, &id);
    employee_getNombre(this, nombre);
    employee_getHorasTrabajadas(this, &horasTrabajadas);
    employee_getSueldo(this, &sueldo);
    printf("Id: %5d | Nombre: %10s | Horas trabajadas: %5d | Sueldo: $%.2f\n", id, nombre, horasTrabajadas, sueldo);
}

int employee_ControlId(LinkedList* pArrayListEmployee, char* idStr)
{
    int retorno = 0;
    int id;
    int i;
    id = atoi(idStr);
    Employee* this;
    if(pArrayListEmployee != NULL){
        for(i=0; i<ll_len(pArrayListEmployee); i++){
            this = (Employee*)ll_get(pArrayListEmployee, i);
            if(this->id == id){
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

void em_calcularSueldo(void* p)
{
    Employee* empleado = NULL;
    float sueldo = 0;
    int horasTrabajadas;
    if(empleado == NULL){
        empleado = (Employee*) p;
        if(employee_getHorasTrabajadas(empleado, &horasTrabajadas) != 1){
            printf("Error.\n");
        }
        if(horasTrabajadas <= 176){
            sueldo = horasTrabajadas * 180;
        }
        else if(horasTrabajadas >= 177 && horasTrabajadas <= 208)
        {
            sueldo = horasTrabajadas * 270;
        }
        else if(horasTrabajadas >= 209 && horasTrabajadas <= 240)
        {
            sueldo = horasTrabajadas * 360;
        }
        //setear
        employee_setSueldo(empleado, sueldo);
    }
}
