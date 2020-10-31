#ifndef CARTON_C_INCLUDED
#define CARTON_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"
#include "carton.h"
#include "funciones.h"

struct CartonEstructura{

int numeros[FILAS][COLUMNAS];
int marcas[FILAS][COLUMNAS];
};

Carton iniciarCarton()
{
    Carton cart = malloc(sizeof(struct CartonEstructura));
    for(int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            cart->numeros[i][j] = 0;
            cart->marcas[i][j] = 0;
        }
    }

    return cart;
}

//----------------carga de carton----------------------------------
void cargarCartonConAleatorios(Carton cart)
{
    int tempvector[FILAS*COLUMNAS];
    cargarVectorConAleatoriosSinRepetir(tempvector,FILAS*COLUMNAS,1,BOLITAS);

    for(int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            //lo hago de este manera porque el tempvactor solo tiene 1 dimension
            //pero es lo suficientemente largo para llenar todo el carton
            cart->numeros[i][j] = tempvector[i*COLUMNAS + j];
        }

    }
}

void cargarCartonPorTeclado(Carton cart)
{
    int numero = -1;

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("Ingrese el numero de la fila %d columna %d\n", i + 1, j + 1);
            scanf("%d",&numero);

            //comprobamos que el numero sea valido
            while(numero > BOLITAS || numero < 1)
            {
                printf("El numero ingresado es incorrecto, tiene que ser del 1 al %d\n", BOLITAS);
                scanf("%d",&numero);
            }

            //comprobamos que el numero no este repetido
            if (buscarNumeroEnCarton(cart, numero) == 1)
            {
                printf("El numero ingresado esta repetido, estos son los numeros cargados hasta ahora:\n");
                dibujarCarton(cart, 0);
                j--;//volvemos a repetir esta parte del ciclo para asi poder ingresar nuevamente un numero
            }else{
                //todo correcto para escribir el numero al carton
                cart->numeros[i][j] = numero;
            }


        }
    }
}

int buscarNumeroEnCarton(Carton cart, int num)
{
    int encontrado = 0; //0 si no encuentra, 1 si encuentra

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (cart->numeros[i][j] == num)
            {
                return 1;
            }
        }
    }

    return 0;
}

void buscarPosicionEnCarton(Carton cart, int num, int *posicion)
{

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (cart->numeros[i][j] == num)
            {
                posicion[0] = i;
                posicion[1] = j;
            }
        }
    }
}

int marcarNumeroEnCarton(Carton cart, int num){
    if (buscarNumeroEnCarton(cart, num) == 1)
    {
        int posicion[2];
        buscarPosicionEnCarton(cart, num, posicion);
        cart->marcas[posicion[0]] [posicion[1]] = 1;
        return 1;
    }else{
        return 0;
    }
}

void dibujarCarton(Carton cart, int num)
{
    printf("------------------\n");
    printf("|    CARTON %d    |\n", num + 1);
    printf("------------------\n");

    for(int i = 0; i < FILAS; i++)
    {
        printf("| ");

        for (int j = 0; j < COLUMNAS; j++)
        {
            if (cart->marcas[i][j] == 1)
            {
                printf("XX ");
            }else{

                if (cart->numeros[i][j] < 10)//si es menor a 10 dibujamos un 0 para que todos los numeros tengan 2 cifras
                {
                    printf("0");
                }
                printf("%d ", cart->numeros[i][j]);
            }
        }
        printf("|\n");
    }
    printf("------------------\n");
}

int comprobarLinea(Carton cart)
{
    int iguales = 1;//si este valor se mantiene en 1 es que encontr una linea

    for (int i = 0; i < FILAS; i++)
    {
        iguales = 1;

        for (int j = 0; j < COLUMNAS; j++)
        {
            if (cart->marcas[i][j] == 0)
            {
                iguales = 0;
            }
        }

        if (iguales == 1)
        {
            return 1;
        }
    }

    return 0;
}

int comprobarColumna(Carton cart)
{
    for (int i = 0; i < COLUMNAS; i++)
    {
        int iguales = 1;//si este valor se mantiene en 1 es que encontr una columna

        for (int j = 0; j < FILAS; j++)
        {
            if (cart->marcas[j][i] == 0) iguales = 0;
        }

        if (iguales == 1) return 1;
    }

    return 0;
}

int comprobarBingo(Carton cart)
{
    int iguales = 1;//si este valor se mantiene en 1 es que es bingo

    for (int i = 0; i < FILAS; i++)
    {

        for (int j = 0; j < COLUMNAS; j++)
        {
            if (cart->marcas[i][j] == 0) iguales = 0;
        }

    }

    return iguales;
}


#endif // CARTON_C_INCLUDED
