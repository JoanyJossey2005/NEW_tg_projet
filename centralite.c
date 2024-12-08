#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXANIMAUX 100
#define MAXNOM 50
#define INF 10000



//trouver le chemin le plus court entre deux sommet
void Chemincourt(int matrice[MAXANIMAUX][MAXANIMAUX], int nombreSommets, int chemins[MAXANIMAUX][MAXANIMAUX]) {

    for (int i = 0; i < nombreSommets; i++) {
        for (int j = 0; j < nombreSommets; j++) {
            if (i == j) {
                chemins[i][j] = 0;
            } else if (matrice[i][j] != 0) {
                chemins[i][j] = matrice[i][j];
            } else {
                chemins[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < nombreSommets; k++) { // soit k notre sommet intermediare
        for (int i = 0; i < nombreSommets; i++) {
            for (int j = 0; j < nombreSommets; j++) {
                if (chemins[i][k] != INF && chemins[k][j] != INF &&
                    chemins[i][k] + chemins[k][j] < chemins[i][j]) {
                    chemins[i][j] = chemins[i][k] + chemins[k][j];
                }
            }
        }
    }
}


//calculer la centralité d'intermédiarité
void calculerCentralite(int matrice[MAXANIMAUX][MAXANIMAUX], int nombreSommets, float centralite[MAXANIMAUX]) {
    int chemins[MAXANIMAUX][MAXANIMAUX];
    Chemincourt(matrice, nombreSommets, chemins);

    for (int s = 0; s < nombreSommets; s++) {
        centralite[s] = 0.0;
        for (int u = 0; u < nombreSommets; u++) {
            for (int v = 0; v < nombreSommets; v++) {
                if (u != s && v != s && u != v) {
                    int totalChemins = 0, cheminsPassantParS = 0;

                    // Compter les chemins les plus courts passant par s,qu'on appelle k
                    for (int k = 0; k < nombreSommets; k++) {
                        if (chemins[u][k] + chemins[k][v] == chemins[u][v]) {
                            totalChemins++;
                            if (k == s) {
                                cheminsPassantParS++;
                            }
                        }
                    }

                    // Ajouter à la centralité
                    if (totalChemins > 0) {
                        centralite[s] += (float)cheminsPassantParS / totalChemins; // on divise le nombre de fois ou s est le point de passage par le nombre de chemin totale
                    }
                }
            }
        }
    }
}

//fonction pour calculer la centralité radiale
void mesurercentraliteradiale(int matrice[MAXANIMAUX][MAXANIMAUX], int ordre, char noms[MAXANIMAUX][MAXNOM]) {
    int demidegreinterieur[MAXANIMAUX] = {0};
    int demidegreexterieur[MAXANIMAUX] = {0};

    // Calcul des demi-degrés intérieur et extérieur
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            if (matrice[i][j] > 0) {
                demidegreexterieur[i]++;
                demidegreinterieur[j]++;
            }
        }
    }

    //affichage des résultats
    printf("\n=== Centralite Radiale ===\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s : Demi-degre interieur = %d, Demi-degre exterieur = %d\n",
               noms[i], demidegreinterieur[i], demidegreexterieur[i]);
    }
}

//la centralité médiane
void mesurercentralitemediane(int matrice[MAXANIMAUX][MAXANIMAUX], int ordre, char noms[MAXANIMAUX][MAXNOM]) {
    float centraliteintermediaire[MAXANIMAUX] = {0};


    calculerCentralite(matrice, ordre, centraliteintermediaire);

    //Affichage des résultats
    printf("\n=== Centralite Mediane ===\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s : Centralite d'intermediarite = %.2f\n", noms[i], centraliteintermediaire[i]);
    }
}