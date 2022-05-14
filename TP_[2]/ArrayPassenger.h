/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Valentin Brazanovich
 */
#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
} Passenger;

#endif // ARRAYPASSENGER_H_INCLUDED
