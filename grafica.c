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
	pos_x = 813;
	pos_y = 575;
	
	for (i = 0; i < 4; i++) {
			partida[0].bola[i].pos_x = pos_x;
			partida[0].bola[i].pos_y = pos_y;
			partida[0].bola[i].color = GRAFICA_colorRandom();
			pos_x = pos_x + 55;
	}
	
}

void GRAFICA_mostrarMenu() {
	printf("Bienvenido a LSBooble\n");
	printf("\n\t1. Nueva Partida\n\t2. Escojer nivel\n\t3. Cargar ranking\n\t4. Ver Ranking\n\t5. Salir\n\tOpcion: ");
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
		printf("Error, opcion solo puede valer un numero del 1 al 5");
	}
	
	return opcion;
}