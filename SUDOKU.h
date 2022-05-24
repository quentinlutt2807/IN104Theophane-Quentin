
void printlamatrice(int** grille);
/*Affiche la grille de jeu*/

bool test_ligne(int** grille, int ligne, int colonne, int valeur);
/*Renvoie True si la valeur donnée se situe déja dans la ligne. Renvoie faux sinon*/
bool test_colonne(int** grille, int ligne, int colonne, int valeur);
/*Renvoie True si la valeur donnée se situe déja dans la colonne. Renvoie faux sinon*/
bool test_sous_matrice(int** grille, int ligne, int colonne, int valeur);
/*Renvoie True si la valeur donnée se situe déja dans la sous grille 3x3. Renvoie faux sinon*/

bool test(int** grille, int ligne, int colonne, int valeur);
/*Renvoie True si la case peut-être remplie par la valeur, False sinon.*/

void remplirdiag(int** grille);
/*Remplie les trois sous grilles de la diagonale, aléatoirement*/

bool remplie(int** grille);
/*Renvoie True si la grille est remplie*/

void reinitialisation(int** grille);
/*Si la grille n'a pas pu être remplie complètement par l'algorithme, on réinitialise la matrice en ne gardant que les 3 sous grilles de la diagonale remplie*/

void remplir_tout(int** grille);
/*Remplie toute la grille*/

void grille_de_jeu(int** grille, int difficulty);
/*Retire des chiffres d'une grille résolue afin de créer une grille de jeu avec plusieurs niveaux de difficultés*/
struct resultat{
	bool juste;
	int errorx;
	int errory;
};
struct resultat test_correct(int** grille);
