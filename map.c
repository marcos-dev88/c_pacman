#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./map_dimension_funcs.h"

// freeMap: free memory allocated in map
void freeMap(gameScreen* gs){
    for(int i = 0; i < gs->dimensions.lines; i++){
        free(gs->map[i]);
    }
    free(gs->map);
}

dimension defineDimension(){
    int lines = checkMapLines();
    int columns = checkMapColumns();
    dimension d;

    d.lines = lines;
    d.columns = columns;

    return d;
}

// genMap: Allocs memory to vector map and write from file.
gameScreen genMap(dimension d){
    FILE *f;
    gameScreen gs;

    char **map = malloc(d.lines * sizeof(char*));
    for (int i = 0; i < d.lines; i++){
        map[i] = malloc((d.columns+1) * sizeof(char));
    }

    f = fopen(MAP_FILE, "r");
    if (f == NULL) {
        printf("file doesn't exist");
        exit(1);
    }

    for (int i = 0; i < d.lines; i++){
        fscanf(f, "%s", map[i]);
        genEmptyFields(i, map);
    }

    gs.map = map;
    gs.dimensions = d;
    fclose(f);
    return gs;
}

void genEmptyFields(int line, char** map){
    for (int c = 0; c < strlen(map[line]); c++){
        if(map[line][c] == SUBSTITUTION_EMPTY_FIELD){
            map[line][c] = EMPTY_FIELD;
        }
    }
}

// checkMapColumns: This function returns the map's width.
int checkMapColumns(){
    FILE *f;
    char ( *columnsChar ) = malloc(6000 * sizeof(char));
    int columns;

    f = fopen(MAP_FILE, "r");

    if (f == NULL){
        printf("error: file not found");
        exit(1);
    }
    
    fscanf(f, "%s", columnsChar); // This scan the first line and get all columns that map has 
    columns = strlen(columnsChar);
    columnsChar = realloc(columnsChar, columns);
    free(columnsChar);
    
    fseek(f, 0, SEEK_SET); // pointing the file in first position (like first line)
    fprintf(f, "%s", columnsChar); //writing the columnsChar that we have "removed" from stack to read it b4

    fclose(f);
    return columns;
}

// checkMapLines: This function returns the map's heigth.
int checkMapLines(){
    FILE *f;
    int lines = 0;
    char fileChar;

    f = fopen(MAP_FILE, "r");

    if (f == NULL) {
        printf("file doesn't exist");
        exit(1);
    }

    while(fileChar != EOF){
        fileChar = fgetc(f);
        if(fileChar == '\n'){
            lines++;
        }
    }

    fclose(f);

    return lines;
}

