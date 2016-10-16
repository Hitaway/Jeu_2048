#include "partie2.h"

/* Partie2 */

int caseVide(jeu *p, int i, int j) {

	int x = getVal(p,i,j);

	if (x == 0) {
		return 1; 
	}
	else {
		return 0;
	}

}

void ajouteValAlea(jeu *p) {
	int i;
	int i2 = 0;
	int nbCasesLibres = (*p).nbCasesLibres;
	int n = ((*p).n) * ((*p).n);

	if (nbCasesLibres > 0) {
		int *tab;
		tab = (int*) malloc(nbCasesLibres*(sizeof(int)));

		for (i=0;i<n;i++) {
			if (((*p).grille)[i] == 0) {
				tab[i2] = i;				//dès qu'on a une case vide, on ajoute l'indice de la grille dans le tab
				i2++;
			}
		}

		int indiceAlea = rand()%nbCasesLibres;		//on prend une valeur aléatoire inférieure ou égale au nb de cases vides
		int indiceAlea2 = tab[indiceAlea];			// on regarde l'indice de la valeur précédente dans tab
		int valeurAlea;
		if (rand()%2 == 0) {
			valeurAlea = 2;
		}
		else {
			valeurAlea = 4;
		}

		((*p).grille)[indiceAlea2]= valeurAlea;		//on ajoute soit 2 soit 4 dans la case
		//printf("%d   %d\n",indiceAlea,((*p).grille)[indiceAlea2]);
		//printf("%d \n%d \n%d \n\n", tab[0],tab[1],tab[2]);
		(*p).nbCasesLibres--;
	}
}

int gagne(jeu *p) {
	int i;
	int j;
	for (i=0;i<(*p).n;i++) {
		for (j=0;j<(*p).n;j++) {
			if (getVal(p,i,j) >= (*p).valMax) {
				return 1;
			}
		}
	}

	return 0;

}

int perdu(jeu *p) {
	if ((*p).nbCasesLibres == 0) {
		int i;
		int j;

		for (i=0;i<(*p).n;i++) {
			for (j=0;j<(*p).n;j++) {
				if (getVal(p,i,j) == getVal(p,i+1,j) || getVal(p,i,j) == getVal(p,i,j+1)) {    
					return 0;																// si case a coté contient le mm numéro pas perdu
				}
			}
		}
		return 1;
	}
	return 0;
}

int finPartie(jeu *p) {
	if (gagne(p) == 1 || perdu(p) == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
