#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_alias.c"

const char LEN = 1024;

char** split_line(char *line){
    int len = 1024, position = 0;
    char **tokens = malloc(len * sizeof(char*));
    char *token = strtok(line, " ");
    char *expLine = "";
    char *fromAlias, *str = " ";
    if(!tokens){
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    // get aliased commands
    while(token != NULL){
        fromAlias = getCommand(token);
        expLine = strAppend(expLine, fromAlias);        
        expLine = strAppend(expLine, str);        
        token = strtok(NULL, " ");
    }
    token = strtok(expLine, " ");

    //get tokens fron command
    while(token != NULL){
        tokens[position] = token;
        position++;
        if(position >= len){
            len += LEN;
            tokens = realloc(tokens, len * sizeof(char *));
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