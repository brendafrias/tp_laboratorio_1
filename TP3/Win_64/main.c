#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    system("color 4F");
    int opcion = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {

        system("cls");
        printf("-------  Menu: -------\n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.biin (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir\n");

        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                if ( controller_loadFromText("data.csv",listaEmpleados) )
                {
                   printf("\nError al cargar los datos en modo texto.\n");
                }
                else
                    {
                        printf("\nSe han cargado los datos.\n");
                    }

                    system("pause");
                    break;

            case 2:
                 if ( controller_loadFromBinary ("data.bin",listaEmpleados) )
                {
                   printf("\nError al cargar los datos en modo binario.\n");

                }
                else
                    {
                        printf("\nSe han cargado los datos.\n");

                    }
                    system("pause");
                    break;

            case 3:
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("\nError no se pudo dar de alta el empleado");
                }
                else
                    {
                        printf("\nAlta exitosa");
                    }
                    system("pause");
                    break;

            case 4:
                printf("\nModificar empleado.\n");
                controller_editEmployee(listaEmpleados);
                    system("pause");
                    break;

            case 5:
               if ( controller_removeEmployee(listaEmpleados) )
                {
                    printf("\nError no se encuentra el id del empleado.\n");
                }
                else
                    {
                        printf("\nBaja exitosa.\n");
                    }
                    system("pause");
                    break;

            case 6:
                if ( controller_ListEmployee(listaEmpleados) )
                {
                    printf("\nError no hay datos para listar.\n");
                }
                else
                    {
                        printf("\nLista de empleados.\n");
                    }
                    system("pause");
                    break;

            case 7:
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("\nError no se pudo ordenar los empleados.");
                }
                else
                    {
                        printf("\nEmpleados ordenados exitosamente.\n");
                    }
                    system("pause");
                    break;

            case 8:
                if ( controller_saveAsText("data.csv", listaEmpleados) )
                {
                    printf("\nError no se encontraron datos a guardar.\n");
                }
                else
                    {
                        printf("\nDatos guardados exitosamente.\n");
                    }
                    system("pause");
                    break;

            case 9:
                 if ( controller_saveAsBinary ("data.bin", listaEmpleados) )
                    {
                    printf("\nError no se encontraron datos a guardar.\n");
                    }
                    else
                        {
                            printf("\nDatos guardados exitosamente.\n");
                        }
                        system("pause");
                        break;

            case 10:
                printf("\nSaliendo.\n");
                ll_deleteLinkedList(listaEmpleados);
                    system("pause");
                    break;
        }


    } while( opcion != 10 );

    return 0;

}
