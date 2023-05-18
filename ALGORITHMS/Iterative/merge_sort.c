#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to split the linked list into two halves
void splitList(struct Node* head, struct Node** first_half, struct Node** second_half) {
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head->next;

    // Move the fast pointer by two nodes and the slow pointer by one node
    while (fast_ptr != NULL) {
        fast_ptr = fast_ptr->next;
        if (fast_ptr != NULL) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
    }

    // Split the list into two halves
    *first_half = head;
    *second_half = slow_ptr->next;
    slow_ptr->next = NULL;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* first_half, struct Node* second_half) {
    if (first_half == NULL) {
        return second_half;
    }
    if (second_half == NULL) {
        return first_half;
    }
    struct Node* merged_list = NULL;
    if (first_half->data <= second_half->data) {
        merged_list = first_half;
        merged_list->next = mergeLists(first_half->next, second_half);
    } else {
        merged_list = second_half;
        merged_list->next = mergeLists(first_half, second_half->next);
    }
    return merged_list;
}

// Function to perform merge sort on a linked list
void mergeSort(struct Node** head_ref) {
    struct Node* head = *head_ref;
    if (head == NULL || head->next == NULL) {
        return;
    }

    // Split the list into two halves
    struct Node* first_half = NULL;
    struct Node* second_half = NULL;
    splitList(head, &first_half, &second_half);

    // Recursively sort the two halves
    mergeSort(&first_half);
    mergeSort(&second_half);

    // Merge the sorted halves
    *head_ref = mergeLists(first_half, second_half);
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = createNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtBeginning(&head, data);
    }
    printf("Before sorting: ");
    printList(head);
    mergeSort(&head);
    printf("After sorting: ");
    printList(head);
    return 0;
}
