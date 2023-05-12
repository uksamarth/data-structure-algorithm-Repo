#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateRand(FILE *fptr,int p,int q,int n)
{
    int i;
    fptr = fopen("input.txt","w");
    printf("File has been created");
    for(i=0;i<n;i++)
    {
        int num = (rand()%(q-p+1))+p;
        fprintf(fptr,"%d ",num);
        printf("%d ",num);
    }
    fclose(fptr);
    return;
}

int main()
{
    FILE *fptr;
    int p,q,n =1;
    printf("Enter the lower value\n");
    scanf("%d",&p);
    printf("Enter the Higher value\n");
    scanf("%d",&q);
    printf("Enter the value of N\n");
    scanf("%d",&n);
    generateRand(fptr,p,q,n);
    return 0;

}
