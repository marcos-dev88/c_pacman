#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_behavior.h"
#include "map_dimension_funcs.h"


gameScreen gScreenPacman;
gameScreen gScreenGhost;

int main(){
    dimension d = defineDimension();
    gScreenPacman = genMap(d);

    gScreenGhost = gScreenPacman;
    char directionKey;
    findPacmanPosition(&gScreenPacman);

    do {

        // This loop is to print the map
        system("clear");
        printf("\n\n\n");
        for (int i = 0; i < d.lines; i++){
            printf("\t\t\t\t%s\n", gScreenPacman.map[i]);
        } 

        scanf(" %c", &directionKey);
        movePacman(directionKey, &gScreenPacman, d); 
        ghosts(&gScreenPacman, d);

    }while(!finishGame());
    
    freeMap(&gScreenPacman);
    freeMap(&gScreenGhost);

    return 0;
}
