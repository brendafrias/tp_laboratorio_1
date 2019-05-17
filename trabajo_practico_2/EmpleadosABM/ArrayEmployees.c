#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define S 4


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Inicializa las posiciones de la lista de Empleados
*           como vacias (1). Y ademas, le asigna un id diferente a cada posicion.(autoincremental).
*
* \param    eEmployee list[] Vector a ser inicializado.
* \param    int len Tamaño del vector a ser inicializado.
* \return   (void).
*
*/
void initEmployee(eEmployee list[],int len)
{

    for(int i=0;i<len;i++)
    {
        list[i].isEmpty=1;

    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca el primer empleado con isEmpty (1) y retorna su posicion o (-1) si no lo encontro
 *
 * \param eEmployee list[] Vector que recorrera la funcion.
 * \param int len Tamaño del vector de la estructura eEmployee.
 * \return  int index (1) la posicion encontrada (-1) si no encuentra posicion.
 *
 */
int searchFree(eEmployee list[], int len)
{

    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**\brief Da de alta un empleado a la lista en el primer espacio vacio que encuentre, retorna (0) si
*           hay lugar, o (-1) si no hay espacio.
*
* \param    eEmployee list[] Vector donde se dara de alta un empleado.
* \param    int len Tamaño del vector.
* \param    char name[] Elemento a ser copiado en list[i].name
* \param    char lastName[] Elemento a ser copiado en list[i].lastName
* \param    float salary Elemento a ser copiado en list[i].salary
* \param    int sector Elemento a ser copiado en list[i].sector
*
* \return   int altaOk(-1 o 0)
*
*/
int addEmployee(eEmployee list[], int len, char name[],char lastName[],float salary,int sector,int idMain)
{

    int altaOk=-0;

        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
            {
                strncpy(list[i].name,name,51);
                strncpy(list[i].lastName,lastName,51);
                list[i].salary=salary;
                list[i].idSector=sector;

                list[i].id=idMain;

                list[i].isEmpty=0;

                toUpperFirstLetter(list,len,i);

                altaOk=1;
                    break;
            }
        }

        return altaOk;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**\brief   Busca un id especifico en la lista y devuelve en que posicion de la lista esta y si no
*           esta devuelve -1.
*
* \param    eEmployee list[] Vector donde se buscara un id de empleado especifico.
* \param    int len Tamño del vector.
* \param    int id Elemento a ser comparado con list[i].id
*
* \return   int index Posicion en la que lo encontro.
*/
int findEmployeeById(eEmployee list[], int len,int id)
{

    int index=-1;

        for(int i=0;i<len;i++)
        {
            if(list[i].id==id && list[i].isEmpty==0)
            {
                index=i;
                    break;
            }
        }

        return index;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**\brief  Cambia el isEmpty de un empleado a (1) "posicion vacia", pudiendo ser reescrita.
*          "Elimina un empleado de la lista". Si la posicion no tiene ningun empleado, devuelve (0).
*          De lo contrario, (1).
*
* \param    eEmployee list[] Vector donde buscara el empleado a ser removido.
* \param    int len Tamaño del vector.
* \param    int id Elemento para buscar el id en la funcion findEmployeeById.
*
* \return   int bajaOk (1) si la baja se puedo realizar (0) si no se
*           realizo la baja.
*
*/
int removeEmployee(eEmployee list[], int len, int id)
{
    int find=findEmployeeById(list,len,id);
    int opcion;
    int bajaOk=0;

        if(find!=-1)
        {

            printf("Esta seguro que desea eliminar al empleado | %s, %s | ?\n 1- Estoy seguro.\n 2- No, Regresar.\n Ingrese una opcion: ",list[find].name,list[find].lastName);
            scanf("%d",&opcion);


            switch(opcion)
            {
                case 1:
                    list[find].isEmpty=1;
                    printf("\nBaja empleado exitosa!!!\n\n");
                    bajaOk=1;
                        break;

                case 2:
                    printf("\nRegresando...\n\n");
                        break;

                default:
                    printf("\nError, no ingreso una opcion valida.\n\n");
                        break;
            }
        }

        return bajaOk;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Ordena la lista de los empleados por sector, luego alfabeticamente por apellido.
*           de manera ascendente o descendiente segun orden ingresado,
*           utilizando una copia de la estructura eEmpleado para "burbujear".
*
* \param    eEmployee list[] Vector a ser ordenado alfabeticamente.
* \param    int lenE Tamaño del vector.
* \param    int order Orden a ser ordenado el vector (1) para ascendiente o (2) para descendiente.
*
* \return   (void)
*
*/
void sortEmployees(eEmployee list[], int lenE, int order)
{
    eEmployee auxEmp;

        for (int i = 0; i < lenE; i++)
        {
            for (int j = i+1; j < lenE; j++)
            {
                if( order == 1)
                {
                    if ( stricmp( list[i].lastName, list[j].lastName) > 0)
                    {
                        auxEmp = list[i];
                        list[i] = list[j];
                        list[j] = auxEmp;
                    }

                    if ( list[i].idSector > list[j].idSector)
                    {
                        auxEmp = list[i];
                        list[i] = list[j];
                        list[j] = auxEmp;
                    }
                }
                else
                {
                    if ( stricmp( list[i].lastName, list[j].lastName) < 0)
                    {
                        auxEmp = list[i];
                        list[i] = list[j];
                        list[j] = auxEmp;
                    }

                    if ( list[i].idSector < list[j].idSector)
                    {
                        auxEmp = list[i];
                        list[i] = list[j];
                        list[j] = auxEmp;
                    }
                }

            }
        }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**\brief Imprime todos los empleados.
*
* \param eEmployee list[] Vector de los empleados a ser imprimido.
* \param int lenE Tamaño del vector de eEmployee.
* \param eSector sectors[] Vector de los sectores.
* \param int lenS Tamaño del vector de eSector.
*
* \return void
*
*/
void printEmployees(eEmployee list[],int lenE,eSector sectors[],int lenS)
{
    int i;

        for(i=0;i<lenE;i++)
        {
            if(list[i].isEmpty==0)
            {
                printOneEmployee(list,lenE,sectors,lenS,i);
            }
        }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/** \brief  Modifica el nombre de un empleado en la lista
 *
 * \param   eEmpleado list[] Vector a ser modificado.
 * \param   int len Tamaño del vector.
 * \param   int position (posicion del vector a modificar).
 *
 * \return  (void)
 *
 **/
void modifyNameEmployee(eEmployee list[],int len, int position)
{
    char newName[51];
    fflush(stdin);

    printf("Ingrese el nuevo nombre del empleado |%s,%s|: ",list[position].lastName,list[position].name);
    fgets(newName,51,stdin);

    newName[strlen(newName)-1]='\0';


    strcpy(list[position].name,"");
    strcat(list[position].name,newName);

    printf("\nModificacion de nombre exitosa!!!\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Modifica el apellido de un empleado en la lista.
 *
 * \param   eEmployee list[] Vector a ser modificado.
 * \param   int len Tamaño del vector.
 * \param   int position (posicion del vector a modificar).
 *
 * \return  (void)
 *
 */
void modifyLastNameEmployee(eEmployee list[],int len, int position)
{
    char newLastName[51];
    fflush(stdin);

    printf("Ingrese el nuevo apellido del empleado |%s,%s|: ",list[position].lastName,list[position].name);
    fgets(newLastName,51,stdin);

    newLastName[strlen(newLastName)-1]='\0';

    strcpy(list[position].lastName,"");
    strcat(list[position].lastName,newLastName);

    printf("\nModificacion de apellido exitosa !!!\n\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Modifica el salario de un empleado
 *
 * \param   eEmployee list[]
 * \param   int len
 * \param   int position
 *
 * \return  (void)
 *
 */
void modifySalaryEmployee(eEmployee list[],int len, int position)
{
    int newSalary;

    printf("Ingrese el nuevo SALARIO del empleado |%s,%s|: $",list[position].lastName,list[position].name);
    scanf("%d",&newSalary);

    list[position].salary=newSalary;

    printf("\nSalario modificado exitosamente!\n\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Modifica el sector de un empleado de la lista.
 *
 *  \param   eEmployee list[] Vector a ser modificado.
 *  \param   int len Tamaño del vector.
 *  \param   int position (posicion del vector a modificar).
 *  \param   eSector sectors[] Vector de la estructura eSector
 *  \param   int lenS Tamaño del vector de la estructura eSector
 *
 * \return   (void)
 *
 */
void modifySectorEmployee(eEmployee list[],int lenE, int position,eSector sectors[],int lenS)
{
    int newSector;

    printf("Ingrese el nuevo sector del empleado |%s,%s|:\n",list[position].lastName,list[position].name);
    newSector=validateSector(sectors,lenS);

    list[position].idSector=newSector;

    printf("\nModificacion de sector exitosa!!!\n\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Valida si el sector ingresado esta en la lista de sectores validos. Y cuando
 *              se ingresa uno valido, lo devuelve(id del sector).
 *
 * \param   sectors[] Vector de la estructura eSector.
 * \param   int lenS Tamaño del vector de la estructura eSector.
 *
 * \return  int sector (id valido).
 *
 */
int validateSector(eSector sectors[],int lenS)
{
    int sector;


        for(int i=0;i<lenS;i++)
        {
            printf("%d)%s\n",sectors[i].idSector,sectors[i].descripcion);
        }

        printf("Sector: ");
        scanf("%d",&sector);



        while(sector>lenS || sector<=0)
        {
            printf("ERROR. Sector no valido, ingrese nuevamente el sector: ");
            scanf("%d",&sector);
        }
    return sector;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Imprime un solo empleado de una posicion en especifica.
 *
 * \param   eEmployee list[] Vector de donde sera mostrado el empleado.
 * \param   int lenE Tamaño del vector de la estructura eEmployee.
 * \param   eSector sectors[] Vector de donde sera mostrado el sector.
 * \param   int lenS Tamaño del vector de la estructura eSector.
 * \param   int position (posicion del vector a mostrar).
 *
 * \return  (void)
 *
 */
void printOneEmployee(eEmployee list[],int lenE,eSector sectors[],int lenS,int position)
{
    int sectorDescription;

    sectorDescription=searchSectorDescription(list,sectors,lenS,position);

    printf("\t%d\t%s, %s\t\t $%.2f\t%s\n",list[position].id,list[position].lastName,list[position].name,list[position].salary,sectors[sectorDescription].descripcion);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Busca la descripcion del sector segun el id sector del empleado.
 *           Devuelve la posicion de "sectors" en la que esta la descripcion
 *           del sector que le pertenece al idsector del empleado.
 *
 * \param   eEmployee list[] Vector donde sera buscado el id sector.
 * \param   eSector sectors[] Vector donde sera buscado la descripcion y el id.
 * \param   int lenS Tamaño del vector de eSector.
 * \param   int position (posicion del vector).
 *
 * \return  int i retorna el id de sector.
 *
 */
 int searchSectorDescription(eEmployee list[],eSector sectors[],int lenS,int position)
 {
    int i;

        for(i=0;i<lenS;i++)
        {
            if(list[position].idSector==sectors[i].idSector)
            {
                break;
            }
        }
    return i;
 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Hace mayuscula la primer letra de una palabra y vuelve minusculas todas las demas
 *
 * \param   eEmployee list[] Vector donde realizara el cambio.
 * \param   int len Tamaño del vector de la estructura eEmployee.
 * \param   int position
 *
 * \return  (void)
 *
 */
 void toUpperFirstLetter(eEmployee list[],int len,int position)
 {
    int i;

    list[position].name[0]=toupper(list[position].name[0]);

        for(i=1;i<51;i++)
        {
            list[position].name[i]=tolower(list[position].name[i]);
        }


    list[position].lastName[0]=toupper(list[position].lastName[0]);

        for(i=1;i<51;i++)
        {
            list[position].lastName[i]=tolower(list[position].lastName[i]);
        }

 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /** \brief Hardcodea una lista de 10 empleados
  *
  * \param  eEmployee list[] Vector donde sera hardcodeada la lista.
  * \param  int tam Tamaño del vector de la estructura eEmployee.
  *
  * \return (void)
  *
  */
void hardcodeEmployeeList(eEmployee list[],int tam)
{


    char names[][51]= {"Roberto","Eugenia","Pedro","Hernan","Raul","Nicolas","Ramon","Jorge","Armando","Pablo"};
    char lastNames[][51]= {"Diaz","Alvaro","Salvo","Frias","Paoli","Hagge","Rios","Sanchez","Roge","Lopez"};
    float salary[]= {23000,21000,17000,5000,22000,8000,7000,7000,9000,16000};
    int sector[]={2,1,4,3,2,1,4,3,1,2};
    int id[]={1,2,3,4,5,6,7,8,9,10};

        for(int i=0; i<tam; i++)
        {
            strcpy(list[i].name, names[i]);
            strcpy(list[i].lastName, lastNames[i]);
            list[i].salary = salary[i];
            list[i].isEmpty = 0;
            list[i].idSector = sector[i];
            list[i].id = id[i];
        }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Hace la suma de todos los salarios de los empleados y devuelve el total
 *
 * \param   eEmployee list[] Vector de donde se sumara los salarios.
 * \param   int len Tamaño del vector de la  estructura eEmployee.
 *
 * \return  float total (suma de todos los salarios).
 *
 */
 float salaryTotal(eEmployee list[],int len)
 {

     float total=0;

        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                total= list[i].salary + total;
            }
        }
     return total;
 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /** \brief Hace la cuenta del promedio de todos los salarios de la lista. Devuelve el promedio.
  *
  * \param  eEmployee list[] Vector de donde se sacara el promedio.
  * \param  int len Tamaño del vector de la estructura eEmployee.
  *
  * \return float average (promedio de todos los salarios).
  *
  */
float salaryAverage(eEmployee list[],int len)
{
    int counter=0;
    float average=0;
    float total;

    total=salaryTotal(list,len);

      for(int i=0;i<len;i++)
      {
          if(list[i].isEmpty==0)
          {
              counter=counter+1;
          }
      }

      average=(float)total/counter;

      return average;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Devuelve la cantidad de empleados que su sueldo supera el promedio de sueldos.
*
* \param    eEmployee list[] Vector de donde se contara la cantidad de empleados que su
 *          sueldo supera al promedio.
* \param    int len Tamaño del vector de la estructura eEmployee.
*
* \return   int counterEmployee (cantidad de empleados que su sueldo supera el promedio).
*
*/
int salaryAverageOvercome(eEmployee list[],int len)
{

    int counterEmployee=0;
    float average;

    average=salaryAverage(list,len);

        for(int i=0;i<len;i++)
        {
            if(list[i].salary>average&&list[i].isEmpty==0)
            {
                counterEmployee=counterEmployee+1;
            }
        }

    return counterEmployee;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Si no hay ningun empleado en la lista, devuelve 0, si hay por lo menos uno, devuelve 1.
*
* \param    eEmployee list[] Vector donde revisara si hay algun empleado.
* \param    int len Tamaño del vector de la estructura eEmployee.
*
* \return   int oneE (0) no encontro empleado o (1) si encontro.
*
*/
int oneEmployee(eEmployee list[],int len)
{

    int oneE=0;


        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                oneE=1;
                    break;
            }
        }
    return oneE;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief  Menu alta de empleados
 *
 * \param   eEmployee list[] Vector donde se dara de alta un empleado.
 * \param   int lenE Tamaño del vector de la estructura eEmployee.
 * \param   eSector sectors[] Vector de sectores.
 * \param   int lenS Tamño del vector de la estructura eSector.
 *
 * \return int altaOk (1) si se realizo el alta (0) si no se realizo.
 *
 */
int addEmployeeMenu(eEmployee list[],int lenE,eSector sectors[],int lenS,int idMain)
{
    int space;
    int space2;

    int altaOk=0;

    char name[51];
    char lastName[51];
    float salary;
    int sector;

        space2=searchFree(list,lenE);
        if(space2==-1)
            {
                printf("\nNo hay lugar en el sistema\n");
                printf("\nRegresando al menu...\n");
                system("pause");

            }
                else
                {
                    printf("\n--Dar de alta un empleado--\n\n");
                    fflush(stdin);
                    printf("Ingrese el nombre: ");
                    fgets(name,51,stdin);
                    name[strlen(name)-1]='\0';

                    printf("Ingrese el apellido: ");
                    fgets(lastName,51,stdin);
                    lastName[strlen(lastName)-1]='\0';

                    printf("Ingrese el salario del empleado: $");
                    scanf("%f",&salary);

                    printf("Ingrese el sector del empleado:\n");
                    sector=validateSector(sectors,lenS);

                    space=addEmployee(list,lenE,name,lastName,salary,sector,idMain);



                        if(space==1)
                        {
                            printf("\nAlta de empleado exitosa!!!\n\n");

                            altaOk=1;
                        }
                        else
                        {
                            printf("\nError, No hay mas lugar.\n\n");
                        }



                    system("pause");
            }

    return altaOk;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Menu de baja de empleado
 *
 * \param eEmployee list[] Vector donde se dara de baja un empleado.
 * \param int len Tamaño del vector de la estructura eEmpleado.
 *
 * \return void
 *
 */
void removeEmployeeMenu(eEmployee list[],int len)
{
    int id;
    int success;

        printf("\n--Baja de empleado--\n\n");
        printf("Ingrese el id del empleado que desea dar de baja: ");
        scanf("%d",&id);

        success=removeEmployee(list,len,id);

            if(success!=1)
            {
                printf("\nError, El id que ha ingresado no se encuentra.\n\n");
            }

                system("pause");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Menu de modificacion de empleado
 *
 * \param eEmployee list[] Vector donde se realizara la modificacion del empleado.
 * \param int len Tamaño del vector de la estructra eEmployee.
 * \param eSector sectors[] Vector de sectors.
 * \param int lenS Tamaño del vector de la estructura eSector.
 *
 * \return void
 *
 */
void modifyEmployeeMenu(eEmployee list[], int lenE,eSector sectors[],int lenS)
{
    int id;
    int position;
    int option;

        printf("\n--Modificacion de empleado--\n\n");
        printf("Ingrese el id del empleado que desea modificar: ");
        scanf("%d",&id);

        position=findEmployeeById(list,lenE,id);

            if(position!=-1)
            {
                printf("Que desea modificar del empleado |%s,%s|?\n\n1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n\n",list[position].lastName,list[position].name);
                printf("Ingrese opcion: ");
                scanf("%d",&option);

                    switch(option)
                    {
                        case 1:
                            modifyNameEmployee(list,lenE,position);
                                break;

                        case 2:
                            modifyLastNameEmployee(list,lenE,position);
                                break;

                        case 3:
                            modifySalaryEmployee(list,lenE,position);
                                break;

                        case 4:
                            modifySectorEmployee(list,lenE,position,sectors,lenS);
                                break;

                        default:
                            printf("\nError, no ingreso una Opcion valida.\n\n");
                                break;

                    }
            }
            else
            {
                printf("\nError, El id que ha ingresado no existe en la lista.\n\n");
            }
                system("pause");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Muestra el total de todos los salarios, el promedio de los salarios, la cantidads
 *          de empleados que superan el salario promedio.
 *
 * \param   eEmployee list[] Vector para hacer las operaciones de salario.
 * \param   int lenE Tamaño del vector de la estructura eEmployee.
 * \param   eEmployee copy[] copia de la estructura eEmployee.
 *
 * \return  void
 *
 */
void showEmployeesMenu(eEmployee list[],int lenE,eEmployee copy[])
{
    float total;
    float average;
    int employeeSalaryAverage;

        total=salaryTotal(list,lenE);
        average=salaryAverage(list,lenE);
        employeeSalaryAverage=salaryAverageOvercome(list,lenE);

        printf("\nEl total de la suma de los salarios es: $%.2f",total);
        printf("\nEl promedio de los salarios es: $%.2f",average);
        printf("\nLa cantidad de empleados que superan el sueldo promedio es: %d.\n\n",employeeSalaryAverage);
            system("pause");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra un menu principal y captura una opcion.
 *
 * \return int opcion (opcion que eligio el usuario).
 *
 */
int menuPrincipal()
{
    int opcion;

            printf("---ABM MENU---\n\n");
            printf("1- Alta empleado\n");
            printf("2- Modificar empleado\n");
            printf("3- Baja empleado\n");
            printf("4- Informes\n");
            printf("5- Salir\n");
            printf("\nIngrese opcion: ");

            scanf("%d",&opcion);
    return opcion;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra un menu de informes y captura una opcion.
 *
 * \return int opcion (opcion que eligio el usuario para mostrar informe).
 *
 */
int menuDeInformes ()
{
    int opcion2;

        printf("\n\n-----INFORMES-----\n\n");
        printf("1- Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
        printf("2- Total y promedio de los salarios,\n");
        printf("y cuantos empleados superan el salario promedio.\n");
        printf("3- Salir\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &opcion2 );

    return opcion2;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra el menu principal.
 *
 * \return (void).
 *
 */
void mostrarMenu()
{
            printf("---ABM MENU---\n\n");
            printf("1- Alta empleado\n");
            printf("2- Modificar empleado\n");
            printf("3- Baja empleado\n");
            printf("4- Informes\n");
            printf("5- Salir\n");
}
