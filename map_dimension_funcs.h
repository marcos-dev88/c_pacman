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


dimension defineDimension();
gameScreen genMap(dimension d);
