#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<0)
            {
                swap(a[i],a[j]);
                j++;
            }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i];
    }
    return 0;
}


