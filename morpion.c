/*Theophane Bernhard*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int* creer_grille()
{
	int* tableau=calloc(9, sizeof(int));
	return tableau;
}


void afficher (int* grille)
{
	for (int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j)
		{
			if (grille[i*3+j]==2)
			{
				printf("o");
			}
			if (grille [i*3+j]==1)
			{
				printf("x");
			}
			if (grille[i*3+j]==0)
			{
				printf(".");
			}
		}
		printf("\n");
	}
}


void placer(int* grille, int chiffre, int joueur)
{
	grille[chiffre-1]=joueur;
}


void placer_alea(int* grille, int joueur)
{
	int chiffre=rand()%9;
	while (grille[chiffre]!=0)
	{
		chiffre=rand()%9;
	}
	placer(grille,chiffre+1,joueur);
}


int a_gagne(int* grille, int joueur)
{
	
	for (int i=0; i<9; ++i)
	{
	if (grille[0]==joueur)
	{
		if (grille[1]==joueur)
		{
			if (grille[2]==joueur)
			{
				return 1;
			}
		}
		if (grille[3]==joueur)
		{
			if (grille[6]==joueur)
			{
				return 1;
			}
		}
		if (grille[4]==joueur)
		{
			if (grille[8]==joueur)
			{
				return 1;
			}
		}
	}
	if (grille[8]==joueur)
	{
		if (grille[5]==joueur)
		{
			if (grille[2]==joueur)
			{
				return 1;
			}
		}
		if (grille[7]==joueur)
		{
			if (grille[6]==joueur)
			{
				return 1;
			}
		}
	}
	if (grille[4]==joueur)
	{
		if (grille[1]==joueur)
		{
			if (grille[7]==joueur)
			{
				return 1;
			}
		}
		if (grille[3]==joueur)
		{
			if (grille[5]==joueur)
			{
				return 1;
			}
		}
		if (grille[2]==joueur)
		{
			if (grille[6]==joueur)
			{
				return 1;
			}
		}
	}
	else 
	{
		return 0;
	}
	}
}


int match_nul(int* grille)
/*Retourne 1 si match nul, 0 sinon*/
{
	for (int i=0; i<9; ++i)
	{
		if (grille[i]==0)
		{
			return 0;
		}
	}
	return 1;
}

/*int main()
{
	srand(time(0));
	int* grille=creer_grille();
	int chiffre=0;
	for (int i=0; i<4; ++i)
	{
		afficher(grille);
		scanf("%d", &chiffre);
		placer(grille, chiffre, 1);
		if (a_gagne(grille, 1)==1)
		{
			printf("Vous avez gagné!");
			return 0;
		}
		placer_alea(grille, 2);
		if (a_gagne(grille, 2)==1)
		{
			printf("L'adversaire a gagné");
			return 0;
		}
	}
	afficher(grille);
	scanf("%d", &chiffre);
	placer(grille, chiffre,1);
	if (a_gagne(grille, 1)==1)
	{
		printf("Vous avez gagné!");
	}
	if (a_gagne(grille, 2)==1)
	{
		printf("L'adversaire a gagné");
	}
	if (match_nul(grille)==1)
	{
		printf("match nul en 9 tours");
	}
	free(grille);
}*/
