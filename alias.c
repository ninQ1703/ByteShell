#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALIAS_LENGTH 100
#define MAX_COMMAND_LENGTH 200

typedef struct {
    char alias[MAX_ALIAS_LENGTH];
    char command[MAX_COMMAND_LENGTH];
} Alias;

Alias aliases[10]; // Array to hold aliases (up to 10 aliases)
int numAliases = 0; // Number of currently defined aliases

void addAlias(const char* alias, const char* command) {
    if (numAliases >= 10) {
        printf("Maximum number of aliases reached.\n");
        return;
    }

    strcpy(aliases[numAliases].alias, alias);
    strcpy(aliases[numAliases].command, command);
    numAliases++;

    printf("Alias '%s' added. for %s\n", alias, command);
}


int alias(char** args){
    // printf("%s",args[0]);
    if(args[1] == NULL || args[2] == NULL ||args[3] == NULL){
        printf("Invalid Command");
        return 1;
    }
    int len = 0;
    int i = 3;
    while(args[i] != NULL){
        len = len + strlen(args[i]);
        i++;
    }
    char* old_name = "";
    i = 3;
    while(args[i] != NULL){
        old_name = strAppend(old_name, args[i]);
        // printf("%s \n", old_name);
        i++;
    }
    if(strcmp(args[1], "add") == 0) addAlias(args[2], old_name);
    return 1;
}

int executeCommand(const char* command) {
    int i;
    for (i = 0; i < numAliases; i++) {
        if (strcmp(aliases[i].alias, command) == 0) {
            printf("Executing command: %s\n", aliases[i].command);
            system(aliases[i].command);
            return 1;
        }
    }

    return 0;
}
