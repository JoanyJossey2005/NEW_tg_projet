//
// Created by DELL 7420 on 04/12/2024.
//

#ifndef PROJET_INFO_TG_CENTRALITE_H
#define PROJET_INFO_TG_CENTRALITE_H

#define MAX_NOM 50
#define MAX_ANIMAUX 100

// Fonction pour calculer la centralité radiale
void mesurer_centralite_radiale(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, char noms[MAX_ANIMAUX][MAX_NOM]);

// Fonction pour calculer la centralité médiane
void mesurer_centralite_mediane(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre, char noms[MAX_ANIMAUX][MAX_NOM]);


#endif //PROJET_INFO_TG_CENTRALITE_H
