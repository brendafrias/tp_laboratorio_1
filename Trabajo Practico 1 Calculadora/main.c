#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



void main(void)
{
    float primerOperando;
    float segundoOperando;
    int flag1=0;
    int flag2=0;
    int opcion;
    char respuesta='s';

    float resultadoSuma;
    float resultadoResta;
    float resultadoDivicion;
    float resultadoMultiplicacion;
    long long int factorialPrimerNumero;
    long long int factorialSegundoNumero;

    while(respuesta=='s')
        {
            if(flag1==0)
            {
                printf(" digite 1 para ingresar el primer operando ");
            }
            else
                {
                    printf("\n digite 1 para ingresar el primer operando A= %.2f",primerOperando);
                }
            if(flag2==0)
            {
                printf("\n digite 2 para ingresar el segundo operando \n");
            }
            else
                {
                    printf("\n digite 2 para ingresar el segundo operando  B= %.2f",segundoOperando);
                    printf("\n");
                }
                printf(" digite 3 para calcular todas las operaciones \n");
                printf(" digite 4 para mostrar los resultados \n");
                printf(" digite 5 para salir \n");
                scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                //Ingresa el primer operando
                scanf("%f",&primerOperando);
                printf("El primer operando es: %.2f",primerOperando);
                flag1=1;
                    break;
            case 2:
                //Ingresa el segundo operando
                scanf("%f",&segundoOperando);
                printf("El segundo operando es: %.2f",segundoOperando);
                flag2=1;
                    break;
            case 3:
                //Calcula todas las operaciones
                resultadoSuma=suma(primerOperando,segundoOperando);
                resultadoResta=resta(primerOperando,segundoOperando);
                resultadoDivicion=divicion(primerOperando,segundoOperando);
                resultadoMultiplicacion=multiplicacion(primerOperando,segundoOperando);
                factorialPrimerNumero= factorial(primerOperando);
                factorialSegundoNumero= factorial (segundoOperando);
                    break;
            case 4:
                //Muestra todas las operaciones

                if(flag1==0 || flag2==0)
                {
                    printf("Error no se puede realizar la operacion porque falta ingresar operando");
                }
                else
                    {
                        printf("\n la suma es: %.2f",resultadoSuma);
                        printf("\n la resta es: %.2f",resultadoResta);

                        if(resultadoDivicion==-1)
                        {
                            printf("\n Error no se puede realizar la operacion porque no se puede dividir por 0");
                        }
                        else
                            {
                                printf("\n la divicion da: %.2f",resultadoDivicion);

                            }
                        printf("\n el resultado de la multiplicacion es: %.2f",resultadoMultiplicacion);
                        printf("\n el factorial del primer numero es: %lld ",factorialPrimerNumero);
                        printf("\n el factorial del segundo numero es: %lld ",factorialSegundoNumero);
                        printf("\n");
                    }
                    break;
            case 5:
                //Sale del programa
                printf("salio del programa");
                respuesta='n';
                    break;

            default:
                printf(" no ingreso una opcion valida, reingrese una opcion entre 1 y 5 \n");
                    break;




            }//termina el switch de opciones

        }//termina  el while de respuesta

}



