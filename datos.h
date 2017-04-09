#ifndef _DATOS_H_
#define _DATOS_H_



typedef struct {
	int aum_velocidad;
	int vel_inicial;
	float tiempo_nivel;
} Nivel;

typedef struct {
	char nombre[100];
	int minutos;
	int segundos;
	int nivel;
} Jugador;

typedef struct {
		char acPlayers[10][20];
		int niveles[10];
		int minutos[10];
		int segundos[10];
} Ranking; 

typedef struct {
	int tiempo_nivel;
	int tiempo_partida;
	
} Tiempo;

typedef struct {
		int pos_x;
		int pos_y;
		int color;
	
} Bola;


typedef struct {
	int pos_x;
	int pos_y;
	Bola bola;
} Disparador;

typedef struct {
	Bola bola;
	int ok_bola;
} Casilla;

typedef struct {
	Jugador jugador;
	Casilla casilla[10][12];
	Disparador disparador;
	Tiempo tiempo;
	Bola bola[4];
	Nivel nivel;	
} Partida;



#endif