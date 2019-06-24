#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int id;
    int isEmpty;

}eEmpleado;



/************************************Opciones del Trabajo practico*********************************************/



/** \brief Inizializa todos los vectores, modificando los id y los isEmpty.
 * \param Estructura de empleado.
 * \param tamañio del array.
 */
void inicializarPrograma(eEmpleado vec[],int tam);


/** \brief Se le suma 1 al contador.
 * \param Un contador previamente inizializado en el main.
 * \return contador +1;
 */
int incrementadorDelContador(int contador);


/** \brief Alta de un empleado
 * \param Estructura de empleado.
 * \param Un contador, previamente inizializado en el main.
 * \param Tamaño del array.
 * \return La suma realizada en la funcion incrementadorDelContador.
 */
int altasDeEmpleados(eEmpleado vec[], int contador, int tam);


/** \brief Modificacion de datos.
 * \param Estructura de empleado.
 * \param Tamaño del array.
 */
void modificarDatos(eEmpleado vec[], int tam);


/** \brief Muesta un solo empleado.
 * \param Estructura de empleado.
 * \param Id previamente ingresado.
 * \param Posicion en la que se encuentra el id.
 */
void mostrarEmpleado(eEmpleado vec[], int idIngresado, int posicionDelId);


/** \brief Muestra el listado total de empleados.
 * \param Estructura de empleado.
 * \param Tamaño del array.
 */
void mostrarEmpleados(eEmpleado vec[], int tam);


/** \brief Ordena el listado de empleados.
 * \param Estructura de empleado.
 * \param Tamaño del array.
 */
void ordenarEmpleados(eEmpleado vec[], int tam);


/** \brief Baja de empleado.
 * \param Estructura de empleado.
 * \param Tamaño del array.
 */
void bajaDeEmpleado(eEmpleado vec[], int tam);


/** \brief Busca la primer posicion libre para carga un empleado
 * \param Estructura de empleado.
 * \param Tamaño del array.
 * \return Sitio libre.
 */
int buscarPosicionLibre(eEmpleado vec[], int tam);


/** \brief Busca la primer posicion en el qeu se encuentra un empleado.
 * \param Estructura de empleado.
 * \param Tamaño del array.
 * \param Id del empleado buscado.
 * \return Sitio del empleado.
 */
int buscarPosicionDelEmpleado(eEmpleado vec[], int tam, int idIngresado);


/** \brief Cuenta la cantidad de empleados que se encuentran dados de alta.
 * \param Estructura de empleado.
 * \param Tamaño del array.
 * \return Cantidad de empleados.
 */
int cantidadDeEmpleadosDadosDeALta(eEmpleado vec[], int tam);


/** \brief Suma todos los sueldos ingresados.
 * \param Estructura de empleado.
 * \param Tamaño del array.
 * \return Total de salarios sumados.
 */
float totalDeSalarios(eEmpleado vec[], int tam);


/** \brief Saca el promedio de todos los salarios.
 * \param Cantidad de empleados.
 * \param Acumulacion de sueldos.
 * \return Promedio de sueldos.
 */
float promedioDeSalarios(int contador, float acumulador);


/** \brief Saca la cantidad de empleados que superan el sueldo promedio.
 * \param Estructura de empleado.
 * \param Tamaño del array.
 * \param Contador de empleados.
 * \param Acumulador de seuldos.
 * \return Cantiadad de empleados que sueperan el sueldo promedio.
 */
int cantidadDeEmpleadosQueSuperanElPromedio(eEmpleado vec[], int tam, int contador, float acumulador);



/************************************Funciones*********************************************/



/** \brief Limpia la pantalla.
 */
void limpiarPantalla();


/** \brief Limpia el buffer.
 */
void limpiarBuffer ();


/** \brief Ingresa una pausa.
 */
void pause();


/** \brief Muetra el menu de opciones.
 * \return devuelve una opcion para el switch.
 */
int menu();


/** \brief Muetra el menu de salida.
 * \return devuelve un entero, para poder salir del while.
 */
int close();



/************************************Encabezados*********************************************/



/** \brief Muestra un encabezado para el alta de empleado.
 */
void encabezadoDeAltas();


/** \brief Muestra un encabezado para mostrar el id asignado.
 */
void encabezadoDeAltasDeId(int id);


/** \brief Muestra un encabezado para un alta exitosa.
 */
void encabezadoDeAltaExitosa();


/** \brief Menu de opciones de modificacion.
 * \return Devuelve una opcion para modificar.
 */
int menuDeModificacion();


/** \brief Muestra un encabezado para modificiones.
 * \param Id para mostrar.
 */
void encabezadoDeModificacion(int id);


/** \brief Muestra un encabezado para una modificacion exitosa.
 */
void encabezadoDeModificacionExitosa();


/** \brief Muestra un encabezado para una baja exitosa.
 */
void encabezadoDeBajaExitosa();


/** \brief Muestra un encabezado por si se ingresa un id que no este en uso.
 */
void encabezadoDeIdSinUso();
