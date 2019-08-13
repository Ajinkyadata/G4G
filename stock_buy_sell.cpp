/* The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input: 
First line contains number of test cases T. First line of each test case contains an integer value N denoting the number of days, followed by an array of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

Constraints:
1 <= T <= 100
2 <= N <= 103
0 <= Ai <= 104

Example
Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
(1 4) (5 9) */
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
		/*for(int i=0;i<n;i++)
	    cout<<arr[i]<<" ";
		cout<<endl;*/
	    
	    int k=1,j=0,profit,np=0;
	    while(k<n)
	    {
	        profit=0;
	        while(profit< arr[k]-arr[j] && k<n)
	        {
	            profit=arr[k]-arr[j];
	            np=profit;
	            k++;
	        }
			if(j!=k-1)
	        {cout<<"("<<j<<" "<<k-1<<")"<<" ";}
	        j=k;
            k++;
	    }
	    if(np==0)
            cout<<"No Profit";
	    cout<<endl;
	}
	return 0;
}