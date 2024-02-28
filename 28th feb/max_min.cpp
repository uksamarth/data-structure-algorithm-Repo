#include<iostream>
#include<algorithm>
using namespace std;
struct Pair{
    int min;
    int max;
};

Pair arrmin_max(int arr[],int size)
{
    Pair a;
    sort(arr,arr+size);
    a.min = arr[0];
    a.max = arr[size-1];
    return a;
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    Pair a = arrmin_max(arr,size);
    cout<<"Minimum element is:"<<a.min<<endl;
    cout<<"Maximum element is:"<<a.max<<endl;
    return 0;
}
// O(n log n)
