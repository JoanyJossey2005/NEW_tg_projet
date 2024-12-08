//
// Created by DELL 7420 on 04/12/2024.
//

#ifndef PROJET_INFO_TG_NIVTROPHIQUESMAXLIM_H
#define PROJET_INFO_TG_NIVTROPHIQUESMAXLIM_H

#define MAX_NOM 50
#define MAX_ANIMAUX 100

void calculer_niveaux_trophiques(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, int niveaux[MAX_ANIMAUX]);
void afficher_niveaux_trophiques(char noms[MAX_ANIMAUX][MAX_NOM], int niveaux[MAX_ANIMAUX], int ordre);
void afficher_niveau_trophique_maximal(int niveaux[MAX_ANIMAUX], int ordre);


#endif //PROJET_INFO_TG_NIVTROPHIQUESMAXLIM_H

