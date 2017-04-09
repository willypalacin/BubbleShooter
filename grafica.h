#ifndef _GRAFICA_H_
#define _GRAFICA_H_

#include "datos.h"
#include <stdio.h>
#include "LS_allegro.h"
#include <time.h>
#include <string.h>

int GRAFICA_colorRandom();
void GRAFICA_mostrarMenu();
int GRAFICA_elegirOpcion();
void GRAFICA_inicializarBolasReserva (Partida partida[1]);
void GRAFICA_pedirNombre(Partida partida[1]);
void GRAFICA_pintarPantalla(Partida partida[1]);
void GRAFICA_generarMatriz(Partida partida[1]);
void GRAFICA_inicializarDisparador(Partida partida[1]);

#endif