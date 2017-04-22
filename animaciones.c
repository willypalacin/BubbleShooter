#include "animaciones.h"

float ANIMACIONES_aumentarSegundos(float time0, float time1, Partida partida[1]) {
	if ((time1-time0)/(float)CLOCKS_PER_SEC >= 1) {
		time0 = (float) clock();
		partida[0].tiempo.tiempo_partida++;
		//Variable que cada 30 segundos se pondrá a cero
		partida[0].tiempo.tiempo_nivel++;
		
		partida[0].tiempo.segs++;
					
	}
	return time0;
	
}

int ANIMACIONES_hayGameOver(int game_over,Partida partida[1]) {
	if (ANIMACIONES_gameOver(partida) == 1) {
		game_over = 1;
	}
	return game_over;
}
void ANIMACIONES_pulsasA(Partida partida[1]) {
	if (LS_allegro_key_pressed(ALLEGRO_KEY_A) == 1) {
		ANIMACIONES_moverDisparadorIzquierda(partida);
	} 
					
}
void ANIMACIONES_pulsasD(Partida partida[1]) {
	if (LS_allegro_key_pressed(ALLEGRO_KEY_D) == 1) {
		ANIMACIONES_moverDisparadorDerecha(partida);
	}

}

void ANIMACIONES_treintaSegundos(Partida partida[1]) {
	if (partida[0].tiempo.tiempo_nivel >= 31) {
		ANIMACIONES_restablecerTiempoNivel(partida);
	}
	
}

void ANIMACIONES_tiempoDeBajarFila(Partida partida[1]) {
	
	if (partida[0].tiempo.segs % 60  >= partida[0].nivel.vel_inicial + partida[0].nivel.aum_velocidad) {
		partida[0].tiempo.segs = 0;
		ANIMACIONES_bajaFila(partida);
		GRAFICA_generarFilaBola1(partida);
	}	
}

void ANIMACIONES_pulsasEspacio(Partida partida[1], int * u, int * w) {
	if (LS_allegro_key_pressed(ALLEGRO_KEY_SPACE) == 1) {
		ANIMACIONES_dispararBola(partida, u, w);
		ANIMACIONES_eliminarBola (partida, u, w);
		ANIMACIONES_cambioBolaReserva(partida);
						
						
	} 	
	
}
int ANIMACIONES_pulsasESC(int nSortir) {
	if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
		nSortir = 1;
	}
	return nSortir;
}
int ANIMACIONES_pulsaP(int pausa) {
	if (LS_allegro_key_pressed(ALLEGRO_KEY_P) == 1) {
		if (pausa == 0) {
			pausa = 1;
						
		} 
		else {
			pausa = 0;
		}
						
	}	
	return pausa;
}
int ANIMACIONES_restablecerPausa (int pausa) {
	if (LS_allegro_key_pressed(ALLEGRO_KEY_P) == 1) {
		if (pausa == 1) {
			pausa = 0;
						
		} 
		else {
			pausa = 1;
		}
						
	}
	return pausa;
}
int ANIMACIONES_gameOver(Partida partida[1]) {
	
	int i = 9;
	int j;
	int game_over = 0;
	for (j = 0; j < 12; j++) {
		if (partida[0].casilla[i][j].ok_bola == 1) {
			game_over = 1;
		}
		
	}
	
return game_over;
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
		GRAFICA_pintarPantalla(partida,0);
		partida[0].disparador.bola.pos_y = partida[0].disparador.bola.pos_y - 4;
		
		pintarDisparador(partida);
		LS_allegro_clear_and_paint(BLACK);
		
		
	}
	//	if(i==0) {}
		partida[0].casilla[i+2][j].bola.color = partida[0].disparador.bola.color;
		partida[0].casilla[i+2][j].ok_bola = 1;
	
	
}

void ANIMACIONES_eliminarBola (Partida partida[1], int * u, int * w) {

	int i, j;
	int contador = 0;
	
	j = *w;
	//Lo que hago aqui es leer toda la columna en la que esta la posicion de x y ver si hay bolas repetidas
	for (i = 8; i >= 1; i--) {
		if (partida[0].casilla[i-1][j].ok_bola == 1 && partida[0].casilla[i][j].ok_bola == 1 && partida[0].casilla[i - 1][j].bola.color == partida[0].casilla[i][j].bola.color) {
			contador++;
			partida[0].casilla[i-1][j].ok_bola = 0;
			partida[0].casilla[i][j].ok_bola = 0;
			partida[0].casilla[*u + 2][j].ok_bola = 1;
		}	
	}
	//Lo mismo que en el anterior pero en vez de filas con columnas
	//El i+2 viene porque se pasa -2 ya que viene de otra funcion
	i = *u;
	for (j = 1; j <= 11; j++) {
		if (partida[0].casilla[i + 2][j].ok_bola == 1 && partida[0].casilla[i+2][j-1].ok_bola == 1 && partida[0].casilla[i+2][j].bola.color == partida[0].casilla[i+2][j -1].bola.color) {
			contador++;
			partida[0].casilla[i+2][j].ok_bola = 0;
			partida[0].casilla[i+2][j -1].ok_bola = 0;
			partida[0].casilla[i+2][*w].ok_bola = 1;
		}	
	}
	
	if (contador > 0) {
		partida[0].casilla[*u + 2][*w].ok_bola = 0;
	
		
	}
	
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
			pos_y = partida[0].casilla[i][j].bola.pos_y -1;
			i--;
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
	partida[0].nivel.aum_velocidad = partida[0].nivel.aum_velocidad - 0.2;
	
	if (partida[0].nivel.aum_velocidad >= 2 ) {
		partida[0].nivel.aum_velocidad = 2;
		
		
	}
	

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
			partida[0].casilla[i + 1][j].bola.color = partida[0].casilla[i][j].bola.color;
			partida[0].casilla[i + 1][j].ok_bola = partida[0].casilla[i][j].ok_bola;
			
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
