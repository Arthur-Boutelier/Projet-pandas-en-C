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
    print_index(cd->head->data);
    tri(cd->head->data, ASC);
    print_index(cd->head->data);
    renommer_col(cd, "1", "2");
    afficher_cd_par_index(cd, cd->head->next->data);
    return 0;
}
