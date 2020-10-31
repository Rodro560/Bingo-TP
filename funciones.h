#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define FILAS 3
#define COLUMNAS 5
#define MAXCARTONES 3
#define BOLITAS 90

//----------------------Asignar Cartones------------------------------
//PRE: pide un numero minimo y un numero maximo
//POST: devuelve un numero aleatorio entre los numeros dados
int aleatorioEntre(int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios entre el numero minimo y maximo especificado
void cargarVectorConAleatorios(int v[], int tam, int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios sin repetir entre el numero minimo y maximo especificado
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi);

//---------------------------------Bolitas-----------------------------------------------
//pre:se necesita un vector sin cargar
//post:aca se pondra todos los numeros del 1 al 90 para el bingo
void generarBolitas(int v[]);
//pre:se necesita el anterior vector cargado
//post:como su nombre lo dice esta funcion mostrara la bolita indicada en el vector de bolitas
void mostrarBolita(int v[], int bolita);

//-----------------Funciones y procedimientos para el menú----------------------------
//Pre: Esta funcion se activara despues de que ingrese el usuario
//Post: Es un menu que te permite elegir la cantidad de cartones con los que vas a jugar
int pedirCantidadDeCartones();
//Pre: Esta funcion se activara despues de que ingrese el usuario y la funcion anterior
//Post: Es un menu que te permite elegir como vas a llenar tus cartones para jugar
int pedirMetodoDeGeneracionDeCarton();

//-----------------------puntos--------------------------------
//Pre: Se usa al final en el main
//Post: Mostrara los puntos conseguidos del jugador
void mostrarRanking();

#endif // FUNCIONES_H_INCLUDED
