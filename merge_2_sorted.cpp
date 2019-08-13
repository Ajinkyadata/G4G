/* Given two sorted arrays P[] and Q[] in non-decreasing order with size X and Y. The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).

Note: Expected time complexity is O((X+Y) log(X+Y)). DO NOT use extra space.

Input:
First line contains an integer T, denoting the number of test cases. First line of each test case contains two space separated integers X and Y, denoting the size of the two sorted arrays. Second line of each test case contains X space separated integers, denoting the first sorted array P. Third line of each test case contains Y space separated integers, denoting the second array Q.

Output:
For each test case, print (X + Y) space separated integer representing the merged array.

Constraints:
1 <= T <= 100
1 <= X, Y <= 5*104
0 <= Pi, Qi <= 109

Example:
Input:
1
4 5
1 3 5 7
0 2 6 8 9

Output:
0 1 2 3 5 6 7 8 9 */
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,p;
	    cin>>n>>p;
	    int arr[n],arr1[p];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    for(int i=0;i<p;i++)
	    cin>>arr1[i];
	    int a=n+p;
	    int ans[a]={0};
	    int k=0,i=0,j=0;
	    while(1)
	    {
	        if(arr[i]<arr1[j])
	        {
	            ans[k]=arr[i++];
	        }
	        else
	        {
	            ans[k]=arr1[j++];
	        }
	        k++;
	        if(i>=n||j>=p)
	            break;
	    }
	    while(i<n)
	    {ans[k++]=arr[i++];}
	    while(j<p)
	    {ans[k++]=arr1[j++];}
	    
	   for(int i=0;i<a;i++) 
	   cout<<ans[i]<<" ";
	   cout<<endl;
	    
	}
	return 0;
}
