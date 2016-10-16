#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct {
	int n;
	int valMax;
	int nbCasesLibres;
	int *grille;
} jeu;

#endif

int caseVide(jeu *p, int i, int j);
void ajouteValAlea(jeu *p);
int gagne(jeu *p);
int perdu(jeu *p);
int finPartie(jeu *p);
