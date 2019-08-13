/* Given two n-ary tree's the task is to check if they are mirror of each other or not.

Example

     1                    1
   /    \                 /   \
 2      3             3     2

Output: 1

    1                      1
   /  \                    /  \
 2    3                2    3

Output: 0

Note: you may assume that root of both the given tree as 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains two space separated values n and e denoting the no of nodes and edges respectively. Then in the next line two lines are 2*e space separated values u,v denoting an edge from u to v for the both trees .

Output:
For each test case in a new line print 1 if both the trees are mirrors of each other else print 0.

Constraints:
1<=T<=20
1<=n<=15
1<=e<=20

Example:
Input:
2
3 2
1 2 1 3
1 3 1 2
3 2
1 2 1 3
1 2 1 3
Output:
1
0 */
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;



bool check( vector<stack <int>>& t1,vector<queue <int>>& t2)
{
        
        for(int i=1;i<t1.size();i++)
        {
            stack <int>& tt1=t1[i];
	        queue <int>& tt2=t2[i];
	    
	        while(!tt1.empty() && !tt2.empty())
	      {
	        int a=tt1.top(); tt1.pop();cout<<a<<"]]";
	        int b=tt2.front(); tt2.pop();cout<<b<<"]]";
	        if(a!=b)
	        return 0;
	        
	      }

	        if(!tt1.empty() || !tt2.empty())
	        return 0;
	    }
	    return 1;
}

int main() {
	//code
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,e;
	    cin>>n>>e;
	    vector <int> u1,u2,v1,v2;
	    for(int i=0;i<e;i++)
	    {
	        int u,v;
	        cin>>u>>v;
	        u1.push_back(u);
	        v1.push_back(v);
	    }
	    for(int i=0;i<e;i++)
	    {
	        int u,v;
	        cin>>u>>v;
	        u2.push_back(u);
	        v2.push_back(v);
	    }
	    
	    vector<stack <int>> tree1(n+1);
	    vector<queue <int>> tree2(n+1);
	    
	    for(int i=0;i<e;i++)
	    {tree1[u1[i]].push(v1[i]);
	    tree2[u2[i]].push(v2[i]);}

		cout<<tree1[1].top()<<"||";
	    
	    if (check(tree1,tree2))
	    cout<<"1"<<endl;
	    else
	    cout<<"0"<<endl;
	    
	}
	return 0;
}