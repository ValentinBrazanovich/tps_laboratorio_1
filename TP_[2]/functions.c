/*
 * functions.c
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


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* vec, int len){
	int todoOk = 0;

	if(vec != NULL && len > 0){
		for(int i = 0; i < len; i++){
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}

    return todoOk;
} //esta bien

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (0) if Error [Invalid length or NULL pointer or without free space] - (1) if Ok
*/
int addPassenger(Passenger* vec, int len, int id, char name[], char lastName[], float price, char flycode[], int typePassenger, int statusFlight){
    int todoOk = 0;
    int pIndex;

    if( buscarPasajeroLibre(vec, len, &pIndex) ){
        vec[pIndex].id = id;
        strcpy(vec[pIndex].name, name);
        strcpy(vec[pIndex].lastName, lastName);
        vec[pIndex].price = price;
        strcpy(vec[pIndex].flycode, flycode);
        vec[pIndex].typePassenger = typePassenger;
        vec[pIndex].statusFlight = statusFlight;
        vec[pIndex].isEmpty = 0;

        todoOk = 1;
        }

    return todoOk;
}

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (0) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* vec, int len,int id, int* pIndex){
    int todoOk = 0;

    if(vec != NULL && len > 0 && pIndex != NULL && id > 0){
        *pIndex = -1;
        for(int i = 0; i<len; i++){
            if(vec[i].isEmpty == 0 && vec[i].id == id){
                *pIndex = i;

                break;
            }
        }
        todoOk = 1;
    }

	return todoOk;
}//esta bien

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* vec, int len, int id){
    int todoOk = -1;
    char confirmar;
    int indice;


    findPassengerById(vec, len, id, &indice);

    if(vec != NULL && len > 0){
        if(indice == -1){
            printf("No hay un pasajero con id %d\t", id);
        }else{
            if(vec != NULL){
                printf("%d \t %s \t %s \t %.2f \t %s \t %d \t %d\n",
                vec[indice].id,
                vec[indice].name,
                vec[indice].lastName,
                vec[indice].price,
                vec[indice].flycode,
                vec[indice].typePassenger,
                vec[indice].statusFlight
                );
            }
            printf("Confirmar baja? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirmar);

            if(confirmar != 's' && confirmar != 'S'){
                printf("Baja cancelada por el usuario\n");
            }else{
                vec[indice].isEmpty = 1;
                printf("Baja realizada con el exito!!!\n");
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* vec, int len, int order){// if order == 1 return ascending order, if order == 0 return descending
    int todoOk = 0;
    Passenger auxPassenger;

    if(vec != NULL && len > 0 && order > -1 && order < 2)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j= i + 1; j < len; j++)
            {
                if( ((((strcmp(vec[i].lastName, vec[j].lastName) > 0) && (vec[i].typePassenger > vec[j].typePassenger))
                || ((vec[i].typePassenger != vec[j].typePassenger) &&(vec[i].typePassenger > vec[j].typePassenger))) && order)
                ||  ((((strcmp(vec[i].lastName, vec[j].lastName) < 0) && (vec[i].typePassenger < vec[j].typePassenger))
                || ((vec[i].typePassenger != vec[j].typePassenger) &&(vec[i].typePassenger < vec[j].typePassenger))) && !order))
                {
                    auxPassenger = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPassenger;
                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
} //esta bien



/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* vec, int length){
    int todoOk = 0;
	int bandera = 0;

    if(vec != NULL && length > 0){
        printf("\t\t *** Listado de Pasajeros *** \n\n");
        printf("  Id   Name        Last Name     Price       Flycode  Type Passenger  Status Flight");
        printf("\n--------------------------------------------------------------------------------------\n");
        for(int i = 0; i<length; i++){
            if(!vec[i].isEmpty) //SI ES 0 SE MUESTRA PASAJERO
            {
                if(vec != NULL){
                    printf(" %3d   %-12s    %-12s  %.2f  %-10s  %d  \t\t%d\n",
                    vec[i].id,
                    vec[i].name,
                    vec[i].lastName,
                    vec[i].price,
                    vec[i].flycode,
                    vec[i].typePassenger,
                    vec[i].statusFlight
                );
                }
                bandera = 1;
            }
        }
        if(bandera == 0){
            printf("\nNo hay pasajeros en el sistema\n");
        }

        todoOk = 1;
    }

    return todoOk;
}//esta bien

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int sortPassengersByCode(Passenger* vec, int len, int order){
    int todoOk = 0;
    Passenger auxPassenger;

    if(vec != NULL && len > 0 && order > -1 && order < 2)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j= i + 1; j < len; j++)
            {
                /*if( (((strcmp(vec[i].flycode, vec[j].flycode) > 0) && (vec[i].statusFlight == 1)) && order)
                ||  (((strcmp(vec[i].flycode, vec[j].flycode) < 0) && (vec[i].statusFlight == 1)) && !order))
                {
                    auxPassenger = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPassenger;
                }*/

                if( ((((strcmp(vec[i].flycode, vec[j].flycode) > 0) && (vec[i].statusFlight > vec[j].statusFlight))
                || ((vec[i].statusFlight != vec[j].statusFlight) &&(vec[i].statusFlight > vec[j].statusFlight))) && order)
                ||  ((((strcmp(vec[i].flycode, vec[j].flycode) < 0) && (vec[i].statusFlight < vec[j].statusFlight))
                || ((vec[i].statusFlight != vec[j].statusFlight) &&(vec[i].statusFlight < vec[j].statusFlight))) && !order))
                {
                    auxPassenger = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPassenger;
                }



            }
        }
        todoOk = 1;
    }

    return todoOk;
}



