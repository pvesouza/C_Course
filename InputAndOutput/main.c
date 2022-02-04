#include <stdio.h>
#include <stdlib.h>

const char inferior = 'a';
const char superior = 'z';
const char *janaina = "janaina.txt";
const char *pedro = "pedro_lower_case.txt";

void toUpperCase(const char *filename);

int main()
{
    char ch = '\0';
    int char_counter = 0;
    int words_counter = 0;

    FILE *fp = NULL;

    fp = fopen("janaina.txt", "rw");

    // Opens a file
    if (fp != NULL){

        // Scans the opened file
        while(ch != EOF){
            ch = getc(fp);
            putchar(ch);
            if (ch == ' ' || ch == '\n'){
                words_counter++;
            }
            char_counter++;
        }
        putchar('\n');
        // Closes the file
        fclose(fp);
        printf("The number of characteres is: %d\n", char_counter);
        printf("The number of words is: %d\n", words_counter);

        printf("Choose on of these files:\n");
        printf("1 - janaina.txt\nor\n");
        printf("2 - pedro_lower_case.txt\n");

        int option = getchar();

        printf("Your choice was: %c\n", option);

        switch(option){
            case '1':{
                toUpperCase(janaina);
                break;
            }

            case '2':{
                toUpperCase(pedro);
                break;
            }

            default:
                printf("Invalid choice\nNo file exists");
                break;
        }

    }
    return 0;
}

void toUpperCase(const char *filename) {

    // Opens a file
    FILE *filePointer = fopen(filename, "rw");

    if (filePointer != NULL){

        char c = '\0';
        FILE *outputFile_ptr = fopen("UpperCase.txt", "w");

        while(c != EOF){

            // Reads a character from file pointed by fp
            c = getc(filePointer);
            if (c <= superior && c >= inferior){
                // Puts to Upper case
                c = c - 32;
            }
            putc(c, outputFile_ptr);
        }

        fclose(filePointer);
        fclose(outputFile_ptr);

        }else{
            printf("File does not exist\n");
        }
}
