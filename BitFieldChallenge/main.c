#include <stdio.h>
#include <stdlib.h>

struct onscreen_Box {
    unsigned int:4;
    unsigned int transparency:1;        // Opaque = 1, Transparent = 0
    unsigned int fillColor:3;           // Black, Red, Green, Yellow, Blue, Magenta, Cyan, White [0 .. 7]
    unsigned int : 2;
    unsigned int border:1;              // Shown = 1, Hidden = 0
    unsigned int borderColor:3;          // Black, Red, Green, Yellow, Blue, Magenta, Cyan, White [0 .. 7]
    unsigned int borderStyle:2;          // solid = 0, dotted = 1, dashed = 2
};

typedef struct onscreen_Box Box;

const char *colors[8] = {"Black", "Red", "Green", "Blue", "Magenta", "Cyan", "White"};
const char *transparency[2] = {"Transparent", "Opaque"};
const char *borderStatus[2] = {"Hidden", "Shown"};
const char *borderStyle[3] = {"Solid", "Dotted", "Dashed"};

void printBox(const Box *b);
void printLine(void);

int main()
{
    Box my_box = {.transparency = 1, .fillColor = 3, .border = 0};
    printBox(&my_box);
    my_box.border = 1;
    my_box.borderStyle = 0;
    my_box.borderColor = 0;
    printLine();
    printBox(&my_box);
    return 0;
}


void printBox(const Box *b){

    printf("Transparency: %s\n", transparency[b->transparency]);
    if (b->transparency){
       printf("Color: %s\n", colors[b->fillColor]);
    }else{
        printf("No fill color\n");
    }
    printf("Border: %s\n", borderStatus[b->border]);
    if (b->border){
        printf("Border color: %s\n", colors[b->borderColor]);
        printf("Border Style: %s\n", borderStyle[b->borderStyle]);
    }else{
        printf("No border\n");
    }
}

void printLine(){
    printf("---------------------------------------------------------------\n");
}
