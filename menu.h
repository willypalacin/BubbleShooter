#ifndef _MENU_H_
#define _MENU_H_

#include <stdio.h>
#include "LS_allegro.h"
#include "grafica.h"
#include "animaciones.h"
#include <time.h>
#include "datos.h"
#include "loadRanking.h"

void MENU_mostrarMenu();
void MENU_case1(Partida partida[1]);
void MENU_case2(Partida partida[1]);
void MENU_pedirNivel(int * nivel);

#endif