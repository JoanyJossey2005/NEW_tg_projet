#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "centralite.h"


#define MAX_ANIMAUX 100

// Fonction pour calculer la centralité radiale
void mesurer_centralite_radiale(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, char noms[MAX_ANIMAUX][MAX_NOM]) {
    int demi_degre_interieur[MAX_ANIMAUX] = {0};
    int demi_degre_exterieur[MAX_ANIMAUX] = {0};

    // Calcul des demi-degrés intérieur et extérieur
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] > 0) {
                demi_degre_exterieur[i]++;
                demi_degre_interieur[j]++;
            }
        }
    }

    // Affichage des résultats
    printf("\n=== Centralite Radiale ===\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s : Demi-degre interieur = %d, Demi-degre exterieur = %d\n",
               noms[i], demi_degre_interieur[i], demi_degre_exterieur[i]);
    }
}

// Fonction pour calculer la centralité médiane
void mesurer_centralite_mediane(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, char noms[MAX_ANIMAUX][MAX_NOM]) {
    float centralite_intermediaire[MAX_ANIMAUX] = {0};

    // Implémentation naïve pour centralité d'intermédiarité (nombre de chemins passant par chaque sommet)
    for (int k = 0; k < ordre; k++) { // Sommet de passage
        for (int i = 0; i < ordre; i++) {
            for (int j = 0; j < ordre; j++) {
                if (i != j && i != k && j != k) {
                    if (matrice[i][k] > 0 && matrice[k][j] > 0) {
                        centralite_intermediaire[k]++;
                    }
                }
            }
        }
    }

    // Normaliser la centralité en divisant par le nombre total de chemins possibles
    int total_chemins_possibles = (ordre - 1) * (ordre - 2);
    for (int i = 0; i < ordre; i++) {
        centralite_intermediaire[i] /= total_chemins_possibles;
    }

    // Affichage des résultats
    printf("\n=== Centralite Mediane ===\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s : Centralite d'intermediarite = %.2f\n", noms[i], centralite_intermediaire[i]);
    }
}
