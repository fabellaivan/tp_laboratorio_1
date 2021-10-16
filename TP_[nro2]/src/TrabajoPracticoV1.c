/*
 ============================================================================
 Name        : TrabajoPracticoV1.c
 Author      : Fabella Ivan
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BibliotecaEmpleados.h"
#include "Informes.h"
#include "InPut.h"
#define TAM 5
#define TAMPUESTOS 3
#define REINTENTOS 3

int main(void) {

	setbuf(stdout, NULL);

		eEmpleado listaEmpleados[TAM];//
		IniciarVectorEmpleado(listaEmpleados, TAM);
		eEmpleado datoId;

		ePuestoTrabajo puestosTrabajo[3]=
		{
				{1,"Programador"},
				{2,"Analista"},
				{3,"Tester"}
		};

		int opcion;
		int opcionMostrar;
		int flagAlta;
		char opcionBorrar;
		int idParaBorrar;
		int testers;
		int contadorId;
		float promedio;
		int sumaSueldos;
		int cantidadMayorAlPromedio;
		int espacioLibreParaId;
		contadorId=1;

		do
		{
			getNumero(&opcion, "\n1. Altas\n2. Modificar\n3. Borrar Cliente ID\n4. INFORMES \n10. Salir\n","Error, debe seleccionar la opcion con un numero", REINTENTOS);
			switch (opcion)
			{
				case 1:
						testers = AgregarEmpleado(listaEmpleados,&espacioLibreParaId,TAM);

						if(testers==1)
						{
							puts("El empleado fue dado de alta exitosamente\n");
							listaEmpleados[espacioLibreParaId]=AltaId(listaEmpleados[espacioLibreParaId],"Su numero de Id es: ", &datoId.idEmpleado, contadorId);
							contadorId++;
							flagAlta=1;
						}
						else
						{
							puts("El empleado no pudo cargarse\n");
						}
				break;

				case 2:
						if(flagAlta==1)
						{
							testers=BuscarEmpleadoParaModificar(listaEmpleados, TAM);
							switch(testers)
								{
								case 0:
										puts("No se encontro El id a modificar, vuelva a intentarlo\n");
								break;
								case -1:
										puts("Se ha canceado la funcion de modificar\n");
								break;
								case 1:
										puts("Se ha modificado el empleado");
								break;
								}
						}
						else
						{
							puts("Aun no se dio de alta ningun usuario\n");
						}


				break;

				case 3:
						if(flagAlta==1)
						{
							getNumero(&idParaBorrar, "Ingrse ID a eliminar: \n", "Error debe seleccionar la opcion con un numero\n", REINTENTOS);
							idParaBorrar=BuscarEmpleadoPorId(listaEmpleados, TAM, testers);
							if(idParaBorrar!=-1)
							{
									puts("El empleado a eliminar es :\n");
									MostrarUnEmpleado(listaEmpleados[idParaBorrar]);
									opcionBorrar=IngresarChar("Seguro desea eliminar ? \n");
									if(opcionBorrar=='s')
									{
										listaEmpleados[idParaBorrar]=RemoverEmpleado(listaEmpleados[idParaBorrar]);
										puts("Se ha eliminado correctamente. \n");
									}
							}
							else
								{
									puts("Se ha seleccionado un ID inexistente\n");
								}
						}
						else
						{
							puts("Aun no se dio de alta ningun usuario\n");
						}

				break;

				case 4:
						if(flagAlta==1)
						{
							getNumero(&opcionMostrar, "\nQue desea ver?\n-1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n-2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n"
									,"Error, debe seleccionar la opcion con un numero", REINTENTOS);
							switch(opcionMostrar)
							{
							case 1:
								OrdenarPorPuesto(listaEmpleados, TAM);
								MostrarTodosLosEmpleados(listaEmpleados,puestosTrabajo, TAM, TAMPUESTOS);
							break;
							case 2:
								if(CalcularPromedioDeSueldos(listaEmpleados, TAM, &promedio,&sumaSueldos) == 1)
								{
								    printf("\nEl promedio de sueldos es de : %.2f", promedio);
								    EmpleadosConMayorSueldoDelPromedio(listaEmpleados,TAM, promedio,&cantidadMayorAlPromedio);
								    printf(" y hay %d  que superan el promedio.\n",cantidadMayorAlPromedio);
								}
								else
									{
									    puts("\nNo se pudo calcular el promedio.\n");
									}

							break;
							}

						}//Fin if
						else
						{
							puts("Aun no se dio de alta ningun usuario\n");
						}

				break;
				case 10:
					puts("\nADIOS\n");
				break;

				default:
						puts("\nSe ha seleccionado una opcion no valida\n");
				break;

				/*;*/

			}

		} while (opcion != 10);

		return EXIT_SUCCESS;
	}




