#include "cdataframe.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

CDATAFRAME* creer_cd(TYPE* type, int size){
    CDATAFRAME * cd = lst_create_list();
    for (int i = 0; i<size; i++){
        COLONNE * col = create_column(type[i], "");
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
                        scanf(" %ld", val_double);
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
    else if(taille>col->tlog){
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
            COLONNE * nouv_col = create_column(NULLVAL, "");
            for (long long int j = 0; j<temp_1->data->tlog; j++)
                inserer_valeur(nouv_col, NULL);
            ajouter_colonne(cd, nouv_col);
        }
    }
    else if(taille_1 > taille_2){
        long long int ecart_taille = taille_1 - taille_2;
        for (long long int i = 0; i<ecart_taille; i++){
            COLONNE * nouv_col = create_column(NULLVAL, "");
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
    return cd->head->data->tlog;
}

void afficher_cd(CDATAFRAME* cd){
    if (cd != NULL) {
        lnode *temp;
        char str[100];
        for (long long i = 0; i < nb_ligne_cd(cd); i++) {
            temp = cd->head;
            printf("[%lld]  ", i);
            while (temp != NULL) {
                if (temp->data->donnees[i] != NULL) {
                    convert_value(temp->data, i, str, 100);
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
