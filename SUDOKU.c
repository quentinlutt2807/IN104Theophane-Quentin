#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define TAILLE 9



void printlamatrice(int** grille){
	for(int i=0; i<TAILLE; i++)
		{
			for(int j=0; j<TAILLE; j++)
			{
				printf("%9d", grille[i][j]);
			}
			printf("\n");
		}
}

bool test_ligne(int** grille, int ligne, int colonne, int valeur)
{
	for (int j=0; j<9; ++j)
	{
		if (colonne!=j)
		{
			if (grille[ligne][j]==valeur)
			{
				return true;
			}
		}
	}
	return false;
}

bool test_colonne(int** grille, int ligne, int colonne, int valeur)
{
	for (int i=0; i<9; ++i)
	{
		if (ligne!=i)
		{
			if (grille[i][colonne]==valeur)
			{
				return true;
			}
		}
	}
	return false;
}

bool test_sous_matrice(int** grille, int ligne, int colonne, int valeur)
{
	int a=ligne/3;
	int b=colonne/3;
	for (int k=0; k<3; ++k)
	{
		int i=3*a+k;
		for (int l=0; l<3; ++l)
		{
			int j=3*b+l;
			if (colonne!=j || ligne!=i)
			{
				if (grille[i][j]==valeur)
				{
					return true;
				}
			}
		}
	}
	return false;
}


void remplirdiag(int** grille)
{
	

	for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				while (grille[i][j]==0)
				{
					int n = rand()%9 + 1; // nombre entre 1 et 9 Normalement
					if (test_sous_matrice(grille, i, j, n)==false)
					{
						grille[i][j]=n;
					}
				}
			}
		}
	
	for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				while (grille[3+i][3+j]==0)
				{
					int n = rand()%9 + 1; // nombre entre 1 et 9 Normalement
					if (test_sous_matrice(grille, 3+i, 3+j, n)==false)
					{
						grille[3+i][3+j]=n;
					}
				}
			}
		}
		
	for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				while (grille[6+i][6+j]==0)
				{
					int n = rand()%9 + 1; // nombre entre 1 et 9 Normalement
					if (test_sous_matrice(grille, 6+i, 6+j, n)==false)
					{
						grille[6+i][6+j]=n;
					}
				}
			}
		}
}

bool remplie(int** grille, int abs, int ord)
{
	for (int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j)
		{
			if (grille[i][j]==0) return 0;
		}
	}
	return 1;
}

void remplir_tout(int** grille)
{
	for (int i=0 ;i<3; ++i)
	{
		for (int j=0; j<3; ++j)
		{
			if (i!=j)
			{
				for (int k=0 ;k<3; ++k)
				{
					for (int l=0; l<3; ++l)
					{
						int n= rand()%9 +1;
						while (test_ligne(grille, 3*i+k, 3*j+l, n)==true || test_colonne(grille, 3*i+k, 3*j+l, n)==true || test_sous_matrice(grille, 3*i+k, 3*j+l, n)==true)
						{
							int n=rand()%9 +1;
							printf("%d",test_sous_matrice(grille, 3*i+k, 3*j+l, n));
						}
						grille[3*i+k][3*j+l]=n;
					}
				}
			}
		}
	}
}


int  main(int argc, char const *argv[])
{
	//srand(time(NULL));

	int **grille=calloc(9,sizeof(int*));
	for (int i=0; i<9; ++i)
	{
		int* ligne=calloc(9,sizeof(int));
		grille[i]=ligne;
	}

	printlamatrice(grille);
	printf("\n");
	printf("\n");
	remplirdiag(grille);
	remplir_tout(grille);
	printlamatrice(grille);
}
