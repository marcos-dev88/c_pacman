#include <stdio.h>
#include <stdlib.h>

#include "./game_behavior.h"


int finishGame(){
    return 0;
}

void findPacmanPosition(gameScreen* gs){
    for(int i = 0; i < gs->dimensions.lines; i++){
        for (int c = 0; c < gs->dimensions.columns; c++){
            if(gs->map[i][c] == '@'){
                gs->dimensions.lines = i;
                 gs->dimensions.columns = c;
                break;
            }
        }
    }
}

void move(char key, gameScreen* gs){    
    gs->map[gs->dimensions.lines][gs->dimensions.columns] = '.';

    switch(key){
        case 'w': 
            gs->map[gs->dimensions.lines-1][gs->dimensions.columns] = '@';    
            gs->dimensions.lines--;
            break;
        case 'a':
            gs->map[gs->dimensions.lines][gs->dimensions.columns-1] = '@';    
            gs->dimensions.columns--;
            break;
        case 's':
            gs->map[gs->dimensions.lines+1][gs->dimensions.columns] = '@';    
            gs->dimensions.lines++;
            break;
        case 'd':
            gs->map[gs->dimensions.lines][gs->dimensions.columns+1] = '@';    
            gs->dimensions.columns++;
            break;
    } 
}
