#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char ch15[16];

/*	definition	liste	*/
typedef	struct liste {
	ch15 nom;
	struct liste *suiv;
}	ELEMENT, *LISTE_ELEMENT;

/*	definition	file	*/
typedef struct file{
	LISTE_ELEMENT	tete;
	int taille;
	LISTE_ELEMENT	queue;
}fILE, *LISTE_FILE;

/*	prototypes des fonctions de liste chainées	*/
LISTE_ELEMENT	inserer_tete(LISTE_ELEMENT, ch15);
LISTE_ELEMENT	supprimer_tete(LISTE_ELEMENT); 
LISTE_ELEMENT	destruction(LISTE_ELEMENT);
LISTE_ELEMENT	creer_maillon(ch15);

/*	prototypes des fonctions de file*/
int	rechercher(fILE, ch15);
int file_vide(fILE);

void afficher_file(fILE);

fILE 	init_file(fILE);
fILE	enfiler(fILE, ch15);
fILE	defiler(fILE);
fILE 	saisir_file(fILE, int);
fILE 	supp_elmt_file(fILE, int);
fILE 	inserer_elmt_file(fILE, ch15, int);
