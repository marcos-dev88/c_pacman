#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_behavior.h"
#include "map_dimension_funcs.h"


gameScreen gScreen;

int main(){
    dimension d = defineDimension();
    gScreen = genMap(d);
    char directionKey;
    findPacmanPosition(&gScreen);

    do {
        // This loop is to print the map
        for (int i = 0; i < d.lines; i++){
            printf("%s\n", gScreen.map[i]);
        } 

        scanf(" %c", &directionKey); 
        move(directionKey, &gScreen);
        

    }while(!finishGame());
    
    freeMap(&gScreen);

    return 0;
}
