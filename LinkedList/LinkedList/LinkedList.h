#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct Node{
    int data;
    struct Node* nextNode;
};

void displayNode(struct Node* node);


#endif // LINKEDLIST_H_INCLUDED
