a.out : 2048.o terminalCouleur.o affichage.o saisieM.o partie1.o partie2.o partie3.o partie4.o
	gcc -Wall 2048.o terminalCouleur.o affichage.o saisieM.o partie1.o partie2.o partie3.o partie4.o -lm

2048.o : 2048.c affichage.h
	gcc -c 2048.c

terminalCouleur.o : terminalCouleur.c terminalCouleur.h
	gcc -c terminalCouleur.c

affichage.o : affichage.c affichage.h terminalCouleur.h
	gcc -c affichage.c

partie1.o : partie1.h partie1.c
	gcc -c partie1.c

partie2.o : partie2.h partie2.c
	gcc -c partie2.c

partie3.o : partie3.h partie3.c
	gcc -c partie3.c

partie4.o : partie4.h partie4.c
	gcc -c partie4.c

saisieM.o : saisieM.h saisieM.c
	gcc -c saisieM.c

clean: 
	rm -f *.o *~ *.txt
