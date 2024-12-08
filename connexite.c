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

void afficher_ecosystemes(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, char noms[MAX_ANIMAUX][50]) {
    static bool deja_affiche = false; // Pour éviter l'affichage multiple

    if (deja_affiche) {
        printf("\n");
        return; // Ne rien faire si déjà affiché
    }
    deja_affiche = true;

    bool visite[MAX_ANIMAUX] = {false};
    int premier_graphe[MAX_ANIMAUX];
    int deuxieme_graphe[MAX_ANIMAUX];
    int taille_premier = 0, taille_deuxieme = 0;

    // Parcours du premier sous-graphe connexe
    parcours_profondeur(0, matrice, ordre, visite);
    for (int i = 0; i < ordre; i++) {
        if (visite[i]) {
            premier_graphe[taille_premier++] = i;
        }
    }

    // Identification des sommets restants pour le deuxième sous-graphe
    bool visite_deuxieme[MAX_ANIMAUX] = {false};
    for (int i = 0; i < ordre; i++) {
        if (!visite[i] && !visite_deuxieme[i]) {
            parcours_profondeur(i, matrice, ordre, visite_deuxieme);
            break; // Une seule recherche de sous-graphe distinct
        }
    }

    for (int i = 0; i < ordre; i++) {
        if (visite_deuxieme[i]) {
            deuxieme_graphe[taille_deuxieme++] = i;
        }
    }

    // Afficher les deux sous-graphes distincts
    printf("Le graphe n'est pas connexe. Voici les deux ecosystemes distincts :\n");

    printf("1er graphe connexe : ");
    for (int i = 0; i < taille_premier; i++) {
        printf("%s ", noms[premier_graphe[i]]);
    }
    printf("\n");

    printf("2eme graphe connexe : ");
    for (int i = 0; i < taille_deuxieme; i++) {
        printf("%s ", noms[deuxieme_graphe[i]]);
    }
    printf("\n");
}

// Vérifier si le graphe est fortement connexe
bool est_fortement_connexe(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    bool visite[MAX_ANIMAUX];

    // Vérifier la connexité en partant de chaque sommet
    for (int sommet = 0; sommet < ordre; sommet++) {
        memset(visite, false, sizeof(visite));
        parcours_profondeur(sommet, matrice, ordre, visite);

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
        memset(visite, false, sizeof(visite));
        parcours_profondeur(sommet, matrice_transposee, ordre, visite);

        for (int i = 0; i < ordre; i++) {
            if (!visite[i]) {
                return false; // Pas fortement connexe
            }
        }
    }

    return true; // Fortement connexe
}

bool est_connexe(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, char noms[MAX_ANIMAUX][50]) {
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

    for (int i = 0; i < ordre; i++) {
        if (!visite[i]) {
            // Si non connexe, afficher les écosystèmes distincts UNE SEULE FOIS
            afficher_ecosystemes(matrice_non_orientee, ordre, noms);
            return false;
        }
    }

    return true; // Faiblement connexe
}
