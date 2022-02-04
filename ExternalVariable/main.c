#include <stdio.h>
#include <stdlib.h>

int cont;
void printCount();

int main()
{
    for (cont = 0; cont < 5; cont++){
        printCount();
    }
    return 0;
}
