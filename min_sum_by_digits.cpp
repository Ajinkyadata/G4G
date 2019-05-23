/*Given an array of digits (values are from 0 to 9), 
find the minimum possible sum of two numbers formed 
from digits of the array. All digits of given array must 
be used to form the two numbers.

Input:

The first line of input contains an integer T denoting 
the number of test cases. Then T test cases follow. 
First line of each test case contains an integer N 
denoting the size of the array. Next line of each test 
contains N space seperated integers denoting the elements 
the array.
Output:

For each test case output a single line containing the 
required sum.
Constraints:

1<=T<=100
1<=N<=50
Example:

Input

2
6
6 8 4 5 2 3
5
5 3 0 7 4

Output

604
82*/

#include <iostream>
#include <array>
#include <algorithm>
#include<iterator>
using namespace std;

//int arr[50];
int main()
{
    int T;
    array<int,50> arr;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int N;
        cin>>N;

        for(int j=0;j<N; j++)
        cin>>arr[j];

        for(int j=0;j<N; j++)
        cout<<arr.at(j)<<endl;

        sort(arr.begin(),arr.end());

        for(int j=0;j<arr.size(); j++)
        cout<<arr.at(j)<<endl;
        
        int n1=0,n2=0;
        for(int i=0,j=1; i<N; i++,j=j*10)
        {
            n1+=arr[i]*j;
            i++;
            n2+=arr[i]*j;
        }

        cout<<n1+n2<<endl;

    }
    
}