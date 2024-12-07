//
// Created by joany on 07/12/2024.
//

#ifndef PROJET_INFO_TG_DYNAMIQUEPOPULATION_H
#define PROJET_INFO_TG_DYNAMIQUEPOPULATION_H



#define MAXANIMAUX 100
#define MAXNOM 50

void AfficherPopulation(int PopulationIniniale[], int PopulationModifie[], int PopulationFinale[], int taille, char NomAnimaux[][20]);
void ModifierPopulation(int populations[], int taille, char NomAnimaux[][20]);
void CalculerNouvellePopulation(int populations[], int NouvellePopulation[], double coefficients[][MAXANIMAUX], int taille);

#endif //PROJET_INFO_TG_DYNAMIQUEPOPULATION_H
