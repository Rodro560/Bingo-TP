#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define FILAS 3
#define COLUMNAS 5

//PRE: pide un numero minimo y un numero maximo
//POST: devuelve un numero aleatorio entre los numeros dados
int aleatorioEntre(int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios entre el numero minimo y maximo especificado
void cargarVectorConAleatorios(int v[], int tam, int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios sin repetir entre el numero minimo y maximo especificado
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi);
//PRE: Pide el vector del carton. TIENE QUE SER DE TAMAÑO [3][5]
//POST: utiliza la funcion de cargarVectorConAleatoriosSinRepetir para llenar dicho vector
void asignarCarton(int v[FILAS][COLUMNAS]);
//PRE: Pide el vector del carton (TIENE QUE SER DE TAMAÑO [3][5]) y el numero del carton
//POST: Dibuja en consola un carton, indicando su numero e imprimiendo el vector en 3x5
void dibujarCarton(int v[FILAS][COLUMNAS], int num);

#endif // FUNCIONES_H_INCLUDED
