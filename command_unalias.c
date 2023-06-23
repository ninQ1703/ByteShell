#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <command_alias.c>

struct Alias{
    char* alias;
    char* command;
    struct Alias* next;
    
};

struct Alias* alias_head = NULL;
struct Alias* alias_cur = NULL;

void deleteAlias(char** args){
    int len = 0;
    char *str1 = " ";
    int i = 1;

    while(args[i+1] != NULL){
        len = len + strlen(args[i]);
        i++;
    }
    
    len = len + strlen(args[i]);
    i = 1;
    
    char* command = (char*)malloc(sizeof(char*)*len);
    
    while(args[i+1] != NULL){
        strcpy(command,strAppend(command, args[i]));
        strcpy(command, strAppend(command,str1));
        i++;
    }

    strcpy(command,strAppend(command, args[i]));
    struct Alias* ptr = alias_head;
    if(alias_head == NULL){
        printf("Alias \"%s\" does not exist \n", command);
        return;
    }
    if(strcmp(alias_head->command,command) == 0){
        printf("Alias \"%s\" has been deleted \n", alias_head->alias);
        alias_head = alias_head->next;
        return;
    }
    while(ptr->next != NULL){
        if(strcmp(ptr->next->command, command) == 0){
            printf("Alias \"%s\" has been deleted \n", ptr->next->alias);
            ptr->next = ptr->next->next;
            if(ptr->next == NULL){
                alias_cur = ptr;
            }
            return;
        }
        ptr = ptr->next;
    }

    printf("Alias \"%s\" does not exist \n", command);
}