#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* archivo;

    archivo = fopen(path, "r");

    if(archivo == NULL)
    {
        printf("No se pudo leer el archivo !");
    }
    else
    {
        parser_EmployeeFromText(archivo, pArrayListEmployee);
    }
    fclose(archivo);


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* archivo;

    archivo = fopen(path, "rb");

    if(archivo == NULL)
    {
        printf("No se pudo leer el archivo !");

    }
    else
    {
        parser_EmployeeFromBinary(archivo, pArrayListEmployee);
    }

    fclose(archivo);

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp;
    Employee* empAux;

    char auxId[20];
    char auxNombre[25];
    char auxHorasTrbajadas[25];
    char auxSueldo[25];
    int tam;
    int idAutomatico;
    int error;
    int i;
    int flag = 1;
    int id;
    int UltimoEmpleado;

    emp = employee_new();
    limpiarPantalla();
    do
    {
        //printf("\nId: %d", idAutomatico);
        idAutomatico = obtenerIdMasGrande(pArrayListEmployee);
        sprintf(auxId, "%d", idAutomatico);

        printf("\nNombre: ");
        limpiarBuffer();
        gets(auxNombre);

        printf("\nHoras Trabajadas: ");
        limpiarBuffer();
        gets(auxHorasTrbajadas);

        printf("\nSueldo: ");
        limpiarBuffer();
        gets(auxSueldo);

        emp = employee_newParametros(auxId, auxNombre, auxHorasTrbajadas,  auxSueldo);

        if(emp == NULL)
        {
            printf("\n Algun dato ingresado en el alta de de empleados fue erroneo.\n\n\n\n");
            error = 1;
            pausa();
            limpiarPantalla();
        }
        else
        {
            ll_add(pArrayListEmployee, emp);
            printf("\n\n Alta Exitosa !!!\n\n\n");
            error = 0;
            pausa();
            limpiarPantalla();
        }
    }while(error);
    pausa();
    limpiarPantalla();

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idBuscada;
    int opcion;
    int posicion = -1;
    int tam;
    int i;

    Employee* emp;
    int auxEntero;
    char auxCadena[50];
    int validacion;

    limpiarPantalla();
    printf("\nIngrese el id del empleado que quiere modificar: ");
    scanf("%d", &idBuscada);

    tam = ll_len(pArrayListEmployee);

    for(i=0; i<tam; i++)
    {
        emp = ll_get(pArrayListEmployee, i);

        if(emp->id == idBuscada)
        {
            posicion = i;
            break;
        }
    }

    emp = ll_get(pArrayListEmployee, posicion);

    if(posicion != -1)
    {
        printf("\n\n\nID   NOMBRE    HORAS TRABAJADAS    SUELDO\n\n");
        printf("%d   %s          %d             %d\n\n\n\n",emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);

        pausa();
        limpiarPantalla();

        printf("\n1-Id");
        printf("\n2-Nombre");
        printf("\n3-Horas Trabajadas");
        printf("\n4-Sueldo");
        printf("\n5-Salir");
        printf("\n\n\n\nIngrese que opcion quiere modificar:");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\nId: ");
                scanf("%d", &auxEntero);
                validacion = employee_setId(emp, auxEntero);
                while(validacion == 0)
                {
                    printf("\nERROR - Reingrese Id: ");
                    scanf("%d", &auxEntero);
                    validacion = employee_setId(emp, auxEntero);
                }
                emp->id = auxEntero;
                break;

            case 2:
                printf("\nNombre: ");
                limpiarBuffer();
                gets(auxCadena);
                validacion = employee_setNombre(emp, auxCadena);
                while(validacion == 0)
                {
                    printf("\nERROR - Reingrese Nombre: ");
                    gets(auxCadena);
                    validacion = employee_setNombre(emp, auxCadena);
                }
                strcpy(emp->nombre, auxCadena);
                break;

            case 3:
                printf("\nHoras Trabajadas: ");
                scanf("%d",&auxEntero);
                validacion = employee_setHorasTrabajadas(emp, auxEntero);
                while(validacion == 0)
                {
                    printf("\nERROR - Reingrese Horas Trabajadas: ");
                    scanf("%d", &auxEntero);
                    validacion = employee_setHorasTrabajadas(emp, auxEntero);
                }
                emp->horasTrabajadas = auxEntero;
                break;
            case 4:
                printf("\nSueldo: ");
                scanf("%d", &auxEntero);
                validacion = employee_setSueldo(emp, auxEntero);
                while(validacion == 0)
                {
                    printf("\nERROR - Reingrese Sueldo: ");
                    scanf("%d", &auxEntero);
                    validacion = employee_setSueldo(emp, auxEntero);
                }
                emp->sueldo = auxEntero;
                break;

            case 5:
                break;

            default:
                defaultError();
                break;
        }
        limpiarPantalla();
        if(opcion < 5)
        {
            printf("\n\nEmpleado modificado\n\n");
            printf("\n\n\nID   NOMBRE    HORAS TRABAJADAS    SUELDO\n\n");
            printf("%d   %s          %d             %d\n\n\n\n",emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
            pausa();
        }
    }
    else
    {
        printf("\n\n\nEl id Ingresado no se encuentra actualmente en uso\n\n\n\n");
        pausa();
    }
    limpiarPantalla();
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int idBuscada;
    int indexAEliminar = -1;
    char respuesta;
    int tam;
    int i;
    Employee* emp;

    limpiarPantalla();
    printf("\nIngrese el id del empleado que quiere dar de baja: ");
    scanf("%d", &idBuscada);

    tam = ll_len(pArrayListEmployee);

    for(i=0; i<tam; i++)
    {
        emp = ll_get(pArrayListEmployee, i);

        if(emp->id == idBuscada)
        {
            indexAEliminar = i;
            break;
        }
    }

    if(indexAEliminar != -1)
        emp = ll_get(pArrayListEmployee, indexAEliminar);
    else
    {
        limpiarPantalla();
        printf("\n\n\tNo se encontro el empleado.\n\n");
        pausa();
        return -1;
    }

    printf("\n\n\nID   NOMBRE    HORAS TRABAJADAS    SUELDO\n\n");
    printf("%d   %s          %d             %d\n\n\n\n",emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);

    printf("\n________________________________________________________________________________\n");
    printf("\n       En pantalla se encuentra el empleado que se va a dar de baja\n");
    printf("\n________________________________________________________________________________\n\n\n\n\n");

    printf("\nEsta seguro que desea dar de baja esta empleado ? [s/n]\n");
    limpiarBuffer();
    scanf("%c", &respuesta);
    tolower(respuesta);

    while(!(respuesta == 's' || respuesta == 'n'))
    {
        printf("\nERROR -Caracter incorrecto - desea dar de baja esta empleado ? [s/n]\n");
        limpiarBuffer();
        scanf("%c", &respuesta);
    }

    if(respuesta == 's')
    {
        ll_remove(pArrayListEmployee, indexAEliminar);
        printf("\n\nBaja exitosa !!\n\n\n\n");
        pausa();
    }

    limpiarPantalla();

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int tam;
    int contador = 0;
    Employee* emp;

    limpiarPantalla();
    tam = ll_len(pArrayListEmployee);

    printf("\n\n       ID          NOMBRE      HORAS TRABAJADAS          SUELDO\n\n");
    for(i=0; i<tam; i++)
    {
        emp = ll_get(pArrayListEmployee, i);
        printf("%10d   %10s          %5d             %10d\n",emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
        contador++;
        if(contador == 250)
        {
            contador = 0;
            pausa();
            limpiarPantalla();
            printf("\n\n       ID          NOMBRE      HORAS TRABAJADAS          SUELDO\n\n");
        }
    }

    pausa();
    limpiarPantalla();
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion = -1;
    int opIncorrecta = 0;
    int criterio = -1;

    do
    {
        limpiarPantalla();
        printf("\t\t---------- ORDENAR EMPLEADOS -----------\n");
        if(opIncorrecta == 1)
                printf("\nOPCION INCORRECTA!\n\n");
        printf("\n1- ID\n2- Nombre\n3- Horas trabajadas\n4- Sueldo\n");
        printf("\nSeleccione por que campo desea ordenar: ");
        scanf("%d", &opcion);
        opIncorrecta = 1;
    }
    while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);

    opIncorrecta = 0;

    do
    {
        limpiarPantalla();
        printf("\t\t---------- ORDENAR EMPLEADOS -----------\n");
        if(opIncorrecta == 1)
                printf("\nOPCION INCORRECTA!\n\n");
        printf("\n1- Ascendente\n2- Descendente\n");
        printf("\nSeleccione que criterio de ordamiento desea utilizar: ");
        scanf("%d", &criterio);
        opIncorrecta = 1;
    }
    while(criterio != 1 && criterio != 2);

    if(criterio == 2)
        criterio = 0;
    printf("\n\nEspere por favor...");

    switch(opcion)
    {
        case 1:
            ll_sort(pArrayListEmployee, compararPorID, criterio);
            break;

        case 2:
            ll_sort(pArrayListEmployee, compararPorNombre, criterio);
            break;

        case 3:
            ll_sort(pArrayListEmployee, compararPorHorasTrabajadas, criterio);
            break;

        case 4:
            ll_sort(pArrayListEmployee, compararPorSueldo, criterio);
            break;
    }

    limpiarPantalla();
    printf("\n\t\t* EMPLEADOS ORDENADOS!\n\n\n");
    pausa();
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *archivo;
    Employee* emp;
    limpiarPantalla();

    int con;

    archivo = fopen(path, "w");

    if(archivo == NULL)
    {
        printf("No se pudo escribir el archivo.");
    }

    con = ll_len(pArrayListEmployee);
    fprintf(archivo,"ID,NOMBRE,HORAS TRABAJADS,SUELDO\n");
    for(int i=0; i<con; i++)
    {
        emp = ll_get(pArrayListEmployee, i);
        fprintf(archivo,"%d,%s,%d,%d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }

    fclose(archivo);

    printf("\n\n\nSe guardo un total de %d empleados en texto \n\n\n\n", ll_len(pArrayListEmployee));
    pausa();
    limpiarPantalla();

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *archivo;
    Employee* emp;
    limpiarPantalla();
    int con;

    archivo = fopen(path, "wb");

    if(archivo == NULL)
    {
        printf("No se pudo escribir el archivo.");
    }

    con = ll_len(pArrayListEmployee);

    for(int i=0; i<con; i++)
    {
        emp = ll_get(pArrayListEmployee, i);
        fwrite(emp, sizeof(Employee), 1, archivo);
    }

    fclose(archivo);

    printf("\n\n\nSe guardo un total de %d empleados en binario \n\n\n\n", ll_len(pArrayListEmployee));
    pausa();
    limpiarPantalla();

    return 1;
}

