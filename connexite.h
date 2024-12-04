//
// Created by DELL 7420 on 02/12/2024.
//

#ifndef PROJET_INFO_TG_CONNEXITE_H
#define PROJET_INFO_TG_CONNEXITE_H

#include <stdbool.h>

#define MAX_ANIMAUX 100

bool est_fortement_connexe(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre);
bool est_connexe(int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre);

#endif //PROJET_INFO_TG_CONNEXITE_H

