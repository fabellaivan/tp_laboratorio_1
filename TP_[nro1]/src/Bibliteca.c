/*
 * Bibliteca.c
 *
 *  Created on: 3 sept 2021
 *      Author: Ivan Fabella
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblioteca.h"

void PedirEntero(char mensaje[],float* refNumeroIngresado)
{
	setbuf(stdout, NULL);
	float numeroIngresado;
//	int valido;

	//do{

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%f",&numeroIngresado);
		*refNumeroIngresado=numeroIngresado;
		/*valido=ValidarNumero(numeroIngresado);

	}while(valido==0);
*/


}
/*
int ValidarNumero(float validarNumeros)
{
	setbuf(stdout, NULL);
	int aux;
	aux=validarNumeros;

	if(validarNumero<MINIMO || validarNumero>MAXIMO)
	{
		printf("El numero ingresado no esta entre los valores correspondientes, intente nuevamente\n");
		return 0;
	}

	if(validarNumero>aux)
	{
		printf("Debe ingresar numeros enteros, no decimales\n");
		return 0;
	}

	return 1 ;
}*/

void Suma(float numeroA, float numeroB,float *refResultadoSuma)
{
	*refResultadoSuma=numeroA+numeroB;
}


void Resta(float numeroA, float numeroB,float* refResultadoResta)
{
	*refResultadoResta=numeroA-numeroB;
}


void Multiplicacion(float numeroA, float numeroB,float* refResultadoMultiplicacion)
{
	*refResultadoMultiplicacion=numeroA*numeroB;
}


int Division(float numeroA, float numeroB,float* refResultadoDivicion)
{
	if(numeroB==0)
	{
		return 0;
	}
	else
	{
		*refResultadoDivicion=numeroA/numeroB;
		return 1;;
	}
}


float factorial(float numeroF)
{

	float factorial;
	factorial=1;

	if(numeroF<0||numeroF>12||numeroF==0)
	{
		return 0;
	}
	else
	{
		for(int i=numeroF;i>1;i--)
		{
			factorial=factorial*i;
		}
		return factorial;
	}
}


