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

void move(char key, gameScreen* gs, dimension mapD){
    if(key != 'w' && key != 'a' && key != 's' &&  key != 'd'){
        return;
    }

    int nextX = gs->dimensions.lines;
    int nextY = gs->dimensions.columns;

    switch(key){
        case 'w': 
            nextX--;
            break;
        case 'a':
            nextY--;
            break;
        case 's':
            nextX++;
            break;
        case 'd':
            nextY++;
            break;
    } 
    
    if(nextX >= mapD.lines){
        return;
    }

    if(nextY >= mapD.columns){
        return;
    }

    if (gs->map[nextX][nextY] == '|' || gs->map[nextX][nextY] == '-'){
        return;
    }

    gs->map[nextX][nextY] = '@';
    gs->map[gs->dimensions.lines][gs->dimensions.columns] = ' ';
    gs->dimensions.lines = nextX;
    gs->dimensions.columns = nextY;
}
