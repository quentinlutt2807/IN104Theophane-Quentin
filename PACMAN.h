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
void initiate_pacman(char area[height][width],struct pacman* pc);
struct ghost{
struct coordinates gho_cord;
int nx;
int ny; 
};

void affichage(char grille[height][width]);
void initialisation(char area[height][width],struct ghost allGhosts[NR_GHOSTS]);
void clavier(struct pacman *pc ,struct ghost allGhosts[NR_GHOSTS],char area[height][width]);
void movepacman(struct pacman *pac,char area[height][width]);
void lives(struct pacman *pac, char area[height][width]);
