#include <stdio.h>
#include "LS_allegro.h"
#include "loadRanking.h"

int main(void){
	
	int nSortir = 0;
	
	//Inicialitzem Allegro
	LS_allegro_init(800,600,"LS Dungeon");
	
	//Bucle infinit del joc
	while(!nSortir){
		
		//Escoltem el teclat esperant la tecla ESC
		if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
			nSortir = 1;
		}
		
		//Donem l'ordre d'escriure el text de benvinguda
		al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,100,0,"%s","Benvingut a Allegro! Prem ESC per sortir...");
	
		//Pintem la pantalla de la finestra gràfica
		LS_allegro_clear_and_paint(BLACK);
	}
	
	
	//Tanquem la finestra gràfica
	LS_allegro_exit();
	
	
	
	return 0;
}
