//
// Created by DELL 7420 on 04/12/2024.
//

#ifndef PROJET_INFO_TG_CENTRALITE_H
#define PROJET_INFO_TG_CENTRALITE_H

#define MAXNOM 50
#define MAXANIMAUX 100

// Prototype des fonctions
void Chemincourt(int matrice[MAXANIMAUX][MAXANIMAUX], int nombreSommets, int chemins[MAXANIMAUX][MAXANIMAUX]);
void calculerCentralite(int matrice[MAXANIMAUX][MAXANIMAUX], int nombreSommets, float centralite[MAXANIMAUX]);
void mesurercentraliteradiale(int matrice[MAXANIMAUX][MAXANIMAUX], int ordre, char noms[MAXANIMAUX][MAXNOM]);
void mesurercentralitemediane(int matrice[MAXANIMAUX][MAXANIMAUX], int ordre, char noms[MAXANIMAUX][MAXNOM]);


#endif //PROJET_INFO_TG_CENTRALITE_H
