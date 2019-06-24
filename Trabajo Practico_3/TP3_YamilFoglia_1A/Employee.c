#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new()
{

    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)//sueldo agregado
{

    Employee* nuevoEmpleado = employee_new();
    int todoOk = 0;

    if(nuevoEmpleado != NULL)
    {
        if(employee_setId(nuevoEmpleado, atoi(idStr)) == 1)
        {
            if(employee_setNombre(nuevoEmpleado, nombreStr) == 1)
            {
                if(employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr)) == 1)
                {
                    if(employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)) == 1)
                    {
                            todoOk = 1;
                    }
                }
            }
        }
        if(todoOk == 0)
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if(sueldo > 0 && sueldo < 100000)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }

    return todoOk;
}


int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;

}

int employee_setNombre(Employee* this,char* nombre)
{
    int error=1;
    int i=0;
    while(nombre[i]!='\0')
    {
        if(nombre[i]!=' ')
        {
            if(nombre[i]<'a'||nombre[i]>'z')
            {
                if(nombre[i]<'A'||nombre[i]>'Z')
                {
                    if(nombre[i]!='-')
                    {
                        error=0;
                        break;
                    }
                }
            }
        }
        i++;
    }
    if(error==1)
    {
        strcpy(this->nombre,nombre);
    }

    return error;
}







