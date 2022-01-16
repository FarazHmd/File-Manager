#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#define Max_path_size 260
#define Max_file_name_size 255
#define Max_Folder_name_size 255
#define Max_files 255
#define Max_Folders 255
#define Max_Extension_size 8
HANDLE hConsole;
void File_ops_Del(char path[]){
    char filename[Max_file_name_size];
    char filesnames[Max_file_name_size][Max_files];
    int num_del;
    int del_sw_file;
    SetConsoleTextAttribute(hConsole ,16);
    do {

        printf("For Delete one  File      : ['1'] \n");
        printf("For Delete Multiple Files : ['2'] \n");
        printf("Return to the previous Menu:['5'] \n");
        printf("QUIT : [0]");
        printf(">>");
        scanf(" %d", &del_sw_file);

        switch (del_sw_file) {
            case 1:
                system("dir");
                printf("Enter The File Name You want Del  \n");
                printf(">>");
                gets(filename);
                gets(filename);

                if (remove(filename) == 0) {
                    printf("The file is deleted successfully.");
                } else {
                    printf("The file is not deleted.");
                }
                del_sw_file=2;
                break;
            case 2:
                printf("How much file you want delete at time ? \n");
                printf(">>");
                scanf("%d", &num_del);

                for (int i = 0; i < num_del; ++i) {
                    system("dir");
                    printf("Enter Name file %d\n", i + 1);
                    printf(">>");
                    gets(filesnames[i]);
                    if (remove(filesnames[i]) == 0) {
                        printf("The file is deleted successfully.");
                    } else {
                        printf("The file is not deleted.");
                    }
                }
                del_sw_file=2;
                break;
            case 5:
                del_sw_file=2;

            case 0:
                return;
            default:
                printf("Enter the Valid number  from Options\n\a");
                break;
        }

    }while (del_sw_file!=2);

}