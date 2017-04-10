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
int esperarCeroUnSegundo(Partida partida[1]) {
	int time5; 
	int time6;
	int si;
	time5 = (float) clock();
	time6 = (float) clock();
	while ((time6-time5)/(float)CLOCKS_PER_SEC <= 0.1) {
		time6 = (float) clock();
		
		
		
	}
	si = 1;
	return si;
	
	
}

void ANIMACIONES_llevarBolaHastaPosicion(Partida partida[1], int pos_y) {
	
	while(partida[0].disparador.bola.pos_y >= pos_y) {
		GRAFICA_pintarPantalla(partida);
		partida[0].disparador.bola.pos_y = partida[0].disparador.bola.pos_y - 1;
		
		pintarDisparador(partida);
		LS_allegro_clear_and_paint(BLACK);
		printf("%d\n",partida[0].disparador.bola.pos_y);
		
	}

}



void ANIMACIONES_dispararBola(Partida partida[1]) {
	int i, j;
	int hay_bola;
	int pos_y;
	//Averiguo en que casilla está la bola
	j = (partida[0].disparador.bola.pos_x - 50) / 60;
	i = 8;
	while (i >= 0 || hay_bola == 0) {
		if (partida[0].casilla[i][j].ok_bola == 1) {
			//Guardas la posicion hasta la que tienes que llevar la bola
			pos_y = partida[0].casilla[i+1][j].bola.pos_y;
			hay_bola = 1;
			
		}
		i--;
		
	
	}
	ANIMACIONES_llevarBolaHastaPosicion(partida, pos_y);
	
}

void ANIMACIONES_restablecerTiempoNivel(Partida partida[1]) {
	
	//restablecerlo a cero y subir nivel	
	partida[0].tiempo.tiempo_nivel = 1;	
	partida[0].jugador.nivel++;
	

}

void ANIMACIONES_bajaFila(Partida partida[1]) {
	int i, j;
	for (i = 8; i >= 0 ; i--) {
		for(j = 11; j >= 0; j--) {
			if (partida[0].casilla[i][j].ok_bola == 1) {
				partida[0].casilla[i + 1][j].bola.color = partida[0].casilla[i][j].bola.color;
				partida[0].casilla[i + 1][j].ok_bola = 1;
			}
		}
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
