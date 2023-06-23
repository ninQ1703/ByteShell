#include "parse.c"
#include "read.c"
#include "execute.c"

void loop(){
    char *line;
    char **args;
    int status;

    do{
        printf("nikki/Byteshell$ ");

        // takes command from user
        line = read_line();

        //adds command to history
        add_to_hist(line);

        //parse the commands to word
        args = split_line(line);

        //execute the command
        status = execute(args);
    }while (status);
    
}