#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alias.c"

char** split_line(char *line){
    int bufsize = 1024, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(line, " ");
    char *expLine = "";
    char *fromAlias, *str = " ";
    if(!tokens){
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }
    while(token != NULL){
        fromAlias = getCommand(token);
        expLine = strAppend(expLine, fromAlias);        
        expLine = strAppend(expLine, str);        
        token = strtok(NULL, " ");
    }
    token = strtok(expLine, " ");
    while(token != NULL){
        tokens[position] = token;
        position++;
        if(position >= bufsize){
            bufsize += bufsize;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if(!tokens){
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }
    tokens[position] = NULL;
    return tokens;
}