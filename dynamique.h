//
// Created by DELL 7420 on 06/12/2024.
//

#ifndef PROJET_INFO_TG_DYNAMIQUE_H
#define PROJET_INFO_TG_DYNAMIQUE_H

#define MAX_ANIMAUX 100
#define MAX_NOM 50
// Initialisation des paramètres dynamiques
void initialiser_parametres_dynamiques(float r[], float K[], int ordre, char noms[MAX_ANIMAUX][MAX_NOM]);

// Mise à jour des populations avec le modèle logistique et gestion des prédations
void calculer_population(int ordre, float populations[], float r[], float K[], int matrice[MAX_ANIMAUX][MAX_ANIMAUX]);

// Affichage des populations actuelles
void afficher_populations(float populations[], char noms[MAX_ANIMAUX][MAX_NOM], int ordre);

// Simulation dynamique en temps réel
void lancer_simulation(int ordre, float populations[], float r[], float K[], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], char noms[MAX_ANIMAUX][MAX_NOM]);

// Sauvegarde des données dynamiques dans un fichier
void sauvegarder_donnees(char* fichier, float populations[], float r[], float K[], int ordre);

// Chargement des données dynamiques depuis un fichier
void charger_donnees(char* fichier, float populations[], float r[], float K[], int ordre);

#endif


