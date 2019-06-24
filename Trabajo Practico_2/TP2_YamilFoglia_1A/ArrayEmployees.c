#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"



/************************************Opciones del Trabajo practico*********************************************/



int cantidadDeEmpleadosDadosDeALta(eEmpleado vec[], int tam)
{
    int contador=0;
    for (int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            contador++;
        }
    }

    return contador;
}
float promedioDeSalarios(int contador, float acumulador)
{
    float promedio;

    promedio = acumulador/contador;

    return promedio;
}
float totalDeSalarios(eEmpleado vec[], int tam)
{
    float acumulador = 0;

    for (int i=0; i<tam; i++)
    {
        if (vec[i].isEmpty==0)
        {
            acumulador = acumulador + vec[i].salary;

        }

    }

    return acumulador;
}
void inicializarPrograma(eEmpleado vec[],int tam)
{


    for(int i=0; i<tam; i++ ){

        vec[i].isEmpty = 1;
        vec[i].id = -1;

    }
}
int buscarPosicionLibre(eEmpleado vec[], int tam)
{
    int i;
    int posicionLibre;

    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            posicionLibre = i;
            break;
        }
    }

    return posicionLibre;
}
int buscarPosicionDelEmpleado(eEmpleado vec[], int tam, int idIngresado)
{
    int posicionDelEmpleado = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(vec[i].id == idIngresado)
        {
            posicionDelEmpleado = i;
            break;
        }
    }

    return posicionDelEmpleado;
}
int altasDeEmpleados(eEmpleado vec[], int contador, int tam)
{
    int contadorDeId;
    int i;

    i = buscarPosicionLibre(vec, tam);

    encabezadoDeAltas();

    vec[i].id = contador+1;
    vec[i].isEmpty = 0;
    limpiarBuffer();

    printf("\nNombre: ");
    gets(vec[i].name);
    limpiarBuffer();

    printf("\nApellido: ");
    gets(vec[i].lastName);
    limpiarBuffer();

    printf("\nSalario: ");
    scanf("%f", &vec[i].salary);
    limpiarBuffer();

    printf("\nSector: ");
    scanf("%d", &vec[i].sector);
    limpiarBuffer();

    contadorDeId = incrementadorDelContador(contador);

    encabezadoDeAltasDeId(contador+1);

    encabezadoDeAltaExitosa();

    return contadorDeId;
}
void modificarDatos(eEmpleado vec[], int tam)
{
    int idIngresado;
    int posicionDelEmpelado;

    printf("\n\n Ingrese el id que quiera modificar:  ");
    scanf("%d", &idIngresado);

    posicionDelEmpelado = buscarPosicionDelEmpleado(vec, tam, idIngresado);

    if(posicionDelEmpelado == -1)
    {
        encabezadoDeIdSinUso();
    }
    else
    {
        mostrarEmpleado(vec, idIngresado, posicionDelEmpelado);

        encabezadoDeModificacion(posicionDelEmpelado);

        switch(menuDeModificacion())
        {
            case 1:

                limpiarBuffer();
                printf("\nNombre: ");
                gets(vec[posicionDelEmpelado].name);

                break;

            case 2:

                limpiarBuffer();
                printf("\nApellido: ");
                gets(vec[posicionDelEmpelado].lastName);

                break;

            case 3:

                limpiarBuffer();
                printf("\nSalario: ");
                scanf("%f", &vec[posicionDelEmpelado].salary);

                break;

            case 4:

                limpiarBuffer();
                printf("\nSector: ");
                scanf("%d", &vec[posicionDelEmpelado].sector);

                break;

            default:

                printf("Opcion incorrecta");

                break;
        }

        mostrarEmpleado(vec, idIngresado, posicionDelEmpelado);
        encabezadoDeModificacionExitosa();
    }
}
void mostrarEmpleado(eEmpleado vec[], int idIngresado, int posicionDelEmpelado)
{

    limpiarPantalla();
    printf("               >--------------------------------------------<\n");
    printf("               |       Datos actuales del Id ingresado      |\n");
    printf("               >--------------------------------------------<\n");
    printf("                                   ID = %d             \n", idIngresado);
    printf("               >--------------------------------------------<\n\n\n");

    printf("Nombre: %s\n\nApellido: %s\n\nSalario: %.2f\n\nSector: %d\n\n\n\n",vec[posicionDelEmpelado].name, vec[posicionDelEmpelado].lastName, vec[posicionDelEmpelado].salary, vec[posicionDelEmpelado].sector);

    pause();
    limpiarPantalla();
}
void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int i;

    limpiarPantalla();
    printf("               >------------------------------------------------<\n");
    printf("               |      Datos actuales de Empleados cargados      |\n");
    printf("               |                                                |\n");
    printf("               |------------------------------------------------|\n");
    printf("               |     Ordenados alfabeticamente y por sector     |\n");
    printf("               >------------------------------------------------<\n\n\n");


    printf("NOMBRE     ||     APELLIDO     ||     SALARIO     ||     SECTOR     \n");
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            printf("%s          %s          %.2f          %d\n",vec[i].name, vec[i].lastName, vec[i].salary, vec[i].sector);
        }
    }
    pause();
  }
void bajaDeEmpleado(eEmpleado vec[], int tam)
{
    int idIngresado;
    int posicionDelEmpleado;

    printf("\n\n Ingrese el id que quiera dar de baja:  ");
    scanf("%d", &idIngresado);

    posicionDelEmpleado = buscarPosicionDelEmpleado(vec, tam, idIngresado);

    if(posicionDelEmpleado == -1)
    {
       encabezadoDeIdSinUso();
    }
    else
    {
        vec[posicionDelEmpleado].isEmpty = 1;
        vec[posicionDelEmpleado].id = -1;
        encabezadoDeBajaExitosa();
    }
}
void ordenarEmpleados(eEmpleado vec[], int tam)
{
    float acumulador = 0;
    int contador=0;
    int superanPromedio=0;
    float promedio;
    eEmpleado aux;
    int opcion;
    int flag=0;

    printf("1. Lista ordenada por apellido y sector.\n");
    printf("2. Totales, Promedio, Empleados que superan el promedio.\n");
    printf("Seleccione una opcion: \n");
    scanf("%d",&opcion);

    do
    {
        switch(opcion)
        {
            case 1:
                for (int i=0; i<tam-1; i++)
                {
                    for(int j=i+1; j<tam; j++)
                    {
                        if(strcmpi(vec[i].lastName, vec[j].lastName) == 1)
                        {
                            aux = vec[i];
                            vec[i] = vec[j];
                            vec[j] = aux;

                        }
                        else if(strcmpi(vec[i].lastName, vec[j].lastName) == 0)
                        {
                            if(vec[i].sector > vec[j].sector)
                            {
                                aux = vec[i];
                                vec[i] = vec[j];
                                vec[j] = aux;
                            }
                        }
                    }
                }
                flag=1;
                mostrarEmpleados(vec, tam);
            break;
            case 2:
                acumulador = totalDeSalarios(vec, tam);
                contador = cantidadDeEmpleadosDadosDeALta(vec, tam);
                cantidadDeEmpleadosQueSuperanElPromedio(vec, tam, contador, acumulador);
                promedio = promedioDeSalarios(contador, acumulador);
                limpiarPantalla();
                printf("   >------------------------------------------------------------------------<\n");
                printf("                TOTALES:  %f                   PROMEDIO: %f\n",acumulador,promedio);
                printf("            Cantidad de empleados que superan el sueldo promedio = %d       \n",superanPromedio);
                printf("   >------------------------------------------------------------------------<\n\n\n");
                flag=1;
                pause();
            break;
            default:
                printf("Opcion invalida, Reintente:  ");
                scanf("%d",&opcion);
        }
    }while(flag==0);

}
int cantidadDeEmpleadosQueSuperanElPromedio(eEmpleado vec[], int tam, int contador, float acumulador)
{
    float promedio = 0;
    int contadorDeEmpleadosConMasSueldoDelPromedio = 0;

    promedio = promedioDeSalarios(contador, acumulador);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].salary > promedio)
        {
            contadorDeEmpleadosConMasSueldoDelPromedio++;
        }
    }



    return contadorDeEmpleadosConMasSueldoDelPromedio;
}



/************************************Funciones*********************************************/



void limpiarPantalla()
{
    system("cls");
}
void limpiarBuffer()
{
    fflush(stdin);
}
void pause()
{
    system("pause");
}
int close()
{

    limpiarPantalla();

    printf("\n\n\n\n\n");
    printf("             >--------------------------------------------------<\n");
    printf("             |       Muchas Gracias por utilizar este ABM !!    |\n");
    printf("             >--------------------------------------------------<\n");
    printf("             |                    Foglia Yamil                  |\n");
    printf("             |                     Division A                   |\n");
    printf("             >--------------------------------------------------<\n\n\n");

    return 0;
}
int menu()
{
    int option;

    limpiarPantalla();

    printf("                      >-------------------------<\n");
    printf("                      |       Foglia Yamil      |\n");
    printf("                      |        Division A       |\n");
    printf("                      |-------------------------|\n");
    printf("                      |     Menu de Opciones    |\n");
    printf("                      >-------------------------<\n\n\n");

    printf(" 1-Altas\n 2-Modificar\n 3-Baja\n 4-Informar\n 5-Salir\n\n");

    printf("\nTranscribir el numero que corresponda a la opcion que quiera realizar:  ");
    scanf("%d", &option);

    return option;
}



/************************************Encabezados*********************************************/



int incrementadorDelContador(int contador)
{
    return contador + 1;
}
void encabezadoDeAltas()
{
    limpiarPantalla();

    printf("                      >-------------------------------<\n");
    printf("                      |       Altas de Empleados      |\n");
    printf("                      >-------------------------------<\n\n\n");
}
void encabezadoDeAltasDeId(int id)
{
    printf("\n\n\n");
    printf("               >----------------------------------------------<\n");
    printf("                      Id del empleado dado de alta: %d         \n", id);
    printf("               >----------------------------------------------<\n\n\n\n");
    pause();
}
void encabezadoDeAltaExitosa()
{
    limpiarPantalla();

    printf("\n\n\n\n\n");
    printf("                 >-------------------------------------------<\n");
    printf("                 |        Alta de empleado Exitosa !!!       |\n");
    printf("                 >-------------------------------------------<\n\n\n\n\n\n");

    pause();
}
int menuDeModificacion()
{
    int option;

    printf("Ingrese lo que le gustaria moficiar:\n\n 1-Nombre\n 2-Apellido\n 3-Salario\n 4-Sector\n\n");
    scanf("%d", &option);

    return option;
}
void encabezadoDeModificacion(int id)
{

    printf("                >--------------------------------------------<\n");
    printf("                |       Modificacion del Id ingresado        |\n");
    printf("                >--------------------------------------------<\n");
    printf("                                   ID = %d             \n",id);
    printf("                >--------------------------------------------<\n\n\n");
}
void encabezadoDeModificacionExitosa()
{
    limpiarPantalla();

    printf("\n\n\n\n\n");
    printf("                      >----------------------------------<\n");
    printf("                      |      Modificacion Exitosa !!!    |\n");
    printf("                      >----------------------------------<\n\n\n\n\n\n");

    pause();
}
void encabezadoDeBajaExitosa()
{
    limpiarPantalla();

    printf("\n\n\n\n\n");
    printf("                 >------------------------------------------<\n");
    printf("                 |        Baja de empleado Exitosa !!!      |\n");
    printf("                 >------------------------------------------<\n\n\n\n\n\n");

    pause();
}
void encabezadoDeIdSinUso()
{
    limpiarPantalla();

    printf("\n\n\n\n\n");
    printf("           >--------------------------------------------------------<\n");
    printf("           |        El id ingresado no se encuentra en uso !!!      |\n");
    printf("           >--------------------------------------------------------<\n\n\n\n\n\n");

    pause();
}




