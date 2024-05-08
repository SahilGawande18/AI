#include<iostream>
#include<climits>
#define N 10
using namespace std;


int minkey(int key[],bool Set[],int V)
{
    int min=INT_MAX,index;
    for (int i=0;i<V;i++)
    {
        if(!Set[i] && key[i]<min)
        {
            min=key[i];
            index=i;
        }
    }
    return index;
}

void print(int parent[],int graph[][N],int V)
{
    cout<<"\nPair\tWeight";

    for(int i=1;i<V;i++)
    {
        cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<endl;
    }
}

void MST(int graph[][N],int V)
{
    int key[V];
    int parent[V];

    bool Set[V];

    for(int i=0;i<V;i++)
    {
       key[i]=INT_MAX;
       Set[i]=false;
    }

    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<V-1;i++)
    {
        int u=minkey(key,Set,V);
        Set[u]=true;

        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && !Set[v] && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
                
            }
        }
    }
    print(parent,graph,V);
}
int main()
{
    int V;
    cout<<"Enter number of edges:";
    cin>>V;
    int graph[V][N];
    cout<<"Enter matrix:"<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }

    MST(graph,V);
}