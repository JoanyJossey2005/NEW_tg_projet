//
// Created by melan on 04/12/2024.
//

#ifndef GRAPHE_H
#define GRAPHE_H

#define MAX_ANIMAUX 100  // Nombre maximum de sommets (animaux)
#define MAX_NOM 50       // Longueur maximale du nom d'un sommet

typedef struct {
    int sommetSupprime;
    int impactPredateurs;
    int impactProies;
    int indicesProies[MAX_ANIMAUX];
    int indicesPredateurs[MAX_ANIMAUX];
} Impact;

// Déclaration des fonctions
void analyserImpact(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, int sommetSupprime, Impact* impact);
void afficherImpact(Impact* impact, char noms[MAX_ANIMAUX][MAX_NOM]);

#endif

