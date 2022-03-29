#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 9



void printlamatrice(int matrice[TAILLE][TAILLE]){
	for(int i=0; i<TAILLE; i++)
		{
			for(int j=0; j<TAILLE; j++)
			{
				printf("%9d", matrice[i][j]);
			}
			printf("\n");
		}
}


int remplirdiag(int matrice[TAILLE][TAILLE])
{
	int n = rand()%9 + 1; // nombre entre 1 et 9 Normalement

	for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				matrice[i][j]=n;
			}

		}
			return matrice[TAILLE][TAILLE];
}


int  main(int argc, char const *argv[])
{
	//srand(time(NULL));

	int matricedebase[TAILLE][TAILLE]={
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

		printlamatrice(matricedebase[TAILLE][TAILLE]);
		matricedebase=remplirdiag(matricedebase[TAILLE][TAILLE]);
		printlamatrice(matricedebase[TAILLE][TAILLE]);
}
