
#define MAP_FILE "./map.txt"

// pacman moves
#define PACMAN_UP 'w'
#define PACMAN_DOWN 's'
#define PACMAN_LEFT 'a'
#define PACMAN_RIGHT 'd'

#define PACMAN_ICON '@'
#define GHOST_ICON '*'
#define EMPTY_FIELD ' '
#define CHEESE_BALL '.'
#define SUBSTITUTION_EMPTY_FIELD ','

//walls
#define WALL_1 '|'
#define WALL_2 '-'

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
