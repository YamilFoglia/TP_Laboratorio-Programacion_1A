#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    //bienvenida();

    do{
        switch(opcion())
        {
            case 1:

                if(!ll_len(listaEmpleados) > 0)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    limpiarPantalla();
                    printf("\n\n\nSe cargo un total de %d empleados en texto\n\n\n\n", ll_len(listaEmpleados));
                }
                else
                {
                    limpiarPantalla();
                    printf("\n\nEl listado de empleados ya se encuentra cargado\n\n");
                }
                pausa();
                limpiarPantalla();
                break;

            case 2:

                if(!ll_len(listaEmpleados) > 0)
                {
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    limpiarPantalla();
                    printf("\n\n\nSe cargo un total de %d empleados en binario \n\n\n\n", ll_len(listaEmpleados));
                }
                else
                {
                    limpiarPantalla();
                    printf("\n\nEl listado de empleados ya se encuentra cargado\n\n");
                }
                pausa();
                limpiarPantalla();
                break;

            case 3:

                controller_addEmployee(listaEmpleados);
                break;

            case 4:

                controller_editEmployee(listaEmpleados);
                break;

            case 5:

                controller_removeEmployee(listaEmpleados);
                break;

            case 6:

                controller_ListEmployee(listaEmpleados);
                break;

            case 7:

                controller_sortEmployee(listaEmpleados);
                break;

            case 8:

                controller_saveAsText("data.csv",listaEmpleados);
                break;

            case 9:

                controller_saveAsBinary("data.bin",listaEmpleados);
                break;

            case 10:

                option = close();
                break;
        }
    }while(option);
    return 0;
}
