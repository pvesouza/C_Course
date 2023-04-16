#include <stdio.h>
#include <stdlib.h>

void print_options() {
    printf("Choose your option\n");
    printf(" 1- Insert and character at the list in alphabetical order\n");
    printf(" 2- To insert a node at end of the list\n");
    printf(" 3- To insert and element at the beginning of the list\n");
    printf(" 4- To delete an element from the list\n");
    printf(" 5- To Delete an element from the beginning of the list\n");
    printf(" 6 - List the size of the list\n");
    printf(" 7- Exit from the program\n\n\n");
}

typedef struct node {
    char value;
    struct node *nextNode;
} NODE;

typedef NODE *ListOfNodes;

// Prototypes of functions of a linked list
void insert(ListOfNodes *head, char value);
void insert_at_end(ListOfNodes *head, char value);
void insert_at_beginning(ListOfNodes *head, char value);
char delete_node(ListOfNodes *head, char value);
void delete_at_beginning(ListOfNodes *head);
int is_empty(ListOfNodes *head);
void print_list(ListOfNodes *head);
int lenght(ListOfNodes *head);


int main()
{

    // Declaring the list
    ListOfNodes head = NULL;

    print_options();

    int choice  = 0;                          // Reading the choice
    char item = '\0';                            // The item we are going to put into the list
    scanf("%d", &choice);

    while (choice != 7) {

        switch(choice) {
            case 1:{
                printf("Insert a character ALPHA\n");
                scanf(" %c", &item);
                insert(&head, item);
                print_list(&head);
                break;
            }

            case 2: {
                printf("Insert a character END\n\n");
                scanf(" %c", &item);
                insert_at_end(&head, item);
                print_list(&head);
                break;
            }

            case 3: {
                printf("Insert a character BEGINNIG\n\n");
                scanf(" %c", &item);
                insert_at_beginning(&head, item);
                print_list(&head);
                break;
            }

            case 4: {
                printf("DELETE ITEM\n\n");

                if (!(is_empty(&head) == 0)) {
                    scanf("%c", &item);
                    char result = delete_node(&head, item);

                    if (result) {

                        printf("Item deleted successfully \n\n");
                    }else {
                        printf("Item not found \n\n");
                    }
                    print_list(&head);
                }else {
                    printf(" List is empty \n\n");
                }
                break;
            }

            case 5: {
                printf("DELETE FROM THE BEGINNING \n\n");

                if (!(is_empty(&head) == 0)) {
                    delete_at_beginning(&head);
                    print_list(&head);

                }else {
                    printf(" List is empty \n\n");
                }
                break;
            }

            case 6: {
                int len = lenght(&head);
                printf("The length of the list is %d\n", len);
            }

            default: {
                printf("Choose the correct option \n");
            }
        }

        printf("Choose another option: \n\n");
        print_options();
        scanf("%d", &choice);
    }
    return 0;
}

void insert_at_beginning(ListOfNodes *head, char value) {
    // Create a new object that will receive the value
    ListOfNodes new_node = malloc(sizeof(NODE));
    // Saves the value
    new_node->value = value;
    // New node will point to the previous head
    new_node->nextNode = *head;
    // Head will point to new_node
    *head = new_node;
}

void insert_at_end(ListOfNodes *head, char value) {
    ListOfNodes current = *head;
    ListOfNodes previous_node = NULL;

    // Test if the list is empty
    if (current != NULL) {
        // Iterates the list until the end of the list
        while (current != NULL) {
            previous_node = current;
            current = current->nextNode;
        }

        // After running on the list and we reaches the end of the list we can add a new variable
        current = malloc(sizeof(NODE));
        current->value = value;
        current->nextNode = NULL;
        previous_node->nextNode = current;

    }else {
        current = malloc(sizeof(NODE));
        current->value = value;
        current->nextNode = NULL;
        *head = current;
    }
}

void insert(ListOfNodes *head, char value) {
    ListOfNodes newNode, currentNode, previousNode;

    newNode = malloc(sizeof(NODE));

    // Verifies if malloc was succeeded
    if (newNode != NULL) {
        newNode->value = value;
        newNode->nextNode = NULL;

         previousNode  = NULL;
        currentNode = *head;

        // Find the exact position on the list
        while (currentNode != NULL && value > currentNode->value) {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }

        // Insert the new value at the beginning
        if (previousNode == NULL) {

            newNode->nextNode = *head;
            *head = newNode;
        }else {
    // Insert the node between the current and the previous
        previousNode->nextNode = newNode;
        newNode->nextNode = currentNode;
        }
    }else {
        printf(" Node not inserted: there is no memory available \n\n");
    }
}

void delete_at_beginning(ListOfNodes *head) {

    ListOfNodes tempNode = NULL;

    // The list is empty
    if (head == NULL) {
        return;
    }

    tempNode = *head;
    *head = tempNode->nextNode;
    free(tempNode);
}

char delete_node(ListOfNodes *head, char value) {

    // Test if the list is empty
    if (*head == NULL) {
        return '\0';
    }

    ListOfNodes previousNode;
    ListOfNodes currentNode;
    ListOfNodes tempNode;

    // If the value is the first value
    if (value == (*head)->value) {

        tempNode = *head;
        *head = tempNode->nextNode;
        free(tempNode);
        return value;
    }else {
        previousNode = *head;
        currentNode = previousNode->nextNode;

        // Runs to find the correct location of the list
        while (currentNode != NULL && value != currentNode->value) {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }

        // If did not find the value
        if (currentNode == NULL) {
            return '\0';

        }else {
            tempNode = currentNode;
            previousNode->nextNode = currentNode->nextNode;
            free(currentNode);
            return value;
        }
    }
}

int is_empty(ListOfNodes *head) {
    return *head == NULL ? 0 : 1;
}

void print_list(ListOfNodes *head) {
    ListOfNodes current_node = *head;

    if (current_node == NULL) {

        printf("The List is empty\n\n");
        return;
    }
    while(current_node != NULL) {

        printf("%c", current_node->value);
        printf("-->");
        current_node = current_node->nextNode;
    }

    printf("NULL\n");
}

int lenght(ListOfNodes *head) {
    ListOfNodes current_node = *head;

    if (current_node == NULL) {
        return 0;
    }
    int sum = 0;
    while(current_node != NULL) {

        sum = sum + 1;
        current_node = current_node->nextNode;
    }
    return sum;
}



