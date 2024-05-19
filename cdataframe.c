#include "cdataframe.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

CDATAFRAME* creer_cd(TYPE* type, long long int size){
    CDATAFRAME * cd = lst_create_list();
    char str[10];
    for (long long int i = 0; i<size; i++){
        long long int cmpt = i;
        do {
            snprintf(str, 10, "%lld", cmpt++);
        } while (col_existe_cd(cd, str));
        COLONNE * col = creer_colonne(type[i], str);
        lnode * p_nouv = lst_create_lnode(col);
        lst_insert_tail(cd, p_nouv);
    }
    return cd;
}

void remplir_cd(CDATAFRAME* cd) {
    long long int size;
    do {
        printf("Combien de ligne voulez vous rajoutez : ");
        scanf("%lld", &size);
    } while (size <= 0);
    lnode *temp = cd->head;
    while (temp != NULL) {
        switch (temp->data->type) {
            case INT:
                printf("Veuillez remplir cette colonne d'entier\n");
                int *val_int = (int *) malloc(sizeof(int));
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %d", val_int);
                        inserer_valeur(temp->data, (void *) val_int);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
            case CHAR:
                printf("Veuillez remplir cette colonne de caractere\n");
                char *val_char = (char *) malloc(sizeof(char));
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %c", val_char);
                        inserer_valeur(temp->data, (void *) val_char);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
            case UINT:
                printf("Veuillez remplir cette colonne d'entier non signé\n");
                unsigned int *val_uint = (unsigned int*) malloc(sizeof(unsigned int));
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %u", val_uint);
                        inserer_valeur(temp->data, (void *) val_uint);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
            case FLOAT:
                printf("Veuillez remplir cette colonne de nombres décimaux\n");
                float *val_float = (float*) malloc(sizeof(float));
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %f", val_float);
                        inserer_valeur(temp->data, (void *) val_float);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
            case DOUBLE:
                printf("Veuillez remplir cette colonne de double\n");
                double *val_double = (double *) malloc(sizeof(double));
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %lf", val_double);
                        inserer_valeur(temp->data, (void *) val_double);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
            case NULLVAL:
                inserer_valeur(temp->data, NULL);
                break;
            case STRUCTURE:
                break;
            case STRING:
                printf("Veuillez remplir cette colonne de chaine de caractere\n");
                char str[100];
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur :");
                        fflush(stdin);
                        fgets(str, 100, stdin);
                        inserer_valeur(temp->data, (void*) str);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
        }
        temp = temp->next;
        }
}

void suppr_cd(CDATAFRAME** cd){
    lst_erase(*cd);
    free(*cd);
    *cd = NULL;
}

void ajouter_colonne(CDATAFRAME* cd, COLONNE* col){
    long long int taille = nb_ligne_cd(cd);
    lnode * temp = cd->head;
    if (taille < col->tlog){
        while (temp != NULL){
            for (long long int i = 0; i<col->tlog-taille; i++)
                inserer_valeur(temp->data, NULL);
            temp = temp->next;
        }
    }
    else if(taille>(col->tlog)){
        for (long long int i = 0; i<taille-col->tlog; i++)
            inserer_valeur(col, NULL);
    }
    lnode* p_nouv = lst_create_lnode(col);
    lst_insert_tail(cd, p_nouv);

}

void ajouter_ligne(CDATAFRAME* cd, CDATAFRAME* cd_2){
    lnode* temp_1 = cd->head;
    lnode* temp_2 = cd_2->head;
    long long int taille_1 = nb_colonne_cd(cd), taille_2 = nb_colonne_cd(cd_2), compteur = 0;
    if (taille_1 < taille_2){
        long long int ecart_taille = taille_2 - taille_1;
        for (long long int i = 0; i<ecart_taille; i++){
            COLONNE * nouv_col = creer_colonne(NULLVAL, "");
            for (long long int j = 0; j<temp_1->data->tlog; j++)
                inserer_valeur(nouv_col, NULL);
            ajouter_colonne(cd, nouv_col);
        }
    }
    else if(taille_1 > taille_2){
        long long int ecart_taille = taille_1 - taille_2;
        for (long long int i = 0; i<ecart_taille; i++){
            COLONNE * nouv_col = creer_colonne(NULLVAL, "");
            for (long long int j = 0; j<temp_2->data->tlog; j++)
                inserer_valeur(nouv_col, NULL);
            ajouter_colonne(cd_2, nouv_col);
        }
    }
    while (temp_1!=NULL) {
        if (compteur++ >= taille_1)
            temp_1->data->type = temp_2->data->type;
        if (temp_1->data->type == temp_2->data->type) {
            for (long long int i = 0; i < temp_2->data->tlog; i++)
                inserer_valeur(temp_1->data, temp_2->data->donnees[i]);
        }
        else{
            for (long long int i = 0; i < temp_2->data->tlog; i++)
                inserer_valeur(temp_1->data, NULL);
        }
        temp_1 = temp_1->next;
        temp_2 = temp_2->next;
    }
}

long long int nb_colonne_cd(CDATAFRAME* cd){
    lnode * temp = cd->head;
    long long int taille = 0;
    while (temp != NULL){
        taille++;
        temp = temp->next;
    }
    return taille;
}

long long int nb_ligne_cd(CDATAFRAME* cd){
    if(cd->head == NULL){
        return 0;
    }
    return cd->head->data->tlog;
}

void afficher_cd(CDATAFRAME* cd){
    if (cd != NULL) {
        lnode *temp;
        char str[100];
        afficher_nom_col(cd);
        for (long long i = 0; i < nb_ligne_cd(cd); i++) {
            temp = cd->head;
            printf("[%7lld]  ", i);
            while (temp != NULL) {
                if (temp->data->donnees[i] != NULL) {
                    convert_val(temp->data, i, str, 100);
                    printf("%15s  ", str);
                } else
                    printf("%15s  ", "NULL");
                temp = temp->next;
            }
            printf("\n");
        }
    }
    else
        printf("Ce Dataframe n'existe pas\n");
}

void suppr_ligne(CDATAFRAME* cd, long long int indice){
    lnode* temp = cd->head;
    while(temp!= NULL){
        colonne_supprimer_indice(temp->data, indice);
        temp = temp->next;
    }
}
long long int nb_valeur_egal_cd(CDATAFRAME* cd, void* valeur, TYPE type_val){
    long long int occ = 0;
    lnode * temp = cd->head;
    while(temp != NULL){
        if(type_val == temp->data->type || valeur == NULL)
            occ += occurence(temp->data, valeur);
        temp = temp->next;
    }
    return occ;
}

long long int nb_valeur_sup_cd(CDATAFRAME* cd, void* valeur, TYPE type_val){
    long long int compteur = 0;
    lnode * temp = cd->head;
    while(temp != NULL){
        if(type_val == temp->data->type || valeur == NULL)
            compteur += nb_valeur_sup_col(temp->data, valeur);
        temp = temp->next;
    }
    return compteur;
}

long long int nb_valeur_inf_cd(CDATAFRAME* cd, void* valeur, TYPE type_val){
    long long int compteur = 0;
    lnode * temp = cd->head;
    while(temp != NULL){
        if(type_val == temp->data->type || valeur == NULL)
            compteur += nb_valeur_inf_col(temp->data, valeur);
        temp = temp->next;
    }
    return compteur;
}

void afficher_nom_col(CDATAFRAME* cd){
    lnode* temp = cd->head;
    printf("           ");
    while (temp != NULL){
        printf("%15s  ", temp->data->titre);
        temp = temp->next;
    }
    printf("\n");
}

int col_existe_cd(CDATAFRAME* cd, char* nom){
    lnode * temp = cd->head;
    while (temp != NULL){
        if (!strcmp(nom, temp->data->titre))
            return 1;
        temp = temp->next;
    }
    return 0;
}

void modif_valeur(CDATAFRAME* cd, char* nom_col, long long int indice_ligne, void* nouv_val, TYPE type_n_v){
    lnode * temp = cd->head;
    if (col_existe_cd(cd,nom_col) && indice_ligne < nb_ligne_cd(cd)){
        while (strcmp(temp->data->titre, nom_col) != 0)
            temp = temp->next;
        if (temp->data->type == type_n_v)
            colonne_modif_valeur(temp->data, indice_ligne, nouv_val, type_n_v);
        else
            printf("La modification n'a pas pu être effectuer");

    }
    else
        printf("La modification n'a pas pu etre effectuer\n");
}

void* obtenir_valeur(CDATAFRAME* cd, char* nom_col, long long int indice_ligne){
    lnode * temp = cd->head;
    if (col_existe_cd(cd,nom_col) && indice_ligne < nb_ligne_cd(cd)){
        while (strcmp(temp->data->titre, nom_col) != 0)
            temp = temp->next;
        return valeur_pos(temp->data, indice_ligne);
    }
    else
        printf("Veuillez vérifiez vos indices ils n'existent pas dans ce dataframe\n");
    return NULL;
}

int existe_cd(CDATAFRAME* cd, void* valeur, TYPE type_n_v){
    lnode * temp = cd->head;
    while (temp != NULL){
        if(temp->data->type == type_n_v){
            if(existe_col(temp->data, valeur))
                return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void renommer_col(CDATAFRAME* cd, char* ancien_nom, char* nouveau_nom){
    lnode * temp = cd->head;
    if(col_existe_cd(cd, ancien_nom) && !col_existe_cd(cd, nouveau_nom)){
        while(strcmp(temp->data->titre, ancien_nom) != 0)
            temp = temp->next;
        strcpy(temp->data->titre, nouveau_nom);
    }
    else
        printf("Erreur pendant la modification du nom de la colonne veuillez verifier les informations transmises\n");
}

void suppr_colonne(CDATAFRAME* cd, char* nom){
    if(col_existe_cd(cd,nom)){
        lnode * temp = cd->head;
        while(strcmp(temp->data->titre, nom) != 0)
            temp = temp->next;
        lst_delete_lnode(cd, temp);
    }
    else
        printf("Cette Colonne n'existe pas\n");
}

void afficher_ligne_entre(CDATAFRAME* cd, long long int debut, long long int fin){
    if (cd != NULL) {
        afficher_nom_col(cd);
        lnode *temp;
        char str[100];
        if (debut>fin){
            long long int val_temp = debut;
            debut = fin;
            fin = val_temp;
        }
        fin ++;
        if(debut >= 0 && fin >= 0 && debut < nb_ligne_cd(cd) && fin < nb_ligne_cd(cd)) {
            for (long long i = debut; i < fin; i++) {
                temp = cd->head;
                printf("[%7lld]  ", i);
                while (temp != NULL) {
                    if (temp->data->donnees[i] != NULL) {
                        convert_val(temp->data, i, str, 100);
                        printf("%15s  ", str);
                    } else
                        printf("%15s  ", "NULL");
                    temp = temp->next;
                }
                printf("\n");
            }
        }
        else
            printf("Erreur les indices fournies ne sont pas bon\n");
    }
    else
        printf("Ce Dataframe n'existe pas\n");
}

void afficher_colonne_entre(CDATAFRAME* cd, char* nom_debut, char* nom_fin){
    if (cd != NULL) {
        lnode *temp = cd->head;
        char str[100];
        lnode * col_debut;
        lnode* col_fin;
        if(col_existe_cd(cd,nom_debut) && col_existe_cd(cd,nom_fin)){
            while(strcmp(temp->data->titre, nom_debut) != 0 && strcmp(temp->data->titre, nom_fin) != 0)
                temp = temp->next;
            if (strcmp(temp->data->titre, nom_debut) == 0) {
                col_debut = temp;
                while (strcmp(temp->data->titre, nom_fin) != 0)
                    temp = temp->next;
                col_fin = temp;
            }
            else {
                col_debut = temp;
                while (strcmp(temp->data->titre, nom_debut) != 0)
                    temp = temp->next;
                col_fin = temp;
            }
            printf("           ");
            temp = col_debut;
            while (temp != col_fin->next) {
                printf("%15s  ", temp->data->titre);
                temp = temp->next;
            }
            printf("\n");
            for (long long i = 0; i < nb_ligne_cd(cd); i++) {
                temp = col_debut;
                printf("[%7lld]  ", i);
                while (temp != col_fin->next) {
                    if (temp->data->donnees[i] != NULL) {
                        convert_val(temp->data, i, str, 100);
                        printf("%15s  ", str);
                    } else
                        printf("%15s  ", "NULL");
                    temp = temp->next;
                }
                printf("\n");
            }
        }
        else
            printf("Erreur les indices fournies ne sont pas bon\n");
    }
    else
        printf("Ce Dataframe n'existe pas\n");
}

CDATAFRAME* csv_vers_cd(char *nom_fichier, TYPE* dftype, int taille){
    void* val = malloc(sizeof(TYPE*));
    FILE* fichier;
    fichier = fopen(nom_fichier, "rt");
    CDATAFRAME * cd = creer_cd(dftype, taille);
    CDATAFRAME* cd_intermediaire ;
    COLONNE * col;
    char ligne[100];
    char nom[10];
    char* mot;
    const char * separateur = " ,-!";
    if (fichier == NULL){
        printf("Le fichier n'existe pas");
        return NULL;
    }
    while (fgets(ligne, 100, fichier) != NULL){
        cd_intermediaire = creer_cd(dftype, 0);
        mot = strtok(ligne, separateur);
        for(long long int i = 0;i<taille; i++){
            snprintf(nom,10, "%lld", i);
            col = creer_colonne(dftype[i], nom);
            switch (dftype[i]) {
                case NULLVAL:
                    inserer_valeur(col, NULL);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case INT:
                    *((int *) val) = atoi(mot);
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case FLOAT:
                    *(float *) val = strtof(mot, NULL);
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case CHAR:
                    *(char *) val = mot[0];
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case DOUBLE:
                    *(double *) val = strtol(mot, NULL, 10);
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case STRING:
                    inserer_valeur(col, mot);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case UINT:
                    *(unsigned int *) val = strtoul(mot, NULL, 10);
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case STRUCTURE:
                    inserer_valeur(col, NULL);
                    ajouter_colonne(cd_intermediaire, col);
                    break;

            }
            mot = strtok(NULL, separateur);
        }
        mot = strtok(NULL, separateur);
        ajouter_ligne(cd, cd_intermediaire);
        suppr_cd(&cd_intermediaire);
    }
    fclose(fichier);
    free(val);
    return cd;
}

void cd_vers_csv(CDATAFRAME* cd, char* nom_fichier){
    FILE* fichier;
    fichier = fopen(nom_fichier, "w");
    if (cd != NULL){
        lnode *temp;
        char str[100];
        for (long long i = 0; i < nb_ligne_cd(cd); i++) {
            temp = cd->head;
            while (temp != NULL) {
                if (temp->data->donnees[i] != NULL) {
                    convert_val(temp->data, i, str, 100);
                    fputs(str, fichier);
                }
                else
                    fputs("NULL", fichier);
                temp = temp->next;
                if(temp == NULL)
                    fputs("\n", fichier);
                else
                    fputs(", ", fichier);
            }
        }
    }
    else
        printf("Ce Dataframe n'existe pas\n");
    fclose(fichier);
}

void afficher_cd_par_index(CDATAFRAME* cd, COLONNE* col){
    if (cd != NULL) {
        lnode *temp;
        char str[100];
        afficher_nom_col(cd);
        for (long long i = 0; i < nb_ligne_cd(cd); i++) {
            temp = cd->head;
            printf("[%7lld]  ", i);
            while (temp != NULL) {
                if (temp->data->donnees[col->index[i]] != NULL) {
                    convert_val(temp->data, col->index[i], str, 100);
                    printf("%15s  ", str);
                } else
                    printf("%15s  ", "NULL");
                temp = temp->next;
            }
            printf("\n");
        }
    }
    else
        printf("Ce Dataframe n'existe pas\n");
}
