/* affichage.h */

#include "terminalCouleur.h"

#ifndef BASE_H // si BASE_H n'est pas défini
#define BASE_H  // contient tous les includes

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

void affichage(jeu *p);
void affichage(jeu *pJeu);
COULEUR_TERMINAL couleurNbr(int x);
int intlen(int x);
void affichageLigne2(int x);
void affichage(jeu *pJeu);
