#include "grafica.h"


int GRAFICA_colorRandom() {
	int num;
	do {
		num = rand();
		num = num % 17;
	} while (num == 1 || num == LIGHT_BLUE || num == 2 || num == 5 || num == 7 || num == 8 || num == 9 || num == 10 || num == 11 || num == 12 || num == 13);
	return num;
}

void GRAFICA_inicializarBolasReserva (Partida partida[1]) {
	
	int pos_x, pos_y, i;	
	//Colores aleatorios cada vez que iniciemos el programa
	time_t t;
	srand((unsigned) time(&t));
	pos_x = 813;
	pos_y = 575;
	partida[0].bola[0].color = 0;
	
	
	for (i = 0; i < 4; i++) {
			partida[0].bola[i].pos_x = pos_x;
			partida[0].bola[i].pos_y = pos_y;
			partida[0].bola[i].color = GRAFICA_colorRandom();
			pos_x = pos_x + 55;
	}
	
}

void GRAFICA_inicializarVelocidades(Partida partida[1]) {
	partida[0].tiempo.segs = 0;
	partida[0].nivel.vel_inicial = 3;
	partida[0].nivel.aum_velocidad = 0,2;
	partida[0].nivel.tiempo_nivel = 64/(partida[0].nivel.vel_inicial + partida[0].nivel.aum_velocidad);	
}

void GRAFICA_pintarGameOver(Partida partida[1]) {
	al_draw_filled_rectangle (0, 0, 1023, 600, LS_allegro_get_color(BLACK));
	al_draw_textf (LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(RED), 320, 300, 0,"%s","GAME OVER");
	al_draw_textf (LS_allegro_get_font(NORMAL),LS_allegro_get_color(RED), 370, 380, 0,"%s","Pulse esc");
	LS_allegro_clear_and_paint(BLACK);
}
void GRAFICA_mostrarMenu() {
	printf("Bienvenido a LSBooble\n");
	printf("\n\t1. Nueva Partida\n\t2. Escojer nivel\n\t3. Cargar ranking\n\t4. Ver Ranking\n\t5. Salir\n\tOpcion: ");
}

void GRAFICA_generarMatriz(Partida partida[1]) {
	int i, j;
	//Colores aleatorios cada vez que iniciemos el programa
	time_t t;
	srand((unsigned) time(&t));

	int centro_x;
	int centro_y = 35;
	for (i = 0; i < 10; i++) {
		centro_x = 50;
		for (j = 0; j < 12; j++) {
			partida[0].casilla[i][j].bola.pos_x = centro_x;
			centro_x = centro_x + 60;
			partida[0].casilla[i][j].bola.pos_y = centro_y;
			partida[0].casilla[i][j].ok_bola = 0;
		}
		centro_y = centro_y + 55;
	}
}

void GRAFICA_generarFilaBola1(Partida partida[1]) {
	int i, j;
	int centro_x;
	int centro_y = 35;
	
	centro_x = 50;
	i = 0;
	int vueltas = 0;
		
	for (j = 0; j < 12; j++) {
		
		if (j == 0 && partida[0].casilla[1][j].ok_bola == 0) {
			partida[0].casilla[i][j].bola.pos_x = centro_x;
			centro_x = centro_x + 60;
			partida[0].casilla[i][j].bola.pos_y = centro_y;
			partida[0].casilla[i][j].bola.color = GRAFICA_colorRandom();
			partida[0].casilla[0][j].ok_bola = 1;
			
		}
		else {
			if (partida[0].casilla[1][j].ok_bola == 1) {
			
				do {
					partida[0].casilla[i][j].bola.color = GRAFICA_colorRandom();
						
						if (partida[0].casilla[0][j].bola.color != partida[0].casilla[1][j].bola.color && partida[0].casilla[0][j].bola.color != partida[0].casilla[i][j-1].bola.color ) {
							partida[0].casilla[0][j].ok_bola = 1;
							partida[0].casilla[0][j].bola.pos_x = centro_x;
							partida[0].casilla[0][j].bola.pos_y = centro_y;
							centro_x = centro_x + 60;
							
							
						}
				
					} while(partida[0].casilla[i][j].bola.color == partida[0].casilla[i][j-1].bola.color || partida[0].casilla[i][j].bola.color == partida[0].casilla[i +1][j].bola.color);
			}
			else {
				do {
					partida[0].casilla[i][j].bola.color = GRAFICA_colorRandom();
						
						if (partida[0].casilla[i][j].bola.color != partida[0].casilla[i][j-1].bola.color) {
							partida[0].casilla[0][j].ok_bola = 1;
							partida[0].casilla[i][j].bola.pos_x = centro_x;
							partida[0].casilla[i][j].bola.pos_y = centro_y;
							centro_x = centro_x + 60;
							
						}
				
					} while(partida[0].casilla[i][j-1].bola.color == partida[0].casilla[i][j].bola.color);
				
			}
		}
		
	}
}
	
void GRAFICA_pedirNombre(Partida partida[1]) {
	
	printf("%s","Introduzca el nombre: ");
	gets(partida[0].jugador.nombre);
	if (strlen(partida[0].jugador.nombre) > 20) {
		printf("Error, el tamano maximo del nombre ha de ser de 20 caracteres\n\n");
	}
	
	
}

void pintarBolaReserva(Partida partida[1]) {
	int i;
	for (i = 0; i < 4; i++) {
			al_draw_filled_circle(partida[0].bola[i].pos_x, partida[0].bola[i].pos_y, 15, LS_allegro_get_color((partida[0].bola[i].color)));
	}
}

void pintarDisparador(Partida partida[1]) {
	//Pintamos el cuadrado
	al_draw_filled_rectangle (partida[0].disparador.pos_x, partida[0].disparador.pos_y, partida[0].disparador.pos_x + 50 , partida[0].disparador.pos_y + 50, LS_allegro_get_color(BLACK));	
	
	//Pintamos la bola
	
	al_draw_filled_circle(partida[0].disparador.bola.pos_x,partida[0].disparador.bola.pos_y, 25, LS_allegro_get_color(partida[0].disparador.bola.color));
	
}

void pintarBolas(Partida partida[1]) {
	int i, j;
	for (i = 0; i < 10; i++) {
		for(j = 0; j < 12; j++) {
			if (partida[0].casilla[i][j].ok_bola == 1) {
				al_draw_filled_circle(partida[0].casilla[i][j].bola.pos_x, partida[0].casilla[i][j].bola.pos_y, 25, LS_allegro_get_color((partida[0].casilla[i][j].bola.color)));
					
			}
		}
	}

}

void GRAFICA_inicializarDisparador(Partida partida[1]) {
	partida[0].disparador.pos_x = 385;
	partida[0].disparador.pos_y = 550;
	
	//Tambien iniciamos la bola del disparador
	
	partida[0].disparador.bola.pos_x = partida[0].disparador.pos_x + 25;
	partida[0].disparador.bola.pos_y = 525;
	partida[0].disparador.bola.color = GRAFICA_colorRandom();

	

}

void mostrarTiempoTotal(Partida partida[1]) {
	al_draw_textf (LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE), 782,	300, 0,"%s","TEMPS TOTAL");
	al_draw_textf (LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE), 870, 340, 0,"%d", partida[0].tiempo.tiempo_partida / 60);
	al_draw_textf (LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE), 899, 340, 0,"%c", ':');
	al_draw_textf (LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE), 910, 340, 0,"%d", partida[0].tiempo.tiempo_partida % 60);

}

void mostrarNivel (Partida partida[1]) {
	al_draw_textf (LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE), 845, 110, 0,"%s","NIVEL");
	al_draw_textf (LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE), 885, 149, 0,"%d", partida[0].jugador.nivel);
	
	al_draw_textf (LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE), 780, 190, 0,"%s","Temps Nivel");
	al_draw_textf (LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE), 870, 240, 0,"%d", partida[0].tiempo.tiempo_nivel / 60);
	al_draw_textf (LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE), 882, 240, 0,"%c", ':');
	al_draw_textf (LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE), 890, 240, 0,"%d", partida[0].tiempo.tiempo_nivel % 60);
}


void GRAFICA_pintarPantalla(Partida partida[1]) {
	//Pintamos rectángulo principal y secundario
	al_draw_filled_rectangle (0, 0, 770, 600, LS_allegro_get_color(LIGHT_BLUE));
	al_draw_filled_rectangle (770, 550, 1024, 600, LS_allegro_get_color(LIGHT_BLUE));
	
	//Printamos Nombre
	al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE), 835, 20, 0,"%s","NOMBRE");
	al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE), 870, 70, 0,"%s", partida[0].jugador.nombre);
	
	//Dibujo lineas
	al_draw_line(0 ,500 ,770, 500, LS_allegro_get_color(WHITE), 0);					
	al_draw_line(770 ,600 ,770, 550, LS_allegro_get_color(WHITE), 0);
	
	pintarBolaReserva(partida);
	pintarDisparador(partida);
	pintarBolas(partida);
	mostrarTiempoTotal(partida);
	mostrarNivel(partida);
	
	
}



	
int GRAFICA_elegirOpcion() {
	char opcion_char[10];
	int opcion;
	gets(opcion_char);
	if (strlen(opcion_char) == 1) {
		opcion = opcion_char[0] - '0';
	} 
	else {
		opcion = 6;
	}
	if (opcion < 1 || opcion > 5) {
		printf("Error, opcion solo puede valer un numero del 1 al 5\n");
	}
	
	return opcion;
}