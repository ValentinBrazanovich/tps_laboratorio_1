#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tp1header.h"


void menu(){
    float precioAerolineas;
    float precioLatam;
    int kilometros;
    int rta;
    float bitcoin = 4606954.5500;

    int banderaKilometros = 0;
    int banderaPrecios = 0;
    int banderaCalculo = 0;

    float debitotaAerolineas;
    float creditoAerolineas;
    float BTCAerolineas;
    float unitarioAerolineas;
    float debitoLatam;
    float creditoLatam;
    float BTCLatam;
    float unitarioLatam;
    float diferencia;

    do{
        printf("Ingrese una opcion: ");
        printf("\n\n1.Ingresar Kilometros\t\t2.Ingresar el precio");
        printf("\n3.Calcular los costos\t\t4.Informar resultados");
        printf("\n5.Carga forzada de datos\t6.Salir\n\n");
        scanf("%d", &rta);

        switch(rta){
            case 1: ingresarKilometros(&kilometros);
                    banderaKilometros = 1;
                    banderaCalculo = 0;
                break;

            case 2: ingresarPrecio(&precioAerolineas, &precioLatam);
                    banderaPrecios = 1;
                    banderaCalculo = 0;
                break;

            case 3: if(banderaKilometros == 1 && banderaPrecios == 1){
                        calcularCostos(&kilometros, &precioAerolineas, &precioLatam, &debitotaAerolineas, &creditoAerolineas, &BTCAerolineas, &unitarioAerolineas, &debitoLatam, &creditoLatam, &BTCLatam, &unitarioLatam, &diferencia, &bitcoin);
                        banderaCalculo = 1;
                        banderaKilometros = 0;
                        banderaPrecios = 0;
                    }else{
                        printf("No se pueden calcular los costos debido a que no se ingresaron los kilometros o los precios\no es innecesario realizar el mismo calculo 2 veces.\n");
                    }
                break;

            case 4: if(banderaCalculo == 1){
                        limpiarPantalla();
                        informarResultados(&kilometros, &precioAerolineas, &precioLatam, &debitotaAerolineas, &creditoAerolineas, &BTCAerolineas, &unitarioAerolineas, &debitoLatam, &creditoLatam, &BTCLatam, &unitarioLatam, &diferencia);
                    }else{
                        printf("No se pueden informar resultados debido a que no se calcularon previamente.\n");
                    }
                break;

            case 5: cargarDatosForzados(&kilometros, &precioAerolineas, &precioLatam);
                    printf("\nCarga de datos exitosa!\n");
                    banderaKilometros = 1;
                    banderaPrecios = 1;
                    banderaCalculo = 0;

                break;

            case 6: printf("Salir\n\n");
                break;

            default: printf("La opcion ingresada no existe");
        }

        if(rta != 6 && rta != 1 && rta != 2){
            system("pause");
        }
        if(rta != 6){
                limpiarPantalla();
            }

    }while(rta != 6);
}


void limpiarPantalla(){
    printf("\n\n\n\n\n\n\n\n\n\n");
}


void ingresarKilometros(int* kms){
    printf("Ingresar Kilometros: ");
    scanf("%d", &*kms);
}


void ingresarPrecio(float* pA, float* pL){
    printf("Precio vuelo Aerolineas: ");
    scanf("%f", &*pA);
    printf("Precio vuelo Latam: ");
    scanf("%f", &*pL);
}


void calcularCostos(int* kms, float* pA, float* pL, float* dA, float* cA, float* BTCA, float* uA, float* dL, float* cL, float* BTCL, float* uL, float* diferenciaAL, float* BTC){
    printf("a) Tarjeta de debito (descuento 10%%)\n");
    *dA = *pA * 0.90;
    *dL = *pL * 0.90;

    printf("b) Tarjeta de credito (interes 25%%)\n");
    *cA = (*pA * 0.25) + *pA;
    *cL = (*pL * 0.25) + *pL;

    printf("c) Bitcoin (1BTC -> 4606954355.55 Pesos Argentinos)\n");
    *BTCA = *pA / *BTC;
    *BTCL = *pL / *BTC;

    printf("d) Precio por km (precio unitario)\n");
    *uA = *pA / *kms;
    *uL = *pL / *kms;

    printf("e)Diferencia de precio ingresada (Latam - Aerolineas)\n\n");
    *diferenciaAL = fabs(*pA - *pL);
}


void informarResultados(int* kms, float* pA, float* pL, float* dA, float* cA, float* BTCA, float* uA, float* dL, float* cL, float* BTCL, float* uL, float* diferenciaAL){
    printf("KMs Ingresados: %d km\n\n", *kms);
    printf("Precio Aerolineas: $ %.2f\n", *pA);
    printf("a) Precio con tarjeta de debito: $ %.2f\n", *dA);
    printf("b) Precio con tarjeta de credito: $ %.2f\n", *cA);
    printf("c) Precio pagando con bitcoin: %.4f BTC\n", *BTCA);
    printf("d) Mostrar precio unitario: $ %.2f\n\n", *uA);
    printf("Precio Latam: $ %.2f\n", *pL);
    printf("a) Precio con tarjeta de debito: $ %.2f\n", *dL);
    printf("b) Precio con tarjeta de credito: $ %.2f\n", *dA);
    printf("c) Precio pagando con bitcoin: %.4f BTC\n", *BTCL);
    printf("d) Mostrar precio unitario: $ %.2f\n\n", *uL);
    printf("La diferencia de precio es: $ %.2f\n", *diferenciaAL);
}


void cargarDatosForzados(int* kms, float* pA, float* pL){
    *kms = 7090;
    *pA = 162965;
    *pL = 159339;
}
