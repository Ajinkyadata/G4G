#include <iostream>
#include <queue>
using namespace std;/////not working

class point{
    public:
    int x; int y;
};


bool isvalid(int x,int y,int r,int c)
{
    return(x>=0 && y>=0 && x<r && y<c );
}

bool frame_end(point t)
{
    return(t.x==-1 && t.y==-1);
}


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int r,c;
	    cin>>r>>c;
	    int mat[r][c];
	    for(int i=0;i<r;i++)
	        for(int j=0;j<c;j++)
	            cin>>mat[i][j];
	            
	            
	    point temp;
        queue<point> q;
    
    
    
        for(int i=0;i<r;i++)
	        {
	            for(int j=0;j<c;j++)
	            {
	                if(mat[i][j]==2)
	                {
	                    temp.x=i; temp.y=j; q.push(temp);
	                }
	            }
	        }

        /* while(!q.empty())
        {
            cout<<q.front().x<<" "<<q.front().y<<"|";
            q.pop();
        }
	        cout<<endl; */
	        
	  temp.x=-1;temp.y=-1;q.push(temp);
	  int ans=0;

      temp=q.front();
        /* 
      if(mat[1][0]==1)
      cout<<"==="; */
	  
	  while(!q.empty())
	  {
	      bool flag=false;
	      
	      while(!frame_end(q.front()))
	      {
	          temp=q.front();
	          if(isvalid(temp.x+1,temp.y,r,c) && mat[temp.x+1][temp.y]==1)
	          {
	              if(flag==false)
	              {ans++;
	              flag=true;}
	              mat[temp.x+1][temp.y]=2;
	              temp.x++;
	              q.push(temp);
	              temp.x--;
	          }
	          if(isvalid(temp.x-1,temp.y,r,c) && mat[temp.x-1][temp.y]==1)
	          {
	              if(flag==false)
	              {ans++;
	              flag=true;}
	              mat[temp.x+1][temp.y]=2;
	              temp.x--;
	              q.push(temp);
	              temp.x++;
	          }
	          if(isvalid(temp.x,temp.y+1,r,c) && mat[temp.x][temp.y+1]==1)
	          {
	              if(flag==false)
	              {ans++;
	              flag=true;}
	              mat[temp.x+1][temp.y]=2;
	              temp.y++;
	              q.push(temp);
	              temp.y--;
	          }
	          if(isvalid(temp.x,temp.y-1,r,c) && mat[temp.x][temp.y-1]==1)
	          {
	              if(flag==false)
	              {ans++;
	              flag=true;}
	              mat[temp.x+1][temp.y]=2;
	              temp.y--;
	              q.push(temp);
	              temp.y++;
	          }
	        q.pop();
	      }
	      q.pop();

	      if(!q.empty())
	      {
	        temp.x=-1;temp.y=-1;q.push(temp);
	      }
	    }
	        int i,j;

            for(int i=0;i<r;i++)
	            for(int j=0;j<c;j++)
	            cout<<mat[i][j]<<" ";
                cout<<endl;


	    /* for(i=0;i<r;i++)
	    {
	      for(j=0;j<c;j++)
	            {
	                if(mat[i][j]==1)
	                cout<<"-1"<<endl;
                    break;
	            }
                if(mat[i][j]==1)
                break;
	  }
	  
	  cout<<ans<<endl; */          
	}
	return 0;
}