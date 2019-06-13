#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

#include "string.h"

// PARCIAL DE LABORATORIO UNA SEMANA ANTES POR QUE SON ALTOS PETES Y NO SE LA BANCAN 26/6/2019
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
   int error;

    FILE* file;

    file = fopen(path, "r");


        error = parser_EmployeeFromText(file, pArrayListEmployee);

    return error;

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
    int error;

    FILE* file;

    file = fopen(path, "rb");

        error = parser_EmployeeFromBinary(file,pArrayListEmployee);


    return error;

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
    int error=1;

    int maximo=0;

    int len=ll_len(pArrayListEmployee);

    Employee* emp;
    emp=employee_new();

    if( emp != NULL && pArrayListEmployee != NULL )
    {
        for(int i = 0; i < len; i++ )
        {
            emp=ll_get(pArrayListEmployee,i);

            if(emp->id > maximo || i == 0)
            {
                maximo = emp->id;
            }
        }


        maximo = maximo + 1;


        emp=employee_new();

        employee_setId(emp, maximo);

        input_getName(emp->nombre,"Ingrese  el nombre del empleado: ", "Error, rango del nombre invalido",2,15);

        input_getInt(&emp->horasTrabajadas, "ingrese horas trabajadas: ", "Error, rango de horas invalidas",1,350);

        input_getInt(&emp->sueldo, "Ingrese sueldo del empleado: ", "Error, rango de sueldo invalido ",5000,100000);


        ll_add(pArrayListEmployee, emp);//empleado agregado a la lista.
        error=0;
    }

    return error;
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
    int id = -1;
    int opcion = 0;

    Employee* emp = NULL;

        if ( pArrayListEmployee != NULL )
        {
            printf("\nIngrese el id del empleado a modificar: ");
            fflush(stdin);
            scanf("%d", &id);


            do
            {
                for ( int i = 0; i < ll_len(pArrayListEmployee); i++)
                {
                    emp = ll_get(pArrayListEmployee, id-1);


                    if ( emp != NULL && emp->id == id)
                    {
                        break;
                    }
                }


            if (emp != NULL)
            {
                system("cls");
                printf("Modificar empleado id: %d | nombre: %s\n", id, emp->nombre);
                printf("Ingrese (1) para modificar nombre.\n");
                printf("Ingrese (2) para modificar sueldo.\n");
                printf("Ingrese (3) para modificar horas trabajadas.\n");
                printf("Ingrese (4) para regresar\n");

                printf("\nSu opcion: ");
                scanf("%d", &opcion);

                switch(opcion)
                {
                    case 1:
                        input_getName(emp->nombre,"Ingrese el nuevo nombre del empleado: ", "Error, rango del nombre invalido",2,15);
                            break;

                    case 2:
                        input_getInt(&emp->sueldo, "Ingrese el nuevo sueldo del empleado: ", "Error, rango de sueldo invalido",5000,100000);
                            break;

                    case 3:
                        input_getInt(&emp->horasTrabajadas, "ingrese las nuevas horas trabajadas: ", "Error, rango de horas invalido",1,350);
                            break;

                    case 4:
                        printf("\nRegresando.\n");
                        system("pause");
                            break;

                    default:
                        printf("\nError, no ingreso un numero valido.\n");
                        system("pause");
                            break;
                }

                fflush(stdin);
            }
            else
                {
                    printf("\nError el id que ingreso es inexistente---id: %d", id);
                    opcion = 4;
                }

            } while (opcion != 4);
    }


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
    int error=-1;

    int auxId;

    int len;
    len=ll_len(pArrayListEmployee);

    Employee* emp=NULL;

    printf("\nIngrese el id del empleado a dar de baja: ");
    scanf("%d", &auxId);

        for(int i = 0; i < len; i++ )
        {
            emp=ll_get(pArrayListEmployee,i);

                if( auxId == emp->id )
                {
                    ll_remove(pArrayListEmployee,i);
                    error = 0;
                    break;
                }
        }


    return error;
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
    int error = 1;
    int len = ll_len(pArrayListEmployee);
    Employee* emp;
    emp=employee_new();


    if ( emp != NULL && len != 0)
    {
        printf("\n ID   // NOMBRE          // HORAS TRABAJADAS   // SUELDO\n");

            for (int i = 0; i < len; i++)
            {

                emp = ll_get(pArrayListEmployee, i);
                printf(" %04d    %-15s    %-16d     %-6d \n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);

            }

        error = 0;
    }


    return error;
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
    int error = 1;

    int len;
    len=ll_len(pArrayListEmployee);

    Employee* emp = employee_new();
    Employee* auxEmp = employee_new();

    printf("\nordenando los empleados  (relax..esto va a  tardar c: )\n");

    if ( emp != NULL && auxEmp != NULL && len != 0)
    {
        for (int i = 0; i < len; i++)
        {
            for ( int j = i + 1; j < len; j++)
            {
                emp = ll_get(pArrayListEmployee, i);

                auxEmp = ll_get(pArrayListEmployee, j);

                if(strcmp(emp->nombre, auxEmp->nombre) > 0 )
                {
                    ll_set(pArrayListEmployee,j, emp);

                    ll_set(pArrayListEmployee,i, auxEmp);
                }
            }
        }

        error = 0;

    }

    return error;
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

    int error = 1;
    int len;
    len=ll_len(pArrayListEmployee);

    Employee* emp;
    emp=employee_new();

    FILE* file;

        if ( len != 0 )
        {
            file = fopen(path, "w");
        }
        else
            {
                file = NULL;
            }

            if ( file != NULL && emp != NULL && pArrayListEmployee != NULL)
            {
                fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");

                for (int i = 0; i < len; i++)
                {
                    emp =ll_get(pArrayListEmployee, i);
                    fprintf(file, "%d,%s,%d,%d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
                }

                    error = 0;
            }


        fclose(file);

    return error;
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
    int error = 1;

    int len;
    len=ll_len(pArrayListEmployee);

    Employee* emp;
    emp=employee_new();

    FILE* file;

        if ( len != 0 )
        {
            file = fopen(path, "wb");
        }
        else
        {
            file = NULL;
        }


        if ( file != NULL && emp != NULL && pArrayListEmployee != NULL)
        {
            fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");

            for (int i = 0; i < len; i++)
            {
                emp = ll_get(pArrayListEmployee, i);
                fprintf(file, "%d,%s,%d,%d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
            }

                error=0;
        }


        fclose(file);

    return error;
}
