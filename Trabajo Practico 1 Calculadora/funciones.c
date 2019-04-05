#include <stdio.h>
#include <stdlib.h>






/** \brief Suma dos valores ingresados y devuelve el resultado
 *
 * \param A es el primer operando flotante
 * \param B es el segundo operando flotante
 * \return el total de la suma de A+B
 *
 */

float suma (float A, float B)
{
    float total;
    total=A+B;
    return total;
}


/** \brief Resta dos valores ingresados y devuelve el resultado
 *
 * \param A es el primer opernado flotante
 * \param B es el segundo operando flotante
 * \return el total de la resta de A-B
 *
 */

float resta (float A,float B)
{
    float total;
    total=A-B;
    return total;

}
/** \brief Divide dos flotantes y devuelve el resultado o -1 para indicar que el segundo operando es 0
 *
 * \param A es el primer  operando flotante
 * \param B es el segundo operando flotante
 * \return el total de la divicion de A/B y para el caso que se divida por 0 retornara -1
 *
 */

float divicion(float A, float B)
{
    float total;

    if(B==0)
        {
            total=-1;
        }else
            {
                total=A/B;

            }
            return total;

}

/** \brief Multiplica dos numeros flotantes y devuelve el resultado
 *
 * \param A es el primer flotante
 * \param B es el segundo flotante
 * \return el total de la multiplicacion A*B
 *
 */

float multiplicacion(float A, float B)
{
    float total;
    total=A*B;
    return total;

}

/** \brief Calcula el factorial de un flotante y devuelve el resultado o un mensaje que indica que no se puede calcular el factorial de un numero negativo/no se puede sacar el factorial de un numero decimal
 *
 * \param A el flotante que sera factoriado
 * \return devuelve el resultado del factoreo de A o un mensaje que indica que no se puede calcular el factorial de un numero negativo/no se puede sacar el factorial de un numero decimal
 *
 */

long long int factorial(float A)
{
    long long int factorialPrimerNumero=1;
    int AuxX=(int)A;
    if(A<0)
        {
            printf("No se puede sacar el factorial de un operando negativo");
        }
        else
            {
                if(A!=AuxX)
                    {
                        printf("No se puede sacar el factorial de un operando decimal");
                    }
                    else
                        {

                            for (int i=1; i<=(int)A; i++)
                            {
                                factorialPrimerNumero=factorialPrimerNumero*i;
                            }

                        }

            }



                return factorialPrimerNumero;

}




