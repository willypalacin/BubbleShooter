#include "animaciones.h"

float ANIMACIONES_aumentarSegundos(float time0, float time1, Partida partida[1]) {
	if ((time1-time0)/(float)CLOCKS_PER_SEC >= 1) {
		time0 = (float) clock();
		partida[0].tiempo.tiempo_partida++;
		//Variable que cada 30 segundos se pondrá a cero
		partida[0].tiempo.tiempo_nivel++;				
					
	}
	return time0;
	
}
void ANIMACIONES_restablecerTiempoNivel(Partida partida[1]) {
	if (partida[0].tiempo.tiempo_nivel >= 31) {
		//restablecerlo a cero y subir nivel	
		partida[0].tiempo.tiempo_nivel = 1;	
		partida[0].jugador.nivel++;
	}

}

void ANIMACIONES_moverDisparadorDerecha(Partida partida[1]) {
	
	partida[0].disparador.pos_x = partida[0].disparador.pos_x + 60;
	partida[0].disparador.bola.pos_x = partida[0].disparador.bola.pos_x + 60;
		
	if (partida[0].disparador.pos_x >= 720) {
		partida[0].disparador.pos_x	= partida[0].disparador.pos_x - 60;
		partida[0].disparador.bola.pos_x = partida[0].disparador.bola.pos_x - 60;
	}
}
	
void ANIMACIONES_moverDisparadorIzquierda(Partida partida[1]) {
	partida[0].disparador.pos_x = partida[0].disparador.pos_x - 60;
	partida[0].disparador.bola.pos_x = partida[0].disparador.bola.pos_x - 60;	
	
	if (partida[0].disparador.pos_x <= 15) {
		partida[0].disparador.pos_x	= partida[0].disparador.pos_x + 60;
		partida[0].disparador.bola.pos_x = partida[0].disparador.bola.pos_x + 60;
	}
}
