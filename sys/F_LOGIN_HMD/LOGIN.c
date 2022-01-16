#include "LOGIN.h"
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <windows.h>

#define Max_user_pass 32
#define BUFFER_SIZE 1000


void LOGIN(){
    struct Account{
        char username[Max_user_pass]
        ,passcode[Max_user_pass];
    }Main_account;
    int lock=0,fail=4;
    char Ucheck[Max_user_pass],Pcheck[Max_user_pass];
    char buf[BUFFER_SIZE],buf2[BUFFER_SIZE];
    FILE *login_p,*login_u;
    int check =access("u.txt",F_OK);
    if (check==-1){
        login_u = fopen("u.txt","w");
        login_p = fopen("p.txt","w");
        printf("\nSet your Username : \n");
        printf(">>");gets(Main_account.username);//gets(username);
        printf("\nSet you PassCode : \n");
        printf(">>");gets(Main_account.passcode);//gets(passcode);
        fprintf(login_p,"%s",Main_account.passcode);
        fprintf(login_u,"%s", Main_account.username);
        fclose(login_p);
        fclose(login_u);
    } else {
        login_u = fopen("u.txt", "r");
        login_p = fopen("p.txt", "r");

        while ((fgets(buf, BUFFER_SIZE, login_u) != NULL)) {
            fgets(buf, BUFFER_SIZE, login_u);
            strcpy(Main_account.username, buf);

        }
        while ((fgets(buf, BUFFER_SIZE, login_p) != NULL)) {
            fgets(buf, BUFFER_SIZE, login_p);
            strcpy(Main_account.passcode, buf);
        }
        fclose(login_u);
        fclose(login_p);
        do {
            fail--;
            printf("Enter Your Username : \n");
            printf(">>");
            gets(Ucheck);//gets(Ucheck);
            printf("Enter Your PassCode : \n");
            printf(">>");
            gets(Pcheck);
            // printf("\n%s || %s\n", Main_account.username, Main_account.passcode);
            if (strcmp(Main_account.username, Ucheck) == 0) {
                if (strcmp(Main_account.passcode, Pcheck) == 0) {
                    printf("\n\nAuthentication Success !");
                    printf("\n MR/MRS |%s| YOU ARE NOW AUTHURIZED  ! \n\n",Main_account.username);
                    lock = 1;
                } else {
                    printf("\n Wrong Username Or PassCode !! \a\n");
                    printf("\nYou can try |%d| more times !!\n\n",fail);
                    lock = -1;
                    if (fail ==0 ) {
                        exit(-2);
                    }
                }
            }else {
                printf("\n Wrong Username Or PassCode !! \a\n");
                printf("\nYou can try |%d| more times !!\n\n",fail);
                lock = -1;
                if (fail ==0 ) {
                    exit(-2);
                }
            }
        }while (lock != 1);
    }
}






