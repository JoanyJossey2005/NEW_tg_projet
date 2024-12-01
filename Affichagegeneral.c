
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Affichagegeneral.h"

#define MAX_ANIMAUX 100
#define MAX_NOM 50

// Fonction pour afficher les successeurs de chaque animal
void afficher_successeurs(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    printf("\nAffichage des successeurs :\n");
    for (int i = 0; i < ordre; i++) {
        printf("Successeurs de %s : ", noms[i]);
        int successeur_existe = 0;

        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] == 1) {
                printf("%s ", noms[j]);
                successeur_existe = 1;
            }
        }

        if (!successeur_existe) {
            printf("Aucun");
        }
        printf("\n");
    }
}

// Fonction pour afficher les prédécesseurs de chaque animal
void afficher_predecesseurs(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    printf("\nAffichage des predecesseurs :\n");
    for (int i = 0; i < ordre; i++) {
        printf("Predecesseurs de %s : ", noms[i]);
        int predecesseur_existe = 0;

        for (int j = 0; j < ordre; j++) {
            if (matrice[j][i] == 1) {
                printf("%s ", noms[j]);
                predecesseur_existe = 1;
            }
        }

        if (!predecesseur_existe) {
            printf("Aucun");
        }
        printf("\n");
    }
}

// Fonction pour trouver les premiers maillons (sans prédécesseurs)
void trouver_premiers_maillons(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    printf("\nPremiers maillons (sans predecesseurs) :\n");
    for (int i = 0; i < ordre; i++) {
        int sans_predecesseur = 1;
        for (int j = 0; j < ordre; j++) {
            if (matrice[j][i] == 1) {
                sans_predecesseur = 0;
                break;
            }
        }
        if (sans_predecesseur) {
            printf("%s\n", noms[i]);
        }
    }
}

// Fonction pour trouver les derniers maillons (sans successeurs)
void trouver_derniers_maillons(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    printf("\nDerniers maillons (sans successeurs) :\n");
    for (int i = 0; i < ordre; i++) {
        int sans_successeur = 1;
        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] == 1) {
                sans_successeur = 0;
                break;
            }
        }
        if (sans_successeur) {
            printf("%s\n", noms[i]);
        }
    }
}