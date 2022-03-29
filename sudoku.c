#include <stdio.h>
#include <stdio.h>

#define TAILLE 9
int  main(int argc, char const *argv[])
{
	int matricedeBase[TAILLE][TAILLE]={
				{0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0},
				}; ;
	for(int i=0; i<TAILLE; i++)
		{
			for(int j=0; j<9; j++)
				printf("%9d", matricedeBase[i][j]);
			printf("\n");
		}
}
int remplirdiag(matrice){
	
}

bool test_ligne(int matrice, int ligne, int colonne, int valeur)
{
	for (int j=0; j<9; ++j)
	{
		if (colonne!=j)
		{
			if (matrice[ligne][j]!=valeur)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

bool test_colonne(int matrice, int ligne, int colonne, int valeur)
{
	for (int i=0; i<9; ++i)
	{
		if (ligne!=i)
		{
			if (matrice[i][colonne]!=valeur)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

bool test_sous_matrice(int matrice, int ligne, int colonne, int valeur)
{
	int a=ligne/3;
	int b=colonne/3;
	for (int k=0; k<3; ++k)
	{
		int i=3*a+k;
		int j=3*b+k;
		if (colonne!=j || ligne!=i)
		{
			if (matrice[i][j]!=valeur)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}
