/* Given an array arr[] of size N where every element is in range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]]. This should be done with O(1) extra space.

Input:
First line contains an integer denoting the test cases 'T'. First line of each test case contains an integer value depicting size of array 'N' and next line contains N space separated integers denoting the elements of the array.

Output:
Print all elements of the array after rearranging, each separated by a space, in separate line for each test case.

Constraints:
1 <= T <= 100
1 <= N<= 107
0 <= Arr[i] < N

Example:
Input:
3
2
1 0
5
4 0 2 1 3
4
3 2 0 1

Output:
0 1
3 4 2 0 1
1 0 3 2 */

#include <iostream>
#include<vector>
using namespace std;



void rearr(vector<long int> &V)
{
    int N=V.size();
    for(int i=0;i<N;i++)
    {
        V[i]=V[i]+(V[V[i]]%N)*N;
    }
    
    for(int j=0;j<N;j++)
    {
        V[j]=V[j]/N;
    }    
}

int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int N;
	    cin>>N;
	    vector<long int> V;
	    for(int j=0;j<N;j++)
	    {
	        int t;
	        cin>>t;
	        V.push_back(t);
	    }
	    
	    rearr(V);
	    for(int j=0;j<N;j++)
	        cout<<V.at(j)<<" ";
	        cout<<"\n";
	}
	return 0;
}