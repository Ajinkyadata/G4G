#include <bits/stdc++.h>
using namespace std;
int findIslands(vector<int> A[], int N, int M);
//Position this line where user code will be pasted.
int main() {
    
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		vector<int> A[N];
		for(int i=0;i<N;i++){
		    vector<int> temp(M);
		    A[i] = temp;
		    for(int j=0;j<M;j++){
		        cin>>A[i][j];
		    }
		}
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*you are required to complete this method*/
/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
bool safe(vector<int> a[], int i, int j,vector<bool> vis[])
{
    int col=a->size();
    //cout<<col<<endl;
    int row=a[0].size();
    
    return ((i<row) && (j<col) && (i>=0) && (j>=0) && (a[i][j] && vis[i][j]==false));
}


void DFS(vector<int> a[], int i, int j,vector<bool> vis[])
{
    int r[]={0,0,-1,1,-1,1,-1,1};
    int c[]={-1,1,1,-1,-1,1,0,0};
    
    vis[i][j]=true;
    
    for(int k=0;k<8;k++)
    {
        if(safe(a,i+r[k],j+c[k],vis))
        DFS(a,i+r[k],j+c[k],vis);
    }
}

int findIslands(vector<int> A[], int N, int M)
{
    
    // Your code here
    
    vector <bool> vis[N];
    for(int i=0;i<N;i++)
       { 
           vector <bool> temp(M);
           vis[i].push_back(0);
           
       }
        
        int count =0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j] && vis[i][j]==0)
            {
                DFS(A,i,j,vis);
                count++;
            }
            
        }
        //cout<<endl;
    }
    return count;
}