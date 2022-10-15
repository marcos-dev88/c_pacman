int checkMapLines();
int checkMapColumns();

typedef struct dimension {
    int lines;
    int columns;
} dimension;


dimension defineDimension();
void genMap(dimension d);
