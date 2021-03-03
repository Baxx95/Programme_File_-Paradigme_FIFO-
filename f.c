#include "f.h"

/*---------------------------------------------------------------------*/

int file_vide(fILE file){
	return file.taille == 0;	/*(file.taille != 0 ? 1 : 0);*/
}
/*---------------------------------------------------------------------*/

fILE 	init_file(fILE file){
	file.taille = 0;
	file.tete = file.queue = NULL;

	return file;
}
/*---------------------------------------------------------------------*/

fILE	enfiler(fILE file, ch15 nom){
	LISTE_ELEMENT	maillon = creer_maillon(nom);
	if(file_vide(file))
		file.tete = file.queue = maillon;
	else{
		file.queue = file.queue->suiv = maillon;
	}
	file.taille++;
	return file;
}
/*---------------------------------------------------------------------*/

fILE	defiler(fILE file){
	if(!file_vide(file)){
		file.tete = supprimer_tete(file.tete);
		if(file.taille == 1)
			file.queue = NULL;
	file.taille--;
	}
	return file;
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
/*------------------------ QUESTION 1 ---------------------------------*/
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/

int	rechercher(fILE file, ch15 nom){
	int i = 1;

	while(!file_vide(file) && strcmp(file.tete->nom, nom)){
		file = defiler(file);
		i++;
	}
	if(file_vide(file))
		return -1;
	else
		return i;
}
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
/*------------------------ QUESTION 2 ---------------------------------*/
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/

fILE 	supp_elmt_file(fILE file, int pos){
	fILE 	f1 = init_file(f1);
	int j = 1;
	while(j < pos){
		f1 = enfiler(f1,file.tete->nom);
		file = defiler(file);
		j++;
	}
	if(!file_vide(file)){
		file = defiler(file);
		while(!file_vide(file)){
			f1 = enfiler(f1,file.tete->nom);
			file = defiler(file);
		}
	}
	return f1;
};
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
/*------------------------ QUESTION 3 ---------------------------------*/
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
fILE 	inserer_elmt_file(fILE file, ch15 nom, int pos){
	fILE 	f1 = init_file(f1);

	//if(!file_vide(file)){
		int j = 1;
		while(j < pos){
			f1 = enfiler(f1,file.tete->nom);
			file = defiler(file);
			j++;
		}
		f1 = enfiler(f1, nom);
		while(!file_vide(file)){
			f1 = enfiler(f1,file.tete->nom);
			file = defiler(file);
		}
	//}
	return	f1;
};
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/


fILE 	saisir_file(fILE file, int n){
	ch15	nom;
	for (int i = 0; i < n; ++i){
		printf("donner nom : \n");
		scanf("%s",nom);
		file = enfiler(file, nom);
	}
	return file;
};
/*---------------------------------------------------------------------*/

void afficher_file(fILE file){
	if(file_vide(file))
		printf("RIEN A AFFICHER !!!\n");
	else{
		int i = 0;
		while(!file_vide(file)){
			printf("NOM[%d] = %s\n",++i, file.tete->nom);
			file = defiler(file);
		}
	}
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	creer_maillon(ch15 nom){

	LISTE_ELEMENT	maillon;
	
	maillon = (LISTE_ELEMENT)malloc(sizeof(ELEMENT));
	maillon->suiv = NULL;
	strcpy(maillon->nom, nom);
	
	return maillon;
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	supprimer_tete(LISTE_ELEMENT liste){
	LISTE_ELEMENT	temp;

	temp = liste->suiv;
	destruction(liste);


	return temp;
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	destruction(LISTE_ELEMENT liste){
	free(liste);
	liste = NULL;
	return liste;
};
/*---------------------------------------------------------------------*/
