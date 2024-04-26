#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    vector<vector<int>> E;

    Graph(int V) : V(V)
    {
        E = vector<vector<int>>(V, vector<int>(V));
    }

    vector<int> adj(int u)
    {
        vector<int> adj_vertices;
        for (int i = 0; i < V; i++)
        {
            if (E[u][i] == 1)
            {
                adj_vertices.push_back(i);
            }
        }
        return adj_vertices;
    }

    void add_edge(int u, int v)
    {
        E[u][v] = 1;
        E[v][u] = 1;
    }
};

int bfs_k_degree(int start_v, Graph &G, int max_depth)
{
    int total_connection = 1;
    int depth = 0;
    vector<int> visited_degree(G.V, -1);
    queue<int> q;
    q.push(start_v);
    // assume we know ourself
    visited_degree[start_v] = 0;
    while (!q.empty() && visited_degree[q.front()] < max_depth)
    {
        int v_front = q.front();
        q.pop();
        for (auto &adj_v : G.adj(v_front))
        {
            if (visited_degree[adj_v] == -1)
            {
                visited_degree[adj_v] = visited_degree[v_front] + 1;
                q.push(adj_v);
                total_connection++;
            }
        }
    }

    return total_connection;
}

int main()
{
    int N, E, K;
    cin >> N >> E >> K;
    Graph G(N);

    while (E--)
    {
        int u, v;
        cin >> u >> v;

        G.add_edge(u, v);
    }

    int max_k_degree = -1;

    // do bfs for each node
    for (int node = 0; node < G.V; node++)
    {
        max_k_degree = max(max_k_degree, bfs_k_degree(node, G, K));
    }
    cout << max_k_degree;
}
