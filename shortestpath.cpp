#include <bits/stdc++.h>

using namespace std;

class pt
{
    public:
    int x,y;  
};

class node
{
    public:
    pt p;
    int dist;
};


bool isvalid(int i, int j, int R ,int C)
{
    return ((i>=0) && (j>=0) && (i<R) && (j<C));
}

int BFS(vector <vector <int>> mat,vector <vector <bool>> vis,pt s, pt d)
{
    if((s.x==0 && s.y==0) || (d.x==0 && d.y==0))
    return -1;
    
    int row[]={1,-1,0,0};
    int col[]={0,0,1,-1};
    
    queue<node> q;
    
    node temp={s,0};
    
    q.push(temp);
    
    while(!q.empty())
    {
        node temp2=q.front();
        pt point=temp2.p;
        
        if((point.x==d.x) && (point.y=d.y))
        return temp2.dist;
        
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            pt point2=point;
            point2.x=point.x+row[i]; point2.y=point.y+col[i];
            if(isvalid(point2.x,point2.y,mat.size(),mat[0].size()) && mat[point2.x][point2.y] && !vis[point2.x][point2.y] )
            {
                vis[point2.x][point2.y]=true;
                node temp3={point2,temp2.dist+1};
                q.push(temp3);
            }
        }
    }
    
    return -1;
}

int main() {
	//code
	
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    vector <vector <int>> mat(m, vector<int>(n,0));
	    
	    for(int i=0;i<m ; i++)
	        for(int j=0;j<n;j++)
	            cin>>mat[i][j];
	            
	    int d1,d2;
	    cin>>d1>>d2;
	    pt d,s; 
	    d.x=d1;
	    d.y=d2;
	    s.x=0;
	    s.y=0;
	    vector <vector <bool>> vis(m, vector<bool>(n,0));
	    
	    cout<<BFS(mat,vis,s,d)<<endl;

	}
	return 0;
}