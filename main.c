#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Fonction pour afficher les successeurs de chaque animal
void afficher_successeurs(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) {
    for (int i = 0; i < ordre; i++) {
        printf("Successeurs de %s : ", noms[i]);
        int successeur_existe = 0;

        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] == 1) {
                printf("%s ", noms[j]);
                successeur_existe = 1;
            }
        }

        if (!successeur_existe) {
            printf("Aucun");
        }
        printf("\n");
    }
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

    // Afficher les successeurs pour chaque animal
    printf("\nAffichage des successeurs :\n");
    afficher_successeurs(noms, matrice, ordre);

    return 0;
}
