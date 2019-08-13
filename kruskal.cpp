#include<bits/stdc++.h>
using namespace std;

class Edge{public: int src, des, wgt; };
class graph
{ public:
    int V,E;  
    Edge *edge;
    /* graph(int x,int y)
    {
        this->V=x;
        this->E=y;
        Edge *edge=new Edge[E];
    }  */
};

class subset{ public: int rank, parent; };

int find(subset y[], int x)
{
    if(y[x].parent!=x)
    y[x].parent=find(y, y[x].parent);

    return y[x].parent;
}

void union_(subset y[],int x,int z)
{
    int u=find(y,x);
    int v=find(y,z);

    if(y[u].rank<y[v].rank)
        y[u].parent=v;
    else if (y[u].rank>y[v].rank)
        y[v].parent=u;
    else
    {
        y[v].parent=u;
        y[u].rank++;
    }
}

bool compare(Edge a, Edge b)
{
    return (a.wgt<b.wgt);
}

void kruskal(graph *g)
{
    int V=g->V;
    int E=g->E;

    Edge res[V];

    subset *sbt= new subset[V];
    
    sort(g->edge,g->edge+E, compare);

    for(int i=0;i<V;i++)
    {
        sbt[i].parent=i;
        sbt[i].rank=0;
    }

    int i=0,e=0;
    while(e<V-1 && i<E)
    {
        Edge next=g->edge[i++];
        int u=find(sbt,next.src);
        int v=find(sbt,next.des);

        if(u!=v)
        {
            res[e++]=next;
            union_(sbt,u,v);
        }
    }

    for(int j=0; j<e; j++)
    {
        cout<<res[j].src<<" -- "<<res[j].des<<" == "<<res[j].wgt<<endl;  
    }
}

graph* create(int x,int y)
{
    graph* temp= new graph;
    temp->V=x;
    temp->E=y;
    temp->edge = new Edge[y];
    return temp;
}

int main()
{   
    graph *g=create(4,5);
    g->edge[0].src = 0; 
	g->edge[0].des = 1; 
	g->edge[0].wgt = 10; 

	g->edge[1].src = 0; 
	g->edge[1].des = 2; 
	g->edge[1].wgt = 6; 

	g->edge[2].src = 0; 
	g->edge[2].des = 3; 
	g->edge[2].wgt = 5; 

	g->edge[3].src = 1; 
	g->edge[3].des = 3; 
	g->edge[3].wgt = 15; 

	g->edge[4].src = 2; 
	g->edge[4].des = 3; 
	g->edge[4].wgt = 4; 

	kruskal(g);


    return 0;
}