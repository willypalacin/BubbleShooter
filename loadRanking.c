#include "loadRanking.h"

/**
*Llegeix un fitxer ranking i posa a players[10][21], nivells[10], minuts[10] i segons[10]
*les dades guardades al fitxer.
*/
int readRankingInfo(char players[][21], int *nivells, int *minuts, int *segons) {
	FILE *fp;

	int i;
	char line[200];
	char *token;
	
	fp = fopen("ranking.txt","r");
	if (fp == NULL) return -1;
	
	for (i = 0; i < 10; i++) {
		
		fgets(line, 200, fp);
		token = strtok(line,";");
		strcpy(players[i],token);
		token = strtok(NULL,";");
		nivells[i] = atoi(token);
		token = strtok(NULL,";");
		minuts[i] = (token[0]-'0')*10+(token[1]-'0');
		segons[i] = (token[3]-'0')*10+(token[4]-'0');
	}
	
	fclose(fp);
	
	return 1;
}