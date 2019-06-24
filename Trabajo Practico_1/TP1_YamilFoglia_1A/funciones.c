#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float numeroUno, float numeroDos)
{
    float resultado = numeroUno + numeroDos;

    return resultado;
}

float resta(float numeroUno, float numeroDos)
{
    float resultado = numeroUno - numeroDos;

    return resultado;
}

float division(float numeroUno, float numeroDos)
{
    float resultado = numeroUno / numeroDos;

    return resultado;
}

float multiplicacion(float numeroUno, float numeroDos)
{
    float resultado = numeroUno * numeroDos;

    return resultado;
}

float factorial(float numero)
{
    if(validarFactorial(numero)==0)
    {
        if(numero == 1 || numero == 0)
        {
            return 1;
        }
        else
        {
            return numero * factorial(numero - 1);
        }
    }
    else
    {
        return 0;
    }

}

int validarDivision(float numeroDos)
{
    int resultado = 0;

    if(numeroDos == 0)
    {
        resultado = 1;
    }

    return resultado;
}


int validarNumero(float numero)
{
    int resultado = 0;

    if(numero == 0)
    {
        resultado = 1;
    }

    return resultado;
}

int validarFactorial(float numero)
{
    int resultado = 0;

    if(numero!=(int)numero || numero<0)
    {
        resultado = 1;
    }

    return resultado;
}

//|| numero<0)
