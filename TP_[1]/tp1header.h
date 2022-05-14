#ifndef TP1HEADER_H_INCLUDED
#define TP1HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#endif // TP1HEADER_H_INCLUDED

/** \brief Se ingresan los kms del vuelo
 *
 * \param kms int* entero de kilometros ingresados
 * \return void
 *
 */
void ingresarKilometros(int* kms);

/** \brief Se ingresa el precio del vuelo para Aerolineas y para Latam
 *
 * \param pA float* precio del vuelo en Aerolineas Argentinas en float
 * \param pL float* precio del vuelo Latam en float
 * \return void
 *
 */
void ingresarPrecio(float* pA, float* pL);

/** \brief Calcula los precios segun sea el caso
 *
 * \param kms int* recibe como parametro los kms ingresados en su funcion correspondiente
 * \param pA float* recibe como parametro el precio de Aerolineas Argentinas ingresado en su funcion correspondiente
 * \param pL float* recibe como parametro el precio de Latam ingresado en su funcion correspondiente
 * \return void
 *
 */
void calcularCostos(int* kms, float* pA, float* pL, float* dA, float* cA, float* BTCA, float* uA, float* dL, float* cL, float* BTCL, float* uL, float* diferenciaAL, float* bitcoin);

/** \brief Muestra por pantalla los resultados
 *
 * \param kms int* recibe como parametro los kms ingresados en su funcion correspondiente
 * \param pA float* recibe como parametro el precio de Aerolineas Argentinas ingresado en su funcion correspondiente
 * \param pL float* recibe como parametro el precio de Latam ingresado en su funcion correspondiente
 * \return void
 *
 */
void informarResultados(int* kms, float* pA, float* pL, float* dA, float* cA, float* BTCA, float* uA, float* dL, float* cL, float* BTCL, float* uL, float* diferenciaAL);

/** \brief Carga los kilometros y los precios automaticamente sin tener que hacerlo de manera manual
 *
 * \param kms int* kilometros cargados automaticamente
 * \param pA float* precio de aerolineas cargado automaticamente
 * \param pL float* precio de latam cargado automaticamente
 * \return void
 *
 */
void cargarDatosForzados(int* kms, float* pA, float* pL);

void limpiarPantalla();

/** \brief Despliega un menu con 6 opciones
 *
 * \return void
 *
 */
void menu();
