#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char id[20];
    char nombre[25];
    char horasTrabajadas[25];
    char sueldo[25];

    Employee* emp;

    int error = 0;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

    while(!(feof(pFile)))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
        emp = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
        ll_add(pArrayListEmployee ,emp);
    }

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cant;

    while(!(feof(pFile)))
    {
        Employee* emp = employee_new();
        cant = fread(emp, sizeof(Employee),1 , pFile);
        if(cant!=1)
            if(feof(pFile))
                break;
            else
                printf("\nSe produjo un error al cargar los empleados\n");

        ll_add(pArrayListEmployee, emp);
    }

    return 1;
}
