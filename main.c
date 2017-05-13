#include <stdio.h>
#include "LS_allegro.h"
#include "grafica.h"
#include "animaciones.h"
#include <time.h>
#include "datos.h"
#include "menu.h"
#include "loadRanking.h"

int main(void){
	Partida partida[1];
	partida[0].ranking[0].iResult = -1;
	int opcion;
	do {
		MENU_mostrarMenu();
		opcion = GRAFICA_elegirOpcion();

		switch (opcion) {
			case 1:
				MENU_case1(partida);
				break;
			case 2:
				MENU_case2(partida);
				break;
			case 3:
				partida[0].ranking[0].iResult = readRankingInfo(partida[0].ranking[0].acPlayers, partida[0].ranking[0].niveles, partida[0].ranking[0].minutos, partida[0].ranking[0].segundos);
				
				if (partida[0].ranking[0].iResult == -1) {
					printf(ERROR_CARGA_RANKING);
				}
				else {
					printf(EXITO_RANKING);
				}
				break;
			
			case 4:
				if(partida[0].ranking[0].iResult != -1) {
					GRAFICA_verRanking(partida[0].ranking);
				}
				else {
					printf("Debe cargar ranking antes de cargarlo\n");
		
				}
		}
		
	} while (opcion != 5);

	return 0;
}
