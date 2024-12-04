#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "connexite.h"

#define MAX_ANIMAUX 100

// Fonction auxiliaire : Parcours en profondeur
void parcours_profondeur(int sommet, int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, bool visite[]) {
    visite[sommet] = true;

    for (int i = 0; i < ordre; i++) {
        if (matrice[sommet][i] == 1 && !visite[i]) {
            parcours_profondeur(i, matrice, ordre, visite);
        }
    }
}

// Vérifier si le graphe est fortement connexe
bool est_fortement_connexe(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    bool visite[MAX_ANIMAUX];

    // Vérifier la connexité en partant de chaque sommet
    for (int sommet = 0; sommet < ordre; sommet++) {
        // Initialiser les visites
        memset(visite, false, sizeof(visite));

        // Effectuer un parcours en profondeur
        parcours_profondeur(sommet, matrice, ordre, visite);

        // Vérifier si tous les sommets ont été visités
        for (int i = 0; i < ordre; i++) {
            if (!visite[i]) {
                return false; // Pas fortement connexe
            }
        }
    }

    // Transposer la matrice d'adjacence
    int matrice_transposee[MAX_ANIMAUX][MAX_ANIMAUX];
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            matrice_transposee[i][j] = matrice[j][i];
        }
    }

    // Vérifier la connexité sur le graphe transposé
    for (int sommet = 0; sommet < ordre; sommet++) {
        // Initialiser les visites
        memset(visite, false, sizeof(visite));

        // Effectuer un parcours en profondeur sur le graphe transposé
        parcours_profondeur(sommet, matrice_transposee, ordre, visite);

        // Vérifier si tous les sommets ont été visités
        for (int i = 0; i < ordre; i++) {
            if (!visite[i]) {
                return false; // Pas fortement connexe
            }
        }
    }

    return true; // Fortement connexe
}

// Vérifier si le graphe est connexe
bool est_connexe(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    // Construire une matrice non orientée à partir de la matrice orientée
    int matrice_non_orientee[MAX_ANIMAUX][MAX_ANIMAUX];
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            matrice_non_orientee[i][j] = matrice[i][j] || matrice[j][i];
        }
    }

    // Vérifier la connexité du graphe non orienté
    bool visite[MAX_ANIMAUX] = {false};
    parcours_profondeur(0, matrice_non_orientee, ordre, visite);

    // Vérifier si tous les sommets ont été visités
    for (int i = 0; i < ordre; i++) {
        if (!visite[i]) {
            return false; // Pas faiblement connexe
        }
    }

    return true; // Faiblement connexe
}

