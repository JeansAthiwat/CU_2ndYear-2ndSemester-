#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;

class Graph
{
public:
    // adjecency lists
    // assuse simple undirected graph;
    int V;
    vector<vector<int>> E;

    Graph(int v)
    {
        V = v;
        E = vector<vector<int>>(v);
    }

    vector<int> adj(int v)
    {
        vector<int> adj_vertices;
        for (auto &u : E[v])
        {
            adj_vertices.push_back(u);
        }
        return adj_vertices;
    }

    void add_edge(int v1, int v2)
    {
        E[v1].push_back(v2);
        E[v2].push_back(v1);
    }
};

vector<int> bfs_dist(int base_node, Graph &G)
{
    vector<int> dist(G.V, -1);

    // using bfs queue

    // initial condition
    queue<int> q;
    dist[base_node] = 0;
    q.push(base_node);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &vertex : G.adj(node))
        {
            if (dist[vertex] == -1)
            {
                dist[vertex] = dist[node] + 1;
                q.push(vertex);
            }
        }
    }

    return dist;
}
int main()
{
    int n, e, k;
    cin >> n >> e >> k;
    Graph G(n + 1); // 0 - n

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        G.add_edge(u, v);
    }

    vector<int> dist = bfs_dist(0, G);

    int distK = 0;
    for (auto &value : dist)
    {
        if (value == k)
        {
            distK++;
        }
    }

    cout << distK;
    return 0;
}