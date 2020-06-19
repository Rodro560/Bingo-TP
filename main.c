#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main()
{
    srand(time(0));
    //todo lo del main es de prueba por ahora, falta el menú
    int carton1[3][5];

    asignarCarton(carton1);
    dibujarCarton(carton1, 1);

    return 0;
}
