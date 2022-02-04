#include <stdio.h>
#include <stdlib.h>

struct packed_struct{
    unsigned int : 3;       // Padding
    unsigned int f1:1;       // Field 1
    unsigned int f2:1;      // Field 2
    unsigned int f3:1;      // Field 3
    unsigned int type:8;
    unsigned int index:18;

    // The total sum must be 32 bits a size of an int


};

int main()
{
    unsigned int number = 0;
    unsigned int lenghtInt = (sizeof(int) * 8) - 1;
    unsigned int n_bit = 0;
    unsigned int mask = 1;
    struct packed_struct packed_data = {.f1 = 1, .type = 255};

    printf("Type an integer number\n");
    scanf("%u", &number);
    printf("Type n bit you want to check whether is 1 value from 0 to %u\n", lenghtInt);
    scanf("%u", &n_bit);
    mask = mask << n_bit;

    if ((number & mask) == mask){
        printf("The number is 1\n");
    }else{
         printf("The number is 0\n");
         number  = number | mask;
         printf("New Number is %u\n", number);
    }

    printf("field f1 is equal to %u and field type is equal to %u\n", packed_data.f1, packed_data.type);


    return 0;
}
