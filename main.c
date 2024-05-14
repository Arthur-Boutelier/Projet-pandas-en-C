#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
#include "sort.h"
int main()
{
    int a=9,b=10,c=15;
    void* u = NULL;
    COLONNE * A= create_column(INT,"caca");
    printf("%s\n",A->titre);
    inserer_valeur(A,NULL);
    inserer_valeur(A,&b);
    inserer_valeur(A,NULL);
    inserer_valeur(A,&c);
    inserer_valeur(A,&a);

    print_col(A);
    tri_insertion(A);
    printf("\n");
    print_col_index(A);


    /*
    TYPE types[]={INT, INT, INT};
    CDATAFRAME* cd = creer_cd(types, 3);
    remplir_cd(cd);
    afficher_cd(cd);
    afficher_ligne_entre(cd, 0,1);*/
    return 0;
}
