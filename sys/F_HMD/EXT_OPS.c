
#include <stdio.h>

#include <string.h>
#define Max_Extension_size 8
HANDLE hConsole;
char Extension_Func(char EX[Max_Extension_size]){
    char Extensions[Max_Extension_size],Ex2[Max_Extension_size];
    char ex_sw;
    SetConsoleTextAttribute(hConsole ,4);


    do {
        printf("\nwhat type file you want create ?");
        printf(" \n << OPTIONS >> \n");
        printf(" Music Files  Enter    :['M'] \n");
        printf(" Picture File Enter    :['P'] \n");
        printf(" Text Files  Enter     :['T'] \n");
        printf("Others Extension Enter :['O'] \n");
        printf("Return to the previous Menu: ['R'] \n");
        printf("Quit : ['Q']\n");
        printf(">>");scanf(" %c",&ex_sw);
        switch (ex_sw) {
            case 'M':
            case 'm':
                strcpy(Extensions,".mp3");
                ex_sw='r';
                break;
            case 'p':
            case 'P':
                strcpy(Extensions,".png");
                ex_sw='r';
                break;
            case 't':
            case 'T':
                strcpy(Extensions,".txt");
                ex_sw='r';
                break;
            case 'o':
            case 'O':
                printf("Enter The Extension (please  Enter with '.'  like > .ini or .jpg )   \n  ");
                scanf("%s",Ex2);
                strcpy(Extensions,Ex2);
                ex_sw='r';
                break;
            case 'R':
            case 'r':
                ex_sw='r';
                break;
            case 'q':
            case 'Q':
                return 0;
            default:
                printf("Enter the Valid char from Options\n\a");
                break;

        }
    }while (ex_sw !='r');
    strcpy(EX,Extensions);
}