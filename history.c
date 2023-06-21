#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Append.c"

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

void add_to_hist(char **args){
    if(head == NULL){
        head = (struct Node *)malloc(sizeof(struct Node));
        head->str = (char *)malloc(0x1000);
        char *str1 = " ";
        if(args[1] == NULL){
            strcpy(head->str, strAppend(args[0], str1));
        }else{
            strcpy(head->str, strAppend(args[0], str1));
            strcpy(head->str, strAppend(head->str, args[1]));
        }
        head->next = NULL;
        cur = head;
    }else{
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        cur->next = ptr;
        ptr->str = (char *)malloc(0x1000);
        char* str1 = " ";
        if(args[1] == NULL){
            strcpy(ptr->str, strAppend(args[0],str1));
        }else{
            strcpy(ptr->str, strAppend(args[0],str1));
            strcpy(ptr->str, strAppend(ptr->str, args[1]));
        }
        ptr->next = NULL;
        cur = ptr;
    }
    
}