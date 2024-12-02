//
// Created by joany on 01/12/2024.
//
// graph.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listedependance.h"



void afficher_sommets(char noms[MAX_ANIMAUX][MAX_NOM], int ordre) {
    printf("Liste des sommets :\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s\n", noms[i]);
    }
}

void afficher_arcs(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    printf("\nListe des arcs :\n");
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] == 1) {
                printf("%s -> %s\n", noms[i], noms[j]);
            }
        }
    }
}

void trouver_chemins_inverse(int sommet, int matrice[MAX_ANIMAUX][MAX_ANIMAUX], char noms[MAX_ANIMAUX][MAX_NOM], int ordre, int chemin[], int niveau,int* compteur) {
    chemin[niveau] = sommet;
    int est_source = 1;

    for (int i = 0; i < ordre; i++) {
        if (matrice[i][sommet] == 1) {
            est_source = 0;
            trouver_chemins_inverse(i, matrice, noms, ordre, chemin, niveau + 1,compteur);
        }
    }

    if (est_source) {
        (*compteur)++;
        printf("Chemin : ");
        for (int i = niveau; i >= 0; i--) {
            printf("%s%s", noms[chemin[i]], (i == 0) ? "\n" : " -> ");
        }
    }
}

void trouver_chemins_dependance(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    char sommet_choisi[MAX_NOM];
    int index = -1;

    printf("\nEntrez le nom du sommet : ");
    scanf("%s", sommet_choisi);

    for (int i = 0; i < ordre; i++) {
        if (strcmp(noms[i], sommet_choisi) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Sommet non trouve.\n");
        return;
    }

    printf("\nTous les chemins aboutissant a %s :\n", sommet_choisi);
    int chemin[MAX_ANIMAUX];
    int compteur = 0;
    trouver_chemins_inverse(index, matrice, noms, ordre, chemin, 0, &compteur);
    printf("\nNombre total de chemins : %d\n", compteur);
}