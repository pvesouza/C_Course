#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000

int main(int argc, const char *argv[])
{
    // The args[0] is the filename I want to open
    const char *filename = argv[2];
    printf("The filename is %s\n", filename);
    int i = 0;
    int readNumber = 0;

    FILE *file = NULL;

    file = fopen(filename, "w");

    if (file == NULL){
        exit(0);
    }

    // Writes 1 to 100 to file
    for (i = 1; i <= LIMIT; i++) {
        fprintf(file, "%d ", i);
    }
    fclose(file);

    // Tests if can open the file or not
    file = fopen(filename, "r");
    if (file == NULL) {
        exit(0);
    }

    // Reads all int values
    while(fscanf(file, "%d", &readNumber) != EOF){
        printf("Number %d -", readNumber);
        // test if it is pair or odd
        if (readNumber % 2 == 0){

            if (readNumber == 2){
                printf(" even - prime number\n");
            }else{
                printf(" even\n");
            }
        }else{
            printf(" odd");
            int count = 0;
            // Test if the number if prime
            for (i = 1; i <= readNumber; i++){
                if (readNumber % i == 0){
                    count++;
                }
            }

            if (count >= 3){
                printf("\n");
            }else{
                printf(" - prime number\n");
            }
        }
    }

    fclose(file);

    return 0;
}
