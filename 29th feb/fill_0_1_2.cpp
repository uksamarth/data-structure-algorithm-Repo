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

    int c0=0,c1=0,c2=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
            c0++;
        else if (a[i]==1)
            c1++;
        else if (a[i]==2)
            c2++;
    }
    for(i=0;i<c0;i++)
    {
        a[i]=0;
    }
    for(i=c0;i<c0+c1;i++)
    {
        a[i]=1;
    }
    while(c2--)
    {
        a[i++]=2;
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i];
    }
    return 0;
}

