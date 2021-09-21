/*
 ============================================================================
 Name        : Calculadora.c
 Author      : Fabella Ivan Maximiliano
 Version     : 2
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Biblioteca.h"

int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	float numeroA;
	float numeroB;
	int flagNumero1;
	int flagNumero2;
	int flagCalculos;
	char salir;
	int validacionDivicion;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorialA;
	float resultadoFactorialB;
	opcion='n';
	flagNumero1=0;
	flagNumero2=0;
	flagCalculos=0;

	do{
		printf("\n1. Ingrese 1er operando (A=");
		if(flagNumero1==0)
		{
			printf("X)\n");
		}else
		{
			printf("%.2f)\n",numeroA);
		}

		printf("2. Ingrese 2do operando (B=");
				if(flagNumero2==0)
				{
					printf("X)\n");
				}else
				{
					printf("%.2f)\n",numeroB);
				}

		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		scanf("%d",&opcion);

		switch(opcion){
		case 1:
				PedirEntero("Ingrese numero A: \n",&numeroA);
				flagNumero1++;
				flagCalculos=0;
		break;

		case 2:
				PedirEntero("Ingrese numero B: \n",&numeroB);
				flagNumero2++;
				flagCalculos=0;
		break;

		case 3:
			if(flagNumero1==0||flagNumero2==0)
			{
				printf("\nFalta cargar alguno de los operandos\n");
			}
			else
			{

				Suma(numeroA,numeroB,&resultadoSuma);
				Resta(numeroA,numeroB,&resultadoResta);
				Multiplicacion(numeroA,numeroB,&resultadoMultiplicacion);
				validacionDivicion=Division(numeroA,numeroB,&resultadoDivision);
				resultadoFactorialB=factorial(numeroB);
				resultadoFactorialA=factorial(numeroA);
				flagCalculos++;

				printf("\nSe relizaron los calculos\n\n");
			}
		break;

		case 4:
			if(flagCalculos==0)
			{
				printf("Aun no se calcularon los resultados. \n");
			}
			else
			{
				printf("El resultado de A+B es %.2f\n",resultadoSuma);

				printf("El resultado de A-B es %.2f\n",resultadoResta);

				printf("El resultado de A*B es %.2f\n",resultadoMultiplicacion);

				if(validacionDivicion==0)
				{
					printf("No se pudo calcular la division.  No se puede dividir entre cero\n ");
				}
				else
				{
					printf("El resultado de la division es %.2f\n",resultadoDivision);
				}

				if(resultadoFactorialA==0)
				{
					printf("El operando A esta fuera de rango para factorizar. Debe ser mayor a 0 y menor a 12 y \n");
				}
				else
				{
					printf("El factorial de A es: %.2f y ",resultadoFactorialA);
				}

				if(resultadoFactorialB==0)
				{
					printf("El operando B esta fuera de rango para factorizar. Debe ser mayor a 0 y menor a 12\n\n");
				}
					else
					{
						printf("el factorial de B es: %.2f\n\n",resultadoFactorialB);
					}
				flagCalculos=0;
				flagNumero1=0;
				flagNumero2=0;
			}

		break;

		case 5:
			printf("Seguro desea salr ? \n");
			fflush(stdin);
			scanf("%c",&salir);
			salir=tolower(salir);

			if(salir=='s')
			{
				printf("\n ADIOS \n");
			}
		break;


		default :
			printf("Opcion no valida\n");
		break;

		}

	}while(salir!='s');

	return EXIT_SUCCESS;
}
