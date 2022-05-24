#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "morpion.h"
#include "SUDOKU.h"
#include "PACMAN.h"

int main()
{
	int x=0;
	while (x!=4)
	{
	/*system("clear");*/
	printf("Quel jeu voulez-vous jouer? Tapez 1 pour Sudoku, 2 pour morpion, 3 pour Pacman, 4 pour quitter.\n");
	printf("\n");
	scanf("%d", &x);
	system("clear");
	if (x==1)
	{
		int difficulte=0;
		printf("Quel niveau de difficulté voulez-vous jouer? Tapez 1 pour facile, 2 pour moyen, 3 pour difficile\n");
		printf("\n");
		scanf("%d", &difficulte);
		system("clear");
		srand(time(NULL));

		int **grille=calloc(9,sizeof(int*));
		for (int i=0; i<9; ++i)
		{
			int* ligne=calloc(9,sizeof(int));
			grille[i]=ligne;
		}
		remplirdiag(grille);
		remplir_tout(grille);
		grille_de_jeu(grille, difficulte);
		printlamatrice(grille);
		printf("\n");
		while (remplie(grille)==false)
		{
			printf("Which case would you like to fill? \n");
			printf("Row\n");
			printf("\n");
			int x=0;
			scanf("%d", &x);
			printf("Column\n");
			printf("\n");
			int y=0;
			scanf("%d", &y);
			printf("Enter the number you would like to put\n");
			int chiffre=0;
			printf("\n");
			scanf("%d", &chiffre);
			system("clear");
			if (chiffre<1 || chiffre>9)
			{
				printf("error\n");
			}
			else
			{
				grille[x-1][y-1]=chiffre;
			}
			printlamatrice(grille);
			printf("\n");
		}
		
		int choice1=1;
		int k=1;
		while (choice1==1)
		{
			if (k==1)
			{
				printlamatrice(grille);
				printf("\n");
				printf("The grill is filled. Would you like to change a case or would you like to know if it is correct. Enter 1 to change a case, 2 to see if it is correct\n");
				printf("\n");
				scanf("%d", &choice1);
			}
			if (choice1==1)
			{
				k=1;
				printlamatrice(grille);
				printf("\n");
				printf("Which case would you like to change? \n");
				printf("Row\n");
				printf("\n");
				int x=0;
				scanf("%d", &x);
				printf("Column\n");
				printf("\n");
				int y=0;
				scanf("%d", &y);
				printf("Enter the number you would like to put\n");
				printf("\n");
				int chiffre=0;
				scanf("%d", &chiffre);
				system("clear");
				if (chiffre<1 || chiffre>9)
				{
					printf("error\n");
				}
				else
				{
					grille[x-1][y-1]=chiffre;
				}
			}
			if (choice1==2)
			{
				k=2;
				struct resultat resultat=test_correct(grille);
				if (resultat.juste==true)
				{
					printf("Well done! The grill is correct\n");
					printf("\n");
					choice1=2;
				}
				else
				{
					printf("There is an error row %d, column %d.\n", resultat.errorx, resultat.errory);
					printf("Would you like to change a case? Enter 1 to change a case.\n");
					scanf("%d", &choice1);
				}
			}
		}
	}
	if (x==2)
	{
		srand(time(0));
		int* grille=creer_grille();
		printf("Les cases sont indexées par des chiffres de 1 à 9.\n");
		printf("\n");
		int jeu_fini=0;
		int compte_tour=0;
		while (jeu_fini==0)
		{
			afficher(grille);
			printf("\n");
			printf("Quelle case voulez-vous jouer?\n");
			printf("\n");
			int chiffre=0;
			scanf("%d", &chiffre);
			while (grille[chiffre-1]!=0)
			{
				printf("Cette case est déjà occupée. Sélectionnez une autre case où jouer\n");
				printf("\n");
				scanf("%d", &chiffre);
			}
			placer(grille, chiffre, 1);
			system("clear");
			if (a_gagne(grille, 1)==1)
			{
				printf("Vous avez gagné!\n");
				jeu_fini=1;
			}
			compte_tour=compte_tour+1;
			if (compte_tour==9 && jeu_fini==0)
			{
				jeu_fini=1;
				printf("Match nul.\n");
			}
			if (compte_tour!=9)
			{
				placer_alea(grille, 2);
			}
			if (a_gagne(grille, 2)==1 && jeu_fini==0)
			{
				printf("L'adversaire a gagné\n");
				jeu_fini=1;
			}
			compte_tour=compte_tour+1;
		}
		free(grille);
	}
	if (x==3)
	{
		srand(time(NULL));
		struct ghost allGhosts[NR_GHOSTS];
		struct pacman* pac=malloc(sizeof(struct pacman));
		//pacman pas encore initialisé
		char area [height][width]={
   		{ "############################################################" },
   		{ "#                                                          #" },
   		{ "#                                                          #" },
   		{ "#        # # # # #          #             # # # # # #      #" },
   		{ "#        #       #         # #            #                #" },
   		{ "#        #       #        #   #           #                #" },
   		{ "#        # # # # #       #     #          #                #" },
   		{ "#        #              # # # # #         #                #" },
   		{ "#        #             #         #        #                #" },
   		{ "#        #            #           #       #                #" },
   		{ "#        #           #             #      #                #" },
   		{ "#        #          #               #     # # # # # #      #" },
   		{ "#                                                          #" },
   		{ "#                                                          #" },
   		{ "#                                                          #" },
   		{ "#        ##        ##           #          ##        #     #" },
   		{ "#        # #      # #          # #         # #       #     #" },
   		{ "#        #  #    #  #         #   #        #  #      #     #" },
   		{ "#        #    # #   #        #     #       #   #     #     #" },
   		{ "#        #     #    #       # # # # #      #    #    #     #" },
   		{ "#        #          #      #         #     #     #   #     #" },
   		{ "#        #          #     #           #    #      #  #     #" },
   		{ "#        #          #    #             #   #       # #     #" },
   		{ "#        #          #   #               #  #        ##     #" },
   		{ "#                                                          #" },
   		{ "#                                                          #" },
   		{ "#                                                          #" },
   		{ "#                                                          #" },
   		{ "#                                                          #" },
   		{ "############################################################" }
		};

		initialisation( area,  allGhosts);
		initiate_pacman(area, pac);
		affichage(area);
		while (pac->lives>=1){
			clavier(pac,allGhosts,area);
			movepacman(pac,area);
		lives(pac, area);
		}
	}
	}
	return 0;
}
