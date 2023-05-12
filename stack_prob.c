#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};

void push(struct stack *sptr, int num, FILE *log, FILE *fpush)
{
    log = fopen("logfile.txt", "a");
    fpush = fopen("push.txt", "a");
    if(sptr->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;

        sptr->data[sptr->top] = num;

        fprintf(log, "push\n", num);

        fprintf(fpush, "%d\n", num);

    }
        fclose(log);
        fclose(fpush);

}

void pop(struct stack *sptr, FILE *log, FILE *fpop)
{
    log = fopen("logfile.txt", "a");
    fpop = fopen("pop.txt", "a");
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

        fprintf(log, "pop\n");

        fprintf(fpop, "%d\n", num);
    }

        fclose(log);
        fclose(fpop);
}

void display(struct stack *sptr, FILE *fstack) {
    fstack = fopen("stack.txt","a");
    if (sptr->top == -1) {
        printf("Stack empty\n");
        return;
    }
    fprintf(fstack, "Currently stack has: ");
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
    FILE *fstack;
    FILE *fpop;
    FILE *fpush;
    FILE *log;
    int p=1,q=100;
    int rand_num;


    fstack = fopen("stack.txt", "a");

    fpush = fopen("push.txt", "a");

    fpop = fopen("pop.txt", "a");
    log = fopen("logfile.txt","a");

    int num, ch;

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

        fclose(fstack);
        fclose(fpush);
        fclose(fpop);
        fclose(log);
    }
    return 0;
}

