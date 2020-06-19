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

