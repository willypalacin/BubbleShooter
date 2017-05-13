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
					time0 = ANIMACIONES_aumentarSegundos(time0, time1, partida);
					ANIMACIONES_movimientos(partida, &u, &w, &game_over, &nSortir, &pausa, &time0, partida[0].ranking);
					GRAFICA_pintarPantalla(partida, game_over);
					//Pintem la pantalla de la finestra gràfica
					LS_allegro_clear_and_paint(BLACK);
				}
				LS_allegro_exit();
				break;
			case 3:
				iResult = readRankingInfo(partida[0].ranking[0].acPlayers, partida[0].ranking[0].niveles, partida[0].ranking[0].minutos, partida[0].ranking[0].segundos);
				
				if (iResult == -1) {
					printf(ERROR_CARGA_RANKING);
				}
				else {
					printf(EXITO_RANKING);
				}
				break;
			
			case 4:
				GRAFICA_verRanking(partida[0].ranking);
		}
		
	} while (opcion != 5);

	return 0;
}
