#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//PRE: pide un numero minimo y un numero maximo
//POST: devuelve un numero aleatorio entre los numeros dados
int aleatorioEntre(int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios entre el numero minimo y maximo especificado
void cargarVectorConAleatorios(int v[], int tam, int mini, int maxi);
//PRE: pide un vector declarado sin asignar, el tamaño del vector, un numero minimo y un numero maximo
//POST: le asigna al vector numeros aleatorios sin repetir entre el numero minimo y maximo especificado
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi);

#endif // FUNCIONES_H_INCLUDED
