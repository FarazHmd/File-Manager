#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#define command_size 255

HANDLE hConsole;

char Import_To_System[command_size];
char dir_object[command_size]={"dir"};
char tree_object[command_size]={"tree"};
int remove_directory(const char *path) {
    DIR *d = opendir(path);
    size_t path_len = strlen(path);
    int r = -1;

    if (d) {
        struct dirent *p;

        r = 0;
        while (!r && (p=readdir(d))) {
            int r2 = -1;
            char *buf;
            size_t len;

            /* Skip the names "." and ".." as we don't want to recurse on them. */
            if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
                continue;

            len = path_len + strlen(p->d_name) + 2;
            buf = malloc(len);

            if (buf) {
                struct stat statbuf;

                snprintf(buf, len, "%s/%s", path, p->d_name);
                if (!stat(buf, &statbuf)) {
                    if (S_ISDIR(statbuf.st_mode))
                        r2 = remove_directory(buf);
                    else
                        r2 = unlink(buf);
                }
                free(buf);
            }
            r = r2;
        }
        closedir(d);
    }

    if (!r)
        r = rmdir(path);

    return r;
}
void DIR_SETTING(){
char d_sw2;
int d_in_1,d_in_2;
do{
    printf("See Dir Setting : ['d']\n");
    printf("See Tree Setting : ['t']\n");
printf(">>");scanf(" %c",&d_sw2);
    switch (d_sw2) {
        case 'd':
            case 'D':
                do {

   printf("Dir with ( List by files in sorted order )  : ['1'] \n");
   printf("Dir with ( Displays files in specified directory and all subdirectories.) Not Recommended !! : ['2']\n");
   printf("Dir with ( Same as wide but files are list sorted by column ) : ['3']\n");
   printf("Dir with ( Uses bare format (no heading information or summary).)Not Recommended !!:['4']\n");
                printf(">>");scanf(" %d",&d_in_1);
            switch (d_in_1) {
                case 1:
                    strcpy(dir_object,"dir /o");
                    d_in_1=1;
                    break;
                case 2:
                    strcpy(dir_object,"dir /s");
                    d_in_1=1;
                    break;
                case 3:
                    strcpy(dir_object,"dir /d");
                    d_in_1=1;
                    break;
                case 4:
                    strcpy(dir_object,"dir /b");
                    d_in_1=1;
                    break;
                default:
                    printf("INVALID INPUT PLEASE SELECT YOUR CHOSE FROM OPTIONS \n\a");
                    break;
            }}while (d_in_1 != 1);
                d_sw2='t';
                break;
        case 't':
        case 'T':
            do {
            printf("Tree with ( Display the names of the files in each folder.) : ['1']\n");
            printf("Tree with (Use ASCII instead of extended characters.)       : ['2']\n");
            printf(">>");scanf("%d",&d_in_2);
            switch (d_in_2) {
                case 1:
                    strcpy(tree_object,"tree /f");
                    d_in_2=1;
                    break;
                case 2:
                    strcpy(tree_object,"tree /a");
                    d_in_2=1;
                    break;
                default:
                    printf("INVALID INPUT PLEASE SELECT YOUR CHOSE FROM OPTIONS \n\a");
                    break;

            }}while (d_in_2 !=1);
            d_sw2='t';
            break;
        default:
            printf("INVALID INPUT PLEASE SELECT YOUR CHOSE FROM OPTIONS \n\a");
            break;

    }}while (d_sw2!='t');

}
void SEE_WORKING_DIR(char path[]){

    strcpy(Import_To_System,dir_object);
    SetConsoleTextAttribute(hConsole ,9);
    chdir(path);
    system(Import_To_System);
}
char Change_path(char  path[]){
    SetConsoleTextAttribute(hConsole ,10);
    printf("Please Enter New Path >>\n");
    scanf("%s", path);
    chdir(path);
    printf("\nThe path was successfully changes \n");
    return *path;

}
void TREE_WORKING_DIR(char path[]){
    strcpy(Import_To_System,tree_object);
    chdir(path);
    system(Import_To_System);
}
char Change_folder_target(char  path[]){
    SetConsoleTextAttribute(hConsole ,10);
    chdir(path);
    printf("\nThe Target was successfully changes \n");
    return *path;
}
void Clear_host(){
    strcpy(Import_To_System,"cls");
    system(Import_To_System);
}

void DIR_OPS(char path[]) {
    char CH_D;
    do {
        printf("TO Change Working Dir :      ['P'] \n");
        printf("TO see working directory :   ['D'] \n");
        printf("TO See The Tree Of Working Directory:['T']\n");
        printf("TO SEE Extra Option : ['E']\n");
        printf(">>");
        scanf(" %c", &CH_D);
        switch (CH_D) {
            case 'D':
            case 'd':
                SEE_WORKING_DIR(path);
                CH_D = 'd';
                break;
            case 'P':
            case 'p':
                Change_path(path);
                CH_D = 'd';
                break;
            case 'T':
            case 't':
                TREE_WORKING_DIR(path);
                CH_D = 'd';
                break;
                case 'E':
                    case 'e':
                DIR_SETTING();
                        break;
            default:
                printf("INVALID INPUT PLEASE SELECT YOUR CHOSE FROM OPTIONS \n\a");
                break;
        }


    }while (CH_D != 'd');

}

