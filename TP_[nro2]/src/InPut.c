/*
 * InPut.c
 *
 *  Created on: 27 sept 2021
 *      Author: Ivan Fabella
 */

#include "InPut.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


int getString(char cadena[],char mensaje[],int reintentos,int tam)
{
	setbuf(stdout,NULL);
	char auxiliarString[1000];
	int valido;
	int retorno;
	int largo;
	if (cadena != NULL && mensaje != NULL)
	{
		do
		{
			if(reintentos==0)
			{
				retorno=0;
				break;
			}

			printf(mensaje);
			fflush(stdin);
			fgets(auxiliarString,21,stdin);
			largo=strlen(auxiliarString);
			valido=0;
			if( largo > tam )
			{
				reintentos--;
				valido=1;
				printf("Ingreso demaciados caracteres. Quedan %d intentos\n",reintentos);
			}
			if(auxiliarString[0]==' '||auxiliarString[0]=='\n')
			{
				reintentos--;
				valido=1;
				printf("Por favor, no ingrese espacios o enter en primer lugar. Quedan %d intentos\n",reintentos);
			}
			if(valido==0)
			{
				valido=ValidaLetrasEspacio(auxiliarString,"Por favor, ingrese solo letras,",largo);
				if(valido==1)
				{
					reintentos--;
					printf(" quedan %d intentos\n",reintentos);
					valido=1;
				}
			}

		}while(valido!=0);

		if(valido==0)
		{
			auxiliarString[largo-1]='\0';
			strcpy(cadena, auxiliarString);
			retorno=1;
		}

	}
	return retorno;
}
int ValidaLetrasEspacio(char cadena[],char mensaje[], int largo)
{
	setbuf(stdout,NULL);
	int valido=0;
	for(int i=0;i<largo-1;i++)
	{
		if((cadena[i]<'a'||cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z')&&!(cadena[i]==' '))
		{
			valido=1;
			printf(mensaje);
			break;
		}
	}
	return valido;
}
char IngresarChar(char mensaje[])
{
	char opcion;
	fflush(stdin);
	printf("%s",mensaje);
	scanf("%c",&opcion);
	opcion=tolower(opcion);


	return opcion;

}
int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}

int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[1000];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}

int getNumero(int* pResultado, char* mensaje, char* mensajeError,  int reintentos)
{
	int retorno=0;
	int buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
	{
		do
			{
				printf("%s",mensaje);
				if(getInt(&buffer)==0)
				{
					*pResultado=buffer;
					retorno= 1;
					break;
				}
				reintentos--;
				printf("%s",mensajeError);

			}while(reintentos>=0);

	}


	return retorno;
}
int esNumerica(char* cadena)
{
	int retorno=1;
	int i=0;
	if(cadena[0]=='-')
	{
		i=1;
	}
	for(;cadena[i] != '\0';i++)
	{
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}
