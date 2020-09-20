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
int busquedaDeNumero(int mat[][FILAS][COLUMNAS],int n, int num);



//-------------------------------------struct-----------------------------------------------
struct Carton{

int    Cartones[MAXCARTONES][FILAS][COLUMNAS];

};
struct Jugador{
char nombreyApellido[50];
double dni;
int puntaje;
struct Carton carton;
};

//Pre:Se necesitara tener los cartones definidos y la cantidad de los mismos
//Post:Guardara los cartones en un struct y a su vez los mostrara
struct Carton formadorDeCartonesEnEstruct(int cartonGuardado[MAXCARTONES][FILAS][COLUMNAS],int CaCarton);
//Pre:Se necesitara crear una estructura cualquiera
//Post:Se guardaran los datos del jugador
struct Jugador IngresarJugadorPorTeclado(struct Jugador j1);

void ConversorDeStructAArchivo(struct Jugador j1);


#endif // FUNCIONES_H_INCLUDED
