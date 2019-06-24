#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float numeroUno, numeroDos;
    float resultadoSuma, resultadoResta, resultadoDivision, resultadoMultiplicacion, resultadoFactorialA, resultadoFactorialB;
    int errorEnDivision;
    int errorEnFactorialUno;
    int errorEnFactorialDos;
    int errorEnNumeroUno;
    int errorEnNumeroDos;
    int flagnumeroUno = 0;
    int flagnumeroDos = 0;
    int cambiarNumeroUno = 0;
    int cambiarNumeroDos = 0;
    int calculo;
    int flag = 1;

    while(flag==1)
    {
        printf("                      >-----------------------------<\n");
        printf("                      |   Calculadora Foglia Yamil  |\n");
        printf("                      |        Divicion A           |\n");
        printf("                      >-----------------------------<\n\n\n");

        printf("Menu de opciones: \n\n 1-Ingresar 1er operando (A=x): \n 2-Ingresar 2do operando(B=y): \n 3-Calcular todas las operaciones \n 4-Informar resultados \n 5-Salir \n\n");

        if (flagnumeroUno == 1)
        {
            printf("Primer numero (A= %.2f) \n",numeroUno);
        }

        if (flagnumeroDos == 1)
        {
            printf("Segundo numero (B= %.2f) \n",numeroDos);
        }

        printf("\nTranscribir el numero que corresponda a la opcion que quiera realizar: ");
        scanf("%d", &calculo);

        switch(calculo)
        {
            case 1:

                if (flagnumeroUno == 0)
                {
                    printf("\n\nIngrese el primer numero: ");
                    scanf("%f", &numeroUno);

                    errorEnNumeroUno = 1;
                    flagnumeroUno = 1;
                }
                else
                {
                    printf("\nYa ingreso un numero en la primer opcion\n\n Quiere cambiar el numero ingresado:\n 1-Si\n 2-No\n ");
                    scanf("%d",&cambiarNumeroUno);

                    if (cambiarNumeroUno == 1)
                    {
                        printf("\nEl numero a sido borrado.\nVuelva a ingresar a la opcion 1 para ingresar el numero que usted quiera.");
                        flagnumeroUno = 0;
                    }
                }

                    break;

            case 2:

                if (flagnumeroDos == 0)
                {
                    printf("\n\nIngrese el segundo numero: ");
                    scanf("%f", &numeroDos);

                    errorEnNumeroDos = 1;
                    flagnumeroDos = 1;

                }
                else
                {
                    printf("\nYa ingreso un numero en la segunda opcion\n\n Quiere cambiar el numero ingresado:\n 1-Si\n 2-No\n ");
                    scanf("%d",&cambiarNumeroDos);

                    if (cambiarNumeroDos == 1)
                    {
                        printf("\nEl numero a sido borrado.\nVuelva a ingresar a la opcion 2 para ingresar el numero que usted quiera.");
                        flagnumeroDos = 0;
                    }
                }


                    break;

            case 3:

                printf("\n\n                           Operacion calculadoras...\n\n\n");

                resultadoSuma=suma(numeroUno, numeroDos);

                resultadoResta=resta(numeroUno, numeroDos);

                resultadoMultiplicacion=multiplicacion(numeroUno, numeroDos);

                errorEnDivision=validarDivision(numeroDos);
                resultadoDivision=division(numeroUno, numeroDos);

                errorEnFactorialUno=validarFactorial(numeroUno);
                resultadoFactorialA=factorial(numeroUno);

                errorEnFactorialDos=validarFactorial(numeroDos);
                resultadoFactorialB=factorial(numeroDos);

                    break;

            case 4:

                system("cls");
                if (errorEnNumeroUno==1 || errorEnNumeroDos==1)
                {
                    //Suma.
                    printf("Suma (A+B): %.2f \n", resultadoSuma);

                    //Resta.
                    printf("Resta (A-B): %.2f \n", resultadoResta);

                    //Multiplicacion.
                    printf("Multiplicacion (A*B): %.2f \n", resultadoMultiplicacion);

                    //Division.
                    if (errorEnDivision==0)
                    {
                        printf("Division (A/B): %.2f \n", resultadoDivision);
                    }
                    else
                    {
                        printf("Error. El divisor no puede ser 0\n");
                    }

                    //FactorialA.
                    if(errorEnFactorialUno == 0)
                    {
                        printf("Factorial de A (A!): %.2f \n", resultadoFactorialA);
                    }
                    else
                    {
                        printf("Error. No es posible realizar el factorial de un numero negativo o con coma\n");
                    }

                    //FactorialB.
                    if(errorEnFactorialDos == 0)
                    {
                        printf("Factorial de B (B!): %.2f \n", resultadoFactorialB);
                    }
                    else
                    {
                        printf("Error. No es posible realizar el factorial de un numero negativo o con coma\n");
                    }
                }
                else
                {
                    printf("Error. Debe ingresar los dos numeros para realizar los calculos \n");

                        break;
                }

                    break;

            case 5:

                flag = 1;

                return 0;

                    break;

            default:

                printf("El numero ingresado no es una opcion\n\n");
        }
    system("pause");
    system("cls");

    }

    return 0;
}


