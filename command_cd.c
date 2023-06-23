#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int cd(char **args){
    if(args[1] == NULL){
        fprintf(stderr, "Expected argument to \"cd\" \n");
    }else{
        if(chdir(args[1]) != 0){
            perror("ByteShell");
        }
    }
    return 1;
}