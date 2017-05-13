#ifndef _GRAFICA_H_
#define _GRAFICA_H_

#include "datos.h"
#include "animaciones.h"
#include <stdio.h>
#include "LS_allegro.h"
#include <time.h>
#include <string.h>

int GRAFICA_colorRandom();
int GRAFICA_elegirOpcion();
void GRAFICA_inicializarBolasReserva (Partida partida[1]);
void GRAFICA_pedirNombre(Partida partida[1]);
void GRAFICA_pintarPantalla(Partida partida[1], int game_over);
void GRAFICA_inicializarVelocidades(Partida partida[1]);
void GRAFICA_pintarPausa();
void GRAFICA_mostrarRanking(Ranking ranking[1]);
void GRAFICA_pintarGameOver(Partida partida[1]);
void GRAFICA_generarFilaBola1(Partida partida[1]);
void GRAFICA_verRanking(Ranking ranking[1]);
void GRAFICA_inicializarValores(Partida partida[1],int* pausa, int* game_over);
void pintarDisparador(Partida partida[1]);
void GRAFICA_generarMatriz(Partida partida[1]);
void GRAFICA_inicializarDisparador(Partida partida[1]);

#endif