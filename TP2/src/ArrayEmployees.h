/*
 * ArrayEmployees.h
 *
 *  Created on: 12 may. 2021
 *      Author: Legion
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <string.h>
#include <stdio.h>

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}employee;

/* \brief Funcion que inicia la variable de control para espacio vacio de la lista de empleados en 0
*  \param list employee* lista de empleados y su largo.
*  \param len int largo del array
*  \return Retorna -1 si revisa nuevamente la lista y encuentra un espacio con un valor distinto a 0, retorna 0 si no encontro ningun problema
*/
int initEmployees(employee* list, int len);

/** \brief busca la primer posicion vacia y llena con los datos que recibe
* \param list employee* lista de empleados y su largo.
* \param len int largo del array
* \param id int numero entero que representa una id de empleado
* \param name[] char cadena de caracteres que representa un numbre
* \param lastName[] char cadena de caracteres que representa el apellido
* \param salary float numero con decimales que representa el salario
* \param sector int numero entero que represeta la seccion
* \return int retorna -1 si no pudo terminar de llenar el espacio por cualquier razon, 0 si pudo
*/
int addEmployee(employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/* \brief Funcion que busca posiciones llenas e imprime su contenido
*  \param list employee* lista de empleados y su largo.
*  \param len int largo del array
*  \return Retorna -1 si no encuentra ninguna posicion llena, 0 si encuentra por lo menos una
*/
int printEmployees(employee* list, int length);

/* \brief Funcion que busca la primer posicion vacia en la lista
*  \param list employee* lista de empleados y su largo.
*  \param len int largo del array
*  \return Retorna -1 si no encuentra espacio vacio, si encuentra un espacio devuelve la posicion en la lista
*/
int searchEmptySpace(employee* list, int lenght);

/* \brief Funcion que busca a un empleado por el numero de id
*  \param list employee* lista de empleados y su largo.
*  \param len int largo del array
*  \param id int numero entero que representa una id
*  \return Retorna -1 si no encuentra a un empleado con ese numero de id, 0 si lo encuentra
*/
int findEmployeeById(employee* list, int len,int id);

/* \brief Funcion que busca si hay aunque sea una posicion llena en la lista
*  \param list employee* lista de empleados y su largo.
*  \param len int largo del array
*  \return Retorna -1 si no encuentra una posicion llena, 0 si la encuentra
*/
int checkAvailableEmployee(employee* list, int len);

/* \brief Funcion que busca a un empleado por el numero de id y lo borra
*  \param list employee* lista de empleados y su largo.
*  \param len int largo del array
*  \param id int numero entero que representa una id
*  \return Retorna -1 si no encuentra a un empleado con ese numero de id, 0 si lo encuentra y lo borra
*/
int removeEmployee(employee* list, int len, int id);

/* \brief Funcion que ordena la lista dependiendo de algunos criterios
*  \param list employee* lista de empleados y su largo.
*  \param len int largo del array
*  \param order int numero entero que marca si el orden es ascendente o descendiente
*  \return Retorna -1 si no encuentra a un empleado que ordenar, 0 si ordena de cualquier manera
*/
int sortEmployees(employee* list, int len, int order);

/* \brief Funcion que imprime un empleado
*  \param list employee* lista de empleados y su largo.
*  \param position int entero que representa una posicion en la lista
*  \return nada
*/
void printEmployee(employee* list, int position);


#endif /* ARRAYEMPLOYEES_H_ */
