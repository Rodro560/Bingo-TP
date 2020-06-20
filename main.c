
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main()
{
    srand(time(0));
    int cantCarton, tipoCarton, carton1[3][5],carton2[3][5],carton3[3][5];

    do
    {
        //las siguentes lineas son para elegir la cantidad de cartones
        printf("Bienvenido al bingo\n\n");
        printf("Escribe 1 para solo usar un carton\n");
        printf("Escribe 2 para solo usar dos cartones\n");
        printf("Escribe 3 para solo usar tres cartones\n");
        printf("Una ves formado tu carton presiona 0\n");
        scanf("%d",&cantCarton);

        //las siguentes lineas son para elegir como van a cargar el carton
        printf("\nQue carton quieres?\n");
        printf("\nIngrese 1 para tomar un/unos carton/cartones alatorio/s\n");
        printf("Ingrese 2 para personalizar su/s carton/cartones\n");
        scanf("%d",&tipoCarton);

        if(tipoCarton==1)
        {
            switch(cantCarton)
            {
                case 1:
                    asignarCarton(carton1);
                    dibujarCarton(carton1, 1);
                    break;
                case 2:
                    asignarCarton(carton1);
                    dibujarCarton(carton1, 1);

                    asignarCarton(carton2);
                    dibujarCarton(carton2, 2);
                    break;
                case 3:
                    asignarCarton(carton1);
                    dibujarCarton(carton1, 1);

                    asignarCarton(carton2);
                    dibujarCarton(carton2, 2);

                    asignarCarton(carton3);
                    dibujarCarton(carton3, 3);
                    break;
                case 0:
                    break;
                default:printf("\n------error------\n");
            }
        }

        if(tipoCarton==2)
        {
            switch(cantCarton)
            {
                case 1:
                    asignarCarton(carton1);
                    dibujarCarton(carton1, 1);
                    break;
                case 2:
                    asignarCarton(carton1);
                    dibujarCarton(carton1, 1);

                    asignarCarton(carton2);
                    dibujarCarton(carton2, 2);
                    break;

                case 3:
                    asignarCarton(carton1);
                    dibujarCarton(carton1, 1);

                    asignarCarton(carton2);
                    dibujarCarton(carton2, 2);

                    asignarCarton(carton3);
                    dibujarCarton(carton3, 3);
                    break;

                case 0:
                    break;
                default:printf("\n------error------\n");
            }
        }
    }while(cantCarton==0);

    return 0;
}

