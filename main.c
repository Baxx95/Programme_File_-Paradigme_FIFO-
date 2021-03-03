#include "f.h"

int main(){
	fILE file;
	afficher_file(inserer_elmt_file(supp_elmt_file(saisir_file(enfiler(init_file(file),"SY"),3),2),"GOUNDIAM",3));
	printf("\n-----------------------------\n");
	int r = rechercher(saisir_file(enfiler(init_file(file),"SY"),3),"DIA");
	if(r == -1)
		printf("L'element 'DIA' ne trouve pas la file\n");
	else
		printf("L'element 'DIA' se trouve a la position %d\n", r);
	
	return 0;
}