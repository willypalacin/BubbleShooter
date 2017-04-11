#include <stdio.h>
#include "LS_allegro.h"
#include "grafica.h"
#include "animaciones.h"
#include <time.h>
#include "datos.h"
#include "loadRanking.h"

int main(void){
	Partida partida[1];
	int opcion;
	
	int u;
	int w;
	float time0, time1;
	
	do {
		
		GRAFICA_mostrarMenu();
		opcion = GRAFICA_elegirOpcion();
		int nSortir = 0;
		
		switch (opcion) {
			case 1:
				partida[0].tiempo.tiempo_partida = 1;
				partida[0].tiempo.tiempo_nivel = 1;	
				partida[0].jugador.nivel = 1;
				do {
					GRAFICA_pedirNombre(partida);
				} while (strlen(partida[0].jugador.nombre) >= 20);
				
				LS_allegro_init(1024,600,"LS Dungeon");
				
				//Inicializamos el tiempo
				time0 = (float) clock();
				
				//Inicializaremos color y posicion de las bolas de reserva
				GRAFICA_inicializarBolasReserva (partida);
				
				GRAFICA_inicializarVelocidades(partida);
				
				//Iniciaremos la posicion del disparador y de la bola del disparador.
				GRAFICA_inicializarDisparador(partida);
				
				//Generamos Matriz de casillas
				GRAFICA_generarMatriz(partida);
				
				//Generamos la primera fila de la matriz
				GRAFICA_generarFilaBola1(partida);
				
				
				while(!nSortir){
					
					
					time1 = (float) clock();
					
					//Cuenta segundos de uno en uno
					time0 = ANIMACIONES_aumentarSegundos(time0, time1, partida);
					
					if (partida[0].tiempo.tiempo_nivel >= 31) {
						ANIMACIONES_restablecerTiempoNivel(partida);
					}
					if (partida[0].tiempo.segs % 65 >= partida[0].nivel.tiempo_nivel) {
						partida[0].tiempo.segs = 0;
						ANIMACIONES_bajaFila(partida);
						GRAFICA_generarFilaBola1(partida);
					}
					
					if (LS_allegro_key_pressed(ALLEGRO_KEY_SPACE) == 1) {
						ANIMACIONES_dispararBola(partida, &u, &w);
						ANIMACIONES_eliminarBola (partida, &u, &w);
						ANIMACIONES_cambioBolaReserva(partida);
						
						
					} 
					
					if (LS_allegro_key_pressed(ALLEGRO_KEY_A) == 1) {
						ANIMACIONES_moverDisparadorIzquierda(partida);
					} 
					
					if (LS_allegro_key_pressed(ALLEGRO_KEY_D) == 1) {
						 ANIMACIONES_moverDisparadorDerecha(partida);
					} 
					
					if (ANIMACIONES_gameOver(partida) == 1) {
						GRAFICA_pintarGameOver(partida);
						
						
					}

				
					if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
						nSortir = 1;
					}
					
					GRAFICA_pintarPantalla(partida);
				
					//Pintem la pantalla de la finestra gràfica
					LS_allegro_clear_and_paint(BLACK);
				}
				LS_allegro_exit();
				
		
		}
		
	} while (opcion != 5);
	
	
	
	
	
	
	return 0;
}
