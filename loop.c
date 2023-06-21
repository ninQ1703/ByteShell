#include "parse.c"
#include "read.c"
#include "execute.c"

void loop(){
    char *line;
    char **args;
    int status;

    do{
        printf(">");
        line = read_line();
        // printf("%s", line);
        args = split_line(line);
        // add_to_hist(args);
        status = execute(args);
    }while (status);
    
}