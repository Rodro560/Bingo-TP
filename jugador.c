#ifndef JUGADOR_C_INCLUDED
#define JUGADOR_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"
#include "carton.h"
#include "funciones.h"

//------------------------------------struct-----------------------------------------

struct JugadorEstructura{

char nombreyApellido[50];
int dni;
int puntaje;
Carton cartones[MAXCARTONES];
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
    return p1->cartones;
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
    scanf("%d",&p1->dni);
}

//------------------constructor----------------//
Jugador ingresarJugadorPorTeclado(){

    Jugador j1= malloc(sizeof(struct JugadorEstructura));

    char aux[50]=" ";

    printf("\nIngresa tu nombre y tu apellido\n");
    fflush(stdin);
    gets(aux);
    strcpy(j1->nombreyApellido, aux);

    printf("\nIngresa tu DNI\n");
    scanf("%d",&j1->dni);

    j1->puntaje=0;

    for (int i = 0; i < MAXCARTONES; i++)//le creamos cartones vacios al jugador.
    {
        j1->cartones[i] = iniciarCarton();
    }

    return j1;
};

Jugador crearJugadorPC(){

    Jugador pc= malloc(sizeof(struct JugadorEstructura));

    char aux[50]=" ";

    strcpy(pc->nombreyApellido, aux);
    pc->dni = 0;
    pc->puntaje=0;

    for (int i = 0; i < MAXCARTONES; i++)//le creamos cartones vacios a la pc.
    {
        pc->cartones[i] = iniciarCarton();
    }


    return pc;
};

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

void crearCartones(Jugador player, Jugador pc, int tipo, int cantidad)
{
    if (tipo == 1)//cartones aleatorios
    {
        for (int i = 0; i < cantidad; i++)
        {
            iniciarCarton(player->cartones[i]);
            cargarCartonConAleatorios(player->cartones[i]);
        }
    }else{//carga manual de cartones

        for (int i = 0; i < cantidad; i++)
        {
            system("cls");
            printf("CARGANDO CARTON %d\n", i + 1);
            iniciarCarton(player->cartones[i]);
            cargarCartonPorTeclado(player->cartones[i]);
        }
    }

    //cartones de la pc
    for (int i = 0; i < cantidad; i++)
    {
        iniciarCarton(pc->cartones[i]);
        cargarCartonConAleatorios(pc->cartones[i]);
    }
}

void dibujarCartones(Jugador player, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        dibujarCarton(player->cartones[i], i);
    }
}
//------------------destructor----------------//
void destruirJugador(Jugador p1){
    free(p1);
}

void mostrarJugador (Jugador p1)
{
    printf("Nombre del jugador: %s\n", p1->nombreyApellido);
    printf("DNI del jugador: %d\n", p1->dni);
}

void marcarNumeroEnCartones(Jugador player, int cant, int num)
{
    for (int i = 0; i < cant; i++)
    {
        if (marcarNumeroEnCarton(player->cartones[i], num) == 1)
        {
            if (player->dni != 0) printf("Marcaste numero en el carton %d!\n", i + 1);
        }
    }
}

int comprobarLineas(Jugador player, int cant)
{
    int encontrado = 0;

    for (int i = 0; i < cant; i++)
    {
        if (comprobarLinea(player->cartones[i]) == 1)
        {
            encontrado = 1;
        }
    }

    return encontrado;
}

int comprobarColumnas(Jugador player, int cant)
{
    int encontrado = 0;

    for (int i = 0; i < cant; i++)
    {
        if (comprobarColumna(player->cartones[i]) == 1)
        {
            encontrado = 1;
        }
    }

    return encontrado;
}

int comprobarBingos(Jugador player, int cant)
{
    int encontrado = 0;

    for (int i = 0; i < cant; i++)
    {
        if (comprobarBingo(player->cartones[i]) == 1)
        {
            encontrado = 1;
        }
    }

    return encontrado;
}

void comprobacionesPC(Jugador pc, int cantidadC, int * linea, int * columna, int * bingo)
{
    if ((comprobarLineas(pc, cantidadC) == 1) && *linea == 0)
    {
        printf("La pc canto linea! \n");
        printf("+20 puntos para la pc\n\n");
        pc->puntaje += 20;
        *linea = 1;
    }

    if ((comprobarColumnas(pc, cantidadC) == 1) && *columna == 0)
    {
        printf("La pc canto columna! \n");
        printf("+10 puntos para la pc\n\n");
        pc->puntaje += 10;
        *columna = 1;
    }

    if ((comprobarBingos(pc, cantidadC) == 1) && *bingo == 0)
    {
        printf("La pc canto bingo! \n");
        printf("+70 puntos para la pc\n\n");
        pc->puntaje += 70;
        *bingo = 1;
    }
}

void mostrarPuntuaciones(Jugador player, Jugador pc)
{
    printf("Puntos del jugador: %d \n", player->puntaje);
    printf("Puntos de la pc: %d \n", pc->puntaje);
}

void jugarBingo(Jugador player, Jugador pc, int cantidadC, int bolitas[])
{
    system("cls");

    int bolitasSacadas = 0;
    int linea = 0;
    int columna = 0;
    int bingo = 0;
    int opc = 0;

    int * lineaPtr = &linea;
    int * columnaPtr = &columna;
    int * bingoPtr = &bingo;

    mostrarBolita(bolitas, bolitasSacadas);
    marcarNumeroEnCartones(player, cantidadC, bolitas[bolitasSacadas]);

    while (bingo == 0)
    {
        //llenamos el vector que tendra las bolitas que iran saliendo


        printf("Que quieres hacer? \n\n");
        printf("1) Cantar linea\n");
        printf("2) Cantar columna\n");
        printf("3) Cantar bingo\n");
        printf("4) Mostrar cartones de la PC\n");
        printf("5) Mostrar puntaje\n");
        printf("6) Sacar nueva bolilla\n");

        scanf("%d",&opc);

        switch(opc)
        {
            case 1://cantar linea
                system("cls");

                if (linea == 0)
                {
                    if (comprobarLineas(player, cantidadC) == 1)
                    {
                        printf("Felicitaciones, hiciste linea! \n");
                        printf("+20 puntos\n");
                        player->puntaje += 20;
                        linea = 1;
                    }else{
                        printf("No hiciste ninguna linea\n");
                    }
                }else{
                    printf("Solo se puede cantar linea 1 vez\n");
                }

            break;

            case 2://cantar columna
                system("cls");
                if (columna == 0)
                {
                    if (comprobarColumnas(player, cantidadC))
                    {
                        printf("Felicitaciones, hiciste columna! \n");
                        printf("+10 puntos\n");
                        player->puntaje += 10;
                        columna = 1;
                    }else{
                        printf("No hiciste ninguna columna\n");
                    }
                }else{
                    printf("Solo se puede cantar columna 1 vez\n");
                }
            break;

            case 3://cantar bingo
                system("cls");
                if (comprobarBingos(player, cantidadC))
                {
                    printf("Felicitaciones, hiciste bingo! \n");
                    printf("+70 puntos\n");
                    player->puntaje += 70;
                    bingo = 1;
                }else{
                    printf("No hiciste bingo\n");
                }
            break;

            case 4://mostrar cartones de la pc
                system("cls");

                printf("Estos son los cartones de la PC:\n");
                dibujarCartones(pc, cantidadC);
            break;

            case 5://mostrar puntajes
                system("cls");

                mostrarPuntuaciones(player, pc);

            break;

            case 6://sacar bolilla
                system("cls");

                marcarNumeroEnCartones(pc, cantidadC, bolitas[bolitasSacadas]);
                comprobacionesPC(pc, cantidadC, lineaPtr, columnaPtr, bingoPtr);

                if (bingo == 0)//
                {
                    bolitasSacadas++;
                    mostrarBolita(bolitas, bolitasSacadas);
                    marcarNumeroEnCartones(player, cantidadC, bolitas[bolitasSacadas]);
                    dibujarCartones(player, cantidadC);
                }
            break;

            default:
                system("cls");
                printf("Opcion incorrecta, vuelve a intentarlo. \n");
            break;
        }
    }

    //multiplicamos los puntos por el resto de bolitas a sacar
    player->puntaje = player->puntaje * (BOLITAS - bolitasSacadas + 1);
    pc->puntaje = pc->puntaje * (BOLITAS - bolitasSacadas + 1);

    printf("Fin del juego\n");
    if (player->puntaje > pc->puntaje)
    {
        printf("Felicitaciones, ganaste!\n");
    }else{
        printf("Gano la pc!\n");
    }

    mostrarPuntuaciones(player, pc);

    printf("Desea guardar su puntuacion en el ranking? (s/n)\n");

    char aux[1];
    int continuar = 0;

    while(continuar == 0)
    {
        fflush(stdin);
        gets(aux);

        if (aux[0] == 's' || aux[0] == 'S')
        {
            guardarPuntuacionEnArchivo(player);
            printf("Gracias por jugar!\n");
            continuar = 1;
        }else if (aux[0] == 'n' || aux[0] == 'n')
        {
            //mostrar ranking
            continuar = 1;
        }else{
            printf("Opcion incorrecta, escriba s para SI o n para NO\n");
        }
    }

}
//---------------------------------------Archivos---------------------------------------
void guardarPuntuacionEnArchivo(Jugador j){

    FILE * punteroArchivoJugador;

    punteroArchivoJugador = fopen("ranking.txt", "a");

    fprintf(punteroArchivoJugador, "%s\n%d\n",j->nombreyApellido,j->puntaje);

    fclose(punteroArchivoJugador);
}


#endif // JUGADOR_C_INCLUDED
