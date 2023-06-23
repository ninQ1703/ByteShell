#include<stdio.h>
#include <stdlib.h>

const int LEN = 1024;

char* read_line(){
    int len = 1024;
    int position = 0;
    char *line = malloc(sizeof(char) *len);
    int c;

    // take characters unless enter is pressed and store in line
    while (1){
        c = getchar();

        if (c == '\n' ){
            line[position] = '\0';
            return line; 
        }
        else{
            line[position] = c;
            position++;
        }
        if (position >= len){
            len += LEN; 
            line = realloc(line, len);
        }
        if (!line){
            fprintf(stderr, "allocation error\n");
            exit(EXIT_FAILURE); 
        }
    }
}