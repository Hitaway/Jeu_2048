/* Partie 4 */

#include "partie4.h"

int sauvegarde(jeu *p,char nomSauvegarde[])
{
	FILE *file = fopen(nomSauvegarde,"wt");

	if (file == NULL) {
		printf("ERROR");
		return 0;
	}

	else {
		int i,i2;
		for (i=0;i<(*p).n;i++) {
			for (i2=0;i2<(*p).n;i2++) {
				fprintf(file,"%d ",getVal(p,i,i2));
			}
			fprintf(file,"\n");
		}
	}
	fclose(file);
	return 1;
}

int chargement(jeu *p, char nomSauvegarde[]) 
{
	FILE *file = fopen(nomSauvegarde,"rt");

	if (file == NULL) {
		printf("ERREUR\n");
		return 0;
	}

	else {
		int i,i2,x;
		for (i=0;i<(*p).n;i++) {
			for (i2=0;i2<(*p).n;i2++) {
				fscanf(file,"%d",&x);
				setVal(p,i,i2,x);
			}
		}
	}
	fclose(file);
	return 1;
}

int menu() {
	int saisie;
	do  {
		printf("     1 - Jouer\n     2 - Sauvegarder\n     3 - Charger\n     4 - Terminer le programme\n     5 - Tableau des scores\n     6 - Options\n");
		scanf("%d%*[^\n]",&saisie);
		getchar(); 					//eviter une boucle infinie si une lettre est tapée

		printf("\033[1;1H");    	//repositionne le curseur
		printf("\033[2J");			//clear
	} while (saisie < 0 || saisie > 6);

	return saisie;
}

void fichierExiste(char nomFichier[], int slot) {
	if (fopen(nomFichier,"r") != NULL) {
		printf("slot %d : OCCUPEE\n",slot);
	}
	else {
		printf("slot %d : VIDE\n",slot);
	}
}

void rangerTab(int tab[], int taille) {
	int i,i2,val,val2,indiceVal;
	val = tab[0];
	indiceVal = 0;

	for (i=0;i<taille;i++) {
		for (i2=i;i2<taille;i2++) {
			if (val < tab[i2]) {
				val = tab[i2];
				indiceVal = i2;
			}
		}
		val2 = tab[i];
		tab[i] = val;
		tab[indiceVal] = val2;
		val = -1;
	}
}

void tableauScore() {
	int i;
	int tabScore[10];
	for (i=0; i<10;i++) {
		tabScore[i] = 0;
	}
	FILE *file = fopen("score.txt","rt");

	if (file == NULL) {
		printf("Nothing ^-^\n");
	}

	else {
		for (i=0;i<10 && !feof(file); i++) {
			fscanf(file,"%d",&(tabScore[i]));
		}

		rangerTab(tabScore,10);

		for (i=0;i<10;i++) {
			printf("%2d  - %d\n",i+1,tabScore[i]);
		}
		fclose(file);
	}
}

void rajouteScore(int score) {
	int i,x;
	FILE *file;
	file = fopen("score.txt","at");
	file = fopen("score.txt","rt");

	for (i=0; !feof(file); i++)
	{
		fscanf(file,"%d",&x);
	}

	if (i > 9) {
		file = fopen("score.txt","rt");
		int tab[10];	
		for (i=0;!feof(file);i++) {
			fscanf(file,"%d",&(tab[i]));
		}
		rangerTab(tab,10);
		tab[9] = score;
		rangerTab(tab,10);

		file = fopen("score.txt","wt");
		for (i=0;i<10;i++) {
			fprintf(file,"%d\n",tab[i]);
		}
	}
	else {
		file = fopen("score.txt","at");
		fprintf(file,"%d\n",score);
	}

	fclose(file);
}
