/*
 * ArrayEmployees.c
 *
 *  Created on: 12 may. 2021
 *      Author: Legion
 */
#include "ArrayEmployees.h"

int initEmployees(employee* list, int len){
	int i;
	int retorno;
	for (i=0;i<len;i++){
		list[i].isEmpty=0;
	}
	retorno=0;
	for (i=0;i<len;i++){
		if(list[i].isEmpty!=0){
			retorno=-1;
			break;
		}
	}
	return retorno;
}

int addEmployee(employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
	int retorno;
	int posicionAuxiliar;
	posicionAuxiliar=searchEmptySpace(list, len);
	retorno=0;
	strcpy(list[posicionAuxiliar].name, name);
	strcpy(list[posicionAuxiliar].lastName, lastName);
	list[posicionAuxiliar].salary=salary;
	list[posicionAuxiliar].sector=sector;
	list[posicionAuxiliar].isEmpty=1;
	list[posicionAuxiliar].id=id;
	return retorno;
}

int printEmployees(employee* list, int length){
	int retorno;
	int i;
	int bandera;
	retorno=-1;
	bandera=0;
	for(i=0;i<length;i++){
		if(list[i].isEmpty==1){
			bandera++;
			break;
		}
	}
	if(bandera!=0){
		retorno++;
		printf("\nLos empleados ingresados son: ");
		for(i=0;i<length;i++){
			if(list[i].isEmpty==1){
				printf("\nNombre: %s\nApellido: %s\nSector: %i\nSalario: %.2f\nId: %i", list[i].name,list[i].lastName,list[i].sector,list[i].salary, list[i].id);
			}
		}
	}else{
		printf("\nNo hay usuarios para mostrar");
	}
	return retorno;
}

int searchEmptySpace(employee* list, int lenght){
	int retorno;
	int i;
	retorno=-1;
	for(i=0;i<lenght;i++){
			if(list[i].isEmpty==0){
				retorno=i;
				break;
			}
		}
	return retorno;
}


int findEmployeeById(employee* list, int len,int id){
	int retorno;
	retorno=-1;
	int i;
	for(i=0;i<len;i++){
		if(list[i].id==id){
			retorno=i;
		}
	}
	return retorno;
}

int checkAvailableEmployee(employee* list, int len){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<len;i++){
		if(list[i].isEmpty==1){
			retorno=0;
			break;
		}
	}
	return retorno;
}

int removeEmployee(employee* list, int len, int id){
	int retorno;
	int i;
	retorno=-1;
	for(i=0;i<len;i++){
		if(list[i].isEmpty==1&&list[i].id==id){
			list[i].isEmpty=0;
			retorno=0;
			printf("\nEmpleado Eliminado.");
			break;
		}
	}
	return retorno;
}

int sortEmployees(employee* list, int len, int order){
	int retorno;
	int i;
	int j;
	int opcion;
	employee auxEmployee;
	retorno=-1;
	printf("\n¿Ordenar por sector o apellido:\n1 - Apellido.\n2 - Sector.\n");
	do{
		scanf("%i", &opcion);
		if(opcion!=1&&opcion!=2){
			printf("\nError, elija opcion disponible.\n");
		}
	}while(opcion!=1&&opcion!=2);
	if(opcion==1){
		switch(order){
			case 1:
				for(i=0;i<len;i++){
					for(j=0;j<len;j++){
						if(list[i].isEmpty==1 && list[j].isEmpty==1 && strcmp(list[i].lastName, list[j].lastName)<1){
							auxEmployee=list[j];
							list[j]=list[i];
							list[i]=auxEmployee;
						}
					}
				}
				retorno++;
				break;
			case 0:
				for(i=0;i<len;i++){
					for(j=0;j<len;j++){
						if(list[i].isEmpty==1 && list[j].isEmpty==1 && strcmp(list[i].lastName, list[j].lastName)>1){
							auxEmployee=list[i];
							list[i]=list[j];
							list[j]=auxEmployee;
						}
					}
				}
				retorno++;
				break;
		}
	}else{
		switch(order){
			case 1:
				for(i=0;i<len;i++){
					for(j=0;j<len;j++){
						if(list[i].isEmpty==1&&list[j].isEmpty==1&&list[i].sector<list[j].sector){
							auxEmployee=list[j];
							list[j]=list[i];
							list[i]=auxEmployee;
						}
					}
				}
				retorno++;
				break;
			case 0:
				for(i=0;i<len;i++){
					for(j=0;j<len;j++){
						if(list[i].isEmpty==1&&list[j].isEmpty==1&&list[i].sector>list[j].sector){
							auxEmployee=list[j];
							list[j]=list[i];
							list[i]=auxEmployee;
						}
					}
				}
				retorno++;
				break;
		}
	}
	return retorno;
}

void printEmployee(employee* list, int position){
	printf("\nNombre: %s\nApellido: %s\nSector: %i\nSalario: %.2f\nId: %i", list[position].name,list[position].lastName,list[position].sector,list[position].salary, list[position].id);
}
