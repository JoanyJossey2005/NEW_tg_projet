#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NivTrophiquesMaxLim.h"

// Fonction pour calculer les niveaux trophiques
void calculer_niveaux_trophiques(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, int niveaux[MAX_ANIMAUX]) {
    // Initialiser tous les niveaux à -1 (non définis)
    for (int i = 0; i < ordre; i++) {
        niveaux[i] = -1;
    }

    // Définir les producteurs primaires (aucun prédécesseur)
    for (int i = 0; i < ordre; i++) {
        int est_producteur = 1;
        for (int j = 0; j < ordre; j++) {
            if (matrice[j][i] == 1) { // Si une espèce prédate i
                est_producteur = 0;
                break;
            }
        }
        if (est_producteur) {
            niveaux[i] = 1; // Producteur au niveau trophique 1
        }
    }

    // Propagation des niveaux trophiques
    int changements;
    do {
        changements = 0;
        for (int i = 0; i < ordre; i++) {
            if (niveaux[i] != -1) continue; // Si déjà calculé

            int max_niveau_predateur = 0;
            int pred_found = 0;

            for (int j = 0; j < ordre; j++) {
                if (matrice[j][i] == 1 && niveaux[j] != -1) { // j prédécesseur de i
                    pred_found = 1;
                    if (niveaux[j] > max_niveau_predateur) {
                        max_niveau_predateur = niveaux[j];
                    }
                }
            }

            if (pred_found) {
                niveaux[i] = max_niveau_predateur + 1;
                changements = 1;
            }
        }
    } while (changements);
}

// Fonction pour afficher les niveaux trophiques
void afficher_niveaux_trophiques(char noms[MAX_ANIMAUX][MAX_NOM], int niveaux[MAX_ANIMAUX], int ordre) {
    printf("\n--- Niveaux trophiques ---\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s : Niveau trophique = %d\n", noms[i], niveaux[i]);
    }
}

// Fonction pour afficher le niveau trophique maximal
void afficher_niveau_trophique_maximal(int niveaux[MAX_ANIMAUX], int ordre) {
    int niveau_max = 0;
    for (int i = 0; i < ordre; i++) {
        if (niveaux[i] > niveau_max) {
            niveau_max = niveaux[i];
        }
    }
    printf("\nLe niveau trophique maximal dans le réseau est : %d\n", niveau_max);
}
