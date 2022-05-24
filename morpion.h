int* creer_grille();
/*Crée une grille de jeu*/

void afficher (int* grille);
/*Affiche une grille de jeu*/

void placer(int* grille, int chiffre, int joueur);
/*Place une croix ou un rond.*/

void placer_alea(int* grille, int joueur);
/*Place une croix ou un rond aléatoirement pour l'ordinateur.*/

int a_gagne(int* grille, int joueur);

int match_nul(int* grille);
