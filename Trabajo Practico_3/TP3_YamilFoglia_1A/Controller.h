/** \brief Carga desde el archivo de texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga desde el archivo binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Agrega un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Edita un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Elimina un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Muestra los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordena los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda en archivo de texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda en archivo binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
