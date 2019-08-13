/* Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Expected Time Complexity: O(n)

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4

Output:
7
15 */

#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int part(int arr[],int l,int h)
{
    int piv=l;
    int i=l,j=h;
    while(i<j)
    {
    do{
        i++;
    }while(arr[i]<=arr[piv]);

    do{
        j--;
    }while(arr[j]>arr[piv]);

    if(i<j)
    swap(&arr[i],&arr[j]);
    }
    swap(&arr[j],&arr[piv]);

    return j;
}

void quick(int arr[],int l,int h,int k)
{
    int j;
    if(l<h)
    {
        j=part(arr,l,h);
        if(j==k)
        {cout<<arr[j-1]<<endl;}
        else if(j<k)
        quick(arr,j+1,h,k);
        else
        quick(arr,l,j,k);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n]={0};
        for(int i=0;i<n;i++)
        cin>>arr[i];
        /* for(int i=0;i<n;i++)
        cout<<arr[i]; */
        int k;
        cin>>k;
        arr[n]=999999;
        int l=0,h=n+1;
        quick(arr,l,h,k);
        //cout<<j<<endl;       

        return 0;       
    }
}