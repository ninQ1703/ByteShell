#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char *str;
    struct Node* next;    
};

struct Node* head = NULL;
struct Node* cur = NULL;

int display_history(char **args){
    struct Node* ptr = head;
    int i = 1;
    while(ptr != NULL){
        printf(" %d %s\n", i++,ptr->str);
        ptr = ptr->next;
    }
    return 1;
}

void add_to_hist(const char *command){
    char* temp = (char *)malloc(strlen(command));
    strcpy(temp, command);
    char* temp_token = strtok(temp, " ");
    if(temp_token == NULL) return;
    
    if(head == NULL){
        head = (struct Node *)malloc(sizeof(struct Node));
        head->str = (char *)malloc(strlen(command));
        strcpy(head->str, command);
        head->next = NULL;
        cur = head;
    }else{
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        cur->next = ptr;
        ptr->str = (char *)malloc(0x1000);
        strcpy(ptr->str, command);
        ptr->next = NULL;
        cur = ptr;
    }
}