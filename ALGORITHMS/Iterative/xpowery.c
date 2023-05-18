#include<stdio.h>
#include<stdlib.h>

long int power(int x,int y)
{
    long int product =1;
    int i=0;
    while(i<y)
    {
        product = product*x;
        i++;
    }
    return product;
}
int main()
{
    int x,y;
    FILE *fp;
    printf("Enter the value of x\n");
    scanf("%d",&x);
    printf("Enter the value of y\n");
    scanf("%d",&y);
    fp = fopen("power.txt","w");
    fprintf(fp,"Value of x^y is:\n");
    long int result = power(x,y);
    fprintf(fp,"%lf",result);
    printf("Value of x^y is:\n");
    printf("%ld",result);
    fclose(fp);
    return 0;
}
