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
    int error = 1;
    int cant;
    char buffer[4][20];

    if (pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); // LECTURA FANTASMA
        ll_clear(pArrayListEmployee); // USADO PARA BORRAAR LA LISTA

        while( !feof(pFile) )
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if ( cant < 4 )
            {
                if(feof(pFile))
                {
                    break;
                }
				else
                    {
                        printf("No leyo el ultimo registro");
                        break;
                    }
            }

            Employee* auxEmp = employee_new();

                if (auxEmp != NULL)
                {
                    auxEmp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                    ll_add(pArrayListEmployee, auxEmp);
                }
                else
                    {
                        printf("Error no se pudo cargar\n");
                        ll_clear(pArrayListEmployee);
                        break;
                    }
        }


        error = 0;
        fclose(pFile);
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
    int error = 1;
    int cant;

    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);


        while( !feof(pFile) )
        {
            Employee* auxEmp = employee_new();
            cant = fread(auxEmp,sizeof(Employee),1,pFile);

            if ( cant != 1 )
            {
               if(feof(pFile))
                {
                    break;
                }
                else
                    {
                        printf("No leyo el ultimo registro");
                        break;
                    }
            }

                if (auxEmp != NULL)
                {
                    ll_add(pArrayListEmployee, auxEmp);
                }
                else
                    {
                    printf("Error no se pudo cargar\n");
                    ll_clear(pArrayListEmployee);
                    break;
                    }
        }

        error = 0;
        fclose(pFile);
    }

    return error;
}
