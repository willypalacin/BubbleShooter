#ifndef _ANIMACIONES_H_
#define _ANIMACIONES_H_

#include <time.h>
#include "grafica.h"
#include "LS_allegro.h"
#include <datos.h>


float ANIMACIONES_aumentarSegundos(float time0, float time1, Partida partida[1]);
void ANIMACIONES_restablecerTiempoNivel(Partida partida[1]);
void ANIMACIONES_moverDisparadorIzquierda(Partida partida[1]);
void ANIMACIONES_moverDisparadorDerecha(Partida partida[1]);
void ANIMACIONES_llevarBolaHastaPosicion(Partida partida[1], int pos_y, int i, int j);
void ANIMACIONES_dispararBola(Partida partida[1], int * u, int * w);
void ANIMACIONES_hayGameOver(int * game_over, Partida partida[1]);
int ANIMACIONES_gameOver(Partida partida[1]);
void ANIMACIONES_pulsaP(int * pausa);
void ANIMACIONES_pulsasD(Partida partida[1]);
void ANIMACIONES_pulsasA(Partida partida[1]);
void ANIMACIONES_pulsasEspacio(Partida partida[1], int * u, int * w);
void ANIMACIONES_tiempoDeBajarFila(Partida partida[1]);
void ANIMACIONES_pulsasESC(int * nSortir);
int ANIMACIONES_restablecerPausa (int pausa);
void ANIMACIONES_eliminarBola (Partida partida[1], int * u, int * w);
void ANIMACIONES_cambioBolaReserva(Partida partida[1]);
void ANIMACIONES_bajaFila(Partida partida[1]);
void ANIMACIONES_movimientos(Partida partida[1], int * u, int * w, int * game_over,  int * nSortir,  int * pausa);


#endif