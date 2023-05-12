#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};

void push(struct stack *sptr, int num, FILE *fstack, FILE *fpush)
{
    fstack = fopen("stack.txt", "w");
    fpush = fopen("push.txt", "w");
    if(sptr->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;

        sptr->data[sptr->top] = num;

        fprintf(fstack, "%d\n", num); // Write the number to stack file

        fprintf(fpush, "%d\n", num); // Write the number to push file

    }
        fclose(fstack);
        fclose(fpush);

}

void pop(struct stack *sptr, FILE *fstack, FILE *fpop)
{
    fstack = fopen("stack.txt", "w");
    fpop = fopen("pop.txt", "w");
    int num;

    if(sptr->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        num = sptr->data[sptr->top];

        sptr->top--;

        printf("%d\n", num);

        fprintf(fstack, "%d\n", num); // Write the number to stack file

        fprintf(fpop, "%d\n", num); // Write the number to pop file
    }

        fclose(fstack);
        fclose(fpop);
}
/*
void peek(struct stack *sptr)
{
    if(sptr->top == -1)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("%d", sptr->data[sptr->top]);
    }
}
*/
void display(struct stack *sptr, FILE *fstack) {
    fstack = fopen("stack.txt","w");
    if (sptr->top == -1) {
        printf("Stack empty\n");
        return;
    }
    fprintf(fstack, "Current stack: ");
    for (int i = sptr->top; i >= 0; i--)
        {
        fprintf(fstack, "%d ", sptr->data[i]);

        printf("%d ", sptr->data[i]);
    }
    fclose(fstack);

}


int main()
{
    struct stack s;
    struct stack * sptr;
    sptr = &s;
    sptr->top = -1;
    FILE *fp;
    FILE *fstack;
    FILE *fpop;
    FILE *fpush;
    int p=1,q=100;
    int rand_num;

    fp = fopen("input.txt", "r");

    fstack = fopen("stack.txt", "w");

    fpush = fopen("push.txt", "w");

    fpop = fopen("pop.txt", "w");

    int num, ch;

    while(fscanf(fp, "%d", &num) != EOF)
    {
        push(sptr, num, fstack, fpush);
    }

    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                rand_num = (rand()%(q-p+1))+p;
                push(sptr,rand_num,fstack,fpush);
                break;
            case 2:
                pop(sptr, fstack, fpop);
                break;
            case 3:
                display(sptr,fstack);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid choice\n");
                break;
        }
        fclose(fp);
        fclose(fstack);
        fclose(fpush);
        fclose(fpop);
    }
    return 0;
}

