#include<stdio.h>

void bubblesort(int a[],int size)
{
    int i,j,temp;

    for(i=0;i<size-1;i++)
    {
        for(j=0;j=size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int arr[]= {25,17,31,13,2};
    int i;

    printf("Bubble sorting\n");
    printf("Array before sorting\n");
    for(i=0;i<5;i++)
    {
        printf("%d\t",arr[i]);
    }
    bubblesort(arr,5);

    printf("\n Array after sorting\n");
    for(i=0;i<5;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
