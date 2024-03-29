#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // adjecency lists
    // assuse simple undirected graph;
    int V;
    vector<vector<int>> E;

    Graph(int v, vector<vector<int>> &e)
    {
        V = v;
        E = e;
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

bool dfs_is_line(int start_vert, Graph &G, vector<bool> &visited, int parent_vertex)
{
    visited[start_vert] = true;

    for (auto &v : G.adj(start_vert))
    {
        if (visited[v] == false)
        {
            if (!dfs_is_line(v, G, visited, start_vert))
            {
                return false;
            }
        }
        // indicate a circuits
        else if (visited[v] == true && v != parent_vertex)
        {
            return false;
        }
    }

    if (G.adj(start_vert).size() > 2)
        return false;

    return true;
}

int cc_and_line(Graph G)
{
    int line_graph_count = 0;

    vector<bool> visited(G.V, 0);

    for (int vert = 0; vert < G.V; vert++)
    {
        // not visited yet
        if (visited[vert] == false)
        {
            if (dfs_is_line(vert, G, visited, -1))
            {
                line_graph_count++;
            }
        }
    }

    return line_graph_count;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(v);

    Graph G(v, edges);
    while (e--)
    {
        int v1, v2;
        cin >> v1 >> v2;

        G.add_edge(v1, v2);
    }
    cout << cc_and_line(G);
    return 0;
}