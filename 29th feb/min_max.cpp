#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n],i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int mini=INT_MAX,maxi=INT_MIN;

    for(i=0;i<n;i++)
    {
        if(arr[i]<mini)
            mini=arr[i];
    }

    for(i=0;i<n;i++)
    {
        if(arr[i]>maxi)
            maxi=arr[i];
    }
    cout<<"Maximum"<<maxi<<"Minimum"<<mini;
    return 0;
}
