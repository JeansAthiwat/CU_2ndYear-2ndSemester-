#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int V;
    vector<vector<int>> E;

    Graph(int V, vector<vector<int>> &E) : V(V + 1), E(E)
    {
    }

    vector<int> adj(int u)
    {
        vector<int> v;
        for (auto &x : E[u])
        {
            v.push_back(x);
        }

        return v;
    }

    void add_edges(int u, int v)
    {
        E[u].push_back(v);
        E[v].push_back(u);
    }
};

void bfs_cc(int startV, Graph G, vector<int> &visited, int cc_type)
{

    queue<int> q;
    q.push(startV);
    visited[startV] = cc_type;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        for (auto &v : G.adj(vertex))
        {
            if (visited[v] == 0)
            {
                visited[v] = cc_type;
                q.push(v);
            }
        }
    }
}
int cc_count(Graph G)
{
    int cc_type = 0;
    vector<int> visited(G.V, 0);
    for (int v = 1; v < G.V; v++)
    {
        if (visited[v] == 0)
        {
            cc_type++;
            bfs_cc(v, G, visited, cc_type);
        }
    }
    // will try using
    return cc_type;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(v + 1);
    Graph G(v, edges);
    while (e--)
    {
        int u, v;
        cin >> u >> v;

        G.add_edges(u, v);
    }

    cout << cc_count(G);
}