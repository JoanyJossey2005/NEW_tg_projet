//
// Created by melan on 07/12/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "visualisation_graphes.h"

void afficherGraphe(int choixGraphe) {
    char commande[512];  // Stocke la commande formée
    char imagesPath[512]; // stocke l'image png a generer

    /* on utilise un fichier batch afin d'executer la commande qui transforme le fichier .dot en fichier .png dans une console externe comme ici Clion n'accepte pas les noms de dossier avec des espaces
    Le fichier .bat du graphe 1 est par exemple :
    echo "lancement de create_graphe1.bat"  // sert juste à voir si la commande s'execute

     // ligne qui transforme le fichier .dot en image .png
         "C:\Melanie\Informatique\Graphviz\bin\dot.exe" -Tpng "C:\Melanie\Informatique\NEW_tg_projet\cmake-build-debug\graphe_1.dot" -o "C:\Melanie\Informatique\NEW_tg_projet\cmake-build-debug\graphe_1.png"

    echo "Fin de create_graphe1.bat"    // sert juste à voir si la commande s'execute */

    snprintf(commande, sizeof(commande),
             "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\create_graphe%d.bat", choixGraphe); // execute le fichier .bat décrit au dessus
    printf("Commande = %s\n", commande);

    // Exécuter la commande avec system()
    if (system(commande) == 0) {
        // Si la commande réussit, ouvrir l'image
        snprintf(imagesPath, sizeof(imagesPath),
                 "C:\\Melanie\\Informatique\\NEW_tg_projet\\cmake-build-debug\\graphe_%d.png", choixGraphe);

        system(imagesPath);  // Ouvrir l'image avec le programme par défaut
        printf("imagesPath = %s\n", imagesPath);
    } else {
        printf("Erreur lors de la génération de l'image.\n");
    }
}