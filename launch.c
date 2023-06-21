#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int launch(char **args){
    pid_t pid;
    int status;
    pid = fork();
    if(pid == 0){
        if(execvp(args[0], args) == -1){
            perror("ByteShellkk");
        }
        exit(EXIT_FAILURE);
    }else{
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));   
    }
    return 1;
}