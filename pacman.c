#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map_dimension_funcs.h"
#include "map_memory.h"

#define MAP_FILE "./map.txt"

char** map;

int main(){
    int lines = checkMapLines();
    int columns = checkMapColumns();

    genMap(columns, lines);

    for (int i = 0; i < lines; i++){
        printf("%s\n", map[i]);
    }

    freeMap(lines);

    return 0;
}


// freeMap: free memory allocated in map
void freeMap(int lines){
    for(int i = 0; i < lines; i++){
        free(map[i]);
    }
    free(map);
}


// genMap: Allocs memory to vector map and write from file.
void genMap(int columns, int lines){
    FILE *f;

    map = malloc(lines * sizeof(char*));
    for (int i = 0; i < lines; i++){
        map[i] = malloc((columns+1) * sizeof(char));
    }

    f = fopen(MAP_FILE, "r");
    if (f == NULL) {
        printf("file doesn't exist");
        exit(1);
    }

    for (int i = 0; i < lines; i++){
        fscanf(f, "%s", map[i]);
    }

    fclose(f);
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

