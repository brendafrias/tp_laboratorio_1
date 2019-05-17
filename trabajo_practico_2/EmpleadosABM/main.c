#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define ELEMENTS 1000
#define S 4

int main()
{
    system("color 5E");
    int opcion;
    int opcion2;
    int oneE;
    int opcionOrden;

    int banderaAlta=0;
    int idMain=11;

    eEmployee list[ELEMENTS];
    initEmployee(list,ELEMENTS);


    hardcodeEmployeeList(list,10);//lista de empleasdos hardcodeada


    eSector sectors[S]={{1,"Sistemas"},{2,"RRHH"},{3,"Contabilidad"},{4,"Ventas"}};
    eEmployee copy[1];

        do
        {
            oneE=oneEmployee(list,ELEMENTS);

            mostrarMenu();
            printf("\nIngrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:



                    banderaAlta=addEmployeeMenu(list,ELEMENTS,sectors,S,idMain);
                    if(banderaAlta==1)
                        {
                            idMain++;
                        }


                            break;

                case 2:
                    if(oneE)
                    {
                        modifyEmployeeMenu(list,ELEMENTS,sectors,S);
                    }
                    else
                    {
                        printf("\nError, no hay empleados para modificar.\n");
                            system("pause");
                    }
                        break;

                case 3:
                    if(oneE)
                    {
                        removeEmployeeMenu(list,ELEMENTS);
                    }
                    else
                    {
                        printf("\nError, no hay empleados para dar de baja.\n");
                            system("pause");
                    }
                        break;

                case 4:

                    if(oneE)
                    {

                        do
                        {
                            system("cls");
                            switch(menuDeInformes())
                            {
                                case 1:
                                    printf("\nIngrese (1) para ordenar ascendiente y (2) para descendiente\n");
                                    scanf("%d",&opcion2);

                                        switch(opcion2)
                                        {
                                            case 1:
                                                opcionOrden=1;
                                                sortEmployees(list, ELEMENTS, opcionOrden);
                                                printEmployees(list,ELEMENTS,sectors,S);
                                                    system("pause");
                                                    break;
                                            case 2:
                                                opcionOrden=2;
                                                sortEmployees(list, ELEMENTS, opcionOrden);
                                                printEmployees(list,ELEMENTS,sectors,S);
                                                    system("pause");
                                                    break;
                                           default:
                                                printf("\nError, no ingreso un numero de orden valido\n");
                                                    system("pause");
                                                    break;
                                        }
                                        break;


                            case 2:
                                showEmployeesMenu(list,ELEMENTS,copy);
                                    break;


                            case 3:
                                printf("\nRegresando...\n");
                                    system("pause");
                                opcion2 = 3;
                                    break;

                            default:
                                printf("\nNo ingreso una opcion valida\n");
                                    system("pause");
                                    break;
                           }
                        } while (opcion2 != 3);
                }
                else
                {
                   printf("\nNo hay empleados para mostrar informes\n\n");
                    system("pause");
                }
                    break;


                case 5:
                    printf("\nSalio del programa!\n\n");
                        system("pause");
                        break;

            default:
                printf("\nError, no ingreso una opcion valida.\n");
                    system("pause");
                    break;
          }
           system("cls");

        }while(opcion!=5);

    return 0;
}
