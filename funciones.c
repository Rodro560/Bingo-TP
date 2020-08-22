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

void asignarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant)
{

    for (int i = 0; i < cant; i++)
    {
        int tempvector[FILAS*COLUMNAS];
        cargarVectorConAleatoriosSinRepetir(tempvector,FILAS*COLUMNAS,1,90);

        for(int j = 0; j < FILAS; j++)
        {
            for (int k = 0; k < COLUMNAS; k++)
            {
                v[i][j][k] = tempvector[j*COLUMNAS + k];
            }

        }
    }
}

void dibujarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant)
{
    for (int i = 0; i< cant; i++)
    {
        dibujarCarton(v,i);
    }
}

void dibujarCarton(int v[MAXCARTONES][FILAS][COLUMNAS], int num)
{
    printf("------------------\n");
    printf("|    CARTON %d    |\n", num + 1);
    printf("------------------\n");

    for(int i = 0; i < FILAS; i++)
    {
        printf("| ");

        for (int j = 0; j < COLUMNAS; j++)
        {
            if (v[num][i][j] < 10)//si es menor a 10 dibujamos un 0 para que todos los numeros tengan 2 cifras
            {
                printf("0");
            }
            printf("%d ", v[num][i][j]);
        }
        printf("|\n");
    }
    printf("------------------\n");
}
