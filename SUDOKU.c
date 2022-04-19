#include <stdio.h>
#include <stdlib.h>
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


void remplirdiag(int** grille)
{
	int n = rand()%9 + 1; // nombre entre 1 et 9 Normalement

	for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				grille[i][j]=n;
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
	printlamatrice(grille);
}
