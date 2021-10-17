/*
 * ArrayEmployees.h
 *
 *  Created on: 15 oct 2021
 *      Author: Ivan Fabella
 */

#ifndef BIBLIOTECAEMPLEADOS_H_
#define BIBLIOTECAEMPLEADOS_H_
typedef struct
{
	int idPuesto;
	char descripcion[50];
}ePuestoTrabajo;

typedef struct
{
	int idEmpleado;
	char apellido[50];
	char nombre[50];
	int sueldo;
	int idPuesto;
	int isEmpty;
}eEmpleado;

/// @fn eEmpleado AltaId(eEmpleado, char[], int*, int, int)
/// @brief Realiza el alta de ID para empleado
///
/// @param lista recibe un empleado para asignarle ID
/// @param mensaje Mensaje de informe
/// @param numeroAlta devuelve por referencia el numero de alta para el proximo empleado
/// @param contadorId recibe el ID para asignar al empleado
/// @return retorna el empleado con su ID
eEmpleado AltaId(eEmpleado lista,char mensaje[],int* numeroAlta,int contadorId);

/// @fn int AgregarEmpleado(eEmpleado[], int*, int)
/// @brief Prepara entorno para agregar empleado
///
/// @param lista recibe vector de empleados
/// @param espacioId devuelve espacio libre para el ID
/// @param largo Recibe cantidad de empleados POSIBLES
/// @return retorna 1 si el empleado se pudo cargar, sino -1
int AgregarEmpleado(eEmpleado lista[],int* espacioId, int largo);

/// @fn eEmpleado IngresarUnEmpleado(eEmpleado)
/// @brief Ingresa los campos del empleado
///
/// @param lista recibe un empleado
/// @return retorna el empleado creado
eEmpleado IngresarUnEmpleado(eEmpleado lista);

/// @fn void OrdenarPorPuesto(eEmpleado[], int)
/// @brief Ordena la lista de empleados por puesto
///
/// @param lista recibe vector de empleado
/// @param largo Recibe cantidad de empleados POSIBLES
void OrdenarPorPuesto(eEmpleado lista[], int largo);

/// @fn int ContarPorPuesto(eEmpleado[], int, char[])
/// @brief
///
/// @param lista
/// @param largo
/// @param puesto
/// @return

/// @fn void IniciarVectorEmpleado(eEmpleado[], int)
/// @brief Inicializa el vector empleado con EMPTY
///
/// @param lista recibe vector de empelados
/// @param largo Recibe cantidad de empleados POSIBLES
void IniciarVectorEmpleado(eEmpleado lista[], int largo);

/// @fn int BuscarPrimerEspacioLibre(eEmpleado[], int, int*)
/// @brief Busca espacio libre para agregar empleado
///
/// @param lista recibe vector de empleados
/// @param tam Recibe cantidad de empleados POSIBLES
/// @param espacioLibre devuelve por referencia el espacio libre
/// @return retoran 1 si encontro espacio libre 0 si no
int BuscarPrimerEspacioLibre(eEmpleado lista[], int tam,int* espacioLibre);

/// @fn int BuscarEmpleadoPorId(eEmpleado[], int, int)
/// @brief Busca empleado segun su ID
///
/// @param lista recive vector de empleado
/// @param tam Recibe cantidad de empleados POSIBLES
/// @param id recibe el ID del empleado a encontrar
/// @return retorna -1 si el empleado no se encontro o el numero de id empleado
int BuscarEmpleadoPorId(eEmpleado lista[], int tam, int id);

/// @fn eEmpleado RemoverEmpleado(eEmpleado)
/// @brief Pone EMPTY al empleado seleccionado en isEmpty
///
/// @param lista recibe un empleado
/// @return retorna el empleado modificado
eEmpleado RemoverEmpleado(eEmpleado lista);

/// @fn int BuscarEmpleadoParaModificar(eEmpleado[], int)
/// @brief Busqueda de empleado a modificar
///
/// @param lista recibe vector de empleado
/// @param tam Recibe cantidad de empleados POSIBLES
/// @return
int BuscarEmpleadoParaModificar(eEmpleado lista[], int tam);

/// @fn eEmpleado ConfirmacionDeModificarEmpleado(eEmpleado, char[], char[], int*)
/// @brief Se le muestra al usuario el empleado a modificar y se le pide confirmacion
///
/// @param lista recibe empleado a modificar
/// @param mensajeCualAModificar Mensaje que muestra el empleado a modificar
/// @param mensajeParaConfirmar pedido de confirmacion para modificar
/// @param retorno 0 Si se cancela la modificacion en esta funcion . 1 Si se realizo la modificacion. -1 Si se cancelo la modificacion en ModificarEmpleado
/// @return retorna el empleado modificado si corresponde
eEmpleado ConfirmacionDeModificarEmpleado(eEmpleado lista,char mensajeCualAModificar[], char mensajeParaConfirmar[],int* retorno);

/// @fn eEmpleado ModificarEmpleado(eEmpleado, char[], int*)
/// @brief Modifica opciones del empleado
///
/// @param elEmpleado recibe empleado a modificar
/// @param mensaje Lista de opciones para modificar
/// @param refVerificacion devuelve por referencia 1 si se pudo modificar o 2 si no se pudo modificar
/// @return retorna empleado modificado si corresponde
eEmpleado ModificarEmpleado(eEmpleado elEmpleado,char mensaje[],int* refVerificacion);
int BuscarEspacioUtilizado(eEmpleado lista[], int tam);

#endif /* BIBLIOTECAEMPLEADOS_H_ */
