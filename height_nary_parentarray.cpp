#include <bits/stdc++.h> 
using namespace std; 

int findh(int p[],int n)
{
    int currh=-1,maxh=-1;

    for(int i=0;i<n;i++)
    {
        currh=0;
        int j=i;
        while(p[j]!=-1)
        {
            currh++;
            j=p[j];
        }
        if(currh>maxh)
        maxh=currh;
    }
    return maxh;
}

int main() 
{ 
    int parent[] = { -1, 0, 0, 0, 3, 1, 1, 2 }; 
    int n = sizeof(parent) / sizeof(parent[0]); 
  
    cout << "Height of N-ary Tree = "
         << findh(parent, n); 
    return 0; 
}