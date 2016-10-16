#include "saisieM.h"

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

int sauvegarde(jeu *p,char nomSauvegarde[]);
int chargement(jeu *p, char nomSauvegarde[]);
int menu();
void fichierExiste(char nomFichier[], int slot);
void rangerTab(int tab[], int taille);
void tableauScore();
void rajouteScore(int score);

