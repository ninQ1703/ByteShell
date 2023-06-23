#include <stdio.h>
#include <stdlib.h>
#include "command_cd.c"
#include "launch.c"
#include "command_history.c"
#include "command_exit.c"
#include "command_help.c"
#include <string.h>

typedef int (*BuiltinFunction)(char**);
BuiltinFunction builtins_func[] = {
    &cd,
    &display_history,
    &help,
    &exits,
    &alias,
    &alias
};

int execute(char **args){
    if(args[0] == NULL){
        return 1;
    }
    int i;
    
    for(i = 0; i < 6 ; i++){
        if(strcmp(args[0], builtins[i]) == 0){
            return (*builtins_func[i])(args);
        }
    }
    return launch(args);
}