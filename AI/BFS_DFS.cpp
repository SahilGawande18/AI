#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

    public:
    
    Graph(int V):V(V)
    {
        adj.resize(V);
    }

    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start)
    {
        vector<bool> visited(V,false);
        stack<int> st;

        st.push(start);

        while(!st.empty())
        {
            int v=st.top();
            st.pop();

            if(!visited[v])
            {
                cout<<" "<<v;
                visited[v]=true;
            }

            for(int u: adj[v])
            {
                if(!visited[u])
                {
                    st.push(u);
                }
            }
        }
    }

    void BFS(int start)
    {
        queue<int>q;
        vector<bool> visited(V,false); 

        q.push(start);
        visited[start]=true;

        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            cout<<" "<<v;

            for(int u:adj[v])
            {
                if(!visited[u]) 
                {
                    visited[u]=true; 

                    q.push(u);
                }
            }
        }
    }
};

int main()
{
    int V,E;
    cout<<"Enter number of vertex and edge:";
    cin>>V>>E;

    Graph g(V);

    
    int u,v;
    for(int i=0;i<E;i++)
    {
        cout<<"Enter edges:";
        cin>>u>>v;
        g.addEdge(u,v);
    }


    int start;
    
    cout<<"Enter Start:";
    cin>>start;

    cout<<"DFS:";
    g.DFS(start);

    cout<<"\nBFS:";
    g.BFS(start);

}
