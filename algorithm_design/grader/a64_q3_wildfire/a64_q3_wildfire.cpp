#include <bits/stdc++.h>
using namespace std;

class Graph
{
    // using adj matrix
public:
    int V;
    vector<vector<int>> E;

    Graph(int V, vector<vector<int>> &E) : V(V), E(E)
    {
    }

    vector<int> adj(int v)
    {
        vector<int> adj_vertices;
        for (int c = 0; c < V; c++)
        {
            if (E[v][c] == 1)
                adj_vertices.push_back(c);
        }

        return adj_vertices;
    }

    void add_edge(int from, int to)
    {
        E[from][to] = 1;
    }
};

void dfs(int starting_vertex, Graph &G, vector<int> &beautifulness)
{
    beautifulness[starting_vertex] = 0;
    for (auto &adj_v : G.adj(starting_vertex))
    {
        if (beautifulness[adj_v] != 0)
        {
            beautifulness[adj_v] = 0;
            dfs(adj_v, G, beautifulness);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> edges(n, vector<int>(n));

    Graph G(n, edges);
    vector<int> beautifulness(n);
    vector<int> start_node(k);

    for (int i = 0; i < n; i++)
        cin >> beautifulness[i];

    for (int i = 0; i < k; i++)
        cin >> start_node[i];

    while (m--)
    {
        int from, to;
        cin >> from >> to;

        G.add_edge(from, to);
    }

    for (auto &start_vertex : start_node)
    {
        dfs(start_vertex, G, beautifulness);
        int sum = 0;
        for (auto &value : beautifulness)
        {
            sum += value;
        }
        cout << sum << " ";
    }

    return 0;
}