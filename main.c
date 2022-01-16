                                /* Programming  &&  Developing  By Faraz  Honarmand   */

/*                                             The File Manager Project
 *
 * This Project Using  Windows Operation System and Maybe it does not work well in Linux , Mac , .... other OS
 *   This File Manager Support  most windows os such as
 *   >> xp  , vista (x86 && x64 )
 *  ,7 (x86 && x64 ), 10 (x86 && x64 ), 11 (x86 && x64 )
 *
 *
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <afxres.h>

#include "./sys/FHMD__h/DIR_OPS.c"         //  These  Header Files are my custom Header File Write in c for some
#include "./sys/F_HMD/EXT_OPS.c"           // operation Like File Deleting && Folder Deleting && choosing Extension
#include "./sys/F.HMD/FILE_OPS_DEL.c"// And Some Directory Operation such as  'dir' command && 'Tree' Command
#include "./sys/FH_MD/Rename_OPS/Rename_OPS.c"     // and other Dir-Ops
#include "./sys/FHM_D/Editing_OPS.c"
#include "./sys/F_LOGIN_HMD/LOGIN.c"

void File_operations(int  );       // Function  File Operation
void Folder_operations();           // Function  Folder Operation
void Folder_ops_del();             //Func to delete folders
void File_CP_OPS();                // func to copy & cut & clone file
HANDLE hConsole ,hMutex;
char path[Max_path_size];

#define Max_path_size 260          //Some Defines
#define Max_file_name_size 255
#define Max_Folder_name_size 255
#define Max_files 255
#define Max_Clone 255
#define Max_Folders 255
#define Max_Extension_size 8
#define Max_user_pass 32
#define BUFFER_SIZE 1000

int main(const int argc, char const *argv[]) {
    LOGIN();       //Func To Authentication User

    chdir("c:\\test");
    char ch1;
    int flag=0;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    do {
        SetConsoleTextAttribute(hConsole ,14);
        printf("\n\t\tWELCOME TO FILE MANAGER !\n\n");
        printf("TO Change Working Dir & Tree dir &  See Working dir : ['D'] \n");
        printf("To See Immediately Working Dir : [I]\n");
        printf("To Clear Host (Clear the Console ) : ['C']\n");
        printf("TO Make Or Modify files :    ['F'] \n");
        printf("TO Make Or Modify Folders :  ['E'] \n");
        printf("To Quit : ['Q'] \n");
        printf(">>");
        scanf(" %c", &ch1);
        switch (ch1) {
            case 'd':
            case 'D':
                DIR_OPS(path);
                break;
                case 'c':
            case 'C':
                Clear_host();
                break;
            case 'i':
            case 'I':
             SEE_WORKING_DIR(path);
                break;
            case 'f':
            case 'F':
               File_operations(flag);
                break;
            case 'e':
            case 'E':
                Folder_operations();
                break;


                case 'q':
            case 'Q':
                return 0;
            default:
                printf("\nPlease Enter Valid Character The From Options\n\a");
                printf(">>");
                scanf(" %c", &ch1);
                break;

        }

    }while (ch1 !='Q');


    return 0;
}

void File_operations(int flag){
    int num_file=0;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *fp;
    getcwd(path,sizeof(path));
    char yn;
    char path2[Max_path_size],ch_sw_dir;
    char file_name[Max_file_name_size];
    char New_file_name[Max_file_name_size];
    char files_names[Max_file_name_size][Max_files];
    char Extension_File_OPS[Max_Extension_size];
    int File_sw;


    do {
        SetConsoleTextAttribute(hConsole ,10);

        printf("\ncreate one file :       ['1']  \n");
    printf(" create multiple files :      ['2']  \n");
        printf("For Deleting File :       ['3']  \n");
        printf("Rename File       :        ['4']    \n");
        printf("Edit the File content :    ['5']\n");
        printf("To set The Extension of file or files : ['6']\n");
        printf("Copy & Move & Clone  File  :         ['7'] \n");
        printf("TO Change Working Dir  :['8'] \n");
        printf("TO  see working dir    :['9'] \n");
        printf(" Return to the previous menu: ['10']  \n");
        printf(" Exit :  ['0'] \n");
    printf(">>");scanf("%d",&File_sw);

    switch (File_sw) {
        case 1:
            printf("\ncreate File in another dir  :  ['y'] , ['n']\n");
            printf(">>>");scanf(" %c",&ch_sw_dir);
            switch (ch_sw_dir) {

            case 'N':
                case 'n':
                    break;
                    case 'y':
                        case 'Y':
                            WaitForSingleObject(hMutex,INFINITE);
                            printf("Enter your target Folder : \n");
                    printf(">>");gets(path2);gets(path2);
                    Change_folder_target(path2);
                    ReleaseMutex(hMutex);

                            break;
                default:
                    printf("Invalid Input \n\a");
                    break;
            }

            printf("Please Enter the name of File (without Extension !)");
            printf(">>");
            scanf("%s", file_name);
            fp = fopen(strcat(file_name,Extension_File_OPS), "w");
            fclose(fp);
            if (access(file_name, F_OK) == 0) {
                printf("File created successfully \n");
            } else {
                printf("File not created successfully ! \a\n");
            }
            chdir(path);
            break;
        case 2:
            printf("how much file you want create \n");
            printf("It is recommended that the number of files created should not exceed %d at a time \n",Max_files);
            printf(">>");
            scanf("%d", &num_file);

            do {
                printf("do you want to enter the names yourself  : Enter  'y' or 'n'\n ");
            printf(">>");
            scanf(" %c", &yn);
            switch (yn) {
                case 'y':
                case 'Y':
                    for (int i = 0; i < num_file; ++i) {
                        printf("Enter File Name %d", i + 1);
                        scanf(" %s", files_names[i]);
                        fp = fopen(strcat(files_names[i],Extension_File_OPS), "w");
                        fclose(fp);
                        if (access(files_names[i], F_OK) == 0) {
                            printf("File %d created successfully \n", i + 1);
                        } else {
                            printf("File %d not created successfully ! \a\n", i + 1);
                        }

                    }
                    yn='y';
                    break;
                case 'n':
                case 'N':
                    for (int j = 0; j < num_file; ++j) {
                        snprintf(files_names[j],Max_file_name_size,"File_(%d)",rand()+j);
                        fp = fopen(strcat(files_names[j],Extension_File_OPS),"w");
                        fclose(fp);
                        if (access(files_names[j], F_OK) == 0) {
                            printf("File %s created successfully \n", files_names[j]);
                        } else {
                            printf("File %s not created successfully ! \a\n", files_names[j]);
                        }
                    }
                    yn='y';
                    break;
                default:
                    printf("\nPlease Enter Y (Yes) or N (No) \n");
                    break;

               }
            }while (yn !='y');
            break;
        case 3:
            File_ops_Del(path);
            break;
            case 4:

                system("dir");
                printf("Enter the File Name you want to rename :\n");
                 printf(">>");  gets(file_name);   gets(file_name);
                printf("Enter the new Name : \n");
                printf(">>");gets(New_file_name);
                Rename_ops(file_name,New_file_name);

                break;
                case 5:
           Editing_OPS();
                    break;
                    case 6:
                        Extension_Func(Extension_File_OPS);
                        break;
                    case 7:
                        File_CP_OPS(path);
                        break;
                        case 8:
                            Change_path(path);
                            break;
        case 9:
            SEE_WORKING_DIR(path);
            break;
        case 10:
            flag=1;
        case 0:
            return ;
            break;
        default:
            printf("\nPlease Enter Valid Number From Options\n\a");
            break;

    }
    }while (flag!=1);

    system("cls");
}
void Folder_operations(){
    char dir_Name_New[Max_Folder_name_size];
    char dir_Name[Max_Folder_name_size],yn;
    char directories[Max_Folder_name_size][Max_Folders];
    int Folder_sw=0,check,num_Folder;

    do{
        SetConsoleTextAttribute(hConsole ,2);
    printf("\n Create one Folder :          ['1']  \n");
    printf("   Create multiple Folders :    ['2']  \n");
    printf("   Deleting Folders :              ['3']  \n ");
    printf("   Return to the previous Menu :   ['4']\n");
        printf("Rename Folder              :   ['5']\n ");
        printf("TO See working dir    :['8'] \n");
        printf("TO Change Working Dir :['9'] \n");
    printf("Exit :  \t\t['0'] \n");
    printf(">>");scanf("%d",&Folder_sw);
    switch (Folder_sw) {
        case 1:
            printf("\nEnter The Dirname \n");
            scanf("%s",dir_Name);
            check = mkdir(dir_Name);
            if (!check) {
                printf("Directory created\n");
            }else {
                printf("Unable to create directory\n");
            }
            break;
        case 2:
            printf("how much folder you want create  ?\n");
            printf("It is recommended that the number of files created should not exceed %d at a time",Max_Folders);
            printf(">>");scanf("%d",&num_Folder);
            do{
            printf("\ndo you want to enter the names yourself  : Enter  'y' or 'n'  \n ");
            printf(">>");scanf(" %c", &yn);
            switch (yn) {
                case 'y':
                    case 'Y':
                        for (int k = 0; k <num_Folder ; ++k) {
                     printf("\nEnter FolderName %d :",k+1);scanf("%s",directories[k]);
                            check = mkdir(directories[k]);
                            if (!check) {
                                printf("Directory %s created\n",directories[k]);
                            }else {
                               printf("Unable to create directory %s\n",directories[k]);
                            }
                        }
                    yn='y';
                        break;
                case 'N':
                    case 'n':
                        for (int l = 0; l <num_Folder ; ++l) {
                            snprintf(directories[l],Max_Folder_name_size,"New_Folder_(%d)",rand()+l);
                            check = mkdir(directories[l]);
                            if (!check) {
                                printf("Directory %s created\n",directories[l]);
                            }else {
                                printf("Unable to create directory %s\n",directories[l]);
                            }


                        }
                    yn='y';

                        break;
                default:
                    printf("\nPlease Enter ['Y'] (Yes) or ['N'] (No) \n");
                    break;
            }}while (yn !='y');

            break;
            case 3:
                Folder_ops_del(path);
                break;
            case 4:
                Folder_sw=4;
            break;
            case 5:
                system("dir");
            printf("Enter the File Name you want to rename :\n");
            printf(">>");  gets(dir_Name);   gets(dir_Name);
            printf("Enter the new Name : \n");
            printf(">>");gets(dir_Name_New);
            Rename_ops(dir_Name,dir_Name_New);

            break;
            case 8:
                SEE_WORKING_DIR(path);

                break;
        case 9:
            Change_path(path);
            break;
        case 0:
            return;

        default:
            printf("\nPlease Enter Valid Number From Options\n\a");
            break;

    }
   }while (Folder_sw !=4);
}

void Folder_ops_del(){
    int check , num_sw ,num_dir;
    char del_path[Max_Folder_name_size];
    do {
        printf("Delete One Folder   : [1] \n");
        printf("Delete Multiple Folder: [2] \n");
        printf("Return to the previous Menu:['3'] \n");
        printf("TO Change Working Dir & see working dir  :['6'] \n");
        printf("QUIT : [0]\n");
        printf(">>");
        scanf("%d", &num_sw);
        switch (num_sw) {
            case 1:
                system("dir");
                printf("Enter The path of folder to delete \n");
                gets(del_path);
                gets(del_path);
                check = remove_directory(del_path);
                if (!check) {
                    printf("The Folder [%s] is deleted successfully. \n", del_path);
                } else {
                    printf("The Folder [%s] is not deleted. \n", del_path);
                }
                break;
            case 2:
                printf("Enter Number folder you want to delete \n");
                printf(">>");scanf("%d",&num_dir);
                for (int k = 0; k <num_dir ; ++k) {
                    system("dir");
                    printf("Enter Folder name [%d] to delete \n",k+1);
                    gets(del_path);
                    getch();
                    check = remove_directory(del_path);
                    if (!check) {
                        printf("The Folder [%s] is deleted successfully. \n", del_path);
                    } else {
                        printf("The Folder [%s] is not deleted. \n", del_path);
                    }
                }
                break;
            case 3:
                num_sw=3;
                break;
                case 6:
                    Change_path(path);
                SEE_WORKING_DIR(path);
                    break;
            case 0:
                return;
            default:
                printf("Enter the Valid Number from Options\n\a");
                break;
        }
    }while (num_sw!=3);
}
void File_CP_OPS(){
    char path2[Max_path_size];
    hMutex = CreateMutexA(NULL,FALSE,NULL);
    char cp_sw,cp_n,ch_dir;
    int clone_num=0;
    char ch, source_file[Max_file_name_size], dst_file[Max_Folder_name_size],
    sr_del[Max_file_name_size];
     char middle[Max_file_name_size] = "COPY_" , CLONE_NAME[Max_file_name_size][Max_Clone];
    FILE *fs, *ft;
    do {
        SetConsoleTextAttribute(hConsole ,1);
        printf("Cut File : [x]\n");
        printf("Copy File : [C]\n");
        printf("Clone the file :[T]\n");
        printf("Return to the previous Menu:['E'] \n");
        printf(">>");
        scanf(" %c", &cp_sw);
        switch (cp_sw) {
            case 'c':
            case 'C':
                system("dir");
                printf("\nEnter Source File Name (with extension): ");
                printf(">>");gets(source_file);
                gets(source_file);
                fs = fopen(source_file, "r");
                if (fs == NULL) {
                    printf("\a\nError in Opening the file, %s", source_file);

                }
                printf("\nCOPY on different Dir  : ['Y']   |or| continue With Current Dir :  Press any key [''] \n");
                printf(">>");scanf(" %c",&ch_dir);
                if (ch_dir=='y'||ch_dir=='Y'){
                    Change_path(path);
                }
                do{
                printf("\nEnter Target Name By Your self : ['i'] \n");
                printf("Fill Target name automatically   : ['a']  \n");
                printf(">>");scanf(" %c",&cp_n);
                switch (cp_n) {
                    case 'i':
                        case 'I':
                            printf("\nEnter Target File Name (with extension): ");
                        printf(">>");gets(dst_file);
                        ft = fopen(dst_file, "w");
                        if (ft == NULL) {
                            printf("\nUnable to create , %s\n", dst_file);

                        }
                        ch = fgetc(fs);
                        while (ch != EOF) {
                            fputc(ch, ft);
                            ch = fgetc(fs);
                        }
                        printf("\nFile |%s| copied successfully.\n",dst_file);
                        fclose(fs);
                        fclose(ft);
                        cp_n='a';
                            break;
                    case 'a':
                        case 'A':
                            snprintf(dst_file,sizeof source_file ,"%s",strcat( middle, source_file));

                        ft = fopen(dst_file, "w");
                        if (ft == NULL) {
                            printf("\nUnable to create , |%s|\n", dst_file);

                        }
                        ch = fgetc(fs);
                        while (ch != EOF) {
                            fputc(ch, ft);
                            ch = fgetc(fs);
                        }
                        printf("\nFile |%s| copied successfully.\n",dst_file);
                        fclose(fs);
                        fclose(ft);
                        cp_n='a';
                            break;
                    default:
                        printf("Invalid input >> ((please select your chose from Options)) \n\a");
                        break;

                }}while (cp_n !='a');



                break;
            case 'X':
            case 'x':

             WaitForSingleObject(hMutex,INFINITE);
                system("dir");
                printf("\nEnter Source File Name (with extension): ");
                printf(">>");gets(source_file);gets(source_file);
                fs=fopen(source_file, "r");
                strcpy(dst_file,source_file);
                strcpy(sr_del,source_file);

                Change_path(path2);

                ft = fopen(dst_file, "w");
                if (ft == NULL) {
                    printf("\nUnable to create , %s\n", dst_file);

                }
                ch = fgetc(fs);
                while (ch != EOF) {
                    fputc(ch, ft);
                    ch = fgetc(fs);
                }

                fclose(ft);
                fclose(fs);
                ReleaseMutex(hMutex);

                chdir(path);
                if (remove(sr_del) == 0) {
                    printf("\nThe file is deleted successfully.\n");
                } else {
                    printf("\nThe file is not deleted.\n");
                }



                //printf("\nFile |%s| copied successfully.\n",dst_file);

                break;
            case 'T':
                case 't':
                    system("dir");
                printf("\nEnter Source File Name (with extension): ");
                printf(">>");gets(source_file);
                gets(source_file);
                fs = fopen(source_file, "r");
                if (fs == NULL) {
                    printf("\a\nError in Opening the file, %s", source_file);

                }
                    printf("\nHow many clones do you want from your file ? \n");
                printf("\aATTENTIONS !! MAX Cloning each time is : %d\n",Max_Clone);
                    printf(">>");scanf("%d",&clone_num);
                    for (int i = 0; i < clone_num; ++i) {
                        sprintf(CLONE_NAME[i],"CLONE_%d_",i);
                        snprintf(dst_file,sizeof source_file ,"%s",strcat(CLONE_NAME[i], source_file));

                        ft = fopen(dst_file, "w");
                        if (ft == NULL) {
                            printf("\nUnable to create , |%s|\n", dst_file);

                        }
                        ch = fgetc(fs);
                        while (ch != EOF) {
                            fputc(ch, ft);
                            ch = fgetc(fs);
                        }
                        printf("\nFile |%s| copied successfully.\n",dst_file);
                        fclose(fs);
                        fclose(ft);
                    }

                    break;
            case 'E':
                case 'e':
                    cp_sw='e';
                    break;
            default:
                printf("Invalid input >> ((please select your chose from Options)) \n\a");
                break;
        }
    }while (cp_sw!='e');

}

