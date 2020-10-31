#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include "jugador.h"

int main()
{
    srand(time(0));
    int cantCarton, tipoCarton, vectorBolitas[BOLITAS];
    Jugador player = ingresarJugadorPorTeclado();
    //al jugador pc no se le pide nombre ni dni
    //usa el mismo struct que el jugador pero con valores predefinidos
    Jugador pc = crearJugadorPC();
    menuDeEmergencia(player);
    mostrarJugador(player);//debug

    printf("\nBienvenido al bingo\n\n");
    //la siguente linea es para elegir la cantidad de cartones
    cantCarton = pedirCantidadDeCartones();
    //las siguente linea es para elegir como van a cargar el carton
    tipoCarton = pedirMetodoDeGeneracionDeCarton();

    crearCartones(player, pc, tipoCarton, cantCarton);

    //llenamos el vector que tendra las bolitas que iran saliendo
    generarBolitas(vectorBolitas);

    //iniciamos el juego
    jugarBingo(player, pc, cantCarton, vectorBolitas);

    mostrarRanking();

    return 0;
}

