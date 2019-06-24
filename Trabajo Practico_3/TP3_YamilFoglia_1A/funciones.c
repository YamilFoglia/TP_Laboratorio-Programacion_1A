#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"


void limpiarBuffer()
{
    fflush(stdin);
}
void limpiarPantalla()
{
    system("cls");
}
void pausa()
{
    system("pause");
}

void defaultError()
{
    limpiarPantalla();
    printf("\n\nOpcion incorrecta\n\n");
    pausa();
    limpiarPantalla();
}

void bienvenida()
{
    printf("\n\n\n________________________________________________________________________________\n");
    printf("\n\n\n                        Programacion-Laboratorio - TP3 \n\n");
    printf("                          Foglia Yamil - Division 'A' \n\n\n\n");
    printf("________________________________________________________________________________\n\n\n\n\n");
    pausa();
    limpiarPantalla();
}

void menu()
{
    limpiarPantalla();
    printf("\n\n                              Menu de Opciones\n\n");
    printf("________________________________________________________________________________\n\n");
    printf("\n1) Load From Text");
    printf("\n2) Load From Binary");
    printf("\n3) Add Employee");
    printf("\n4) Edit Employee");
    printf("\n5) Remove Employee");
    printf("\n6) List Employee");
    printf("\n7) Sort Employee");
    printf("\n8) Save As Text");
    printf("\n9) Save As Binary");
    printf("\n10) Close");
}

int opcion()
{
    int opcion;
    menu();
    printf("\n\n\nIngrese la opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int close()
{
    return 0;
}

int compararPorID(void* empleado1, void* empleado2)
{
    int respuesta = -2;

    if(empleado1 !=NULL && empleado2 !=NULL)
    {
        if(((Employee*)empleado1)->id > ((Employee*)empleado2)->id)
            respuesta = 1;

        else if(((Employee*)empleado1)->id == ((Employee*)empleado2)->id)
            respuesta = 0;

        else if(((Employee*)empleado1)->id < ((Employee*)empleado2)->id)
            respuesta = -1;
    }

    return respuesta;
}

int compararPorHorasTrabajadas(void* empleado1, void* empleado2)
{
    int respuesta = -2;

    if(empleado1 !=NULL && empleado2 !=NULL)
    {
        if(((Employee*)empleado1)->horasTrabajadas > ((Employee*)empleado2)->horasTrabajadas)
            respuesta = 1;

        else if(((Employee*)empleado1)->horasTrabajadas == ((Employee*)empleado2)->horasTrabajadas)
            respuesta = 0;

        else if(((Employee*)empleado1)->horasTrabajadas < ((Employee*)empleado2)->horasTrabajadas)
            respuesta = -1;
    }

    return respuesta;
}

int compararPorSueldo(void* empleado1, void* empleado2)
{
    int respuesta = -2;

    if(empleado1 !=NULL && empleado2 !=NULL)
    {
        if(((Employee*)empleado1)->sueldo > ((Employee*)empleado2)->sueldo)
            respuesta = 1;

        else if(((Employee*)empleado1)->sueldo == ((Employee*)empleado2)->sueldo)
            respuesta = 0;

        else if(((Employee*)empleado1)->sueldo < ((Employee*)empleado2)->sueldo)
            respuesta = -1;
    }

    return respuesta;
}

int compararPorNombre(void* empleado1, void* empleado2)
{
    int respuesta = -2;

    if(empleado1 !=NULL && empleado2 !=NULL)
    {
        if(strcmpi(((Employee*)empleado1)->nombre, ((Employee*)empleado2)->nombre) == 1)
            respuesta = 1;

        else if(strcmpi(((Employee*)empleado1)->nombre, ((Employee*)empleado2)->nombre) == 0)
            respuesta = 0;

        else if(strcmpi(((Employee*)empleado1)->nombre, ((Employee*)empleado2)->nombre) == -1)
            respuesta = -1;
    }

    return respuesta;
}

int obtenerIdMasGrande(LinkedList* lista)
{
    int cantidad = ll_len(lista);
    int i;
    int idMayor = 0;
    Employee* aux;

    for(i=0;i<cantidad;i++)
    {
        aux = ll_get(lista, i);
        if(aux->id > idMayor)
            idMayor = aux->id;
    }

    return idMayor+1;
}
