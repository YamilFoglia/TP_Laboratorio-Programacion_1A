/** \brief Carga desde el archivo de texto y lo mete dentro de la LinkedList
 *
 * \param Archivo
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Carga desde el archivo binario y lo mete dentro de la LinkedList
 *
 * \param Archivo
 * \param pArrayListEmployee LinkedList*
 * \return codigo de error
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
