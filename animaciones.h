#ifndef _ANIMACIONES_H_
#define _ANIMACIONES_H_

#include <time.h>
#include <datos.h>

float ANIMACIONES_aumentarSegundos(float time0, float time1, Partida partida[1]);
void ANIMACIONES_restablecerTiempoNivel(Partida partida[1]);
void ANIMACIONES_moverDisparadorIzquierda(Partida partida[1]);
void ANIMACIONES_moverDisparadorDerecha(Partida partida[1]);

#endif