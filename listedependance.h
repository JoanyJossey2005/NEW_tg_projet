//
// Created by joany on 01/12/2024.
//

#ifndef PROJET_INFO_TG_LISTEDEPENDANCE_H
#define PROJET_INFO_TG_LISTEDEPENDANCE_H

#define MAXANIMAUX 100
#define MAXNOM 50

void trouvercheminsinverse(int sommet, int matrice[MAXANIMAUX][MAXANIMAUX], char noms[MAXANIMAUX][MAXNOM], int ordre, int chemin[], int niveau,int* compteur);

void trouvercheminsdependance(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre);
void afficherarcs(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre);
void affichersommets(char noms[MAXANIMAUX][MAXNOM], int ordre);
#endif //PROJETINFOTGLISTEDEPENDANCEH
