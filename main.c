#include <stdio.h>
#include "LS_allegro.h"
#include "grafica.h"
#include "datos.h"
#include "loadRanking.h"

int main(void){
	Partida partida[1];
	int opcion;
	do {
	
		GRAFICA_mostrarMenu();
		opcion = GRAFICA_elegirOpcion();
		int nSortir = 0;
		
		switch (opcion) {
			case 1:
				do {
					GRAFICA_pedirNombre(partida);
				} while (strlen(partida[0].jugador.nombre) >= 20);
				
				LS_allegro_init(1024,600,"LS Dungeon");
				
				//Inicializaremos color y posicion de las bolas de reserva
				GRAFICA_inicializarBolasReserva (partida);
				
				//Iniciaremos la posicion del disparador y de la bola del disparador.
				
				//GRAFICA_inicializarDisparador(partida);
				
				while(!nSortir){
					GRAFICA_pintarPantalla(partida);
					
		
				
					if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
						nSortir = 1;
					}
					
				
					//Pintem la pantalla de la finestra gràfica
					LS_allegro_clear_and_paint(BLACK);
				}
				LS_allegro_exit();
				
		
		}
		
	} while (opcion != 5);
	
	
	
	
	
	
	return 0;
}
