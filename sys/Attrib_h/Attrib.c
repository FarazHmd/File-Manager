#include "ATTRIB.h"

#include <stdio.h>
#define Max_file_name_size 255
#define Attrib_Size_input 256
HANDLE hMutex;
void Attrib(void ) {
    int as1=0;
    char filename[Max_file_name_size];
    char att_h[Attrib_Size_input] = {"attrib \t"},
            att_r[Attrib_Size_input] = {"attrib \t"};
    char U_att_h[Attrib_Size_input] = {"attrib \t"},
            U_att_r[Attrib_Size_input] = {"attrib \t"};
    char A_r[Attrib_Size_input] = {"\t+r\t"},
    A_h[Attrib_Size_input] = {"\t+h\t"},
            U_A_r[Attrib_Size_input] = {"\t-r\t"}
    , U_A_h[Attrib_Size_input] = {"\t-h\t"};
    char last_att[Attrib_Size_input]={"attrib \t"};
    char ac;
    do {
        printf("To make hide file  :    ['H']\n");
        printf("To make readonly file : ['R']\n");
        printf("To undo hide file  :    ['!']\n");
        printf("To undo readonly file : ['x']\n");
        printf("Return to the previous Menu: ['B'] \n");
        printf(">>");
        scanf(" %c", &ac);
        switch (ac) {
            case 'h':
            case 'H':
                WaitForSingleObject(hMutex,INFINITE);
                system("dir");
                printf("Enter The File Name You want set attribute  \n");
                printf(">>");
                gets(filename);
                gets(filename);
                if (access(filename, F_OK) == 0) {
                    strcat(att_h, filename);
                    strcat(att_h, A_h);
                    system(att_h);
                } else {
                    printf("File not Not found .. check the name and try again !! \a\n");
                }
                if (access(filename, F_OK) == 0) {
                    printf("\nfile is  hided successfully !!\n");
                } else {
                    printf("\nfile is not hide successfully !!\n\a");
                }

                strcat(last_att,filename);
                system(last_att);
                ReleaseMutex(hMutex);
system("cls");
                filename[0]='\0';
                break;
            case 'r':
            case 'R':
                WaitForSingleObject(hMutex,INFINITE);
                system("dir");
                printf("Enter The File Name You want set attribute  \n");
                printf(">>");
                gets(filename);
                gets(filename);
                strcat(U_att_h, filename);
                strcat(U_att_h, U_A_h);
                system(U_att_h);

                system("cls");

                if (access(filename, F_OK) == 0) {
                    strcat(att_r, filename);
                    strcat(att_r, A_r);
                    system(att_r);
                    strcat(att_h, filename);
                    strcat(att_h, A_h);
                    system(att_h);
                } else {
                    printf("File not Not found .. check the name and try again !! \a\n");
                }
                system("cls");

                if (access(filename, F_OK) == 0) {
                    printf("\nfile is now readonly  !!\n");
                } else {
                    printf("\nfile is not set to readonly successfully !!\n\a");
                }
                strcat(last_att,filename);
                system(last_att);
                ReleaseMutex(hMutex);
                system("cls");
                filename[0]='\0';
                break;
            case 'x':
            case 'X':
                WaitForSingleObject(hMutex,INFINITE);
                system("dir");
                printf("Enter The File Name You want unset attribute  \n");
                printf(">>");
                gets(filename);
                gets(filename);
                if (access(filename, F_OK) == 0) {
                    strcat(U_att_r, filename);
                    strcat(U_att_r, U_A_r);
                    system(U_att_r);
                } else {
                    printf("File not Not found .. check the name and try again !! \a\n");
                }
                if (access(filename, F_OK) == 0) {
                    printf("\nUnset attribute successfully !!\n");
                } else {
                    printf("\nUnset attribute  not successfully \n\a");
                }
                strcat(last_att,filename);
                system(last_att);
                ReleaseMutex(hMutex);
                system("cls");
                filename[0]='\0';
                break;
            case '!':
                WaitForSingleObject(hMutex,INFINITE);
                system("dir");
                printf("Enter The File Name You want unset attribute  \n");
                printf(">>");
                gets(filename);
                gets(filename);
                if (access(filename, F_OK) == 0) {
                    strcat(U_att_h, filename);
                    strcat(U_att_h, U_A_h);
                    system(U_att_h);
                } else {
                    printf("File not Not found .. check the name and try again !! \a\n");
                }
                if (access(filename, F_OK) == 0) {
                    printf("\nUnset attribute successfully !!\n");
                } else {
                    printf("\nUnset attribute  not successfully \n\a");
                }
                strcat(last_att,filename);
                system(last_att);
                ReleaseMutex(hMutex);
                filename[0]='\0';
                system("cls");
                break;
            case 'b':
            case 'B':
                as1 +=1;
                return;
                break;
            default:
                printf("Enter the Valid char from Options\n\a");
                break;


        }
    }while (as1!=1);

    }
