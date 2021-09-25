/*
 * Biblioteca.h
 *
 *  Created on: 3 sept 2021
 *      Author: Ivan Fabella
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_


/// @fn void PedirEntero(char[], float*)
/// @brief
///
/// @param mensaje
/// @param refNumeroIngresado
void PedirEntero(char mensaje[],float* refNumeroIngresado);


/// @fn void Suma(float, float, float*)
/// @brief Realiza la suma de dos operandos
///
/// @param numeroA Operando a sumar
/// @param numeroB Operando a sumar
/// @param refResultadoSuma se devuelve por referencia el resultado
void Suma(float numeroA, float numeroB,float* refResultadoSuma);

/// @fn void Resta(float, float, float*)
/// @brief Realiza la resta de dos operandos
///
/// @param numeroA Operando a restar
/// @param numeroB Operando a restar
/// @param refResultadoResta se devuelve por referencia el resultado
void Resta(float numeroA, float numeroB,float* refResultadoResta);

/// @fn void Multiplicacion(float, float, float*)
/// @brief  Realiza la multiplicacion de dos operandos
///
/// @param numeroA Operando a multiplicar
/// @param numeroB Operando a multiplicar
/// @param refResultadoMultiplicacion se devuelve por referencia el resultado
void Multiplicacion(float numeroA, float numeroB,float* refResultadoMultiplicacion);

/// @fn int Division(float, float, float*)
/// @brief Realiza la divicion de dos operando
///
/// @param numeroA Operando que ocupara el lugar del dividendo
/// @param numeroB Operando que ocupara el lugar del divisor
/// @param refResultadoDivicion se devuelve por referencia el resultado
/// @return retorna 0 cuando no se pudo resolver la divicion por parametro numeroB=0 o 1 cuando se puedo calcular la division
int Division(float numeroA, float numeroB,float* refResultadoDivicion);

/// @fn int factorial(float, float*)
/// @brief
///
/// @param numeroF
/// @param resultado
/// @return
int factorial(float numeroF,float* resultado);


#endif /* BIBLIOTECA_H_ */
