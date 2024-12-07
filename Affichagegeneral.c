
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Affichagegeneral.h"

#define MAXANIMAUX 100
#define MAXNOM 50

// Fonction pour afficher les successeurs de chaque animal
void affichersuccesseurs(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre) {
    printf("--------------------------------\n");
    printf("\nAffichage des successeurs :\n");
    printf("--------------------------------\n");

    for (int i = 0; i < ordre; i++) {
        printf("Successeurs de %s : ", noms[i]);
        int successeurexiste = 0;

        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] == 1) {
                printf("%s ", noms[j]);
                successeurexiste = 1;
            }
        }

        if (!successeurexiste) {
            printf("Aucun");
        }
        printf("\n");
    }
}

// Fonction pour afficher les prédécesseurs de chaque animal
void afficherpredecesseurs(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre) {
    printf("--------------------------------\n");
    printf("\nAffichage des predecesseurs :\n");
    printf("--------------------------------\n");
    for (int i = 0; i < ordre; i++) {
        printf("Predecesseurs de %s : ", noms[i]);
        int predecesseurexiste = 0;

        for (int j = 0; j < ordre; j++) {
            if (matrice[j][i] == 1) {
                printf("%s ", noms[j]);
                predecesseurexiste = 1;
            }
        }

        if (!predecesseurexiste) {
            printf("Aucun");
        }
        printf("\n");
    }
}

// Fonction pour trouver les premiers maillons (sans prédécesseurs)
void trouverpremiersmaillons(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre) {
    printf("\n-  Premiers maillons (sans predecesseurs) :\n");
    for (int i = 0; i < ordre; i++) {
        int sanspredecesseur = 1;
        for (int j = 0; j < ordre; j++) {
            if (matrice[j][i] == 1) {
                sanspredecesseur = 0;
                break;
            }
        }
        if (sanspredecesseur) {
            printf("%s\n", noms[i]);
        }
    }
}

// Fonction pour trouver les derniers maillons (sans successeurs)
void trouverderniersmaillons(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre) {
    printf("\n-  Derniers maillons (sans successeurs) :\n");
    for (int i = 0; i < ordre; i++) {
        int sanssuccesseur = 1;
        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] == 1) {
                sanssuccesseur = 0;
                break;
            }
        }
        if (sanssuccesseur) {
            printf("%s\n", noms[i]);
        }
    }
}