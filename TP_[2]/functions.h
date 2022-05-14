/*
 * functions.h
 *
 *  Created on: 14 may. 2022
 *      Author: Valentin Brazanovich
 */

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int initPassengers(Passenger* vec, int len);
int addPassenger(Passenger* vec, int len, int id, char name[],char lastName[],float price,char flycode[], int typePassenger, int statusFlight);
int findPassengerById(Passenger* vec, int len, int id, int* pIndex);
int removePassenger(Passenger* vec, int len, int id);
int sortPassengers(Passenger* vec, int len, int order);
int printPassenger(Passenger* vec, int length);
int sortPassengersByCode(Passenger* vec, int len, int order);

#endif // FUNCTIONS_H_INCLUDED
