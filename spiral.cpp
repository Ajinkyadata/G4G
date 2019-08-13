/* Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Input: 
The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each testcase has 2 lines. First line contains M and N respectively separated by a space. Second line contains M*N values separated by spaces.

Output:
Elements when travelled in Spiral form, will be displayed in a single line.

Constraints:
1 <= T <= 100
2 <= M,N <= 10
0 <= Ai <= 100

Example:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7 */
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int a[m][n];
	    for (int i=0;i<m;i++)
	        for(int j=0;j<n;j++)
	            cin>>a[i][j];	            
	            
	    int r=0,rmax=m-1,c=0,cmax=n-1;
	    
 	    while(r<=rmax && c<=cmax )
	    {
	        for(int b=c;b<=cmax;b++)
	            cout<<a[r][b]<<" ";
	            r++;

	        for(int b=r;b<=rmax;b++)
	            cout<<a[b][cmax]<<" ";
	            cmax--;
				
				if(r<=rmax)
	        {for(int b=cmax;b>=c;b--)
	            cout<<a[rmax][b]<<" ";
	            rmax--;}

				if(c<=cmax)
	        {for(int b=rmax;b>=r;b--)
	            cout<<a[b][c]<<" ";
	            c++;}
	    }
	    cout<<endl;
	}
	return 0;
}