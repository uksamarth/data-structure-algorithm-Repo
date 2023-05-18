#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

node *createNode(int ele) {
    node *t = (node*)malloc(sizeof(node));
    if(t == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    t->data = ele;
    t->next = NULL;
    return t;
}

node *insert_rear(node *head, int ele) {
    node *t = createNode(ele);
    if(head == NULL) {
        return t;
    }
    node *c = head;
    while(c->next != NULL) {
        c = c->next;
    }
    c->next = t;
    return head;
}

node *findMiddleTerm(node *head) {
    if(head == NULL) {
        return NULL;
    }
    node *slow = head;
    node *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void displayList(node *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *t = head;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    int n, ele, choice;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &ele);
        head = insert_rear(head, ele);
    }
    while(1) {
        printf("\n1. Display List\n2. Find Middle Term\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("List: ");
                displayList(head);
                break;
            case 2:
                printf("Middle Term: ");
                node *mid = findMiddleTerm(head);
                if(mid != NULL) {
                    printf("%d\n", mid->data);
                } else {
                    printf("List is empty\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
