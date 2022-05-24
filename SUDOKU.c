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
				if (j%3==2)
				{
					printf("   ");
				}
			}
			if (i%3==2)
			{
				printf("\n");
				printf("\n");
			}
			printf("\n");
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

bool test(int** grille, int ligne, int colonne, int valeur)
{
	if (test_colonne(grille, ligne, colonne, valeur)==false)
	{
		if (test_ligne(grille, ligne, colonne, valeur)==false)
		{
			if (test_sous_matrice(grille, ligne, colonne, valeur)==false)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
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

bool remplie(int** grille)
{
	for (int i=0; i<9; ++i)
	{
		for (int j=0; j<9; ++j)
		{
			if (grille[i][j]==0) return false;
		}
	}
	return true;
}

void reinitialisation(int** grille)
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
						grille[3*i+k][3*j+l]=0;
					}
				}
			}
		}
	}
}
	

void remplir_tout(int** grille)
{
	while (remplie(grille)==false)
	{
		reinitialisation(grille);
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
							/*printlamatrice(grille);
							printf("\n");
							printf("\n");
							printf("\n");*/
							int m=0;
							while (grille[3*i+k][3*j+l]==0)
							{
								int n=rand()%9 +1;
								/*printf("%d", n);
								printf("\n");*/
								m=m+1;
								if (m==30) break;
								/*printf("%d",test_sous_matrice(grille, 3*i+k, 3*j+l, n));
								printf("%d",test_colonne(grille, 3*i+k, 3*j+l, n));
								printf("%d",test_ligne(grille, 3*i+k, 3*j+l, n));
								printf("\n");*/
								if (test(grille, 3*i+k, 3*j+l, n)==true)
								{
									grille[3*i+k][3*j+l]=n;
								}
							}
						}
					}
				}
			}
		}
	}
}

void grille_de_jeu(int** grille, int difficulty)
/*1=easy, 2=medium, 3=hard*/
{
	if (difficulty==1)
	{
		for (int i=0; i<1; ++i)
		{
			int n=rand()%9 ;
			int m=rand()%9 ;
			while (grille[n][m]==0)
			{
				n=rand()%9 ;
				m=rand()%9 ;
			}
			grille[n][m]=0;
		}
	}
	if (difficulty==2)
	{
		for (int i=0; i<55; ++i)
		{
			int n=rand()%9 ;
			int m=rand()%9 ;
			while (grille[n][m]==0)
			{
				n=rand()%9 ;
				m=rand()%9 ;
			}
			grille[n][m]=0;
		}
	}
	if (difficulty==3)
	{
		for (int i=0; i<65; ++i)
		{
			int n=rand()%9 ;
			int m=rand()%9 ;
			while (grille[n][m]==0)
			{
				n=rand()%9 ;
				m=rand()%9 ;
			}
			grille[n][m]=0;
		}
	}
}

struct resultat{
	bool juste;
	int errorx;
	int errory;
};

struct resultat test_correct(int** grille)
{
	
	for (int i=0; i<9; ++i)
	{
		for (int j=0; j<9; ++j)
		{
			if (test(grille, i, j, grille[i][j])==false)
			{
				struct resultat resultat={false, i+1, j+1};
				return resultat;
			}
		}
	}
	struct resultat resultat={true, 0, 0};
	return resultat;
}

/*int  main(int argc, char const *argv[])
{
	srand(time(NULL));

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
	printf("\n");
	printf("\n");
	grille_de_jeu(grille, 1);
	printlamatrice(grille);
	while (remplie(grille)==false)
	{
		printf("Which case would you like to fill? \n");
		printf("Row\n");
		int x=0;
		scanf("%d", &x);
		printf("Column\n");
		int y=0;
		scanf("%d", &y);
		printf("Enter the number you would like to put");
		int chiffre=0;
		scanf("%d", &chiffre);
		if (chiffre<1 || chiffre>9)
		{
			printf("error\n");
		}
		else
		{
			grille[x][y]=chiffre;
		}
		printlamatrice(grille);
		printf("\n");
		printf("\n");
	}
	printlamatrice(grille);
	printf("\n");
	printf("\n");		
	printf("The grill is filled. Would you like to change a case or would you like to know if it is correct. Enter 1 to change a case, 2 to see if it is correct");
	int choice=0;
	scanf("%d", &choice);
	while (choice==1)
	{
		printf("Which case would you like to change? \n");
		printf("Row\n");
		int x=0;
		scanf("%d", &x);
		printf("Column\n");
		int y=0;
		scanf("%d", &y);
		printf("Enter the number you would like to put");
		int chiffre=0;
		scanf("%d", &chiffre);
		if (chiffre<1 || chiffre>9)
		{
			printf("error\n");
		}
		else
		{
			grille[x][y]=chiffre;
		}
		printlamatrice(grille);
		printf("\n");
		printf("\n");
		printf("Would you like to change a case or would you like to know if it is correct. Enter 1 to change a case, 2 to see if it is correct");
		scanf("%d", &choice);
	}
}*/
