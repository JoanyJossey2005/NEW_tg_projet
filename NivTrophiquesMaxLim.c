#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NivTrophiquesMaxLim.h"

#define MAX_ANIMAUX 100

// Calculer les niveaux trophiques pour chaque espèce
void calculer_niveaux_trophiques(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, int niveaux[MAX_ANIMAUX]) {
    // Initialiser les niveaux trophiques à -1 (inconnu)
    for (int i = 0; i < ordre; i++) {
        niveaux[i] = -1;
    }

    // Le niveau trophique des producteurs (niveau 1) est 0, donc toutes les espèces de niveau 1 commencent ici
    for (int i = 0; i < ordre; i++) {
        int is_producer = 1;  // On suppose que l'espèce i est un producteur (niveau 1)
        for (int j = 0; j < ordre; j++) {
            if (matrice[j][i] == 1) {
                // Si l'espèce i est mangée par une autre espèce j, alors ce n'est pas un producteur
                is_producer = 0;
                break;
            }
        }
        if (is_producer) {
            niveaux[i] = 1;  // Le niveau trophique des producteurs est défini à 1
        }
    }

    // Propager les niveaux trophiques pour les autres espèces
    int niveau;
    int changed;
    do {
        changed = 0;  // Variable pour vérifier si des niveaux trophiques ont changé
        for (int i = 0; i < ordre; i++) {
            // Si le niveau trophique de l'espèce i est déjà défini, on continue
            if (niveaux[i] != -1) continue;

            // Chercher les prédateurs de l'espèce i (espèces qui peuvent la manger)
            for (int j = 0; j < ordre; j++) {
                if (matrice[j][i] == 1 && niveaux[j] != -1) {
                    // L'espèce j mange l'espèce i et son niveau trophique est déjà connu
                    niveau = niveaux[j] + 1;
                    if (niveaux[i] == -1 || niveaux[i] < niveau) {
                        niveaux[i] = niveau;
                        changed = 1;  // Un niveau trophique a été modifié
                    }
                }
            }
        }
    } while (changed);  // Répéter jusqu'à ce qu'aucun niveau trophique ne change
}

// Afficher les niveaux trophiques de toutes les espèces
void afficher_niveaux_trophiques(char noms[MAX_ANIMAUX][MAX_NOM], int niveaux[MAX_ANIMAUX], int ordre) {
    printf("\n--- Niveaux trophiques ---\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s : Niveau trophique = %d\n", noms[i], niveaux[i]);
    }
}

// Afficher le niveau trophique maximal
void afficher_niveau_trophique_maximal(int niveaux[MAX_ANIMAUX], int ordre) {
    int niveau_max = 0;
    for (int i = 0; i < ordre; i++) {
        if (niveaux[i] > niveau_max) {
            niveau_max = niveaux[i];
        }
    }
    printf("\nLe niveau trophique maximal dans le reseau est : %d\n", niveau_max);
}

