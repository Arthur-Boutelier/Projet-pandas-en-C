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
