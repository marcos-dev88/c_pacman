#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map_dimension_funcs.h"

#define MAP_FILE "./map.txt"

int main(){

    FILE *f;
    int lines = checkMapLines();
    int columns = checkMapColumns();

    f = fopen(MAP_FILE, "r");

    char map[lines][columns+1];

    for (int i = 0; i < lines; i++){
        fscanf(f, "%s", map[i]);
    }

    for (int i = 0; i < lines; i++){
        printf("%s\n", map[i]);
    }

    fclose(f);

    return 0;
}

// checkMapColumns: This function returns the map's width.
int checkMapColumns(){
    FILE *f;
    char ( *columnsChar ) = malloc( 6000 * sizeof( char ) );
    int columns;

    f = fopen(MAP_FILE, "r");

    if (f == NULL){
        printf("error: file not found");
        return 1;
    }
    
    fscanf(f, "%s", columnsChar); // This scan the first line and get all columns that map has 
    columns = strlen(columnsChar);
    columnsChar = realloc(columnsChar, columns);
    
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

    while(fileChar != EOF){
        fileChar = fgetc(f);
        if(fileChar == '\n'){
            lines++;
        }
    }

    fclose(f);

    return lines;
}

