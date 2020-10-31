#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int aleatorioEntre(int mini, int maxi)
{
    return mini + rand()%(maxi-mini+1);
}

void cargarVectorConAleatorios(int v[], int tam, int mini, int maxi)
{
    int aleatorio = 0;

    for (int i = 0; i < tam; i++)
    {
        aleatorio = aleatorioEntre(mini, maxi);
        v[i] = aleatorio;
    }
}

void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi)
{
    int aleatorio = 0;

    for (int i = 0; i < tam; i++)
    {//antes de asignar el numero aleatorio pasamos por los numeros ya generados para comprobar que no se repitan
        aleatorio = aleatorioEntre(mini, maxi);

        for(int j = 0; j < i; j++)
        {

            if (v[j] == aleatorio)
            {//si se encontro un numero repetido volvemos a generar un numero aleatorio y volvemos a comprobar el vector
                aleatorio = aleatorioEntre(mini, maxi);
                j = 0;
            }
        }

        v[i] = aleatorio;
    }
}

//---------------------------bolitas------------------------------------------------
void generarBolitas(int v[]){
    for(int i = 0; i < BOLITAS; i++){
        cargarVectorConAleatoriosSinRepetir(v,BOLITAS,1,BOLITAS);
    }
}

void mostrarBolitas(int v[])
{
    for(int i = 0; i < BOLITAS; i++)
    {
        mostrarBolita(v, i);
    }

}

void mostrarBolita(int v[], int bolita)
{
    printf("   SALIO EL NUMERO:\n");
    printf("     ___________        \n");
    printf("    |           |       \n");
    printf("    |           |       \n");

    printf("    |     ");
    if (v[bolita]< 10) printf("0");
    printf("%d    |       \n",v[bolita]);

    printf("    |           |       \n");
    printf("    |___________|       \n");
    printf("\n\n\n");

}


//-----------------------busqueda y marca de numeros---------------------------------

int busquedaDeNumero(int mat[][FILAS][COLUMNAS], int num[])
{
    int posReglon = -1, posFila = -1, rpt = 0;

    for(int i=0; i < FILAS; i++)
    {
        for(int j=0;j<COLUMNAS;j++)
        {
            if(mat[1][i][j] == num)
            {
                posReglon = i;
                posFila = j;
            }
        }
    }
    rpt = posFila*10 + posReglon;
    return rpt;
}

//Funciones y procedimientos para el menú
int pedirCantidadDeCartones()
{
    int cantidad = MAXCARTONES + 1;//cantidad inicial invalida para evitar problemas en caso de que falle el scanf

    do
    {
        printf("Escribe 1 para solo usar un carton\n");

        for (int i = 2; i <= MAXCARTONES; i++)
        {
            printf("Escribe %d para usar %d cartones\n", i, i);
        }

        scanf("%d",&cantidad);

        if (cantidad < 0 || cantidad > MAXCARTONES)//detectamos si es un numero invalido de cartones
        {
            system("cls");
            printf("La cantidad de cartones ingresada es invalida, escriba un numero del 1 al %d \n", MAXCARTONES);
        }

    }while(cantidad < 0 || cantidad > MAXCARTONES);//hasta que no se ingrese u numero correcto de cartones este menu se repetira

    return cantidad;
}

int pedirMetodoDeGeneracionDeCarton()
{
    int metodo = 3;

    do
    {
        printf("\nComo quieres general los cartones?\n\n");
        printf("Ingrese 1 para general el/los cartones automaticamente\n");
        printf("Ingrese 2 para personalizar su/s cartones\n");
        scanf("%d",&metodo);

        if (metodo < 0 || metodo > 2)
        {
            system("cls");
            printf("La opcion ingresada es invalida, intentalo de nuevo.");
        }

    }while(metodo < 0 || metodo > 2);

    return metodo;
}

void mostrarRanking()
{
    FILE * punteroAUnArchivo;
    punteroAUnArchivo = fopen("ranking.txt", "r");

    printf("Puntuaciones anteriores: \n\n");

    while (!feof(punteroAUnArchivo))//feof devuelve si ya se llego al final del archivo (eof)
    {
        char aux[50] = " ";
        fgets(aux, 50, punteroAUnArchivo);

        char aux2[50] = " ";
        fgets(aux2, 50, punteroAUnArchivo);

        //solo mostramos si el nombre no esta vacio
        if (aux[0] != ' ') printf("Jugador: %s  --  Puntaje: %s\n", aux, aux2);
    }

    printf("GRACIAS POR JUGAR!\n");
    //cerrar
    fclose(punteroAUnArchivo);
}
