/* Partie 3 */

#include "partie3.h"

int fusionG(jeu *p,int ligne) {

	int i2,i3,val,val2,c;
	c = 0;
	val = 0;
	val2 = 0;

	for (i2=0;i2<(*p).n;i2++) {
		if (getVal(p,ligne,i2)!=0) {
		val = getVal(p,ligne,i2);				//on recup la valeur si non nulle
			for (i3=i2+1; i3 < (*p).n; i3++) {  
				if (getVal(p,ligne,i3) != 0) {
					val2 = getVal(p,ligne,i3);  //on recup la valeur d'a droite
					break;
				}
			}	
			if (val == val2) {
				setVal(p,ligne,i2,val+val2); // on les fusionne
				setVal(p,ligne,i3,0);		 // on supprime la case de droite
				c++;
			}
			val = 0;
			val2 = 0;
		}
	}

	if (c>0) {
		return 1;         //s'il y a eu fusion retourne 1
	}

	else {
		return 0;
	}

}


int fusionD(jeu *p,int ligne) {

	int i2,i3,val,val2,c;
	c = 0;
	val = 0;
	val2 = 0;

	for (i2=(*p).n;i2>=0;i2--) {
		if (getVal(p,ligne,i2)!=0) {
			val = getVal(p,ligne,i2);
			for (i3=i2-1; i3 >= 0; i3--) {
				if (getVal(p,ligne,i3) != 0) {
					val2 = getVal(p,ligne,i3);
					break;
				}
			}
			if (val == val2) {
				setVal(p,ligne,i2,val*2);
				setVal(p,ligne,i3,0);
				c++;
			}
			val = 0;
			val2 = 0;
		}
	}
	if (c>0) {
		return 1;
	}
	else {
		return 0;
	}
}

int fusionH(jeu *p,int colonne) {

	int i2,i3,val,val2,c;
	c =0;
	val = 0;
	val2 = 0;

	for (i2=0;i2<(*p).n;i2++) {
		if (getVal(p,i2,colonne)!=0) {
			val = getVal(p,i2,colonne);
			for (i3=i2+1; i3 < (*p).n; i3++) {
				if (getVal(p,i3,colonne) != 0) {
					val2 = getVal(p,i3,colonne);
					break;
				}
			}	
			//printf("val = %d\n val2 = %d\n",val,val2);
			if (val == val2) {
				setVal(p,i2,colonne,val*2);
				setVal(p,i3,colonne,0);
				c++;
			}
			val = 0;
			val2 = 0;
		}
	}
	if (c>0) {
		return 1;
	}
	else {
		return 0;
	}
}

int fusionB(jeu *p,int colonne) {

	int i2,i3,val,val2,c;
	c =0;
	val = 0;
	val2 = 0;


	for (i2=(*p).n;i2>=0;i2--) {
		if (getVal(p,i2,colonne)!=0) {
			val = getVal(p,i2,colonne);
			for (i3=i2-1; i3 >= 0; i3--) {
				if (getVal(p,i3,colonne) != 0) {
					val2 = getVal(p,i3,colonne);
					break;
				}
			}	
			if (val == val2) {
				setVal(p,i2,colonne,val*2);
				setVal(p,i3,colonne,0);
				c++;
			}
			val = 0;
			val2 = 0;
		}
	}
	if (c>0) {
		return 1;
	}
	else {
		return 0;
	}
}

int decalageG(jeu *p,int ligne) {

	int i,i2,indiceCaseVide,c;
	c = 0;
	indiceCaseVide = -1;

	for (i=0;i<(*p).n;i++) {
		if (getVal(p,ligne,i) == 0 && indiceCaseVide == -1) {
			indiceCaseVide = i;
		}    													//on cherche une case vide en parcourant la ligne, on stocke l'indice

		if (getVal(p,ligne,i) > 0 && indiceCaseVide != -1) {
			setVal(p,ligne,indiceCaseVide,getVal(p,ligne,i));	//on met la premiere valeur non nulle dans la premiere case vide
			setVal(p,ligne,i,0);
			indiceCaseVide++;
			c++;
		}
	}
	if (c>0) {
		return 1;
	}
	else {
		return 0;
	}
}

int decalageD(jeu *p,int ligne) {

	int i,i2,indiceCaseVide,c;
	c=0;
	indiceCaseVide = -1;

	for (i=(*p).n;i>=0;i--) {
		if (getVal(p,ligne,i) == 0 && indiceCaseVide == -1) {
			indiceCaseVide = i;
		}

		if (getVal(p,ligne,i) > 0 && indiceCaseVide != -1) {
			setVal(p,ligne,indiceCaseVide,getVal(p,ligne,i));
			setVal(p,ligne,i,0);
			indiceCaseVide--;
			c++;
		}
	}
	if (c>0) {
		return 1;
	}
	else {
		return 0;
	}
}

int decalageH(jeu *p,int colonne) {

	int i,i2,indiceCaseVide,c;
	c=0;
	indiceCaseVide = -1;

	for (i=0;i<(*p).n;i++) {
		if (getVal(p,i,colonne) == 0 && indiceCaseVide == -1) {
			indiceCaseVide = i;
		}

		if (getVal(p,i,colonne) > 0 && indiceCaseVide != -1) {
			setVal(p,indiceCaseVide,colonne,getVal(p,i,colonne));
			setVal(p,i,colonne,0);
			indiceCaseVide++;
			c++;
		}
	}
	if (c>0) {
		return 1;
	}
	else {
		return 0;
	}
}

int decalageB(jeu *p,int colonne) {

	int i,indiceCaseVide,c;
	c=0;
	indiceCaseVide = -1;

	for (i=(*p).n;i>=0;i--) {
		if (getVal(p,i,colonne) == 0 && indiceCaseVide == -1) {
			indiceCaseVide = i;
		}

		if (getVal(p,i,colonne) > 0 && indiceCaseVide != -1) {
			setVal(p,indiceCaseVide,colonne,getVal(p,i,colonne));
			setVal(p,i,colonne,0);
			indiceCaseVide--;
			c++;
		}
	}

	if (c>0) {
		return 1;
	}
	else {
		return 0;
	}
}

int mouvementLigne(jeu *p,int ligne,int direction) {
	int i = 0;

	if (direction == 1) {
		i = i + fusionG(p,ligne) + decalageG(p,ligne);
	}
	else {
		i = i + fusionD(p,ligne) + decalageD(p,ligne);
	}

	if (i > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int mouvementColonne(jeu *p,int colonne,int direction) {
	int i;

	if (direction == 1) {
		i = fusionH(p,colonne) + decalageH(p,colonne);
	}
	else {
		i = fusionB(p,colonne) + decalageB(p,colonne);
	}

	if (i > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int mouvementLignes(jeu *p,int direction) {
	int i,c;
	c=0;

	for (i=0;i<(*p).n;i++) {
		c = c + mouvementLigne(p,i,direction);
	}

	if (c>0) {
		return 1;
	}
	else {
		return 0;
	}
}

int mouvementColonnes(jeu *p,int direction) {
	int i,c;
	c=0;

	for (i=0;i<(*p).n;i++) {
		c = c + mouvementColonne(p,i,direction);
	}

	if (c>0) {
		return 1;
	}
	else {
		return 0;
	}
}

int mouvement(jeu *p,int direction) {
	if (direction == 0) {
		return mouvementColonnes(p,-1);
	}
	else if (direction == 1) {
		return mouvementLignes(p,-1);
	}
	else if (direction == 2) {
		return mouvementColonnes(p,1);
	}
	else if (direction == 3) {
		return mouvementLignes(p,1);
	}
	else {
		return 0;
	}
}

int saisieD() {

	debutTerminalSansR();
	Key saisie = NO_KEY;
	do  {
		saisie = lectureFleche();	
	} while (saisie == NO_KEY);

	if (saisie == KEY_DOWN) {
		finTerminalSansR();
		return 0;
	}
	else if (saisie == KEY_RIGHT) {
		finTerminalSansR();
		return 1;
	}
	else if (saisie == KEY_UP) {
		finTerminalSansR();
		return 2;
	}
	else if (saisie == KEY_LEFT) {
		finTerminalSansR();
		return 3;
	}
	else {
		finTerminalSansR();
		return -1;
	}
}

int score(jeu *p) {
	int score,i,i2;
	score = 0;
	for (i=0;i<(*p).n;i++) {
		for (i2=0;i2<(*p).n;i2++) {
			score = score + getVal(p,i,i2);		//somme de toutes les cases
		}
	}
	return score;
}

int jouer(jeu *p) {

	int saisie;
	int mouvementt = 0;
	do  {
		affichage(p);
		printf("score : %d\n\n",score(p));
		saisie = saisieD();
		mouvementt = mouvement(p,saisie);
		affichage(p);
		if (mouvementt == 1) {
			usleep(100000);    //pause de 0.1ms temps en nanoseconde
			ajouteValAlea(p);
		}
		affichage(p);
	} while (saisie != -1 && finPartie(p) == 0);
	return finPartie(p);
}
