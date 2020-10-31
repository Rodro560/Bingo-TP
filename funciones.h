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



//---------------------------------Bolitas-----------------------------------------------
//pre:se necesita un vector sin cargar
//post:aca se pondra todos los numeros del 1 al 90 para el bingo
void generarBolitas(int v[]);
//pre:se necesita el anterior vector cargado
//post:como su nombre lo dice esta funcion mostrara la bolita indicada en el vector de bolitas
void mostrarBolita(int v[], int bolita);
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

//Funciones y procedimientos para el menú
int pedirCantidadDeCartones();
int pedirMetodoDeGeneracionDeCarton();

void mostrarRanking();

#endif // FUNCIONES_H_INCLUDED
