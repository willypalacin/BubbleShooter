#include "menu.h"


void MENU_mostrarMenu() {
	printf("Bienvenido a LSBooble\n");
	printf("\n\t1. Nueva Partida\n\t2. Escojer nivel\n\t3. Cargar ranking\n\t4. Ver Ranking\n\t5. Salir\nOpcion: ");
}

void MENU_pedirNivel(int * nivel) {
	do {
		printf("Introduzca el nivel ");
		fflush(stdin);
		scanf("%d", nivel);
		if(*nivel < 0 || *nivel >100) {
			printf("Error, el nivel debe ser un numero entero de como maximo de dos cifras \n");
		}
	}while(*nivel < 0 || *nivel >100);
	fflush(stdin);
}

void MENU_case1(Partida partida[1]) {
	int u,w,pausa,game_over;
	int nSortir = 0;
	float time0, time1;
	GRAFICA_inicializarValores(partida, &game_over, &pausa, 1);
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
			
}

void MENU_case2(Partida partida[1]) {
	int u,w,pausa,game_over, nivel;
	int nSortir = 0;
	float time0, time1;
	MENU_pedirNivel(&nivel);
	GRAFICA_pedirNombre(partida);
	GRAFICA_inicializarValores(partida, &game_over, &pausa, nivel);
	
	
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
			
}