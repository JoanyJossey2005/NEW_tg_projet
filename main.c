#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listedependance.h"
#include "Affichagegeneral.h"

#define MAX_ANIMAUX 100
#define MAX_NOM 50

// Fonction pour lire le fichier et extraire les données
void lire_fichier(char* nomFichier, char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int* ordre) {
    FILE* fichier = fopen(nomFichier, "r");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lire l'ordre (nombre de sommets/animaux)
    fscanf(fichier, "%d", ordre);

    // Lire les noms des animaux
    for (int i = 0; i < *ordre; i++) {
        fscanf(fichier, "%s", noms[i]);
    }

    // Lire la matrice d'adjacence
    for (int i = 0; i < *ordre; i++) {
        for (int j = 0; j < *ordre; j++) {
            fscanf(fichier, "%d", &matrice[i][j]);
        }
    }

    fclose(fichier);
}


int main() {
    char nomFichier[100];
    int matrice[MAX_ANIMAUX][MAX_ANIMAUX];
    char noms[MAX_ANIMAUX][MAX_NOM];
    int ordre;

    // Demander le nom du fichier
    printf("Entrez le nom du fichier contenant le graphe : ");
    scanf("%s", nomFichier);

    // Lire le fichier et charger les données
    lire_fichier(nomFichier, noms, matrice, &ordre);

    // Afficher les sommets
    afficher_sommets(noms, ordre);

    // Afficher les arcs
    afficher_arcs(noms, matrice, ordre);

    // Afficher les successeurs
    afficher_successeurs(noms, matrice, ordre);

    // Afficher les prédécesseurs
    afficher_predecesseurs(noms, matrice, ordre);

    // Trouver les premiers maillons
    trouver_premiers_maillons(noms, matrice, ordre);

    // Trouver les derniers maillons
    trouver_derniers_maillons(noms, matrice, ordre);

    // Trouver et afficher les chemins dépendants d'un sommet
    trouver_chemins_dependance(noms, matrice, ordre);



    return 0;
}