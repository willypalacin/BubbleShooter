#include <stdio.h>
#include "LS_allegro.h"
#include "grafica.h"
#include "animaciones.h"
#include <time.h>
#include "datos.h"
#include "loadRanking.h"

int main(void){
	Partida partida[1];
	int opcion,u,w,pausa,game_over,iResult;
	Ranking ranking[1];
	float time0, time1;
	do {
		GRAFICA_mostrarMenu();
		opcion = GRAFICA_elegirOpcion();
		int nSortir = 0;
		
		switch (opcion) {
			case 1:
				GRAFICA_inicializarValores(partida,&game_over,&pausa);
				GRAFICA_pedirNombre(partida);
				LS_allegro_init(1024,600,"LS Dungeon");
				//Inicializamos el tiempo
				time0 = (float) clock();
				
				while(!nSortir){
					time1 = (float) clock();
					//Cuenta segundos de uno en uno
					time0 = ANIMACIONES_aumentarSegundos(time0, time1, partida);
					
					ANIMACIONES_movimientos(partida, &u, &w, &game_over, &nSortir, &pausa);
					
					
					while (pausa == 1) {
						GRAFICA_pintarPausa();
						time0 = (float) clock();
						//Si vuelves a pulsar P, restablecemos
						pausa = ANIMACIONES_restablecerPausa(pausa);
					}
				
					
					GRAFICA_pintarPantalla(partida, game_over);
				
					//Pintem la pantalla de la finestra gràfica
					LS_allegro_clear_and_paint(BLACK);
				}
				LS_allegro_exit();
				break;
			case 3:
				iResult = readRankingInfo(ranking[0].acPlayers, ranking[0].niveles, ranking[0].minutos, ranking[0].segundos);
				
				if (iResult == -1) {
					printf(ERROR_CARGA_RANKING);
				}
				else {
					printf(EXITO_RANKING);
				}
				break;
			
			case 4:
				GRAFICA_verRanking(ranking);
		}
		
	} while (opcion != 5);

	return 0;
}
