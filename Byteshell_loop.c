#include "parse.c"
#include "read.c"
#include "execute.c"

void loop(){
    char *line;
    char **args;
    int status;

    do{
        printf("nikki/Byteshell$ ");
        line = read_line();
        add_to_hist(line);
        args = split_line(line);
        status = execute(args);
    }while (status);
    
}