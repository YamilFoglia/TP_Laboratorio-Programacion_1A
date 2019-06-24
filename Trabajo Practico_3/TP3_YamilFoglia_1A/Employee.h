#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Constructor de empleado
 *
 * \return empleado
 *
 */
Employee* employee_new();

/** \brief Constructor de empleado con parametros
 *
 * \return empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Elimiona un empleado
 *
 */
void employee_delete();

/** \brief Setter de ID
 *
 * \param Empleado
 * \param ID
 * \return codigo de error
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Getter de ID
 *
 * \param Empleado
 * \param ID
 * \return codigo de error
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Setter de Nombre
 *
 * \param Empleado
 * \param nombre
 * \return codigo de error
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Getter de Nombre
 *
 * \param Empleado
 * \param nombre
 * \return codigo de error
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Setter de Horas trabajadas
 *
 * \param Empleado
 * \param horas
 * \return codigo de error
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Getter de horas
 *
 * \param Empleado
 * \param sueldo
 * \return codigo de error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Setter de Sueldo
 *
 * \param Empleado
 * \param sueldo
 * \return codigo de error
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Getter de Sueldo
 *
 * \param Empleado
 * \param sueldo
 * \return codigo de error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
