#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define height 30
#define width 60
#define NR_GHOSTS 10


struct coordinates {
int cordx;
int cordy;
};

struct pacman {
struct coordinates pac_cord;
int nx;
int ny;
int lives;
int food;
};
void initiate_pacman(char area[height][width],struct pacman* pc){
	struct coordinates coord={1,1};
             pc->pac_cord=coord;
             pc->nx= 0;
             pc->ny= 0;
             pc->lives= 2;
             pc->food=0;
             
             area[1][1]='P';       
}	

struct ghost{
struct coordinates gho_cord;
int nx;
int ny; 
};

void affichage(char grille[height][width]){
	for(int i=0;i<30;++i){
		for(int j=0;j<60;++j){
			if(grille[i][j]=='F'){ 
				printf("%c",'G');
			}
			else{	
			printf("%c" , grille[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");		
}		
void initialisation(char area[height][width],struct ghost allGhosts[NR_GHOSTS]){

		for (int i=0; i<NR_GHOSTS;i++){
			int randh=(rand() % height);
			int randw=(rand() % width);
			while (area[randh][randw]=='#' || (randh==1 && randw==1 )){
				randh=(rand() % height);
			 	randw=(rand() % width);

		
		}
		
		allGhosts[i].gho_cord.cordx=randh;
		allGhosts[i].gho_cord.cordy=randw;
		area[allGhosts[i].gho_cord.cordx][allGhosts[i].gho_cord.cordy]='G';


		//IL peut y avoir 2 fantomme dans la meme case
}
		for (int k=1; k<height;k++){
			for (int l=1; l<width;l++){
				if (area[k][l]!='#' && area[k][l]!='G'){
					area[k][l]='.';
				}
			}	
		

		}
		area[1][1]=' ';
		//Les points ne sont pas des structures en supprimer un ne change rien au programme

}


void clavier(struct pacman *pc ,struct ghost allGhosts[NR_GHOSTS],char area[height][width]){

printf("appuyer sur z ou q ou s ou d: \n  ");
char c;
scanf("%c",&c);
while(getchar()!='\n');
system("clear");

if(c=='z'){ //z
	pc->nx=-1;
	pc->ny=0;
}
else if(c=='q'){ 
	pc->nx=0;
	pc->ny=-1;
}
else if(c=='s'){ 
	pc->nx=1;
	pc->ny=0;
}
else if(c=='d'){ 
	pc->nx=0;
	pc->ny=1;

}
else {
pc->nx=2; // pas de mouvement

}
for (int i=0;i<NR_GHOSTS;i++){

	int destination=rand() % 4;
	//oupacman a rajoutter
	
	if (destination==0){
		allGhosts[i].nx=1;
		allGhosts[i].ny=0;
	}

	else if (destination==1){
		allGhosts[i].nx=-1;
		allGhosts[i].ny=0;
				}

	else if (destination==2){
		allGhosts[i].nx=0;
		allGhosts[i].ny=1;
			
	}
	else if (destination==3){
		allGhosts[i].nx=0;
		allGhosts[i].ny=-1;
	}
	
	while (area[allGhosts[i].gho_cord.cordx+allGhosts[i].nx][allGhosts[i].gho_cord.cordy+allGhosts[i].ny]=='#')
	{
		int destination=rand() % 4;
	
		if (destination==0){
			allGhosts[i].nx=1;
			allGhosts[i].ny=0;
		}

		else if (destination==1){
			allGhosts[i].nx=-1;
			allGhosts[i].ny=0;
				}

		else if (destination==2){
			allGhosts[i].nx=0;
			allGhosts[i].ny=1;
			
		}
		else if (destination==3){
			allGhosts[i].nx=0;
			allGhosts[i].ny=-1;
		}
	}

	if (area[allGhosts[i].gho_cord.cordx][allGhosts[i].gho_cord.cordy]=='J'){
		area[allGhosts[i].gho_cord.cordx][allGhosts[i].gho_cord.cordy]='.';

	}
	if (area[allGhosts[i].gho_cord.cordx][allGhosts[i].gho_cord.cordy]=='G'){
		area[allGhosts[i].gho_cord.cordx][allGhosts[i].gho_cord.cordy]=' ';
	}

		
	
	if (area[allGhosts[i].gho_cord.cordx+allGhosts[i].nx][allGhosts[i].gho_cord.cordy+allGhosts[i].ny]=='.'){
		area[allGhosts[i].gho_cord.cordx+allGhosts[i].nx][allGhosts[i].gho_cord.cordy+allGhosts[i].ny]='J';
	}
	if (area[allGhosts[i].gho_cord.cordx+allGhosts[i].nx][allGhosts[i].gho_cord.cordy+allGhosts[i].ny]==' '){
		area[allGhosts[i].gho_cord.cordx+allGhosts[i].nx][allGhosts[i].gho_cord.cordy+allGhosts[i].ny]='G';
	}
	
	allGhosts[i].gho_cord.cordx=allGhosts[i].gho_cord.cordx+allGhosts[i].nx;
	allGhosts[i].gho_cord.cordy=allGhosts[i].gho_cord.cordy+allGhosts[i].ny;

}
}

void movepacman(struct pacman *pac,char area[height][width]){
if (pac->nx==2)
{// si aucun deplacement}
}
else{

	struct coordinates anciennecord_pac = pac->pac_cord;
	
	int nouvelle_cordx=(anciennecord_pac).cordx + pac->nx;
		int nouvelle_cordy=(anciennecord_pac).cordy + pac->ny;
		

	if (area[(anciennecord_pac).cordx][(anciennecord_pac).cordy] =='G'){ 
		pac->lives=pac->lives-1;
		nouvelle_cordx=1;
		nouvelle_cordy=1;
	}
	
	else if (area[nouvelle_cordx][nouvelle_cordy]=='G'){ 
		pac->lives=pac->lives-1;
		nouvelle_cordx=1;
		nouvelle_cordy=1;
	}
	
	else if (area[nouvelle_cordx][nouvelle_cordy]=='J'){ 
		pac->lives=pac->lives-1;
		nouvelle_cordx=1;
		nouvelle_cordy=1;
	}
	
	else if (area[nouvelle_cordx][nouvelle_cordy]=='#'){ 
		pac->lives=pac->lives-1;
		nouvelle_cordx=1;
		nouvelle_cordy=1;
	}
	
	struct coordinates nouvellecord_pac={nouvelle_cordx,nouvelle_cordy};
	
	(pac)->pac_cord=nouvellecord_pac;

	if (area[nouvelle_cordx][nouvelle_cordy]=='.')
	{ // si le pacman arrive sur un emplacement food
		(pac)->food=(pac)->food +1; 
	}
	area[nouvelle_cordx][nouvelle_cordy]='P';
	area[anciennecord_pac.cordx][anciennecord_pac.cordy]=' ';



	}
}

void lives(struct pacman *pac, char area[height][width])
{
	if (pac->lives<=0)
	{
		printf("Your score: %d.\n", pac->food);
	}
	else
	{
		affichage(area);
	}
}


/*int  main(int argc, char const *argv[])
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


return 0;
}*/
