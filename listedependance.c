//
// Created by joany on 01/12/2024.
//
// graph.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listedependance.h"



void affichersommets(char noms[MAXANIMAUX][MAXNOM], int ordre) {
    printf("Nombre de sommet : %d  :\n", ordre);
    printf("\n");
    printf("**** Liste des sommets : ****\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s\n", noms[i]);
    }
}

void afficherarcs(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre) {
    int nbarcs = 0;

    // Calcul du nombre d'arcs
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] == 1) {
                nbarcs++;
            }
        }
    }

    printf("\nNombre des arc %d  :\n", nbarcs);
    printf("\n");
    printf("\n**** Liste des arcs:****\n");
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] == 1) {
                printf("%s -> %s\n", noms[i], noms[j]);
            }
        }
    }
}

void trouvercheminsinverse(int sommet, int matrice[MAXANIMAUX][MAXANIMAUX], char noms[MAXANIMAUX][MAXNOM], int ordre, int chemin[], int niveau,int* compteur) {
    chemin[niveau] = sommet;
    int estsource = 1;

    for (int i = 0; i < ordre; i++) {
        if (matrice[i][sommet] == 1) {
            estsource = 0;
            trouvercheminsinverse(i, matrice, noms, ordre, chemin, niveau + 1,compteur);
        }
    }

    if (estsource) {
        (*compteur)++;
        printf("Chemin : ");
        for (int i = niveau; i >= 0; i--) {
            printf("%s%s", noms[chemin[i]], (i == 0) ? "\n" : " -> ");
        }
    }
}

void trouvercheminsdependance(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre) {
    char sommetchoisi[MAXNOM];
    int index = -1;

    printf("\nEntrez le nom du sommet : ");
    scanf("%s", sommetchoisi);

    for (int i = 0; i < ordre; i++) {
        if (strcmp(noms[i], sommetchoisi) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Sommet non trouve.\n");
        return;
    }

    printf("\nTous les chemins aboutissant a %s :\n", sommetchoisi);
    int chemin[MAXANIMAUX];
    int compteur = 0;
    trouvercheminsinverse(index, matrice, noms, ordre, chemin, 0, &compteur);
    printf("\n*   Nombre total de chemins : %d\n", compteur);
}