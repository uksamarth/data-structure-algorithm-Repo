#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cout<<"Enter the value of n and k:"<<endl;
    cin>>n>>k;
    int a[n],i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<"Kth min:"<<a[k-1]<<"Kth max:"<<a[n-k]<<endl;
    return 0;
}
