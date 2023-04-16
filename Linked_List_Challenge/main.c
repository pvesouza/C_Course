#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void print_menu();
// Linked List functions

typedef struct node {
    int value;
    struct node *next_node;
}NODE;

typedef NODE List;

int lenght(List *list);
bool is_empty(List *list);
void insert_at_beginning(List **list, int value);
void insert_at_last(List **list, int value);
bool insert_at_position(List **list, int position, int value);
void print_list(List *list);
int search_value(List *list, int value);
void delete_at(List **heap, int position);
void update_at(List **list, int position, int value);


int main()
{
    printf("LINKED LIST CHALLENGE\n\n");

    List *heap = NULL;

    print_menu();
    int status = 0;
    int value = 0;
    scanf("%d", &status);

    while(status != 7) {

        switch(status) {
            // Insert a node at beginning
            case 1:{
                printf("Insert a value: ");
                scanf("%d", &value);
                insert_at_beginning(&heap, value);
                print_list(heap);
                break;
            }
            // Insert a node at last
             case 2:{
                printf("Insert a value: ");
                scanf("%d", &value);
                insert_at_last(&heap, value);
                print_list(heap);
                break;
            }
            // Insert a node at position
             case 3:{
                int pos = 0;
                printf("Insert a value for position: ");
                scanf("%d", &pos);
                printf("\nInsert a value: ");
                scanf("%d", &value);
                if (insert_at_position(&heap, pos, value)){
                    print_list(heap);
                }
                break;
            }
            // Delete a node at position
             case 4:{
                int pos = 0;
                printf("Insert a value for position: ");
                scanf("%d", &pos);
                delete_at(&heap, pos);
                print_list(heap);
                break;
            }
            // Update a node at position
             case 5:{
                int pos = 0;
                printf("Insert a value for position: ");
                scanf("%d", &pos);
                printf("\nInsert a value: ");
                scanf("%d", &value);
                update_at(&heap, pos, value);
                print_list(heap);
                break;
            }
            // Search element at linked list
             case 6:{
                printf("Insert a value: ");
                scanf("%d", &value);
                int position = search_value(heap, value);
                if (position == -1) {
                    printf("Value not found on the list\n");
                }else{
                    printf("Value found at position %d\n", position);
                }
                break;
            }
        }

        print_menu();
        scanf("%d", &status);
    }

    return 0;
}

void print_menu() {
    printf("Type one of the below options\n\n"
            "1 - Insert a node at beginning\n"
            "2 - Insert a node at last\n"
            "3 - Insert a node at position\n"
            "4 - Delete a node at the position i\n"
            "5 - Update node value\n"
            "6 - Search element in the linked list\n"
            "7 - Exit\n");

}

int lenght(List *list) {
    if (list == NULL) {
        return 0;
    }

    int sum = 0;
    List *current_list = list;

    while(current_list->next_node != NULL) {
        sum = sum + 1;
        current_list = current_list->next_node;
    }
    return sum + 1;
}

bool is_empty(List *list) {

    if (list == NULL) {
        return true;
    }else{
        return false;
    }
}

void insert_at_beginning(List **list, int value) {
    List *current_list = malloc(sizeof(NODE));
    current_list->value = value;
    current_list->next_node = *list;
    *list = current_list;
}

void print_list(List *list) {

    if (list == NULL){
        printf("The List is empty\n");
        return;
    }else {
        List *current_value = list;

        while(current_value != NULL) {
            printf("%d", current_value->value);
            printf("-->");
            current_value = current_value->next_node;
        }

        printf("NULL\n");
    }
}

void insert_at_last(List **list, int value) {
    List *current_node = NULL;
    List *prev_node = NULL;

    if (is_empty(*list)) {
        insert_at_beginning(list, value);
    }else {
        current_node = *list;
        while(current_node != NULL){
            prev_node = current_node;
            current_node = current_node->next_node;
        }
        // Runs the list towards the end
        List *temp_node = malloc(sizeof(NODE));
        temp_node->value = value;
        temp_node->next_node = NULL;
        prev_node->next_node = temp_node;
    }
}

int search_value(List *list, int value) {
    List *current_node = list;
    int position = 0;
    if (is_empty(list)) {
        position = -1;
    }else {

        while((current_node != NULL) && (current_node->value != value)) {
            position = position + 1;
            current_node = current_node->next_node;
        }

        if (current_node == NULL) {
            position = -1;
        }
    }
    return position;
}

bool insert_at_position(List **list, int position, int value) {
    bool result = false;
    if (is_empty(*list)){
        printf("Node not inserted because list is empty\n");
    }else{
        int len = lenght(*list);

        if (0 < position && position < len){
            List *current_node = *list;
            List *previous_node = NULL;
            List *temp_node = malloc(sizeof(NODE));
            temp_node->value = value;

            int i = 0;
            // Runs until position i
            for (i = 0; i < position; i++){
                previous_node = current_node;
                current_node = current_node->next_node;
            }
            previous_node->next_node = temp_node;
            temp_node->next_node = current_node;
            printf("Node inserted successfully\n");
            result = true;

        }else if (position == len){
            insert_at_last(list, value);
            result = true;
        }else if (position == 0) {
            insert_at_beginning(list, value);
            result = true;
        }else {
            printf("Position out of range of the list\n");
        }
    }
    return result;
}

void delete_at(List **heap, int position) {
    int len = 0;
    List *current_node = NULL;
    List *previous_node = NULL;

    if (is_empty(*heap)) {
        printf("The list is empty\n");
    }else{
        len = lenght(*heap);
        if (position >= len){
            printf("Position out of range\n");
        }else if (position > 0){
            int pos = 0;
            current_node = *heap;
            for (pos = 0; pos < position; pos++) {
                previous_node = current_node;
                current_node = current_node->next_node;
            }
            previous_node->next_node = current_node->next_node;
            free(current_node);
            printf("Node deleted\n");
        }else {
            current_node = *heap;
            *heap = current_node->next_node;
            free(current_node);
        }
    }
}

void update_at(List **list, int position, int value) {
    List *current_node = *list;

    if (is_empty(*list)){
        printf("The list is empty\n");
    }else if (position >= lenght(current_node)){
        printf("Position is out of range\n");
    }else {
        int pos = 0;
        // Runs until position
        for (pos = 0; pos < position; pos++) {
            current_node = current_node->next_node;
        }

        if (current_node != NULL) {
            current_node->value = value;
            printf("Node updated\n");
        }else{
            printf("Current node is null\n");
        }
    }
}
