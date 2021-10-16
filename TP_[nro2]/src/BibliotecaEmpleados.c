/*
 * ArrayEmployes.c
 *
 *  Created on: 15 oct 2021
 *      Author: Ivan Fabella
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "BibliotecaEmpleados.h"
#include "Informes.h"
#include "InPut.h"
#define EMPTY 0
#define FULL 1
#define TAM 10000// cantidad de altas
#define REINTENTOS 3

void IniciarVectorEmpleado(eEmpleado lista[], int largo)
{
    for(int i = 0;i < largo; i++)
    {
        lista[i].isEmpty = EMPTY;
    }
}
int AgregarEmpleado(eEmpleado lista[],int* espacioId,int largo)
{
	int espacioLibre;
	int index = BuscarPrimerEspacioLibre(lista, largo,&espacioLibre);

	if(index==1)
	{
		lista[espacioLibre] = IngresarUnEmpleado(lista[espacioLibre]);
		if(lista[espacioLibre].isEmpty==EMPTY)
		{
			index=-1;
		}
		else
		{
			*espacioId=espacioLibre;
		}

	}
return index;

}

int BuscarPrimerEspacioLibre(eEmpleado lista[], int tam,int* espacioLibre)
{
	int i;
	int retorno =0;
	for(i = 0; i<tam; i++)
	{
		if(lista[i].isEmpty == EMPTY)
		{
			*espacioLibre = i;
			retorno=1;
			break;
		}
	}
	return retorno;
}

eEmpleado IngresarUnEmpleado(eEmpleado lista)
{
	eEmpleado dato;
	int validar=0;
	int validacionWhile=0;
	do
	{
		validar=getString(dato.apellido, "\nIngrese el apellido: \n",REINTENTOS, 50);
		if(validar==0)
		{
			break;
		}

		validar=getString(dato.nombre, "\nIngrese el nombre: \n",REINTENTOS, 50);
		if(validar==0)
		{
			break;
		}

		validar=getNumero(&dato.sueldo, "Ingrese el sueldo: \n", "Error, vuelva a intentarlo", REINTENTOS);
		if(validar==0)
		{
			break;
		}

		validar=getNumero(&dato.idPuesto , "Ingrese\n 1.-Programador\n 2-Analista\n 3-Tester: \n", "Vuelva a intentar con solo numeros\n", 3);
		if(validar==0||dato.idPuesto<1||dato.idPuesto>3)
		{
			validar=0;
			printf("Ingreso una opcion Erronea\n");
			break;
		}

	}while(validacionWhile!=0);


	if(validar==1)
	{
		dato.isEmpty=FULL;

	}
	else
	{
		dato.isEmpty=EMPTY;
	}
	return dato;


}

eEmpleado AltaId(eEmpleado lista,char mensaje[],int* numeroAlta,int contadorId)
{

		lista.idEmpleado=contadorId;

		printf("%s %d",mensaje,contadorId++);
		*numeroAlta=contadorId++;
		return lista;

}

int BuscarEmpleadoPorId(eEmpleado lista[], int tam, int id)
{
	int i;
	int index;

	index = -1;
	for(i = 0; i<tam; i++){
		if(lista[i].isEmpty==FULL && lista[i].idEmpleado == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int BuscarEmpleadoParaModificar(eEmpleado lista[], int tam)
{
	int id;
	int idAux;
	int retorno=-1;
	int testers;


	testers=getNumero(&idAux,"Ingrse ID a modificar: \n","Vuelva a intentar con solo numeros\n", 3);

	if(testers==1)
	{
		id=BuscarEmpleadoPorId(lista,tam,idAux);
	}
	if(!(id==-1)&&(testers==1))
	{
		lista[id]=ConfirmacionDeModificarEmpleado(lista[id],"El Empleado a modificar es :\n", "Desea continuar con la modificacion S o N  ?\n",&testers);
		if(testers==1)
		{
			retorno=1;
		}
	}
	return retorno;
}

eEmpleado ConfirmacionDeModificarEmpleado(eEmpleado lista,char mensajeCualAModificar[], char mensajeParaConfirmar[],int* retorno)
{
	char opcion;
	int validacionModificado;
	int validar=0;
	printf(mensajeCualAModificar);
	MostrarUnEmpleado(lista);
	opcion=IngresarChar(mensajeParaConfirmar);

	if(opcion=='s')
	{
		lista=ModificarEmpleado(lista,"\n1-Modificar Nombre\n2-Modificar Apellido\n3- Sueldo\n4-Puesto \n",&validacionModificado);
			if(validacionModificado==1)
		{
			MostrarUnEmpleado(lista);
			validar=1;
		}
		else
		{
			validar=-1;
		}
	}
	*retorno=validar;
	return lista;

}


eEmpleado ModificarEmpleado(eEmpleado elEmpleado,char mensaje[],int* refVerificacion)
{
	setbuf(stdout, NULL);
	char opcionSeguir;
	int opcionModificarParte;
	int testers;
	do{
		testers=getNumero(&opcionModificarParte,mensaje,"Vuelva a intentar con solo numeros\n",3);
		if(testers==1)
		{
			switch(opcionModificarParte)
			{
			case 1:
					testers=getString(elEmpleado.nombre, "Ingrese el nombre nuevo: ",REINTENTOS, 50);
			break;
			case 2:
					testers=getString(elEmpleado.apellido, "Ingrese el apellido nuevo: ",REINTENTOS, 50);

			break;
			case 3:
					testers=getNumero(&elEmpleado.sueldo, "Ingrese el sueldo nuevo : ", "Error", REINTENTOS);
			break;
			case 4:
					testers=getNumero(&elEmpleado.idPuesto, "Ingrese puesto (Programador - Analista - Tester): ","Vuelva a intentar con solo numeros\n", 3);
			break;
			default:
					puts("Opcion Invalida");
					*refVerificacion=0;
			break;

			}
			opcionSeguir=IngresarChar("Desea continuar con la modificacion  S o N?\n");
		}

	}while(opcionSeguir=='s');

		if(testers!=0)
		{
			*refVerificacion=1;
		}


		return elEmpleado;
}

eEmpleado RemoverEmpleado(eEmpleado lista)
{
	lista.isEmpty=EMPTY;

	return lista;
}

