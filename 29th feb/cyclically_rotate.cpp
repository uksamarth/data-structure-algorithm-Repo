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

    int last = a[n-1];
    for(i=n-1;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=last;

    for(i=0;i<n;i++)
    {
        cout<<a[i];
    }

    //right shift
    //std::rotate(v.begin(),v.begin()+v.size()-k,v.end())
    //left shift
    //std::rotate(v.begin(),v.begin()+k,v.end())
    return 0;
}


