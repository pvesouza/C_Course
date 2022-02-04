#include <stdio.h>
#include <stdlib.h>

const int total = 9;

int main()
{
    // Print the top
    int i = 0;
    begin:{
        if (i < total){
            if (i == 5){
                printf("*");
            }else{
                printf(" ");
            }
            i++;
            goto begin;
        }else{
            i = 0;
            printf("\n");
        }
    }

    sec:{
        if (i < total){
            if (i == 4 || i == 6){
                printf("*");
            }else{
                printf(" ");
            }
            i++;
            goto sec;
        }else{
            i = 0;
            printf("\n");
        }
    }

    i = 0;

    third:{
        if (i < total){
            if (i == 3 || i == 7){
                printf("*");
            }else{
                printf(" ");
            }
            i++;
            goto third;
        }else{
            i = 0;
            printf("\n");
        }
    }

    fourth:{
        if (i < total){
            if (i == 2 || i == 8){
                printf("*");
            }else{
                printf(" ");
            }
            i++;
            goto fourth;
        }else{
            i = 1;
            printf("\n ");
        }
    }

    fifth:{
        if (i <= total){
            printf("*");
            i++;
            goto fifth;
        }else{
            i = 0;
            printf("\n");
        }
    }

    return 0;
}

