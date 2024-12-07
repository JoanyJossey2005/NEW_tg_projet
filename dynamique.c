#include "dynamique.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h> // Pour sleep()

// Initialisation des paramètres dynamiques
void initialiser_parametres_dynamiques(float* r, float* K, int ordre, char noms[MAX_ANIMAUX][MAX_NOM]) {
    for (int i = 0; i < ordre; i++) {
        r[i] = 0.1f;  // Taux de croissance initial arbitraire
        K[i] = 500.0f; // Capacité de charge initiale arbitraire (modifiable)
    }
}

// Calcul de la nouvelle population à l'instant t+1
void calculer_population(int ordre, float* populations, float* r, float* K, int matrice[MAX_ANIMAUX][MAX_ANIMAUX]) {
    float nouvelles_populations[MAX_ANIMAUX];

    for (int i = 0; i < ordre; i++) {
        float sum_predation = 0.0f;

        // Calcul des prédations
        for (int j = 0; j < ordre; j++) {
            if (matrice[j][i] != 0) { // Les arcs de j vers i
                sum_predation += matrice[j][i] * populations[j] * 0.01f;
            }
        }

        // Calcul du modèle logistique avec les prédations
        nouvelles_populations[i] = populations[i] + r[i] * populations[i] * (1 - populations[i] / K[i]) - sum_predation;

        // Prévenir les valeurs négatives
        if (nouvelles_populations[i] < 0) {
            nouvelles_populations[i] = 0;
        }
    }

    // Mise à jour des populations (synchronisée)
    for (int i = 0; i < ordre; i++) {
        populations[i] = nouvelles_populations[i];
    }
}

// Affichage des populations
void afficher_populations(float* populations, char noms[MAX_ANIMAUX][MAX_NOM], int ordre) {
    printf("\n=== Populations actuelles ===\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s: %.2f\n", noms[i], populations[i]);
    }
}

// Lancer la simulation en temps réel
void lancer_simulation(int ordre, float* populations, float* r, float* K, int matrice[MAX_ANIMAUX][MAX_ANIMAUX], char noms[MAX_ANIMAUX][MAX_NOM]) {
    bool en_pause = false;
    char commande;

    printf("Simulation en temps reel démarree.\n");

    while (1) {
        if (!en_pause) {
            calculer_population(ordre, populations, r, K, matrice);
            afficher_populations(populations, noms, ordre);
        }

        printf("\nCommandes disponibles :\n");
        printf("[p] Pause/Relancer | [n] Neutraliser sommet | [m] Modifier parametres | [q] Quitter\n");
        printf("Votre choix : ");
        scanf(" %c", &commande);

        if (commande == 'p') {
            en_pause = !en_pause;
            printf(en_pause ? "Simulation mise en pause.\n" : "Simulation reprise.\n");
        } else if (commande == 'n') {
            int sommet;
            printf("Entrez le numéro du sommet à neutraliser (0 à %d) : ", ordre - 1);
            scanf("%d", &sommet);
            if (sommet >= 0 && sommet < ordre) {
                populations[sommet] = 0;
                printf("Sommet %d neutralise (%s).\n", sommet, noms[sommet]);
            } else {
                printf("Sommet invalide.\n");
            }
        } else if (commande == 'm') {
            int sommet;
            printf("Entrez le numéro du sommet à modifier (0 à %d) : ", ordre - 1);
            scanf("%d", &sommet);
            if (sommet >= 0 && sommet < ordre) {
                printf("Parametres actuels pour %s: r = %.2f, K = %.2f\n", noms[sommet], r[sommet], K[sommet]);
                printf("Nouvelle valeur pour r : ");
                scanf("%f", &r[sommet]);
                printf("Nouvelle valeur pour K : ");
                scanf("%f", &K[sommet]);
                printf("Mise à jour : %s -> r = %.2f, K = %.2f\n", noms[sommet], r[sommet], K[sommet]);
            } else {
                printf("Sommet invalide.\n");
            }
        } else if (commande == 'q') {
            printf("Simulation terminee.\n");
            break;
        } else {
            printf("Commande invalide.\n");
        }

        sleep(1); // Simulation temps réel (modifiable)
    }
}
