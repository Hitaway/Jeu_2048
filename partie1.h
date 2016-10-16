#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct{
	int n;
	int valMax;
	int nbCasesLibres;
	int *grille;
} jeu;  			//Définition du type structuré jeu

#endif

void initialiseJeu(jeu *p, int n, int valMax);
void libereMemoire(jeu *p);
int indiceValide(jeu *p, int i, int j);
int getVal(jeu *p, int ligne, int colonne);
void setVal(jeu *p, int ligne, int colonne, int val);

