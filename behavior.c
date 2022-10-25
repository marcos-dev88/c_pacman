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

void findGhostsPosition(gameScreen* gs, dimension mapD){
    for(int i = 0; i < gs->dimensions.lines; i++){
        for (int c = 0; c < gs->dimensions.columns; c++){
            if(gs->map[i][c] == GHOST_ICON){
                gs->dimensions.lines = i;
                gs->dimensions.columns = c;
                moveGhosts(gs, mapD);
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

    if (gs->map[x][y] == WALL_1 || gs->map[x][y] == WALL_2 || gs->map[x][y] == GHOST_ICON){
        isValid = 0;
    }

    return isValid;
}

void ghosts(gameScreen* gs, dimension mapD){
    findGhostsPosition(gs, mapD);
}

void movePacman(char key, gameScreen* gs, dimension mapD){

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

void moveGhosts(gameScreen* gs, dimension mapD){

    int moveX = gs->dimensions.lines;
    int moveY = gs->dimensions.columns+1;

    if (!isValidLimits(moveX, moveY, mapD, gs)) {
       return;
    }

    // after the validations, the ghost can move here:
    gs->map[moveX][moveY] = GHOST_ICON;
    gs->map[gs->dimensions.lines][gs->dimensions.columns] = checkLastField(gs->dimensions.lines, gs->dimensions.columns, gs->map);
    gs->dimensions.lines = moveX;
    gs->dimensions.columns = moveY;    
}

char checkLastField(int x, int y, char** map){
    return map[x][y] == CHEESE_BALL ? CHEESE_BALL : EMPTY_FIELD;
}

