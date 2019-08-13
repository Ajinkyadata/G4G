/* Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated elements.

Output:
For each test case, print the count of all triplets, in new line. If no such triplets can form, print "-1".

Constraints:
1 <= T <= 100
3 <= N <= 105
1 <= A[i] <= 106

Example:
Input:
2
4
1 5 3 2
3
3 2 7
Output:
2
-1 */
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n],c=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        // O(n2) nice code

        for(int i=n-1;i>=2;i--)
        {
            int l=0,r=i-1;
            while(l<r)
            {
                if(arr[i]==arr[l]+arr[r])
                {
                    c++;
                    l++;
                }
                else if (arr[i]>arr[l]+arr[r])
                l++;
                else
                {
                    r--;
                }
            }
        }
        
        if (c==0)
        cout<<"-1"<<endl;
        else
        cout<<c<<endl;
    }
    return 0;
}