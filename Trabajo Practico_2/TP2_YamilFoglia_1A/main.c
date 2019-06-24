#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    int flag = 1;
    int contador = 0;
    int flag2 = 0;
    eEmpleado emp[TAM];

    inicializarPrograma(emp, TAM);

    while(flag == 1)
    {
        switch(menu())
        {
            case 1:

                contador = altasDeEmpleados(emp, contador, TAM);
                flag2 = 1;
                break;

            case 2:

                if(flag2==1)
                modificarDatos(emp, TAM);
                else
                {
                    printf("Debe ingresar un empleado antes.\n");
                    pause();
                }
                break;

            case 3:
                if(flag2==1)
                bajaDeEmpleado(emp, TAM);
                else
                {
                    printf("Debe ingresar un empleado antes.\n");
                    pause();
                }
                break;

            case 4:
                if(flag2==1)
                ordenarEmpleados(emp, TAM);
                else
                {
                    printf("Debe ingresar un empleado antes.\n");
                    pause();
                }

                break;

            case 5:

                flag = close();
                break;
        }
    }

    return 0;
}


