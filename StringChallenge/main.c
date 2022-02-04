#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <malloc.h>

void printCorrectLine(const char ch, FILE *file);
const unsigned int buffer_size = 256;
const size_t mem_size = buffer_size * sizeof(char);

int main()
{
    printf("Type a character you'd like to search\n");

    char ch = '\0';
    char option = '\0';
    // Reads a character from inputstream
    ch = getchar();
    fflush(stdin);
    printf("The character you choose is: %c\n", ch);

    printf("Choose an option to a file you'd like to execute\n");
    printf("1 - Pedro.txt\n");
    printf("2 - Janaina.txt\n");

    option = getchar();
    fflush(stdin);
    printf("You choose arquive %c\n", option);

    FILE *pt_file = NULL;

    if (option == '1'){
        pt_file = fopen("Pedro.txt", "r");

    }else if (option == '2'){
        pt_file = fopen("Janaina.txt", "r");
    }

    printCorrectLine(ch, pt_file);

    return 0;
}

void printCorrectLine(const char ch, FILE *file) {

    if (file == NULL){
        puts("File not found");
        return;
    }

    // Mallocs a block of memory
    char *line = (char *)malloc(mem_size);

    while(fgets(line, mem_size, file) != NULL){
        if (strchr(line, ch) != NULL){
             puts(line);
        }
    }

    fclose(file);
}
