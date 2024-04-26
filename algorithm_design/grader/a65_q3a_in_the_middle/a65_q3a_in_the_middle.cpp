#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;

class Graph
{
public:
    // adjecency lists
    // assuse simple undirected graph;
    // node index from 1-n
    int V;
    vector<vector<int>> E;

    Graph(int v)
    {
        V = v;
        E = vector<vector<int>>(v);
    }

    vector<int> adj(int from)
    {
        vector<int> adj_vertices;
        for (auto &to : E[from - 1])
        {
            adj_vertices.push_back(to + 1);
        }
        return adj_vertices;
    }

    void add_edge(int from, int to)
    {
        E[from - 1].push_back(to - 1);
    }
};

void print_g(Graph &G)
{
    cout << "print nodes adjs s---- \n";
    for (int node = 1; node <= G.V; node++)
    {
        cout << node << " : ";
        for (auto &x : G.adj(node))
        {
            cout << x << " ";
        }
        cout << " \n";
    }
}

vector<int> bfs_dist(int starting_node, Graph &G)
{
    // dist index 1-n
    vector<int> dist(G.V + 1, INF);

    queue<int> q;
    q.push(starting_node);
    dist[starting_node] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &vertex : G.adj(node))
        {
            if (dist[vertex] == INF)
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
    int n, t1, t2, t3;
    cin >> n >> t1 >> t2 >> t3;
    Graph G(n);

    for (int node = 1; node <= n; node++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int to;
            cin >> to;
            G.add_edge(node, to);
        }
    }

    vector<int> t1_cost = bfs_dist(t1, G);
    vector<int> t2_cost = bfs_dist(t2, G);
    vector<int> t3_cost = bfs_dist(t3, G);

    int min_cost = INF;
    for (int city = 1; city <= n; city++)
    {
        min_cost = min(min_cost,
                       max({
                           t1_cost[city],
                           t2_cost[city],
                           t3_cost[city],
                       }));
    }

    cout << min_cost;
    // print_g(G);
    return 0;
}