
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define FILAS 3
#define COLUMNAS 5
#define MAXCARTONES 3

//-------------Los vectores alatorios------------------
//PRE: pide un numero minimo y un numero maximo
//POST: devuelve un numero aleatorio entre los numeros dados
int aleatorioEntre(int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios entre el numero minimo y maximo especificado
void cargarVectorConAleatorios(int v[], int tam, int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios sin repetir entre el numero minimo y maximo especificado
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi);

//----------------carga de carton y muestra del mismo----------------------------------
//PRE: Pide el vector del carton y la cantidad de cartones
//POST: utiliza la funcion de cargarVectorConAleatoriosSinRepetir para llenar dicho vector
void asignarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant);
//PRE: Pide el vector del carton y la cantidad de cartones
//POST: Llama correctamente a la funcion de dibujarCarton las veces que sean necesarias
void dibujarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant);
//PRE: Pide el vector del carton y el numero del carton
//POST: Dibuja en consola un carton, indicando su numero e imprimiendo el vector
void dibujarCarton(int v[MAXCARTONES][FILAS][COLUMNAS], int num);

//-----------------------busqueda y marca de numeros---------------------------------
//PRE:Se necesita una matriz cargada y un numero (el mismo es sacado de las bolitas del bingo)
//POST:Buscara un numero en la matriz y pondra la posicion en la cual encontro dicho numero,
int busquedaDeNumero(int mat[3][5],int n, int num);



//-------------------------------------struct-----------------------------------------------
/*struct Jugador{

char nombreyApellido[50];
double dni;
};


struct Jugador IngresarJugadorPorTeclado(struct Jugador w);*/

#endif // FUNCIONES_H_INCLUDED
