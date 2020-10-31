#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

struct CartonEstructura;
typedef struct CartonEstructura * Carton;

//Pre: Necesita un struct carton
//Post: Iniciara los cartones en 0
Carton iniciarCarton();

//--------------------------Carga de Cartones-------------------------------
//Pre:Necesita structs de Cartones vacios y la cantidad de los mismos
//Post:Dejara que el usuario ingrese los numeros del carton/es 
void cargarCartonPorTeclado(Carton cart);
//Pre: Se necesita structs de Cartones vacios y la cantidad de los mismos
//Post: Cargara un struct/s de Cartones con alatorios
void cargarCartonConAleatorios(Carton cart);

//----------------------------Mostrar Carton----------------------------------------
//PRE: Pide el vector del carton y el numero del carton 
//POST: Dibuja en consola un carton, indicando su numero e imprimiendo el vector
void dibujarCarton(Carton cart, int num);

//------------------------------Busqueda y marcas de numeros------------------------
//Pre: Precisa un carton cargado y el numero a buscar
//Post:  Devolvera un "0"(no lo encuentra) o "1"(lo encuentra) dependiendo de si encuentra el numero o no
int buscarNumeroEnCarton(Carton cart, int num);
//Pre: Precisa el carton, el numero y un puntero hacia un vector, 
//ademas esta funcion solo se llama despues de comprobar con la funcion de buscarNumeroEnCarton si encontro un numero
//Post: Escribe la posicion del numero a buscar en el vector al que apunta el puntero
void buscarPosicionEnCarton(Carton cart, int num, int *posicion);
//Pre: Precisa de un carton cargado y que el numero coinsida con un numero del carton antes mencionado, ademas de las dos anteriores funciones
//Post: Pondra "xx" si todo lo anterior esta correcto
int marcarNumeroEnCarton(Carton cart, int num);

//-----------------------------Comprobante-------------------------------------
//Pre: necesita que el jugador cante linea
//Post: Comprobara si la linea cantada es correcta o no 
int comprobarLinea(Carton cart);
//Pre: necesita que el jugador cante columna
//Post: Comprobara si la columna cantada es correcta o no 
int comprobarColumna(Carton cart);
//Pre: necesita que el jugador cante bingo
//Post: Comprobara si el bingo cantado es correcta o no 
int comprobarBingo(Carton cart);



#endif // CARTON_H_INCLUDED
