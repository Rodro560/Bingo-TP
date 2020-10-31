#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "funciones.h"

struct JugadorEstructura;
typedef struct JugadorEstructura * Jugador;

//----------Funciones get------------//
char* getNombreYApellido(Jugador p1);
double getDNI(Jugador p1);
int getPuntaje(Jugador p1);
int getCartones(Jugador p1);

//-----------Funciones set-----------//
void setNombreYApellido(Jugador p1);
void setDNI(Jugador p1);

//PRE: Pide el jugador que contiene los cartones y la cantidad de cartones
//POST: Llama correctamente a la funcion de dibujarCarton las veces que sean necesarias
void dibujarCartones(Jugador player, int cant);

//-----------constructor------------//
//Pre:Se necesitara crear una estructura cualquiera
//Post:Se guardaran los datos del jugador
Jugador ingresarJugadorPorTeclado();

void jugarBingo(Jugador player, Jugador pc, int cantidadC, int bolitas[]);

//------------destructor-----------//
void destruirJugador(Jugador p1);

//-------------------------------------------Archivos---------------------------------------

//Pre: Se necesita un struct ya cargado
//Post: El struct se guardadra en un archivo
void conversorDeStructAArchivo(Jugador j);

void cargarCartonAArchivo(Jugador j,int v[MAXCARTONES][FILAS][COLUMNAS], int cant);

void menuDeEmergencia(Jugador juga);

#endif // JUGADOR_H_INCLUDED
