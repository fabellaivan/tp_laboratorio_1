/*
 * Informes.h
 *
 *  Created on: 15 oct 2021
 *      Author: Ivan Fabella
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Informes.h"
#include "BibliotecaEmpleados.h"
/// @fn void MostrarTodosLosEmpleados(eEmpleado[], ePuestoTrabajo[], int, int)
/// @brief Prepara entorno para mostrar los empleados
///
/// @param lista Recibe vector de empleados
/// @param listado Recibe vector de puestos de trabajo
/// @param largo Recibe cantidad de empleados POSIBLES
/// @param largoPuesto Recibe vector con cantidad de puestos de trabajo
void MostrarTodosLosEmpleados(eEmpleado lista[], ePuestoTrabajo listado[],int largo,int largoPuesto);

/// @fn void MostrarUnEmpleado(eEmpleado)
/// @brief Muestra un empleado pedido
///
/// @param unEmpleado Recibe una direccion de memoria vinculada a eEmpleado
void MostrarUnEmpleado(eEmpleado unEmpleado);

/// @fn int CalcularPromedioDeSueldos(eEmpleado[], int, float*, int*)
/// @brief Calcula el promedio de los sueldos
///
/// @param lista Recibe vector para calcular promedio
/// @param largo Recibe cantidad de empleados POSIBLES
/// @param promedio Devuelve por referencia el promedio de los sueldos
/// @param sumaSueldos devuelve por referencia la suma de todos los sueldos
/// @return retorna -1 si no se puedo realizar el calculo o 1 si se pudo.
int CalcularPromedioDeSueldos(eEmpleado lista[], int largo, float* promedio,int* sumaSueldos);

/// @fn void AcumuladorDeSueldos(eEmpleado[], int, float*, int*)
/// @brief Acumula sueldo y cantidad de empleados activos
///
/// @param lista Recibe vector para acumular sueldos
/// @param largo Recibe cantidad de empleados POSIBLES
/// @param acumuluado Devuelve por referencia la suma de todos los sueldos
/// @param unidadesSueldo Devuelve por referencia cuantos sueldos se calcularon
void AcumuladorDeSueldos(eEmpleado lista[], int largo, float* acumuluado,int* unidadesSueldo);

/// @fn void EmpleadosConMayorSueldoDelPromedio(eEmpleado[], int, int, int*)
/// @brief Calcula cuantos empleados ganan por encima del promedio
///
/// @param lista Recive vector para calcular los sueldos
/// @param largo Recibe cantidad de empleados POSIBLES
/// @param promedio Recibe el promedio para comparar
/// @param cantidadMayorAlPromedio Devuelve por referencia cuantos ganan mas que el promedio
void EmpleadosConMayorSueldoDelPromedio(eEmpleado lista[], int largo,int promedio,int* cantidadMayorAlPromedio);

#endif /* INFORMES_H_ */
