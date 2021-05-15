/*
 ============================================================================
 Name        : TP2.c
 Author      : Francisco Cantariño
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico 2
 ============================================================================
 */


#include "UTN.h"
#include "ArrayEmployees.h"




int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int i;
	int j;
	int auxId;
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;
	int bandera;
	int auxEntero;
	auxId=100;
	employee employeeList[TAM];
	if(initEmployees(employeeList, TAM)!=-1)
	{
		do{
			conseguirEnteroConParametros(&opcion,"\nElija opcion:\n1 - Alta.\n2 - Encontrar empleado por ID.\n3 - Quitar empleado.\n4 - Organizar lista.\n5 - Mostrar empleados.\n6 - salir.\n\n", "\nError, elija opcion valida\n", 1, 6,5);
			switch(opcion){
			case 1:
				bandera=0;
				if(searchEmptySpace(employeeList, TAM)!=-1){
					for(i=0;i<1;i++){
						if(conseguirCadenaCaracteres(auxName, "Ingrese nombre de 3 a 50 caracteres: ", "Error, elija un nombre valido.",2, 50,5)!=0){
							break;
						}else if(conseguirCadenaCaracteres(auxLastName, "Ingrese apellido de 3 a 50 caracteres: ", "Error, elija un nombre valido.",2, 50,5)!=0){
							break;
						}else if(conseguirNumeroDecimalConParametros(&auxSalary,"Ingrese sueldo, entre 30000 y 90000", "Error, elija un sueldo valido.", 30000, 90000, 5)!=0){
							break;
						}else if(conseguirEnteroConParametros(&auxSector,"Ingrese sector, de 1 a 5", "Error, elija un sector valido.",1, 5,5)!=0){
							break;
						}
						for(j=0;j<TAM;j++){
							if(employeeList[j].isEmpty==1&&employeeList[j].id>=auxId){
							auxId=employeeList[j].id+1;
							}
						}
						bandera=1;
					}
					if (bandera==1){
						addEmployee(employeeList, TAM, auxId, auxName,auxLastName,auxSalary,auxSector);
						printf("\nUsuario cargado.");
					}else{
						printf("\nNo se pudo ingresar empleado.\n");
					}
				}else{
					printf("\nNo hay espacio para otro empleado.\n");
				}

				break;
			case 2:
				if(checkAvailableEmployee(employeeList, TAM)!=-1){
					do{}while(conseguirEntero(&auxEntero, "\nIngrese ID.", "\nNo es un numero valido.")==-1);
					if(findEmployeeById(employeeList, TAM,auxEntero)!=-1){
							auxEntero=findEmployeeById(employeeList, TAM,auxEntero);
							printEmployee(employeeList, auxEntero);
						}else{
							printf("\nNo hay empleado con esa ID.");
						}
				}else{
					printf("\nNo hay empleados para mostrar");
				}
				break;
			case 3:
				if(printEmployees(employeeList, TAM)!=-1){
					do{}while(conseguirEntero(&auxId, "\n\n\nIngrese ID del empleado a eliminar.", "\nNo es una ID valida.")==-1);
				}
				if(findEmployeeById(employeeList, TAM,auxId)!=-1){
					printf("\n¿Desea eliminar el empleado?");
					do{}while(conseguirEnteroConParametros(&auxEntero,"\n1 - Si.\n2 - No.", "Error, elija una opcion disponible.", 1, 2,5)==-1);
					switch(auxEntero){
					case 1:
						removeEmployee(employeeList,TAM, auxId);
						break;
					case 2:
						break;
					}
				}else{
					printf("\nNo hay empleado con esa ID.");
				}

				break;
			case 4:
				if(checkAvailableEmployee(employeeList, TAM)!=-1){
					do{}while(conseguirEnteroConParametros(&auxEntero,"\nElija criterio para organizar:\n1 - Ascendente\n2 - Descendente.", "Error, numero no valido.", 1,2, 5)==-1);
					if(auxEntero==2){
						auxEntero=0;
					}
					if(sortEmployees(employeeList, TAM, auxEntero)!=-1){
						printf("\nLista organizada.");
					}
				}else{
					printf("\nNo hay usuarios para ordenar.");
				}
				break;
			case 5:
				printEmployees(employeeList, TAM);
				break;
			case 6:
				break;
			}
		}while(opcion!=6);
	}
    printf("\n========================================================================");
    printf("\n========================Gracias, vuelva pronto!=========================");
    printf("\n========================================================================");
	return 0;

}
