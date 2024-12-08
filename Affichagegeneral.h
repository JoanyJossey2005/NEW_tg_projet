


#define MAXANIMAUX 100
#define MAXNOM 50

// Fonction pour afficher les successeurs de chaque animal
void affichersuccesseurs(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre) ;


// Fonction pour afficher les prédécesseurs de chaque animal
void afficherpredecesseurs(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre) ;
void unesourcedalimentation(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre);


// Fonction pour trouver les premiers maillons (sans prédécesseurs)
void trouverpremiersmaillons(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre) ;
void trouverderniersmaillons(char noms[MAXANIMAUX][MAXNOM], int matrice[MAXANIMAUX][MAXANIMAUX], int ordre);