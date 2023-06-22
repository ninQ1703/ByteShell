#include<stdio.h>
#include <stdlib.h>

const int BUF_SIZE = 1024;

char* read_line(){
    int bufsize = 1024;
    int position = 0;
    char *buffer = malloc(sizeof(char) *bufsize);
    int c;

    if(!buffer){
        fprintf(stderr, "Allocation error");
        exit(EXIT_FAILURE);
    }
    while (1){
        c = getchar();
        if (c == '\n' ){
            buffer[position] = '\0';
            return buffer; 
        }
        else{
            buffer[position] = c;
            position++;
        }
        if (position >= bufsize){
            bufsize += BUF_SIZE; 
            buffer = realloc(buffer, bufsize);
        }
        if (!buffer){
            fprintf(stderr, "allocation error\n");
            exit(EXIT_FAILURE); 
        }
    }
}