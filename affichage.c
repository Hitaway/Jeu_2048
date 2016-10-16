/* affichage.c */

#include "affichage.h"


/*
   void affichage(jeu *p) {
   int valMax = (*p).valMax;
   int iEspaceINT = 1;
   int dEspaceINT = 10;
   while (valMax/dEspaceINT != 0) {
   iEspaceINT++;
   dEspaceINT*=10;
   }
   int espaceINT = iEspaceINT;	

   int nbrColonne = sqrt((*p).n);
   int i;
   int sautDeLigne = nbrColonne;
   for (i=0;i<(*p).n;i++) {
   if (i == sautDeLigne) {
   printf("\n");
   sautDeLigne = sautDeLigne+nbrColonne;
   }
   color_printf(WHITE,BLUE,"%d",((*p).grille)[i]);
   color_printf(WHITE,BLUE," ");


   }
   printf("\n");
   }*/

/* void affichage(jeu *pJeu) */
/* { */
/* 	int n = (*pJeu).n; */
/* 	int i; */
/* 	int i2; */
/*  */
/* 	for (i=0; i<n; i++) { */
/* 		for (i2=0; i2<sqrt(n);i2++) { */
/* 			//printf(" %d",((*pJeu).grille)[i]); */
/* 			printf("%d\n",i); */
/* 			if (i2 != sqrt(n)-1) { */
/* 				i++; */
/* 			}; */
/* 		} */
/* 		printf("\n"); */
/* 	} */
/* } */

/* void affichage(jeu* p) { */
/* 	int i, j, cote; */
/* 	cote = (int)sqrt(p->n); */
/* 	for (i = 0; i < cote; ++i) { */
/* 		for (j = 0; j < cote; ++j) */
/* 			color_printf(RED,GREEN,"%4d", p->grille[i * cote + j]); */
/* 		printf("\n"); */
/* 	} */
/* } */

COULEUR_TERMINAL couleurNbr(int x) {				//fonction de type COULEUR_TERMINAL, parametre x
	COULEUR_TERMINAL couleur[6] = {RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN};
	int i=2;
	int i2=0;

	if (x == 0) {
		return BLACK;
	}

	else {
		while (i < x) {
			i2++;
			if (i2 == 6) {
				i2 = 0;
			}
			i = i*2;
		}
	}
	return couleur[i2];
}  							//associe la couleur en fonction du x donné

int intlen(int x)
{
	if (x <          10)
		return 1;
	if (x <         100)
		return 2;
	if (x <        1000)
		return 3;
	if (x <       10000)
		return 4;
	if (x <      100000)
		return 5;
	if (x <     1000000)
		return 6;
	if (x <   100000000)
		return 7;

	return 8;
} 							//retourne la taille du x donné

void affichageLigne2(int x) {
	COULEUR_TERMINAL couleur = couleurNbr(x);
	COULEUR_TERMINAL white = WHITE;
	int tailleDeX = intlen(x);
	if (x == 0) {
		color_printf(white,couleur,"   .   ");
	}
	else if (tailleDeX == 1) {
		color_printf(white,couleur,"   %d   ",x);
	}
	else if (tailleDeX == 2) {
		color_printf(white,couleur,"  %d   ",x);
	}
	else if (tailleDeX == 3) {
		color_printf(white,couleur,"  %d  ",x);
	}
	else if (tailleDeX == 4) {
		color_printf(white,couleur," %d  ",x);	// on centre bien le chiffre dans la ligne, et on l'écrit en blanc avec le fond correspondant
	}
	else if (tailleDeX == 5) {
		color_printf(white,couleur," %d ",x);
	}
	else if (tailleDeX == 6) {
		color_printf(white,couleur,"%d ",x);
	}
	else if (tailleDeX == 7) {
		color_printf(white,couleur,"%d",x);
	}
	else {
		printf("Erreur");
	}
}

void affichage(jeu *pJeu) {
	clear_terminal();
	int cote = (*pJeu).n;
	int coteMOD = cote;
	int i;
	int i2 = 0;
	int i3 = 0;
	int i4 = 0;
	COULEUR_TERMINAL couleur;

	for (i=0; i<cote; i++) {

		for (i2; i2<coteMOD; i2++) {
			couleur = couleurNbr(((*pJeu).grille)[i2]);         //affichage de la première ligne d'une case
			color_printf(WHITE,couleur,"       ");
		}
		printf("\n");

		for (i3; i3<coteMOD; i3++) {
			affichageLigne2(((*pJeu).grille)[i3]);				//affichage de la deuxième ligne d'une case
		}
		printf("\n");

		for (i4; i4<coteMOD; i4++) {
			couleur = couleurNbr(((*pJeu).grille)[i4]);			//affichage de la troisième ligne d'une case
			color_printf(WHITE,couleur,"       ");
		}
		printf("\n");

		coteMOD = coteMOD + cote;
	}
}
