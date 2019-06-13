#include <stdlib.h>
#include <stdio.h>
#include "string.h"

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

/** \brief Asigna a la estructura employee en el campo nombre un dato validando sus caracteres
 *
 * \param this Employee* estructura donde se guardara el nombre.
 * \param nombre char* parametro a ser validado.
 * \return todoOk int retornara 0 si no se logro asignar o 1 si se logro asignar
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

        if( this != NULL && strlen(nombre) < 128 && strlen(nombre) > 0 )
        {
            strcpy(this->nombre, nombre);
            todoOk = 1;
        }

    return todoOk;
}

/** \brief Asigna a la estructura employee en el campo horasTrabajadas
 *         un dato validado entre 1 y 750.
 *
 * \param this Employee* estructura donde se guardara las horasTrabajadas.
 * \param horasTrabajadas int parametro a ser validado.
 * \return todoOk int retornara 0 si no se logro asignar o 1 si se logro asignar
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

        if( this != NULL && horasTrabajadas >0 && horasTrabajadas <=750 )
        {
            this->horasTrabajadas = horasTrabajadas;
            todoOk = 1;
        }

    return todoOk;
}

/** \brief Asigna a la estructura employee en el campo sueldo un dato entero validado
 *         entre 1 y 100000.
 * \param this Employee* estructura donde se guardara el sueldo.
 * \param sueldo int parametro a ser validado.
 * \return todoOk int retornara 0 si no se logro asignar o 1 si se logro asignar
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOK = 1;

        if ( this != NULL && sueldo > 0 && sueldo < 100000 )
        {
            this->sueldo = sueldo;
            todoOK = 0;
        }

    return todoOK;
}


/** \brief Asigna a la estructura employee en el campo id un dato entero validado
 *         entre 1 y 100000.
 * \param this Employee* estructura donde se guardara el id.
 * \param id int parametro a ser validado.
 * \return todoOk int retornara 0 si no se logro asignar o 1 si se logro asignar
 *
 */
int employee_setId(Employee* this,int id)
{
    int todoOK = 1;

        if ( this != NULL && id > 0 && id < 100000 )
        {
            this->id = id;
            todoOK = 0;
        }

        return todoOK;
}

/** \brief Es usado para obtener el sueldo de un empleado, coprobando que
 *         el empleado no sea NULL o que su sueldo no sea NULL
 *
 * \param this Employee estructura a ser validada.
 * \param sueldo int entero a ser validado.
 * \return todoOk int retornara 0 si alguno de los campos son NULL o 1 si pudo obtener el dato.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOK = 0;

        if ( this != NULL || sueldo != NULL)
        {
            todoOK = 1;
            *sueldo = this->sueldo;
        }

    return todoOK;
}

/** \brief Es usado para obtener el id de un empleado, coprobando que
 *         el empleado no sea NULL o que su id no sea NULL
 *
 * \param this Employee* estructura a ser validada.
 * \param id int* entero a ser validado.
 * \return todoOk int retornara 0 si alguno de los campos son NULL o 1 si pudo obtener el dato.
 *
 */
int employee_getId(Employee* this,int* id)
{
    int todoOK = 0;

        if ( this != NULL || id != NULL)
        {
            todoOK = 1;
            *id = this->id;
        }

    return todoOK;
}

/** \brief Crea un nuevo empleado pidiendo memoria dinamica,si consigue memoria lo
 *         carga "vacio" en todos sus campos de la estructura y retorna la direccion de memoria de este.
 *
 * \param no tiene parametros.
 * \return newEmploye Employe* retornara NULL si no consige espacio o la direccion de memoria de donde consiguio.
 *
 */
Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

        if (newEmployee != NULL)
        {
            newEmployee->id = 0;

            strcpy(newEmployee->nombre, " ");

            newEmployee->horasTrabajadas = 0;

            newEmployee->sueldo = 0;
        }

    return newEmployee;
}

/** \brief Carga datos a un nuevo empleado si lo logra retorna la direccion de memoria de este
 *         si no lo logra libera el espacio en memoria y carga al nuevo empleado con NULL.
 *
 * \param idStr char* es usado para asignar el id al nuevo empleado.
 * \param nombreStr char* es usado para asignar el nombre al nuevo empleado.
 * \param horasTrabajadasStr char* es usado para asignar el nombre al nuevo empleado.
 * \param sueldo char* es usado para asignar el sueldo al nuevo empleado.
 * \return newEmploye NULL si no se pudieron cargar los datos o la direccion de memoria del nuevo empleado.
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo)
{
    int todoOK = -1;

    Employee* newEmployee = employee_new();

        if (newEmployee != NULL)
        {
            employee_setId(newEmployee, atoi(idStr));

            employee_setNombre(newEmployee, nombreStr);

            employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));

            employee_setSueldo(newEmployee, atoi(sueldo));


            todoOK = 0;
    }

        if (todoOK == -1)
        {
            free(newEmployee);

            newEmployee = NULL;
        }

    return newEmployee;
}
