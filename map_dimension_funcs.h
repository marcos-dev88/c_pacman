int checkMapLines();
int checkMapColumns();

typedef struct dimension {
    int lines;
    int columns;
} dimension;

typedef struct gameScreen {
    dimension dimensions;
    char **map; 
} gameScreen;

typedef struct direction {
    int x;
    int y;
} direction;


void move(char key, gameScreen* gs);
dimension defineDimension();
gameScreen genMap(dimension d);
void findPacmanPosition(gameScreen* gs);
void freeMap(gameScreen* gs);
int finishGame();
