#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
#include "sort.h"
int main()
{


    TYPE type [] = {INT,NULLVAL,CHAR, NULLVAL};
    char nom_fichier[] = "C:\\Users\\arthu\\CLionProjects\\Projet-C\\test.csv";
    CDATAFRAME * cd = csv_vers_cd(nom_fichier, type, 4);
    afficher_cd(cd);
    cd_vers_csv(cd, "C:\\Users\\arthu\\CLionProjects\\Projet-C\\test_2.csv");
    int a=9,b=10,c=15;

    void* u = NULL;
    COLONNE * A= create_column(INT,"colonne1");
    printf("%s\n",A->titre);
    inserer_valeur(A,NULL);
    inserer_valeur(A,&b);
    inserer_valeur(A,NULL);
    inserer_valeur(A,&c);
    inserer_valeur(A,&a);
    print_col(A);
    printf("\n");
    sort(A,DESC);
    print_col_index(A);
    inserer_valeur(A,&a);
    printf("\n");
    print_col_index(A);
    sort(A,DESC);
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
