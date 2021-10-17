/*
 * Informes.c
 *
 *  Created on: 15 oct 2021
 *      Author: Ivan Fabella
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Informes.h"

#include "BibliotecaEmpleados.h"
#define EMPTY 0
#define FULL 1

void MostrarTodosLosEmpleados(eEmpleado lista[],ePuestoTrabajo listado[], int largo,int largoPuesto)
{
	printf("Sector         Nombre        Apellido        Sueldo\n");

	for(int i=0;i<largoPuesto;i++)
	{
		printf("%s: \n",listado[i].descripcion);
		for(int j=0;j<largo;j++)
		{
			if(listado[i].idPuesto==lista[j].idPuesto && (lista[j].isEmpty==FULL))
			{
		 		printf("\t");
				MostrarUnEmpleado(lista[j]);
			}
		}

	}
}


void MostrarUnEmpleado(eEmpleado unEmpleado)
{
	printf("\t%-8s     %-10s %10.2d \n",unEmpleado.nombre,unEmpleado.apellido,unEmpleado.sueldo);

}

void OrdenarPorPuesto(eEmpleado lista[], int largo)
{
    int i;
    eEmpleado aux;
    int j;

    for(i=0;i<largo-1;i++)
    {
        for(j=i+1;j<largo;j++)
        {
        	if(strcmp(lista[i].apellido,lista[j].apellido)<0)
        	{
        		//if(lista[i].idProducto<lista[j].idProducto)
        		//if(strcmp(lista[i].idPuesto,lista[j].idPuesto ) < 0)
        		if(lista[i].idPuesto>lista[j].idPuesto)
        		{
        		   aux = lista[i];
        		   lista[i] = lista[j];
        		   lista[j] = aux;
        		}
        	}


        }
    }

}
int CalcularPromedioDeSueldos(eEmpleado lista[], int largo, float* promedio,int* sumaSueldos)
{
    int retorno;
    int cantidadEmpleados=0;
    retorno = -1;
    float acumuladorSueldos;
    acumuladorSueldos = 0;
    if(promedio != NULL && lista != NULL && largo > 0)
    {
    	AcumuladorDeSueldos(lista, largo, &acumuladorSueldos,&cantidadEmpleados);
        retorno = 1;
    }
    *promedio = acumuladorSueldos / cantidadEmpleados;
    *sumaSueldos=acumuladorSueldos;
    return retorno;
}
void AcumuladorDeSueldos(eEmpleado lista[], int largo, float* sueldoAcumuluado,int* unidadesSueldo)
{
	int i;
    float acumuladorSueldos;
    int cantidadEmpleados=0;
	for(i=0; i<largo; i++)
	{
	  	if(lista[i].isEmpty==FULL)
	   	{
	   		acumuladorSueldos += lista[i].sueldo;
	   		cantidadEmpleados++;
	   	}
    }
	*sueldoAcumuluado=acumuladorSueldos;
	*unidadesSueldo=cantidadEmpleados;
}
void EmpleadosConMayorSueldoDelPromedio(eEmpleado lista[], int largo,int promedio,int* cantidadMayorAlPromedio)
{
	int i;
	int contadorMayores=0;
	for(i=0;i<largo;i++)
	{
		if(lista[i].isEmpty==FULL&&lista[i].sueldo>promedio)
		{
			contadorMayores++;
		}
	}
	*cantidadMayorAlPromedio=contadorMayores;
}




















