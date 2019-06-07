/* Given an unsorted array of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Note: If you find multiple answers then print the Smallest number found. Also, expected solution is O(n) time and constant extra space.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print B, the repeating number followed by A which is missing in a single line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ A[i] ≤ N

Example:
Input:
2
2
2 2
3 
1 3 3

Output:
2 1
3 2 */


#include<iostream>
#include<vector>

using namespace std;

/* int main()
{
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int n,arr[100000],B[100000];
        cin>>n;
        for(int i=0; i<n;i++)
        {
            cin>>arr[i];
        } 
        for(int i=0;i<=n;i++)
            B[i]=0;
        
        int repe,miss;
        for(int i=0;i<n;i++)
        {
            if(B[arr[i]]<0)
            repe=arr[i];
            B[arr[i]]=-1;
        } 

        for(int i=1;i<n;i++)
        {
            if(B[i]>=0)
            miss=i;
        } 
        cout<<repe<<" "<<miss<<endl;        
    }
    return 0;
} */

int main()
{
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int n;
        vector<int> v;
        cin>>n;
        int B[n]={0};
        for(int i=0; i<n;i++)
        {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }                 
        int repe,miss;
        for(int i=0;i<n;i++)
        {
            if(B[v.at(i)]<0)
            repe=v.at(i);
            B[v.at(i)]=-1;
        } 

        for(int i=1;i<=n;i++)
        {
            if(B[i]!=-1 && B[i]!=-2)
            miss=i;
        } 
        cout<<repe<<" "<<miss<<endl;        
    }
    return 0;
}

