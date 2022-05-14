/*
 ============================================================================
 Name        : tp_[2].c
 Author      : Valentin Brazanovich
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayPassenger.h"
#include "functions.h"
#include "funciones_propias.h"

#define LEN 2000


int main(){
	setbuf (stdout,NULL);
    char salir = 'n';
    int proximoId = 1;
    int id;

    int flagPassenger = 0;

    Passenger list[LEN];

    initPassengers(list, LEN);
    hardcodePassengers(list, LEN, 5, &proximoId);
    flagPassenger = 1;

    do{
        switch(menu()){
            case 1:
                    loadPassenger(list, LEN, &proximoId);
                    flagPassenger = 1;

                break;

            case 2:
                if(flagPassenger != 1){
                    printf("\nNo se cargo ningun pasajero\n");
                }else{
                    printPassenger(list,  LEN);
                    modificarPasajero(list, LEN);
                }

                break;

            case 3:
                if(flagPassenger != 1){
                    printf("\nNo se cargo ningun pasajero\n");
                }else{
                    printPassenger(list, LEN);
                    printf("\n\nIngrese el id del pasajero que desea eliminar: ");
                    scanf("%d", &id);
                    removePassenger(list, LEN, id);
                }

                break;

            case 4:
                if(flagPassenger != 1){
                    printf("\nNo se cargo ningun pasajero\n");
                }else{
                    informarPassenger(list, LEN);
                    /*scanf("%d", &order);
                    sortPassengers(list, LEN, order);
                    printPassenger(list, LEN);
                    //informarPassenger(list, LEN);*/
                }
                break;
            case 5:
                salir = 's';
                break;

            default: printf("\nLa opcion ingresada no existe\n");
        }

    }while(salir != 's');

    return 0;
}
