#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
int main()
{
    TYPE type [] = {INT,NULLVAL,CHAR, NULLVAL};
    char nom_fichier[] = "C:\\Users\\arthu\\CLionProjects\\Projet-C\\test.csv";
    CDATAFRAME * cd = csv_vers_cd(nom_fichier, type, 4);
    afficher_cd(cd);
    cd_vers_csv(cd, "C:\\Users\\arthu\\CLionProjects\\Projet-C\\test_2.csv");
    return 0;
}
