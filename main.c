#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

void dibujarCarton(int v[3][5]);
void asignarCarton(int v[3][5]);

int main()
{
    srand(time(0));
    int carton1[3][5];

    asignarCarton(carton1);
    dibujarCarton(carton1);

    return 0;
}

void dibujarCarton(int v[3][5])
{
    printf("------------------\n");

    for(int i = 0; i < 3; i++)
    {
        printf("| ");

        for (int j = 0; j < 5; j++)
        {
            if (v[i][j] < 10)//si es menor a 10 dibujamos un 0 para que todos los numeros tengan 2 cifras
            {
                printf("0");
            }
            printf("%d ", v[i][j]);
        }
        printf("|\n");
    }
}

void asignarCarton(int v[3][5])
{
    int tempvector[15];
    int contador = 0;
    cargarVectorConAleatoriosSinRepetir(tempvector,15,1,90);

    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            v[i][j] = tempvector[contador];
            contador++;
        }

    }
}
