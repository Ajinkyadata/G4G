// adjacency list 
#include<iostream>
#include<list>
#include<cstring>
using namespace std;


void DFS(list <int > adj[],bool vis[],int s)
{
    vis[s]=true;
    cout<<s<<" ";

    for(auto i=adj[s].begin(); i!=adj[s].end(); i++)
    {
        if(vis[*i]==false)
        DFS(adj,vis,*i);
    }
}


int main()
{
    int E,V,u,v;
    cin>>V>>E;
     list <int > adj[V];
    for(int i=0;i<E;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //bool vis[V]={false};
    bool vis[V];
    memset(vis,false,sizeof(vis));
    int s=0;
    DFS(adj,vis,s);    
   
    return 0;
}

