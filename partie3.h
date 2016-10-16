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

int fusionG(jeu *p,int ligne);
int fusionD(jeu *p,int ligne);
int fusionB(jeu *p,int ligne);
int fusionH(jeu *p,int ligne);
int decalageG(jeu *p,int ligne);
int decalageD(jeu *p,int ligne);
int decalageH(jeu *p,int ligne);
int decalageB(jeu *p,int ligne);
int mouvementLigne(jeu *p,int ligne,int direction);
int mouvementColonne(jeu *p,int colonne,int direction);
int mouvementLignes(jeu *p,int direction);
int mouvementColonnes(jeu *p,int direction);
int mouvement(jeu *p,int direction);
int saisieD();
int jouer(jeu *p);
