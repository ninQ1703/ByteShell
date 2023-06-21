#include <stdio.h>
#include <stdlib.h>
#include "cd.c"
#include "launch.c"
#include "history.c"
#include "exits.c"
#include "alias.c"
#include "help.c"
#include <string.h>

typedef int (*BuiltinFunction)(char**);
BuiltinFunction builtins_func[] = {
    &cd,
    &display_history,
    &help,
    &exits,
    &alias
};

int execute(char **args){
    if(args[0] == NULL){
        return 1;
    }
    int i;
    int aliased = executeCommand(args[0]);
    if(aliased) return 1;
    
    for(i = 0; i < 5 ; i++){
        if(strcmp(args[0], builtins[i]) == 0){
            return (*builtins_func[i])(args);
        }
    }
    return launch(args);
}