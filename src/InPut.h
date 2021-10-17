/*
 * InPut.h
 *
 *  Created on: 27 sept 2021
 *      Author: Ivan Fabella
 */

#ifndef INPUT_H_
#define INPUT_H_
#include "InPut.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "BibliotecaEmpleados.h"
#include "Informes.h"
/// @fn int myGets(char*, int)
/// @brief Valida el largo de la cadena
///
/// @param cadena devuelve la cadena con \0
/// @param longitud
/// @return
int myGets(char* cadena, int longitud);

/// @fn int getInt(int*)
/// @brief busca validar que sea solo nmero y que no sobrepase
///
/// @param pResultado devuelve la cadena como int con atoi
/// @return retorna -1 si fallo o 0 si salio bien
int getInt(int* pResultado);

/// @fn int getNumero(int*, char*, char*, int)
/// @brief Verifica si es solo numero lo ingresado
///
/// @param pResultado devuelve por referencia el numero
/// @param mensaje Mensaje
/// @param mensajeError Mensaje de error
/// @param reintentos intentos disponibles
/// @return retorna 0 si algo fallo . Retorna 1 si salio OK
int getNumero(int* pResultado, char* mensaje, char* mensajeError, int reintentos);

/// @fn int esNumerica(char*)
/// @brief verifica que los caracteres sean solo numeros
///
/// @return retorna 1 si salio todo OK o 0 si algun caracter no es numero
int esNumerica(char* cadena);

/// @fn char IngresarChar(char[])
/// @brief Opcion para ingresar caracter //se puede mejorar
///
/// @param mensaje recibe mensaje para usuario
/// @return retorna caracter
char IngresarChar(char mensaje[]);

/// @fn int getString(char[], char[], int, int)
/// @brief  Valida que sea solo letras lo ingresado
///
/// @param cadena recibe una cadena
/// @param mensaje recibe mensaje para usr
/// @param reintentos intentos disponibles
/// @param tam recibe el tamaño maximo de caracteres
/// @return retorna 0 si se alcanzaron la cantidad maxima de intentos o 1 si salio bien
int getString(char cadena[],char mensaje[],int reintentos,int tam);

/// @fn int ValidaLetrasEspacio(char[], char[], int)
/// @brief  Valida el ingreso de letras y espacios
///
/// @param cadena recibe cadena a corroborar
/// @param mensaje mensaje de error para usr
/// @param largo recibe el largo de la cadena
/// @return retorna 0 si salio ok. 1 si algun caracter no es letra o espacio
int ValidaLetrasEspacio(char cadena[],char mensaje[], int largo);

#endif /* INPUT_H_ */
