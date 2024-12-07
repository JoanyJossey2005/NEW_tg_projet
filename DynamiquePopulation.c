//
// Created by joany on 07/12/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamiquePopulation.h"

#define MAXANIMAUX 100

void AfficherPopulationActuelle(int Population[], char NomAnimaux[][20], int taille) {
    printf("\n=== Population actuelle ===\n");
    printf("%-20s %-20s\n", "Animal", "Population");
    printf("--------------------------------------\n");
    for (int i = 0; i < taille; i++) {
        printf("%-20s %-20d\n", NomAnimaux[i], Population[i]);
    }
}

// Sous-fonction : Modifier les populations
void ModifierPopulation(int populations[], int taille, char NomAnimaux[][20]) {
    int animal;
    int Nouvelvaleur;

    while (1) {
        printf("\nEntrez le numero de l'animal a modifier (0 a %d, ou -1 pour terminer) : ", taille - 1);
        scanf("%d", &animal);

        if (animal == -1) {
            printf("Modification terminee.\n");
            break;
        }

        if (animal < 0 || animal >= taille) {
            printf("Numero invalide.\n");
            continue;
        }

        printf("Entrez la nouvelle valeur pour %s : ", NomAnimaux[animal]);
        scanf("%d", &Nouvelvaleur);

        if (Nouvelvaleur < 0) {
            printf("La population ne peut pas être négative.\n");
            continue;
        }

        populations[animal] = Nouvelvaleur;
        printf("La population de %s a ete mise A jour à %d.\n", NomAnimaux[animal], Nouvelvaleur);
    }
}

// Sous-fonction : Calculer la nouvelle population
void CalculerNouvellePopulation(int populations[], int NouvellePopulation[], double coefficients[][MAXANIMAUX], int taille) {
    for (int i = 0; i < taille; i++) {
        NouvellePopulation[i] = populations[i]; // Copie de la population actuelle

        // Consommation par les prédateurs
        for (int j = 0; j < taille; j++) {
            NouvellePopulation[i] -= coefficients[j][i] * populations[j];
        }

        // Empêcher les valeurs négatives
        if (NouvellePopulation[i] < 0) {
            NouvellePopulation[i] = 0;
        }
    }
}

// Sous-fonction : Afficher le résumé des populations
void AfficherPopulation(int PopulationIniniale[], int PopulationModifie[], int PopulationFinale[], int taille, char NomAnimaux[][20]) {
    printf("%-20s %-20s %-20s %-20s\n", "Animal", "Population Initiale", "Population Modifie", "Population Final");
    printf("-----------------------------------------------------------------------------------\n");
    for (int i = 0; i < taille; i++) {
        printf("%-20s %-20d %-20d %-20d\n",
               NomAnimaux[i],
               PopulationIniniale[i],
               PopulationModifie[i],
               PopulationFinale[i]);
    }
}
