#ifndef _LOADRANKING_H_
#define _LOADRANKING_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
*Llegeix un fitxer ranking i posa a players[10][21], nivells[10], minuts[10] i segons[10]
*les dades guardades al fitxer.
*/
int readRankingInfo(char players[][21], int *nivells, int *minuts, int *segons);

#endif

