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

//-----------constructor------------//
//Pre:Se necesitara crear una estructura cualquiera
//Post:Se guardaran los datos del jugador
Jugador ingresarJugadorPorTeclado();
//Pre: Se iniciara una vez el usuario halla puesto sus datos
//Post: Creara un jugador no humano que compitira con el ususario
Jugador crearJugadorPC();
//Pre: Precisa de structs del usuario y el pc, tambien necesitara la cantidad y la forma en que crearlos
//Post: Creara cartones para el jugador y la pc
void crearCartones(Jugador player, Jugador pc, int tipo, int cantidad);

//----------------------mostrar-----------------------------
//PRE: Pide el jugador que contiene los cartones y la cantidad de cartones
//POST: Llama correctamente a la funcion de dibujarCarton las veces que sean necesarias
void dibujarCartones(Jugador player, int cant);
//Pre: Necesita al jugador cargado
//Post: Mostrara al jugador
void mostrarJugador (Jugador p1);
//Pre: Necesita que tanto al pc como al jugador ya cargado
//Post: Imprimira la puntacion de el pc como la del jugador
void mostrarPuntuaciones(Jugador player, Jugador pc);

//------------destructor-----------//
void destruirJugador(Jugador p1);

//----------------------------comprobantes-----------------------------
//Pre: Necesita que el jugador halla cantado linea en alguno de sus cartones
//Post: LLama correctamente a la funcion comprobarLinea las veces necesarias
int comprobarLineas(Jugador player, int cant);
//Pre: Necesita que el jugador halla cantado columna en alguno de sus cartones
//Post: LLama correctamente a la funcion comprobarColumna las veces necesarias
int comprobarColumnas(Jugador player, int cant);
//Pre: Necesita que el jugador halla cantado bingo en alguno de sus cartones
//Post: LLama correctamente a la funcion comprobarBingo las veces necesarias
int comprobarBingos(Jugador player, int cant);
//Pre: Necesita que la pc halla conseguido cantar algo
//Post: Hara las 3 funciones anteriores pero en pc
void comprobacionesPC(Jugador pc, int cantidadC, int * linea, int * columna, int * bingo);

//-------------------------------varios----------------------------------------
//Pre: Precisa que se halla cargado un dato tipo Jugador y que el usuario quiera cambiarlo
//Post: Cambia los datos del DNI o el nombre si el usuario asi lo quiso
void menuDeEmergencia(Jugador juga);
//Pre: Necesita que el numero coincida con algun dato del craton del jugador
//post: Llamara la funcion marcarNumeroEnCarton segun corresponda
void marcarNumeroEnCartones(Jugador player, int cant, int num);
//Pre: Se necesita tanto la pc, jugador, cartones y cantidad de los mismos, ademas de un vector
//Post: Se encargara de hacer el proceso del juego
void jugarBingo(Jugador player, Jugador pc, int cantidadC, int bolitas[]);

//-------------------------------------------Archivos---------------------------------------
//Pre: Se necesita un struct ya cargado
//Post: El struct se guardadra en un archivo
void conversorDeStructAArchivo(Jugador j);
//Pre: Se necesita una puntuacion
//Post: Guardara la puntuacion en el archivo
void guardarPuntuacionEnArchivo(Jugador j);



#endif // JUGADOR_H_INCLUDED
