#include <string.h>

char* strAppend(const char* str1, const char* str2){
    
    char* str3 = (char*)malloc(sizeof(char*)*(strlen(str1) + strlen(str2)));
    char* str4 = (char*)malloc(sizeof(char*)*strlen(str2));

    if(str1 == ""){
        strcpy(str4, str2);
        return str4;
    }
    strcpy(str3, str1);
    strcpy(str4, str2);
    strcat(str3, str4);
    return str3;
}