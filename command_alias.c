#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringAppend.c"
#include "command_unalias.c"


void addAlias(char** args) {
    int len = 0;
    char *str1 = " ";
    int i = 2;

    while(args[i+1] != NULL){
        len = len + strlen(args[i]);
        i++;
    }
    
    len = len + strlen(args[i]);
    i = 2;
    
    char* command = (char*)malloc(sizeof(char*)*len);
    char *alias = (char *)malloc(sizeof(char*)*strlen(args[2]));
    
    while(args[i+1] != NULL){
        strcpy(command,strAppend(command, args[i]));
        strcpy(command, strAppend(command,str1));
        i++;
    }

    strcpy(command,strAppend(command, args[i]));
    strcpy(alias, args[1]);

    struct Alias *ptr = alias_head;
    while(ptr!= NULL){
        if(strcmp(ptr->command, command) == 0){
            printf("Alias '%s' added for %s\n", alias, command);
            strcpy(ptr->alias, alias);
            return;
        }
        ptr = ptr->next;
    }

    if(alias_head == NULL){
        alias_head = (struct Alias *)malloc(sizeof(struct Alias));
        alias_head->alias = (char *)malloc(sizeof(char*)*strlen(alias));
        alias_head->command = (char *)malloc(sizeof(char*)*strlen(command));
        strcpy(alias_head->alias, alias);
        strcpy(alias_head->command, command);
        alias_head->next = NULL;
        alias_cur = alias_head;
    }else{
        struct Alias *ptr = (struct Alias *)malloc(sizeof(struct Alias));
        alias_cur->next = ptr;
        ptr->alias = (char *)malloc(sizeof(char*)*strlen(alias));
        ptr->command = (char *)malloc(sizeof(char*)*strlen(command));
        strcpy(ptr->alias, alias);
        strcpy(ptr->command, command);
        ptr->next = NULL;
        alias_cur = ptr;
    }

    printf("Alias '%s' added for %s\n", alias, command);
}


int alias(char** args){

    if(strcmp(args[0], "alias") == 0){
        if(args[1] == NULL || args[2] == NULL){
            printf("Expected command to \"alias\" \n");
            return 1;
        }
        addAlias(args);
    }

    if(strcmp(args[0], "unalias") == 0){
        if(args[1] == NULL){
            printf("Expected command to \"unalias\" \n");
            return 1;
        }
        deleteAlias(args);
    }
    return 1;
}

char* getCommand(char* command) {

    struct Alias* ptr = alias_head;
    while(ptr != NULL){
        if (strcmp(ptr->alias, command) == 0) {
            return ptr->command;
        }
        ptr = ptr->next;
    }
    return command;

}
