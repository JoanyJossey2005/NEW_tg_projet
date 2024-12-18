//
// Created by melan on 04/12/2024.
//

#include "disparition_espece.h"
#include <stdio.h>

// Fonction pour analyser l'impact de la suppression d'une espece sur les proies et les predateurs
void analyserImpact(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, int sommetSupprime, Impact* impact) {
    impact->sommetSupprime = sommetSupprime;
    impact->impactProies = 0;
    impact->impactPredateurs = 0;

    // Initialiser les indices
    for (int i = 0; i < ordre; i++) {
        impact->indicesProies[i] = -1;
        impact->indicesPredateurs[i] = -1;
    }

    // Analyser les proies et les prédateurs
    for (int i = 0; i < ordre; i++) {
        if (matrice[sommetSupprime][i] == 1) { // Predateurs
            impact->indicesPredateurs[impact->impactPredateurs++] = i;
        }
        if (matrice[i][sommetSupprime] == 1) { // Proies
            impact->indicesProies[impact->impactProies++] = i;
        }
    }
}

// Fonction pour afficher les impacts, incluant les noms des proies et des prédateurs
void afficherImpact(Impact* impact, char noms[MAX_ANIMAUX][MAX_NOM]) {
    printf("Sommet supprime : %s\n", noms[impact->sommetSupprime]);

    // Afficher les proies impactées (especes dont l'indice "impactProies" est positif)
    printf("Impact sur les proies : %d\n", impact->impactProies);
    if (impact->impactProies > 0) {
        printf("Proies impactees : ");
        for (int i = 0; i < impact->impactProies; i++) {
            printf("%s ", noms[impact->indicesProies[i]]);
        }
        printf("\n");
    }

    // Afficher les predateurs impactés (especes dont l'indice "impactPredateurs" est positif)
    printf("Impact sur les predateurs : %d\n", impact->impactPredateurs);
    if (impact->impactPredateurs > 0) {
        printf("Predateurs impactes : ");
        for (int i = 0; i < impact->impactPredateurs; i++) {
            printf("%s ", noms[impact->indicesPredateurs[i]]);
        }
        printf("\n");
    }
}