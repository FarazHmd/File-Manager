#include "Rename_OPS.h"
#include <string.h>
#include <stdio.h>

#define Max_old 255
#define Max_new 255

HANDLE hConsole;

void Rename_ops(char old[Max_old],char new[Max_new]){

SetConsoleTextAttribute(hConsole,6);

    char old_name[Max_old];
    char new_name[Max_new];
    strcpy(old_name,old);
    strcpy(new_name,new);
    int value;

    value = rename(old_name, new_name);
    system("dir");
    if(!value)
    {
        printf("\n|%s|  >>>  |%s|\n",old_name,new_name);
        printf("\n Name changed successfully\n");
    }
    else
    {
        perror("\nError\n\a");
    }

}