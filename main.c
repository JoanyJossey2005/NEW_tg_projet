#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listedependance.h"
#include "Affichagegeneral.h"
#include "disparition_espece.h"
#include "connexite.h"
#include "centralite.h"
#include "NivTrophiquesMaxLim.h"
#include "visualisation_graphes.h"
#include "dynamique.h"

#define MAX_ANIMAUX 100
#define MAX_NOM 50

// Afficher le menu principal
void afficher_menu_principal() {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Etudier le graphe 1\n");
    printf("2. Etudier le graphe 2\n");
    printf("3. Etudier le graphe 3\n");
    printf("0. Quitter\n");
}

// Afficher le menu secondaire
void afficher_menu_secondaire() {
    printf("\n=== MENU SECONDAIRE ===\n");
    printf("1. Afficher les sommets\n");
    printf("2. Afficher les arcs\n");
    printf("3. Afficher les successeurs\n");
    printf("4. Afficher les predecesseurs\n");
    printf("5. Trouver les premiers maillons\n");
    printf("6. Trouver les derniers maillons\n");
    printf("7. Mesurer la centralite radiale et mediane\n");
    printf("8. Calculer les niveaux trophiques\n");
    printf("9. Simuler la disparition d'une espece\n");
    printf("10. Visualiser le graphe\n");
    printf("11. Simuler les flux\n");
    printf("12. Analyser la dynamique des populations\n");
    printf("13. Liste des dependances d'un sommet\n");
    printf("14. Verifier la connexite du graphe\n");

    printf("0. Retour au menu principal\n");
}

// Fonction pour lire les données d'un fichier et remplir les structures associées
void lire_fichier(char* nomFichier, char noms[MAX_ANIMAUX][MAX_NOM],
                  float populations[MAX_ANIMAUX], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int* ordre) {
    FILE* fichier = fopen(nomFichier, "r");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lire l'ordre (nombre de sommets/animaux)
    fscanf(fichier, "%d", ordre);

    // Lire les noms des animaux et leurs populations
    for (int i = 0; i < *ordre; i++) {
        fscanf(fichier, "%s %f", noms[i], &populations[i]);
    }

    // Lire la matrice d'adjacence
    for (int i = 0; i < *ordre; i++) {
        for (int j = 0; j < *ordre; j++) {
            fscanf(fichier, "%d", &matrice[i][j]);
        }
    }

    fclose(fichier);
}

// Fonction pour charger le graphe depuis un fichier
void charger_graphe(char* nomFichier, char noms[MAX_ANIMAUX][MAX_NOM],
                    float populations[MAX_ANIMAUX], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int* ordre) {
    lire_fichier(nomFichier, noms, populations, matrice, ordre);
}

int main() {
    char nomFichier[100];
    int matrice[MAX_ANIMAUX][MAX_ANIMAUX];
    char noms[MAX_ANIMAUX][MAX_NOM];
    int niveaux[MAX_ANIMAUX];
    float populations[MAX_ANIMAUX];  // Déclaration des populations
    float r[MAX_ANIMAUX];            // Déclaration des taux de croissance
    float K[MAX_ANIMAUX];            // Déclaration des capacités de charge
    int ordre = 0;
    int choixGraphe, choixFonctionnalite;
    int sommetSupprime;

    const char *imagePath = "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_1.png";
   // const char* fichierDot = "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_1.dot";
   // const char* fichierImage = "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_1.png";

    while (1) {
        afficher_menu_principal();
        printf("Choisissez un graphe a etudier (1, 2 ou 3, ou 0 pour quitter) : ");
        scanf("%d", &choixGraphe);

        if (choixGraphe == 0) {
            printf("Vous avez choisi de quitter\n");
            break;
        }

        // Charger le fichier correspondant au graphe choisi
        switch (choixGraphe) {
            case 1:
                strcpy(nomFichier, "graphe_1.txt");
              //  snprintf(fichierDot, sizeof(fichierDot), "cmake-build-debug\\graphe_1.dot");
               // snprintf(fichierImage, sizeof(fichierImage), "cmake-build-debug\\graphe_1.png");
                break;
            case 2:
                strcpy(nomFichier, "graphe2.txt");
              //  snprintf(fichierDot, sizeof(fichierDot), "graphe_2.dot");
              //  snprintf(fichierImage, sizeof(fichierImage), "graphe_2.png");
                break;
            case 3:
                strcpy(nomFichier, "graphe3.txt");
              //  snprintf(fichierDot, sizeof(fichierDot), "graphe_3.dot");
              //  snprintf(fichierImage, sizeof(fichierImage), "graphe_3.png");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                continue;
        }

        charger_graphe(nomFichier, noms, populations, matrice, &ordre);
        printf("Graphe %d chargé avec succès.\n", choixGraphe);

        initialiser_parametres_dynamiques(r, K, ordre, noms);

        // Afficher le menu secondaire pour les fonctionnalités
        while (1) {
            afficher_menu_secondaire();
            printf("Choisissez une fonctionnalite (1-14, ou 0 pour revenir au menu principal) : ");
            scanf("%d", &choixFonctionnalite);

            if (choixFonctionnalite == 0) {
                printf("Retour au menu principal\n");
                break;
            }

            switch (choixFonctionnalite) {
                case 1:
                    affichersommets(noms, ordre);
                    break;
                case 2:
                    afficherarcs(noms, matrice, ordre);
                    break;
                case 3:
                    affichersuccesseurs(noms, matrice, ordre);
                    break;
                case 4:
                    afficherpredecesseurs(noms, matrice, ordre);
                    break;
                case 5:
                    trouverpremiersmaillons(noms, matrice, ordre);
                    break;
                case 6:
                    trouverderniersmaillons(noms, matrice, ordre);
                    break;
                case 7:
                    mesurer_centralite_radiale(matrice, ordre, noms);
                    mesurer_centralite_mediane(matrice, ordre, noms);
                    break;
                case 8:
                    // Calculer les niveaux trophiques
                    calculer_niveaux_trophiques(matrice, ordre, niveaux);
                    // Afficher les niveaux trophiques de toutes les espèces
                    afficher_niveaux_trophiques(noms, niveaux, ordre);
                    // Afficher le niveau trophique maximal
                    afficher_niveau_trophique_maximal(niveaux, ordre);
                    break;
                case 9:
                    printf("Entrez le numero du sommet a supprimer (0 à %d) : ", ordre - 1);
                    scanf("%d", &sommetSupprime);

                    // Analyser et afficher l'impact
                    Impact impact;
                    analyserImpact(matrice, ordre, sommetSupprime, &impact);
                    afficherImpact(&impact, noms);
                    break;
                case 10:
                    // "C:\Melanie\Informatique\Graphviz\bin\dot.exe" -Tpng "C:\Melanie\Informatique\NEW_tg_projet\cmake-build-debug\graphe_1.dot" -o "C:\Melanie\Informatique\NEW_tg_projet\cmake-build-debug\graphe_1.png"
                 //   printf("Affichage du graphe en cours...\n");
                 //   afficherGraphe();

                    system(imagePath);
                    break;
                case 11:
                   // moteur_simulation_flux(noms, matrice, ordre);
                    printf("\n pas encore implemente");
                    break;
                case 12:
                    printf("\n=== Simulation Dynamique en Temps Reel ===\n");
                    printf("Les populations actuelles seront mises a jour selon le modèle logistique.\n");
                    printf("Vous pouvez interagir avec la simulation en temps reel.\n");

                    // Initialisation des paramètres dynamiques
                    initialiser_parametres_dynamiques(r, K, ordre, noms);

                    // Lancement de la simulation
                    lancer_simulation(ordre, populations, r, K, matrice, noms);

                    printf("Simulation terminee. Retour au menu principal.\n");
                    break;
                case 13:
                    // dependance d'un chemin
                    trouvercheminsdependance(noms, matrice, ordre);
                    break;
                case 14:
                    if (est_fortement_connexe(matrice, ordre)) {
                        printf("Le graphe est fortement connexe.\n");
                    } else if (est_connexe(matrice, ordre)) {
                        printf("Le graphe est connexe.\n");
                    } else {
                        printf("Le graphe n'est pas connexe.\n");
                    }
                    break;

                default:
                    printf("Choix invalide. Veuillez reessayer.\n");
            }
        }
    }
    return 0;
}
