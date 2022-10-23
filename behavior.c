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

int isValidMoveKey(char key){
    return key == 'w' || key == 'a' || key == 's' ||  key == 'd';
}

int isValidLimits(int x, int y, dimension mapD, gameScreen* gs){
    int isValid = 1;

    if(x >= mapD.lines){
        isValid = 0;
    }

    if(y >= mapD.columns){
        isValid = 0;
    }

    if (gs->map[x][y] == '|' || gs->map[x][y] == '-'){
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
        case 'w': 
            moveX--;
            break;
        case 'a':
            moveY--;
            break;
        case 's':
            moveX++;
            break;
        case 'd':
            moveY++;
            break;
    } 
    
   if (!isValidLimits(moveX, moveY, mapD, gs)) {
       return;
   }

    // after the validations, the pacman can move here:
    gs->map[moveX][moveY] = '@';
    gs->map[gs->dimensions.lines][gs->dimensions.columns] = ' ';
    gs->dimensions.lines = moveX;
    gs->dimensions.columns = moveY;
}
