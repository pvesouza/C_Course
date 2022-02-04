#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


// This example shows the use of getline

int main()
{
    char *buffer = NULL;
    size_t bufsize = 32;
    size_t characters;

    // Allocates a block of memory with size = 32 * 8 bits
    buffer = (char *)malloc(bufsize * sizeof(char));

    if (buffer == NULL){
        printf("Impossible to allocates memory\n");
        exit(1);
    }

    printf("Type something to be read and stored in the memory\n");

    characters = getline(&buffer, &bufsize, stdin);

    printf("%zu characteres were read: \n", characters);
    printf("you typed this %s", buffer);
    return 0;
}
