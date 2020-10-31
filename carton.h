#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

struct CartonEstructura;
typedef struct CartonEstructura * Carton;

Carton iniciarCarton();

void cargarCartonConAleatorios(Carton cart);
//PRE: Pide el vector del carton y el numero del carton
//POST: Dibuja en consola un carton, indicando su numero e imprimiendo el vector
void dibujarCarton(Carton cart, int num);
int comprobarLinea(Carton cart);
int comprobarColumna(Carton cart);

int marcarNumeroEnCarton(Carton cart, int num);

void cargarCartonPorTeclado(Carton cart);
int buscarNumeroEnCarton(Carton cart, int num);
#endif // CARTON_H_INCLUDED
