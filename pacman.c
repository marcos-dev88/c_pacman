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
    /* findGhostsPosition(&gScreenGhost); */

    do {

        // This loop is to print the map
        system("clear");
        printf("\n\n\n");
        for (int i = 0; i < d.lines; i++){
            printf("\t\t\t\t%s\n", gScreenPacman.map[i]);
        } 

        scanf(" %c", &directionKey); 
        ghosts(&gScreenGhost, d);
        movePacman(directionKey, &gScreenPacman, d); 

    }while(!finishGame());
    
    freeMap(&gScreenPacman);

    return 0;
}
