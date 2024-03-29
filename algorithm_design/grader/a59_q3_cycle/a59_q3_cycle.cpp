#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int V;
    vector<vector<int>> E;

    Graph(int V, vector<vector<int>> &E) : V(V), E(E)
    {
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
bool dfs(int starting_vertex, Graph &graph, vector<int> &visited_depth, int parent, int &cycle_len)
{

    for (auto &v : graph.adj(starting_vertex))
    {
        if (visited_depth[v] == -1)
        {
            visited_depth[v] = visited_depth[starting_vertex] + 1;
            if (dfs(v, graph, visited_depth, starting_vertex, cycle_len))
                return true;
        }
        else if (visited_depth[v] != -1 && v != parent)
        {
            cycle_len = visited_depth[starting_vertex] - visited_depth[v] + 1;
            return true;
        }
    }
    return false;
}

int find_cycle_len(Graph &graph)
{
    // using depths first search to find the shortest path for a circuits (could also use bredths? but takes lots of memory worst case)

    // initialize the visited with -1 means havnt gone yet
    vector<int> visited_depth(graph.V, -1);
    int cycle_len = -1;
    visited_depth[0] = 0;
    dfs(0, graph, visited_depth, -1, cycle_len);
    return cycle_len;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> edges(n);
    Graph graph(n, edges);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        graph.add_edge(u, v);
    }

    int cycle_len = find_cycle_len(graph);
    cout << cycle_len;

    return 0;
}