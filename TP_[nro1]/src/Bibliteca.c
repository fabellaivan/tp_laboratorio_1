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
#define TAM 10

void PedirEntero(char mensaje[],float* refNumeroIngresado)
{
	setbuf(stdout, NULL);
	float numeroIngresado;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%f",&numeroIngresado);
	*refNumeroIngresado=numeroIngresado;
}


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


int factorial(float numeroF,float* resultado)
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
		*resultado=factorial;
		return 1;
	}
}


