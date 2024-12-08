#include "dynamique.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

//initialisation des paramètres dynamiques
void initialiser_parametres_dynamiques(float* r, float* K, int ordre, char noms[MAX_ANIMAUX][MAX_NOM]) {
    for (int i = 0; i < ordre; i++) {
        r[i] = 0.1f;  //taux de croissance initial peut etre modif plus tard
        K[i] = 500.0f; //capacité de charge initiale " "
    }
}

//calcul de la nouvelle population à l'instant t+1
void calculer_population(int ordre, float* populations, float* r, float* K, int matrice[MAX_ANIMAUX][MAX_ANIMAUX]) {
    float nouvelles_populations[MAX_ANIMAUX];

    for (int i = 0; i < ordre; i++) {
        float sum_predation = 0.0f;

        //calcul des prédations
        for (int j = 0; j < ordre; j++) {
            if (matrice[j][i] != 0) { // les arcs de j vers i
                sum_predation += matrice[j][i] * populations[j] * 0.01f;
            }
        }

        //calcul du modèle logistique avec les prédations
        nouvelles_populations[i] = populations[i] + r[i] * populations[i] * (1 - populations[i] / K[i]) - sum_predation;

        //pas de valeurs négatives
        if (nouvelles_populations[i] < 0) {
            nouvelles_populations[i] = 0;
        }
    }

    //Mise à jour des populations
    for (int i = 0; i < ordre; i++) {
        populations[i] = nouvelles_populations[i];
    }
}

//affichage des populations
void afficher_populations(float* populations, char noms[MAX_ANIMAUX][MAX_NOM], int ordre) {
    printf("\n=== Populations actuelles ===\n");
    for (int i = 0; i < ordre; i++) {
        printf("%s: %.2f\n", noms[i], populations[i]);
    }
}

//Lancer la simulation en temps réel
void lancer_simulation(int ordre, float* populations, float* r, float* K, int matrice[MAX_ANIMAUX][MAX_ANIMAUX], char noms[MAX_ANIMAUX][MAX_NOM]) {
    bool en_pause = false;
    char commande;

    printf("Simulation en temps reel demarree.\n");

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
            printf("Entrez le numero du sommet a neutraliser (0 a %d) : ", ordre - 1);
            scanf("%d", &sommet);
            if (sommet >= 0 && sommet < ordre) {
                populations[sommet] = 0;
                printf("Sommet %d neutralise (%s).\n", sommet, noms[sommet]);
            } else {
                printf("Sommet invalide.\n");
            }
        } else if (commande == 'm') {
            int sommet;
            printf("Entrez le numero du sommet a modifier (0 a %d) : ", ordre - 1);
            scanf("%d", &sommet);
            if (sommet >= 0 && sommet < ordre) {
                printf("Parametres actuels pour %s: r = %.2f, K = %.2f\n", noms[sommet], r[sommet], K[sommet]);
                printf("Nouvelle valeur pour r : ");
                scanf("%f", &r[sommet]);
                printf("Nouvelle valeur pour K : ");
                scanf("%f", &K[sommet]);
                printf("Mise a jour : %s -> r = %.2f, K = %.2f\n", noms[sommet], r[sommet], K[sommet]);
            } else {
                printf("Sommet invalide.\n");
            }
        } else if (commande == 'q') {
            printf("Simulation terminee.\n");
            break;
        } else {
            printf("Commande invalide.\n");
        }

        sleep(1); //simulation temps réel peut etre modif
    }
}

// Fonction pour afficher les graphiques avec gnuplot
void afficher_graphique(float populations[MAX_ANIMAUX][MAX_ANIMAUX], char noms[MAX_ANIMAUX][MAX_NOM], int ordre, int steps) {
    FILE* gnuplotPipe = popen("C:\\gnuplot\\bin\\gnuplot.exe -persistent", "w");
    if (!gnuplotPipe) {
        perror("Erreur lors de l'ouverture de gnuplot");
        exit(EXIT_FAILURE);
    }

    // Préparer le fichier temporaire contenant les données
    FILE* dataFile = fopen("populations.dat", "w");
    if (!dataFile) {
        perror("Erreur lors de la création du fichier temporaire");
        exit(EXIT_FAILURE);
    }

    // Écrire les données pour gnuplot
    for (int step = 0; step < steps; step++) {
        fprintf(dataFile, "%d", step); // Temps
        for (int i = 0; i < ordre; i++) {
            fprintf(dataFile, " %.2f", populations[step][i]); // Population de chaque espèce
        }
        fprintf(dataFile, "\n");
    }
    fclose(dataFile);

    // Préparer la commande gnuplot
    fprintf(gnuplotPipe, "set title 'Evolution des populations'\n");
    fprintf(gnuplotPipe, "set xlabel 'Temps'\n");
    fprintf(gnuplotPipe, "set ylabel 'Population'\n");
    fprintf(gnuplotPipe, "plot ");

    for (int i = 0; i < ordre; i++) {
        fprintf(gnuplotPipe, "'populations.dat' using 1:%d with lines title '%s'", i + 2, noms[i]);
        if (i < ordre - 1) {
            fprintf(gnuplotPipe, ", ");
        }
    }
    fprintf(gnuplotPipe, "\n");

    fflush(gnuplotPipe);
    pclose(gnuplotPipe);
}