#include<iostream>
using namespace std;

int arr[100];
int thanos_snap(int l,int h)
{
    return (h-l)/2;
}


bool check(int l, int h)
{
    for(int i=l; i<h; i++)
    {
        if(arr[i]>arr[i+1])
        return false;
    }
    return true;
}


int snap_out(int l,int h)
{
    bool sorted,sortedA,sortedB;

    if(l==h)
    return 1;

    sorted=check(l,h);    
    if(sorted==true)
    return h+1;
    else
    {
        int mid;
        mid=thanos_snap(l,h);
        sortedA=check(l,mid);
        sortedB=check(mid+1,h);
        if(sortedA==true||sortedB==true)
        return mid+1;
        else
        {
            snap_out(l,mid);
            snap_out(mid+1,h);
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n;i++)
    cin>>arr[i];
    int l,h;
    l=0,h=n-1;
    cout<<snap_out(l,h);
    return 0;
}
