#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Append.c"

struct Alias{
    char* alias;
    char* command;
    struct Alias* next;
    
};

struct Alias* alias_head = NULL;
struct Alias* alias_cur = NULL;

void addAlias(const char* alias, const char* command) {

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
    if(args[1] == NULL || args[2] == NULL ||args[3] == NULL){
        printf("Invalid Command");
        return 1;
    }
    int len = 0;
    char* old_name = "", *str1 = " ";
    int i = 3;
    while(args[i+1] != NULL){
        len = len + strlen(args[i]);
        i++;
    }
    len = len + strlen(args[i]);
    i = 3;
    old_name = (char*)malloc(sizeof(char*)*len);
    while(args[i+1] != NULL){
        strcpy(old_name,strAppend(old_name, args[i]));
        strcpy(old_name, strAppend(old_name,str1));
        i++;
    }
    strcpy(old_name,strAppend(old_name, args[i]));
    if(strcmp(args[1], "add") == 0){
        addAlias(args[2], old_name);
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
