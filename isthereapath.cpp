#include <bits/stdc++.h>
using namespace std;

bool valid(vector<vector<int>> mat,int i,int j) 
{
    if(i>=0 && i<mat.size() && j>=0 
                       && j<mat.size()) 
            return true; 
        return false;
}

bool find(vector<vector<int>> mat,vector<vector<bool>> &vis,int i,int j)
{
    if(valid(mat,i,j) && !vis[i][j] && mat[i][j]!=0 )
    {
        vis[i][j]=true;
        
        if(mat[i][j]==2)
        return true ;        
        
        if(find(mat,vis,i+1,j) ||find(mat,vis,i-1,j) || find(mat,vis,i,j+1) ||find(mat,vis,i,j-1))
        return true;
    }
    return false;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<vector<int>> mat(n,vector<int> (n));
	    
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            cin>>mat[i][j];
	            
	   
	   vector<vector<bool>> vis(n,vector<bool> (n,false));
	   
	   int u,v;
       bool flag=0;
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            if(mat[i][j]==1 && !vis[i][j])
	            {
                    if(find(mat,vis,i,j))
                    {
                        flag=1;
                        break;
                    }
	            }
	   
	   
	   cout<<(flag==1)<<endl;
	}
	
	return 0;
}