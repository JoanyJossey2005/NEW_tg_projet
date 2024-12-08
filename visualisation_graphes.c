//
// Created by melan on 07/12/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "visualisation_graphes.h"

void afficherGraphe() {
    char commande[512];  // Stocke la commande formée

    // Formater la commande avec snprintf
//    snprintf(commande, sizeof(commande),
//             "\"C:\\Melanie\\Informatique\\Graphviz\\bin\\dot.exe\" -Tpng "
//             "\"C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_1.dot\" "
//             "-o \"C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_1.png\"");

    snprintf(commande, sizeof(commande),
             "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\create_graphe1.bat");
    printf("Commande = %s\n", commande);

    // Exécuter la commande avec system()
    if (system(commande) == 0) {
        // Si la commande réussit, ouvrir l'image
        const char *imagePath = "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_1.png";
        system(imagePath);  // Ouvrir l'image avec le programme par défaut
    } else {
        printf("Erreur lors de la génération de l'image.\n");
    }

}