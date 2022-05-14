/*
 * funciones propias.c
 *
 *  Created on: 14 may. 2022
 *      Author: Valentin Brazanovich
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayPassenger.h"
#include "functions.h"
#include "funciones_propias.h"

/** \brief Despliega un menu de opciones
 *
 * \return retorna la respuesta ingresada
 *
 */
int menu(){
    int rta;

    printf("\n\nIngrese una opcion: ");
    printf("\n\n1.Ingresar pasajero\t\t2.Modificar pasajero");
    printf("\n3.Eliminar pasajero\t\t4.Informar");
    printf("\n5.Salir\n\n");
    scanf("%d", &rta);

    return rta;
}

/** \brief Se le ingresa por teclado los datos requeridos del pasajero
*  y los guarda en la lista con la funcion addPassenger()
* \param vec Passenger* Pointer to array of passenger
* \param len int Array length
* \param pId int* Pointer to prox id
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int loadPassenger(Passenger vec[], int len, int* pId)
{
    int todoOk = 0;
    int indice = 1;
    char auxCad[100];
    float precio;
    int tipoPasajero;
    int estadoVuelo;

    Passenger newPassenger;

    if(vec != NULL && len > 0 && pId != NULL)
    {
        if( buscarPasajeroLibre(vec, len, &indice) )
        {

            if(indice == 0)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {

                printf("Ingrese el nombre del pasajero: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) > 51)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(newPassenger.name, auxCad);

                printf("Ingrese el apellido del pasajero: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) > 51)
                {
                    printf("Apellido demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(newPassenger.lastName, auxCad);

                printf("Ingrese el precio del viaje: ");
                scanf("%f", &precio);

                while(precio < 1){
                    printf("No es un numero correcto, reingresar: ");
                    scanf("%f", &precio);
                }
                newPassenger.price = precio;

                printf("Ingrese el tipo de pasajero (1, 2, 3): ");
                scanf("%d", &tipoPasajero);

                while((tipoPasajero > 3) || (tipoPasajero < 1)){
                    printf("No es un numero correcto, reingresar: ");
                    scanf("%d", &tipoPasajero);
                }
                newPassenger.typePassenger = tipoPasajero;

                printf("Ingrese el codigo de vuelo del pasajero: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) > 10){
                    printf("Codigo demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(newPassenger.flycode, auxCad);

                printf("Ingrese el estado de vuelo (1-Activo 2-Atrasado): ");
                scanf("%d", &estadoVuelo);

                while((estadoVuelo > 0) && (estadoVuelo < 3) && (isalpha(estadoVuelo) != 0)){
                    printf("No es un numero correcto, reingresar: ");
                    scanf("%d", &estadoVuelo);
                }

                newPassenger.statusFlight = estadoVuelo;


                newPassenger.id = indice + 1;
                *pId = *pId + 1;

                addPassenger(vec, len, newPassenger.id, newPassenger.name, newPassenger.lastName, newPassenger.price, newPassenger.flycode, newPassenger.typePassenger, newPassenger.statusFlight);
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}


/** \brief Busca la posicion mas cercana libre
* \param vec Passenger* Pointer to array of passenger
* \param len int Array length
* \param pIndex int* Pointer to prox id
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int buscarPasajeroLibre(Passenger vec[], int len, int* pIndex){
    int todoOk = 0;

    if(vec != NULL && len > 0 && pIndex != NULL){
        *pIndex = -1;

        for(int i=0; i < len; i++){
            if( vec[i].isEmpty ){
                *pIndex = i;
                break;
            }
        }

        todoOk = 1;
    }else{
        printf("\nNo hay lugar dispoible\n");
    }

    return todoOk;
}

/** \brief Modifica algun campo de el pasajero elegido por id
* \param vec Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int modificarPasajero(Passenger vec[], int len){
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    char auxCad[100];
    int tipoPasajero;
    int estadoVuelo;


    if(vec != NULL && len > 0){
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(findPassengerById(vec, len, id, &indice))
        {
            if(id == -1)
            {
                printf("No hay un pasajero con id %d\n", id);
            }
            else
            {
                if(vec != NULL){
                    printf("%d \t %s \t %s \t %.2f \t %s \t %d \t %d\n",
                    vec[id].id,
                    vec[id].name,
                    vec[id].lastName,
                    vec[id].price,
                    vec[id].flycode,
                    vec[id].typePassenger,
                    vec[id].statusFlight
                );
            }

                do
                {
                    switch(menuModificarPasajero())
                    {

                    case 1:
                        printf("\nIngrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxCad);

                        while(strlen(auxCad) > 51)
                        {
                            printf("Nombre demasiado largo. Reingrese nombre: ");
                            fflush(stdin);
                            gets(auxCad);
                        }
                        strcpy(vec[id].name, auxCad);

                        printf("Se ha modificado el nombre\n");
                        break;

                    case 2:
                        printf("\nIngrese nuevo apellido: ");
                        fflush(stdin);
                        gets(auxCad);

                        while(strlen(auxCad) > 51)
                        {
                            printf("Apellido demasiado largo. Reingrese apellido: ");
                            fflush(stdin);
                            gets(auxCad);
                        }
                        strcpy(vec[id].lastName, auxCad);
                        printf("Se ha modificado el apellido\n");
                        break;

                    case 3:
                        printf("\nIngrese nuevo precio: ");
                        scanf("%f", &vec[id].price);
                        printf("Se ha modificado el precio\n");
                        break;

                        break;
                    case 4:
                        printf("\nIngrese nuevo codigo de vuelo: ");
                        fflush(stdin);
                        gets(auxCad);

                        while(strlen(auxCad) > 10)
                        {
                            printf("Codigo demasiado largo. Reingrese codigo: ");
                            fflush(stdin);
                            gets(auxCad);
                        }
                        strcpy(vec[id].flycode, auxCad);
                        printf("Se ha modificado el codigo de vuelo\n");

                        break;
                    case 5:
                        printf("\nIngrese nuevo tipo de pasajero: ");
                        scanf("%d", &tipoPasajero);

                        while((tipoPasajero > 3) || (tipoPasajero < 1)){
                            printf("No es un numero correcto, reingresar: ");
                            scanf("%d", &tipoPasajero);
                        }
                        vec[id].typePassenger = tipoPasajero;

                        printf("Se ha modificado el tipo de pasajero\n");
                        break;
                    case 6:
                        printf("\nIngrese nuevo estado de vuelo (1-Activo 2-Atrasado): ");
                        scanf("%d", &estadoVuelo);

                        while((estadoVuelo > 0) && (estadoVuelo < 3) && (isalpha(estadoVuelo) != 0)){
                            printf("No es un numero correcto, reingresar: ");
                            scanf("%d", &estadoVuelo);
                        }

                        vec[id].statusFlight = estadoVuelo;
                        break;
                    case 7:
                        salir = 's';
                        break;

                    default: printf("\nLa opcion ingresada no existe\n");
                    }

                }while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar pasajero\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


/** \brief Despliega un menu de opciones de campos a modificar
 *
 * \return todoOk
 *
 */
int menuModificarPasajero()
{
    int opcion;


    printf("     *** Campos a modificar ***\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- precio\n");
    printf("4- Codigo de vuelo\n");
    printf("5- Tipo de pasajero (1, 2, 3)\n");
    printf("6- Estado de vuelo (1-Activo 2-Atrasado)\n");
    printf("7- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


/** \brief Ordena los pasajeros segun lo que se requiera en orden ascendente o descendente
*  muestra el promedio de precios, el total de precios y la cantidad de pasajeros que exceden el promedio
* \param vec Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int informarPassenger(Passenger vec[], int len){
    int ord;
    int todoOk = 0;
    int salirp = 'n';

    if(vec != NULL && len > 0){
        do{
            switch(menuInformar()){
                case 1:
                    printf("Elija el orden (1-ascendente, 0-descendente): ");
                    scanf("%d", &ord);
                    sortPassengers(vec, len, ord);
                    printPassenger(vec, len);

                    break;
                case 2:
                    totalPromedioPrecios(vec, len);

                    break;
                case 3:
                    printf("Elija el orden (1-ascendente, 0-descendente): ");
                    scanf("%d", &ord);
                    sortPassengersByCode(vec, len, ord);
                    printPassenger(vec, len);

                    break;
                case 4:
                    salirp = 's';

                    break;

                default: printf("\nLa opcion ingresada no esta disponible\n");
            }

        }while(salirp != 's');

        todoOk = 1;
    }
    else
    {
        printf("Ocurrio un problema al ordenar pasajeros\n");
    }

    return todoOk;
}


/** \brief Despliega un menu de opciones
 *
 * \return retorna la respuesta ingresada
 *
 */
int menuInformar(){
    int opcion;

    printf("     *** Informar ***\n");
    printf("1- Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero\n");
    printf("2- Total y promedio de los precios de los pasajes\n");
    printf("3- Listado de los pasajeros por codigo de vuelo y estados de vuelos activos(1)\n");
    printf("4- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


/** \brief Calcula el total de precios, el promedio de estos y la cantidad de pasajeros que exceden el promedio
* \param vec Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int totalPromedioPrecios(Passenger vec[], int len){
    int todoOk;
    float totalPrecios = 0;
    float promedio;
    float cantPrecios = 0;
    int arribaDePromedio = 0;

    if(vec != NULL && len > 0){
        for(int i=0; i < len; i++){
            if(vec[i].isEmpty == 0){
            	totalPrecios = totalPrecios + vec[i].price;
            	cantPrecios++;
            }
        }

        promedio = totalPrecios / cantPrecios;

        for(int i=0; i < cantPrecios; i++){
            if(vec[i].price > promedio){
               arribaDePromedio++;
            }
        }

        informarTotalPromedioPrecios(vec, len, totalPrecios, promedio, arribaDePromedio);

        todoOk = 1;
    }

    return todoOk;
}


/** \brief Carga forzada de 5 pasajeros
* \param vec Passenger* Pointer to array of passenger
* \param len int Array length
* \param cant int ammount of passengers
* \param pId int* Pointer to prox id
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int hardcodePassengers(Passenger vec[], int len, int cant, int* pId){
    int todoOk = 0;

	Passenger listaP[] = {
		{1000, "Dario", "Sosa", 20000.00, "a000001", 1, 1, 0},
		{1001, "Maximiliano", "Morales", 23000.00, "a000002", 1, 1, 0},
		{1002, "Tiago", "Castillo", 27000.00, "a000003", 2, 1, 0},
		{1003, "Jorge", "Sosa", 15000.00, "a000004", 3, 2, 0},
		{1007, "Estefania", "Suarez", 37000.00, "a000005", 2, 2, 0}
	};


	if(vec != NULL && len > 0 && pId != NULL && cant > 0 && cant <= len)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = listaP[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }

	return todoOk;
}


/** \brief Muestra por pantalla el total de precios, el promedio de estos y la cantidad de pasajeros que lo exceden
* \param vec Passenger* Pointer to array of passenger
* \param len int Array length
* \param totalPrecios float total de todos los precios
* \param promedio float promedio de precios
* \param arribaDePromedio int cantidad de pasajeros que exceden el promedio de precios
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int informarTotalPromedioPrecios(Passenger vec[], int len, float totalPrecios, float promedio, int arribaDePromedio){
    int todoOk = 0;

    if(vec != NULL && len > 0){
        printf("\n\nTotal precios: %.2f", totalPrecios);
        printf("\nPromedio de precios: %.2f", promedio);
        printf("\nPasajeros que exceden el promedio: %d\n\n", arribaDePromedio);

        todoOk = 1;
    }

    return todoOk;
}
