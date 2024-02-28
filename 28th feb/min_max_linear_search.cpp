#include<iostream>
#include<algorithm>
using namespace std;
struct ABC {
    int min;
    int max;
};
ABC arrmin_max(int arr[],int arr_size)
{
    struct ABC a;
    int i;
    if (arr_size==1)
    {
        a.min=arr[0];
        a.max=arr[0];
        return a;
    }
    if(arr[0]>arr[1])
    {
        a.min=arr[1];
        a.max=arr[0];
    }
    else
    {
        a.min = arr[0];
        a.max = arr[1];
    }
    for(i=2;i<arr_size;i++)
    {
        if(arr[i]>a.max)
        {
            a.max = arr[i];
        }
        else if(arr[i]<a.min)
            a.min = arr[i];
    }
    return a;
}

int main()
{
    int arr[]= {1,2,3,5,6,7,8};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    struct ABC a= arrmin_max(arr,arr_size);
    cout<<"Minimum element is "<<a.min<<endl;
    cout<<"Maximum element is "<<a.max<<endl;
}

