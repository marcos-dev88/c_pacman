#include "./model.h"

int isValidMoveKey(char key);
int isValidLimits(int x, int y, dimension mapD, gameScreen* gs);
void movePacman(char key, gameScreen* gs, dimension mapDimensions);
int finishGame();
void findPacmanPosition(gameScreen* gs);
void findGhostsPosition(gameScreen* gs, dimension mapD);
void ghosts(gameScreen* gs, dimension mapD);
void moveGhosts(gameScreen* gs, dimension mapD, int x, int y);
char checkLastField(int x, int y, char** map);
void copyGs(gameScreen* fromGs, gameScreen* toGs);
