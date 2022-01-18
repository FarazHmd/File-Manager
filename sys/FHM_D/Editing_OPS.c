#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


#define Max_File_size 255
#define BUFFER_SIZE 1000



void Editing_OPS()
{
    system("dir");


    FILE *MY_FILE ,*TEMP_FILE;
    char buffer[BUFFER_SIZE];
char FileName[Max_File_size];
    char data[Max_File_size];
    char temp[Max_File_size]={"temp.txt"};

    int lno, ctr = 0;
    int totalRead = 0;
   int sw_1;
do{
printf("See  Content Of File : ['1']\n");
printf("Edit Content Of File : ['2']\n");
printf("Delete Some Content Of File : ['3']\n");
printf(">>");scanf(" %d",&sw_1);
    switch (sw_1) {
case 1:
    printf("Enter The  Name Of  Target File \n ");
            printf(">>"); gets(FileName);gets(FileName);
            MY_FILE=fopen(FileName,"r");

            while(fgets(buffer, BUFFER_SIZE, MY_FILE) != NULL)
            {
                /* Total character read count */
                totalRead = strlen(buffer);


                /*
                 * Trim new line character from last if exists.
                 */
                buffer[totalRead - 1] = buffer[totalRead - 1] == '\n'
                                        ? '\0'
                                        : buffer[totalRead - 1];


                /* Print line read on cosole*/
                printf("%s\n", buffer);

            }


            /* Done with this file, close file to release resource */
            fclose(MY_FILE);
            sw_1 =4;
            break;
case 2:
    printf("Enter The  Name Of  Target File \n ");
            printf(">>"); gets(FileName);gets(FileName);
            MY_FILE = fopen(FileName, "a");





/* If the searched file is not found, the program exits */
            if (MY_FILE == NULL)
            {
                /* Unable to open file hence exit */
                printf("\nUnable to open |%s| file.\n", FileName);
                printf("Please check whether file exists and you have write privilege.\n");
                exit(EXIT_FAILURE);
            }
          

            /* Input data to append from user */
            printf("\nEnter data to append: ");
            gets(data);
            fflush(stdin);          // To clear extra white space characters in stdin
            fgets(data, BUFFER_SIZE, stdin);


            /* Append data to file */
            fputs(data, MY_FILE);


            /* Reopen file in read mode to print file contents */


            /* Print file contents after appending string */
            printf("\nSuccessfully appended data to file. \n");


            /* Success message */
            fclose(MY_FILE);
            sw_1 =4;
    break;
    case 3:
        printf("Enter The  Name Of  Target File \n ");
            printf(">>"); gets(FileName);gets(FileName);
        MY_FILE = fopen(FileName, "r");
            if (!MY_FILE)
            {
                printf(" File not found or unable to open the input file!!\n");
                exit(EXIT_FAILURE);
            }
            TEMP_FILE = fopen(temp, "w"); // open the temporary file in write mode
            if (!TEMP_FILE)
            {
                printf("Unable to open a temporary file to write!!\n");
                fclose(MY_FILE);
                exit(EXIT_FAILURE);
            }
            printf(" Input the line you want to remove : ");
            scanf("%d", &lno);
            lno++;
            // copy all contents to the temporary file except the specific line
            while (!feof(MY_FILE))
            {
                strcpy(buffer, "\0");
                fgets(buffer, BUFFER_SIZE, MY_FILE);
                if (!feof(MY_FILE))
                {
                    ctr++;
                    /* skip the line at given line number */
                    if (ctr != lno)
                    {
                        fprintf(TEMP_FILE, "%s", buffer);
                    }
                }
            }
            fclose(MY_FILE);
            fclose(TEMP_FILE);
            remove(FileName);  		// remove the original file
            rename(temp, FileName); 	// rename the temporary file to original name

            printf("Tha Changes Was Successfully saved \n");
            sw_1 =4;
        break;
        default:
            printf("\nINVALID INPUT DETECTED !! \n\a");
            break;
    }}while (sw_1 !=4);

    }

/* If the file is found */

