#include "./model.h"

int checkMapLines();
int checkMapColumns();

dimension defineDimension();
void genEmptyFields(int line, char** map);
gameScreen genMap(dimension d);
void freeMap(gameScreen* gs);

