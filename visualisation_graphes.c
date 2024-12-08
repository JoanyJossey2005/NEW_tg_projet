//
// Created by melan on 07/12/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "visualisation_graphes.h"

void afficherGraphe(int choixGraphe) {
    char commande[512];  // Stocke la commande formée
    char imagesPath[512];

    // Formater la commande avec snprintf
//    snprintf(commande, sizeof(commande),
//             "\"C:\\Melanie\\Informatique\\Graphviz\\bin\\dot.exe\" -Tpng "
//             "\"C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_1.dot\" "
//             "-o \"C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_1.png\"");

    snprintf(commande, sizeof(commande),
             "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\create_graphe%d.bat", choixGraphe);
    printf("Commande = %s\n", commande);

    // Exécuter la commande avec system()
    if (system(commande) == 0) {
        // Si la commande réussit, ouvrir l'image
        snprintf(imagesPath, sizeof(imagesPath),
                 "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_%d.png", choixGraphe);
       // const char *imagePath = "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_1.png";
        system(imagesPath);  // Ouvrir l'image avec le programme par défaut
        printf("imagesPath = %s\n", imagesPath);
    } else {
        printf("Erreur lors de la génération de l'image.\n");
    }

}