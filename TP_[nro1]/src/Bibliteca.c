/*
 * Bibliteca.c
 *
 *  Created on: 3 sept 2021
 *      Author: Ivan Fabella
 */

#include "Biblioteca.h"

/// @fn int Suma(int, int)
/// @brief Funcion que suma dos operandos
///
/// @param numeroA Operando ingresado como primer numero para calculo
/// @param numeroB Operando ingresado como segundo numero para calculo
/// @return Retorna el resultado del calculo
int Suma(int numeroA, int numeroB)
{
	int resultado;
	resultado=numeroA+numeroB;
	return resultado;
}

/// \fn int Resta(int, int)
/// \brief Funcion de RESTAR dos operandos
///
/// @param numeroA Operando ingresado como primer numero para calculo
/// @param numeroB Operando ingresado como segundo numero para calculo
/// @return Retorna el resultado del calculo
int Resta(int numeroA, int numeroB)
{
	int resultado;
	resultado=numeroA-numeroB;
	return resultado;
}

/// @fn int Multiplicacion(int, int)
/// @brief Funcion de MULTIPLICAR dos operandos
///
/// @param numeroA Operando ingresado como primer numero para calculo
/// @param numeroB Operando ingresado como segundo numero para calculo
/// @return Retorna el resultado del calculo
int Multiplicacion(int numeroA, int numeroB)
{
	int resultado;
	resultado=numeroA*numeroB;
	return resultado;
}

/// @fn float Division(int, int)
/// @brief Funcion de divicion de dos operandos
///
/// @param numeroA Operando ingresado como primer numero para calculo
/// @param numeroB Operando ingresado como segundo numero para calculo
/// @return Retorna 0 si el @param "numeroB" recibe '0' o Retorna resultado del calculo
float Division(int numeroA, int numeroB)
{
	float resultado;
	if(numeroB==0)
	{
		return 0;
	}
	else
	{
		resultado=(float)numeroA/numeroB;
		return resultado;
	}
}

/// @fn int factorial(int)
/// @brief Funcion para factoriar un operando
///
/// @param numero Operando  a factorizar
/// @return Retorna '0' si los valores son mayores a 12 o menores a 0 O el resultado del factorial
int factorial(int numeroF)
{

	int factorial;
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


