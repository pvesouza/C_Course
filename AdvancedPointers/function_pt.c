#include <stdio.h>

int some_display(int arg){
    printf("This function 1 was called by pointer %d\n", arg);
}

int some_display_2(int arg){
    printf("THis function 2 was called %d\n", arg);
}

int main(void) {
    int (*func_ptr)(int);
    func_ptr = some_display;
    printf("The address of the pointer function is %p\n", func_ptr);
    (*func_ptr)(4);
    (*func_ptr)(20);
    return 0;
}