#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int aleatorioEntre(int mini, int maxi)
{
    return mini + rand()%(maxi-mini+1);
}

void cargarVectorConAleatorios(int v[], int tam, int mini, int maxi)
{
    int aleatorio = 0;

    for (int i = 0; i < tam; i++)
    {
        aleatorio = aleatorioEntre(mini, maxi);
        v[i] = aleatorio;
    }
}

void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi)
{
    int aleatorio = 0;

    for (int i = 0; i < tam; i++)
    {//antes de asignar el numero aleatorio pasamos por los numeros ya generados para comprobar que no se repitan
        aleatorio = aleatorioEntre(mini, maxi);

        for(int j = 0; j < i; j++)
        {

            if (v[j] == aleatorio)
            {//si se encontro un numero repetido volvemos a generar un numero aleatorio y volvemos a comprobar el vector
                aleatorio = aleatorioEntre(mini, maxi);
                j = 0;
            }
        }

        v[i] = aleatorio;
    }
}
//----------------carga de carton y muestra del mismo----------------------------------
void asignarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant)
{

    for (int i = 0; i < cant; i++)
    {
        int tempvector[FILAS*COLUMNAS];
        cargarVectorConAleatoriosSinRepetir(tempvector,FILAS*COLUMNAS,1,BOLITAS);

        for(int j = 0; j < FILAS; j++)
        {
            for (int k = 0; k < COLUMNAS; k++)
            {
                v[i][j][k] = tempvector[j*COLUMNAS + k];
            }

        }
    }
}

void dibujarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant)
{
    for (int i = 0; i< cant; i++)
    {
        dibujarCarton(v,i);
    }
}

void dibujarCarton(int v[MAXCARTONES][FILAS][COLUMNAS], int num)
{
    printf("------------------\n");
    printf("|    CARTON %d    |\n", num + 1);
    printf("------------------\n");

    for(int i = 0; i < FILAS; i++)
    {
        printf("| ");

        for (int j = 0; j < COLUMNAS; j++)
        {
            if (v[num][i][j] < 10)//si es menor a 10 dibujamos un 0 para que todos los numeros tengan 2 cifras
            {
                printf("0");
            }
            printf("%d ", v[num][i][j]);
        }
        printf("|\n");
    }
    printf("------------------\n");
}

//---------------------------bolitas------------------------------------------------
void generarBolitas(int v[]){
    for(int i = 0; i < BOLITAS; i++){
        cargarVectorConAleatoriosSinRepetir(v,BOLITAS,1,BOLITAS);
    }
}

void mostrarBolitas(int v[])
{
    for(int i = 0; i < BOLITAS; i++)
    {
        printf("     ___________        \n");
        printf("    |           |       \n");
        printf("    |           |       \n");

        printf("    |     ");
        if (v[i]< 10) printf("0");
        printf("%d    |       \n",v[i]);

        printf("    |           |       \n");
        printf("    |___________|       \n");
    }
    printf("\n\n\n");

    }

//-----------------------busqueda y marca de numeros---------------------------------

int busquedaDeNumero(int mat[][FILAS][COLUMNAS], int num[])
{
    int posReglon = -1, posFila = -1, rpt = 0;

    for(int i=0; i < FILAS; i++)
    {
        for(int j=0;j<COLUMNAS;j++)
        {
            if(mat[][i][j] == num)
            {
                posReglon = i;
                posFila = j;
            }
        }
    }
    rpt = posFila*10 + posReglon;
    return rpt;
}

void marcarNumero(int mat[][FILAS][COLUMNAS], int num[]){
    for(int i=0; i<90; i++){
        rpt=busquedaDeNumero(mat,num[i]);
        
    }
}

void menuDeEmergencia(Jugador juga){
    int rpt=0, opc=0;

    printf("\Te equivocaste en ingresar tus datos?");
    printf("\n1.Me equivoque");
    printf("\n2.No me equivoque\n");
    scanf("%d",&rpt);

    if (rpt==1){
        do{
            system("cls");
            printf("\nEn que te equivocaste?\n\n ");
            printf("\n1.Me equivoque en mi nombre");
            printf("\n2.Me equivoque en mi DNI");
            printf("\n0.Para salir\n");
            scanf("%d",&opc);

        switch(opc){
            case 1:
                system("cls");
                getNombreYApellido(juga);
                setNombreYApellido(juga);
                break;
            case 2:
                system("cls");
                getDNI(juga);
                setDNI(juga);
                break;
            case 0:
                break;
            default:
                system("cls");
                printf("La opcion ingresada es incorrecta");
                break;
        }
        }while(opc!=0);
    }
}
//------------------------------------struct-----------------------------------------

struct JugadorEstructura{

char nombreyApellido[50];
double dni;
int puntaje;
int Cartones[MAXCARTONES][FILAS][COLUMNAS];
};

struct PCEstructura{
int puntaje;
int Cartones[MAXCARTONES][FILAS][COLUMNAS];
};

//----------------------------------TDA------------------------------------------------
//-------------Get---------------//
char* getNombreYApellido(Jugador p1){
    return p1->nombreyApellido;
}

double getDNI(Jugador p1){
    return p1->dni;
}

int getPuntaje(Jugador p1){
    return p1->puntaje;
}

int getCartones(Jugador p1){
    return p1->Cartones;
}

//-------------Set---------------//
void setNombreYApellido(Jugador p1){

char aux[50]= " ";

    printf("\nIngrese el nuevo nombre\n");
    fflush(stdin);
    gets(aux);
    strcpy(p1->nombreyApellido,aux);
}

void setDNI(Jugador p1){

    printf("\nIngrese el nuevo DNI\n");
    scanf("%lf",&p1->dni);
}

//------------------constructor----------------//
Jugador IngresarJugadorPorTeclado(){

    Jugador j1= malloc(sizeof(struct JugadorEstructura));

    char aux[50]=" ";

    printf("\nIngresa tu nombre y tu apellido\n");
    fflush(stdin);
    gets(aux);
    strcpy(j1->nombreyApellido, aux);

    printf("\nIngresa tu DNI\n");
    scanf("%lf",&j1->dni);

    j1->puntaje=0;

    return j1;
};

//------------------destructor----------------//
void DestruirJugador(Jugador p1){
    free(p1);
}

//---------------------------------------Archivos---------------------------------------
void conversorDeStructAArchivo(Jugador j){

    FILE * punteroArchivoJugador;

    punteroArchivoJugador = fopen("ArchivoJugador.txt", "w");

    fprintf(punteroArchivoJugador, "%s\n%lf\n%d",j->nombreyApellido,j->dni,j->puntaje);

    fclose(punteroArchivoJugador);
}

