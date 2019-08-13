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
(1 4) (5 9)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line. */

#include<iostream>
#include<cmath>
using namespace std;

int fun(int start,int n,int a[])
{
    for(int i=start+1;i<n;i++)
    {
        if(a[start]>a[i])
        {
            return i;
        }
    }
    return n-1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int in[n];
        for(int i=0;i<n;i++)
            cin>>in[i];
        /* for(int i=0;i<n;i++)
            cout<<in[i]; */
        int k,j=0;
        while(j<n)
        {
            k=fun(j,n,in);
            cout<<k-1<<" ";
            j=k;
        }

    }
    return 0;
}