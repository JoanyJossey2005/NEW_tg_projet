


#define MAX_ANIMAUX 100
#define MAX_NOM 50

// Fonction pour afficher les successeurs de chaque animal
void afficher_successeurs(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) ;


// Fonction pour afficher les prédécesseurs de chaque animal
void afficher_predecesseurs(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) ;


// Fonction pour trouver les premiers maillons (sans prédécesseurs)
void trouver_premiers_maillons(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre) ;
void trouver_derniers_maillons(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre);