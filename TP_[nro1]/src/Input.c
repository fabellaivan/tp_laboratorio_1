/*
 * Input.c
 *
 *  Created on: 25 sept 2021
 *      Author: Ivan Fabella
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Bibliotecas.h"
#define TAM 10

void PedirNumero(char mensaje[],float* refNumeroIngresado)
{
	setbuf(stdout, NULL);
	float numeroIngresado;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%f",&numeroIngresado);
	*refNumeroIngresado=numeroIngresado;
}
