#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkMapLines(){
    FILE *f;
    int lines = 0;
    char fileChar;

    f = fopen("./map.txt", "r");

    while(fileChar != EOF){
        fileChar = fgetc(f);
        if(fileChar == '\n'){
            lines++;
        }
    }

    fclose(f);

    return lines;
}


int main(){
    FILE *f;
    char ( *columnsChar ) = malloc( 6000 * sizeof( char ) );

    int lines = checkMapLines();

    f = fopen("./map.txt", "r");

    if (f == NULL){
        printf("error: file not found");
        return 1;
    }
    
    fscanf(f, "%s", columnsChar); // This scan the first line and get all columns that map has
                                  
    int columns = strlen(columnsChar);

    columnsChar = realloc(columnsChar, columns);
    
    // TODO: create a function to do this
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%s", columnsChar);

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


