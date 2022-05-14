/*
 * funciones propias.h
 *
 *  Created on: 14 may. 2022
 *      Author: Valentin Brazanovich
 */

#ifndef FUNCIONES_PROPIAS_H_INCLUDED
#define FUNCIONES_PROPIAS_H_INCLUDED

int hardcodePassengers(Passenger vec[], int len, int cant, int* pId);
int loadPassenger(Passenger vec[], int len, int* pId);
int buscarPasajeroLibre(Passenger vec[], int len, int* pIndex);
int modificarPasajero(Passenger vec[], int len);
int informarPassenger(Passenger vec[], int len);
int totalPromedioPrecios(Passenger vec[], int len);
int informarTotalPromedioPrecios(Passenger vec[], int len, float totalPrecios, float promedio, int arribaDePromedio);
int menuModificarPasajero();
int menuInformar();
int menu();

#endif // FUNCIONES_PROPIAS_H_INCLUDED
