#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

struct node* insert_at_end(struct node *newnode)
{
    if(head==NULL)
    {
        head=newnode;
        head->next=NULL;
        return(head);
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
        return(head);
    }
}

void displayList(struct node *head)
{
    if(head==NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
        printf("List is sucessfully printed\n");
    }
}
int main()
{
    int i=0,n;
    printf("Enter the number of nodes you want to add\n");
    scanf("%d",&n);
    printf("Enter the information of the nodes\n");
    while(i!=n)
    {
        struct node *newnode= (struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        head=insert_at_end(newnode);
        i++;
    }
    printf("Elements in the list are:\n");
    displayList(head);
    return 0;
}
