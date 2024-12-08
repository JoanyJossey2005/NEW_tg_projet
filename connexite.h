//
// Created by DELL 7420 on 02/12/2024.
//

#ifndef PROJET_INFO_TG_CONNEXITE_H
#define PROJET_INFO_TG_CONNEXITE_H

#include <stdbool.h>

#define MAX_ANIMAUX 100

// Fonction pour effectuer un parcours en profondeur
void parcours_profondeur(int sommet, int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, bool visite[]);

// Vérifier si le graphe est fortement connexe
bool est_fortement_connexe(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre);

// Vérifier si le graphe est faiblement connexe
bool est_connexe(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, char noms[MAX_ANIMAUX][50]);

// Afficher les deux sous-graphes (écosystèmes) distincts si le graphe n'est pas connexe
void afficher_ecosystemes(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, char noms[MAX_ANIMAUX][50]);

#endif //PROJET_INFO_TG_CONNEXITE_H

