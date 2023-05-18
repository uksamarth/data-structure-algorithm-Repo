#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void write_linked_list(Node* head) {
    FILE* fptr = fopen("output.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        fprintf(fptr, "%d ", current->data);
        current = current->next;
    }

    fclose(fptr);
}

int random_element(Node* head) {
    srand(time(NULL));
    int count = 0, result;
    Node* current = head;
    while (current) {
        if (rand() % (++count) == 0) {
            result = current->data;
        }
        current = current->next;
    }
    return result;
}

int main() {
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    Node* head = NULL;

    // Create the linked list
    for (int i = 0; i < size; i++) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = i+1;
        new_node->next = head;
        head = new_node;
    }

    // Write the linked list to a file
    write_linked_list(head);

    printf("Random element from the linked list: %d\n", random_element(head));

    return 0;
}
