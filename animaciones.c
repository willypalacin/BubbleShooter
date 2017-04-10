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

void ANIMACIONES_llevarBolaHastaPosicion(Partida partida[1], int pos_y, int i, int j) {
	
	while(partida[0].disparador.bola.pos_y >= pos_y) {
		GRAFICA_pintarPantalla(partida);
		partida[0].disparador.bola.pos_y = partida[0].disparador.bola.pos_y - 4;
		
		pintarDisparador(partida);
		LS_allegro_clear_and_paint(BLACK);
		
		
	}
	
		partida[0].casilla[i+2][j].bola.color = partida[0].disparador.bola.color;
		partida[0].casilla[i+2][j].ok_bola = 1;
	
	
}

void ANIMACIONES_eliminarBola (Partida partida[1], int * u, int * w) {
	int i, j;
	int contador = 0;
	
	j = *w;
	
	for (i = 8; i >= 1; i--) {
		if (partida[0].casilla[i-1][j].ok_bola == 1 && partida[0].casilla[i][j].ok_bola == 1 && partida[0].casilla[i - 1][j].bola.color == partida[0].casilla[i][j].bola.color) {
			contador++;
			partida[0].casilla[i-1][j].ok_bola = 0;
			partida[0].casilla[i][j].ok_bola = 0;
			partida[0].casilla[*u + 2][j].ok_bola = 1;
		}	
	}
	i = *u;
	for (j = 1; j <= 11; j++) {
		if (partida[0].casilla[i + 2][j].ok_bola == 1 && partida[0].casilla[i+2][j-1].ok_bola == 1 && partida[0].casilla[i+2][j].bola.color == partida[0].casilla[i+2][j -1].bola.color) {
			contador++;
			partida[0].casilla[i+2][j].ok_bola = 0;
			partida[0].casilla[i+2][j -1].ok_bola = 0;
			partida[0].casilla[i+2][*w].ok_bola = 1;
		}	
	}
	if(contador > 0) {
		partida[0].casilla[*u + 2][*w].ok_bola = 0;
	
		
	}
	/*i = *u;
	j = *w;
	
	if (j == 0) {
		if (partida[0].casilla[i+2][j+1].ok_bola == 1 && partida[0].casilla[i+2][j].bola.color == partida[0].casilla[i+2][j+1].bola.color ) {
			partida[0].casilla[i+2][j].ok_bola = 0;
			partida[0].casilla[i+2][j +1].ok_bola = 0;
		}
		if (partida[0].casilla[i+1][j].ok_bola == 1 && partida[0].casilla[i+1][j].bola.color == partida[0].casilla[i+2][j].bola.color ) {
			partida[0].casilla[i+1][j].ok_bola = 0;
			partida[0].casilla[i+2][j].ok_bola = 0;
		}
	}
	if (j == 11) {
		if (partida[0].casilla[i+2][j - 1].ok_bola == 1 && partida[0].casilla[i+2][j].bola.color == partida[0].casilla[i+2][j - 1].bola.color) {
			partida[0].casilla[i+2][j].ok_bola = 0;
			partida[0].casilla[i+2][j - 1].ok_bola = 0;
		}
		if (partida[0].casilla[i+1][j].ok_bola == 1 && partida[0].casilla[i+1][j].bola.color == partida[0].casilla[i+2][j].bola.color) {
			partida[0].casilla[i+1][j].ok_bola = 0;
			partida[0].casilla[i+2][j].ok_bola = 0;
		}
	}
	
	if (j != 11 && j != 0) {
		
		if (partida[0].casilla[i+2][j - 1].ok_bola == 1 && partida[0].casilla[i+2][j].bola.color == partida[0].casilla[i+2][j - 1].bola.color) {
			partida[0].casilla[i+2][j].ok_bola = 0;
			partida[0].casilla[i+2][j - 1].ok_bola = 0;
		}
		
		if (partida[0].casilla[i+1][j].ok_bola == 1 && partida[0].casilla[i+1][j].bola.color == partida[0].casilla[i+2][j].bola.color) {
			partida[0].casilla[i+1][j].ok_bola = 0;
			partida[0].casilla[i+2][j].ok_bola = 0;
		}
		
		if (partida[0].casilla[i+2][j+1].ok_bola == 1 && partida[0].casilla[i+2][j].bola.color == partida[0].casilla[i+2][j+1].bola.color ) {
			partida[0].casilla[i+2][j].ok_bola = 0;
			partida[0].casilla[i+2][j +1].ok_bola = 0;
		}
	}
	
	
	*/	
}

void ANIMACIONES_dispararBola(Partida partida[1], int * u, int * w) {
	int i, j;
	int hay_bola = 0;
	int pos_y;
	//Averiguo en que casilla está la bola
	j = (partida[0].disparador.bola.pos_x - 50) / 60;
	*w = j;
	i = 8;
	while (i >= 0 && hay_bola == 0) {
		if (partida[0].casilla[i][j].ok_bola == 1) {
			//Guardas la posicion hasta la que tienes que llevar la bola
			pos_y = partida[0].casilla[i+1][j].bola.pos_y;
			hay_bola = 1;
			
		}
		if (partida[0].casilla[0][j].ok_bola == 0 && i == 0) {
			//Guardas la posicion hasta la que tienes que llevar la bola
			pos_y = partida[0].casilla[i][j].bola.pos_y;
			hay_bola = 1;
			
		}
		i--;
		
	
	}
	*u = i;
	ANIMACIONES_llevarBolaHastaPosicion(partida, pos_y, i, j);
	
}

void ANIMACIONES_restablecerTiempoNivel(Partida partida[1]) {
	
	//restablecerlo a cero y subir nivel	
	partida[0].tiempo.tiempo_nivel = 1;	
	partida[0].jugador.nivel++;
	

}

void ANIMACIONES_cambioBolaReserva(Partida partida[1]) {
		
		// Ponemos la altura a la inicial ya que al disparar habrá aumentado
		partida[0].disparador.bola.pos_y = 525;

		partida[0].disparador.bola.color = partida[0].bola[0].color;
	
		partida[0].bola[0].color = partida[0].bola[1].color;
		
		partida[0].bola[1].color = partida[0].bola[2].color;
		
		partida[0].bola[2].color = partida[0].bola[3].color;
		
		partida[0].bola[3].color = GRAFICA_colorRandom();
		
		
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
