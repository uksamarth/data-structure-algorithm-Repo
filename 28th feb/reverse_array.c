#include<stdio.h>
void reverse_arr(int arr[],int size)
{
    int rev[size];
    for(int i=0;i<size;i++)
    {
        rev[i]=arr[(size-1)-i];
        printf("%d\t",rev[i]);
    }
}
int main()
{
    int arr[]= {1,2,3,4,5};
    int size= sizeof(arr)/sizeof(arr[0]);
    reverse_arr(arr,size);
    return 0;
}
