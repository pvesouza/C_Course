#include <stdio.h>
#include <stdlib.h>

#include "Linkedlist.h"
#include "insert.h"



int main()
{
    struct Node node;
    node.data = 5;
    node.nextNode = NULL;

    displayNode(&node);
    insert_node(&node);
    return 0;
}
