#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define FILAS 3
#define COLUMNAS 5
#define MAXCARTONES 3
#define BOLITAS 90

//PRE: pide un numero minimo y un numero maximo
//POST: devuelve un numero aleatorio entre los numeros dados
int aleatorioEntre(int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios entre el numero minimo y maximo especificado
void cargarVectorConAleatorios(int v[], int tam, int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios sin repetir entre el numero minimo y maximo especificado
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi);
//PRE: Pide el vector del carton y la cantidad de cartones
//POST: utiliza la funcion de cargarVectorConAleatoriosSinRepetir para llenar dicho vector
void asignarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant);
//PRE: Pide el vector del carton y la cantidad de cartones
//POST: Llama correctamente a la funcion de dibujarCarton las veces que sean necesarias
void dibujarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant);
//PRE: Pide el vector del carton y el numero del carton
//POST: Dibuja en consola un carton, indicando su numero e imprimiendo el vector
void dibujarCarton(int v[MAXCARTONES][FILAS][COLUMNAS], int num);



//---------------------------------Bolitas-----------------------------------------------
//pre:se necesita un vector sin cargar
//post:aca se pondra todos los numeros del 1 al 90 para el bingo
void generarBolitas(int v[]);
//pre:se necesita el anterior vector cargado
//post:como su nombre lo dice esta funcion mostrara los numeros del vector de bolitas
void mostrarBolitas(int v[]);

//-----------------------busqueda y marca de numeros---------------------------------
//PRE:Se necesita una matriz cargada y un numero (el mismo es sacado de las bolitas del bingo)
//POST:Buscara un numero en la matriz y pondra la posicion en la cual encontro dicho numero,
int busquedaDeNumero(int mat[][FILAS][COLUMNAS], int num[]);
//
//
void marcarNumero(int mat[][FILAS][COLUMNAS], int num[]);

//-------------------------------------struct-----------------------------------------------
struct JugadorEstructura;

struct PCEstructura;

typedef struct PCEstructura * PC;

typedef struct JugadorEstructura * Jugador;
//-------------------------------------------TDA--------------------------------------------
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
Jugador IngresarJugadorPorTeclado();

//------------destructor-----------//
void DestruirJugador(Jugador p1);

//-------------------------------------------Archivos---------------------------------------

//Pre: Se necesita un struct ya cargado
//Post: El struct se guardadra en un archivo
void conversorDeStructAArchivo(Jugador j);

void cargarCartonAArchivo(Jugador j,int v[MAXCARTONES][FILAS][COLUMNAS], int cant);

void menuDeEmergencia(Jugador juga);



#endif // FUNCIONES_H_INCLUDED
