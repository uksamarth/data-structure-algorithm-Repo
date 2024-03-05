#include<iostream>
#include<algorithm>
using namespace std;

int findduplicate(int arr[100],int n)
{
    int duplicate;
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1])
        {
            duplicate = arr[i];
            break;
        }
    }
    return duplicate;
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //int a_size = sizeof(arr)/sizeof(arr[0]);
    int x= findduplicate(arr,n);
    cout<<"the duplicate number is:"<<x;
    return 0;
}
