#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
int main()
{
    int a=9,b=10;
    void* u = NULL;
    COLONNE * A= create_column(INT,"caca");
    printf("%s\n",A->titre);
    inserer_valeur(A,&a);
    inserer_valeur(A,&a);
    inserer_valeur(A,NULL);
    inserer_valeur(A,&b);
    print_col(A);
    printf("%lld\n", occurence(A,u));

    TYPE types[]={INT, INT, INT};
    CDATAFRAME* cd = creer_cd(types, 2);
    remplir_cd(cd);
    afficher_cd(cd);
    afficher_ligne_entre(cd, 0,1);
    return 0;
}
