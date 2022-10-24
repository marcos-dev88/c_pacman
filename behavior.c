#include <stdio.h>
#include <stdlib.h>

#include "./game_behavior.h"


int finishGame(){
    return 0;
}

void findPacmanPosition(gameScreen* gs){
    for(int i = 0; i < gs->dimensions.lines; i++){
        for (int c = 0; c < gs->dimensions.columns; c++){
            if(gs->map[i][c] == PACMAN_ICON){
                gs->dimensions.lines = i;
                 gs->dimensions.columns = c;
                break;
            }
        }
    }
}

int isValidMoveKey(char key){
    return key == PACMAN_UP || key == PACMAN_DOWN || key == PACMAN_LEFT ||  key == PACMAN_RIGHT;
}

int isValidLimits(int x, int y, dimension mapD, gameScreen* gs){
    int isValid = 1;

    if(x >= mapD.lines){
        isValid = 0;
    }

    if(y >= mapD.columns){
        isValid = 0;
    }

    if (gs->map[x][y] == WALL_1 || gs->map[x][y] == WALL_2){
        isValid = 0;
    }

    return isValid;
}

void move(char key, gameScreen* gs, dimension mapD){

    if (!isValidMoveKey(key)){
        return;
    }
    
    int moveX = gs->dimensions.lines;
    int moveY = gs->dimensions.columns;

    switch(key){
        case PACMAN_UP: 
            moveX--;
            break;
        case PACMAN_LEFT:
            moveY--;
            break;
        case PACMAN_DOWN:
            moveX++;
            break;
        case PACMAN_RIGHT:
            moveY++;
            break;
    } 
    
   if (!isValidLimits(moveX, moveY, mapD, gs)) {
       return;
   }

    // after the validations, the pacman can move here:
    gs->map[moveX][moveY] = PACMAN_ICON;
    gs->map[gs->dimensions.lines][gs->dimensions.columns] = EMPTY_FIELD;
    gs->dimensions.lines = moveX;
    gs->dimensions.columns = moveY;
}
