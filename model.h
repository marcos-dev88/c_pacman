#ifndef DIMENSION
#define DIMENSION
typedef struct dimension {
    int lines;
    int columns;
} dimension;
#endif

#ifndef GAMESCREEN
#define GAMESCREEN
typedef struct gameScreen {
    dimension dimensions;
    char **map; 
} gameScreen;
#endif

#ifndef DIRECTION
#define DIRECTION
typedef struct direction {
    int x;
    int y;
} direction;
#endif
