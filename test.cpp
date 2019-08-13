//Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include<bits/stdc++.h>
using namespace std;



int main()
{



    vector <int > a;
    int n=9;
    
    for(int i=0;i<5;i++)
    {
        a.push_back(n);
        n--;
    }
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    reverse(a.begin(),a.end());

    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }


    return 0;
}