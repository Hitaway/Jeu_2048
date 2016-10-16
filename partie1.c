#include "partie1.h"

/* Partie1 */

void initialiseJeu(jeu *p, int n, int valMax) {
	(*p).grille = (int*) malloc((n*n)*(sizeof(int)));  //allocation dynamique de la grille

	int *i;

	for (i=(*p).grille; i<(*p).grille+(n*n); i++) {
		*i = 0;	
	}			//initialise la grille

	(*p).n = n;				// taille de la grille
	(*p).valMax = valMax;	// valeur max
	(*p).nbCasesLibres = (n*n);
}


void libereMemoire(jeu *p) {
	free((*p).grille);
	(*p).grille = NULL;
}

int indiceValide(jeu *p, int i, int j) {
	if (i >= 0 && i < (*p).n && j >= 0 && j < (*p).n) {
		return 1;
	}

	else {
		return 0;
	}
}

int getVal(jeu *p, int ligne, int colonne) {
	int nbrColonne = (*p).n;
	if (ligne >= 0 && colonne >= 0 && ligne < nbrColonne && colonne < nbrColonne) {
		int x = ligne*(nbrColonne) +colonne;  //formule pour retrouver une case particulière
		return ((*p).grille)[x];
	}

	else {
		return -1;
	}
}

void setVal(jeu *p, int ligne, int colonne, int val) {
	if (getVal(p,ligne,colonne) == 0 && val > 0) {
		((*p).nbCasesLibres)--;	
	}
	else if (getVal(p,ligne,colonne) != 0 && val == 0 ) {
		((*p).nbCasesLibres)++;
	}
	int nbrColonne = (*p).n;
	int x = ligne*(nbrColonne) +colonne; //formule
	if (ligne >= 0 && colonne >= 0 && ligne < nbrColonne && colonne < nbrColonne) {
		(*p).grille[x] = val;
	}
}
