#include <bits/stdc++.h>
using namespace std;

class Graph
{
    // graph as adjecency lists
public:
    int V;
    vector<set<int>> E;

    Graph(int n, vector<set<int>> &e)
    {
        V = n;
        E = e;
    }

    set<int> adj(int vertex1)
    {
        set<int> adj_vertices;
        for (auto vertex2 : E[vertex1])
        {
            adj_vertices.insert(vertex2);
        }

        return adj_vertices;
    }

    /*bool has_edge(int vertex1, int vertex2)
    {
        for (auto &v : E[vertex1])
        {
            if (v == vertex2)
                return true;
        }
        return false;
    }*/

    void add_edge(int vertex1, int vertex2)
    {
        E[vertex1].insert(vertex2);
        E[vertex2].insert(vertex1);
    }

    void remove_edge(int vertex1, int vertex2)
    {
        E[vertex1].erase(vertex2);
        E[vertex2].erase(vertex1);
    }

    void print_edges()
    {
        cout << "-----------------------\n";
        for (int i = 0; i < V; i++)
        {
            cout << "vertex " << i << " : ";
            for (auto &x : E[i])
            {
                cout << x << " ";
            }
            cout << "\n";
        }
        cout << "-----------------------\n";
    }
};

bool dfs_cd(int v_start, Graph &graph, vector<bool> &visited, int parent)
{
    visited[v_start] = true;
    for (auto &vertex : graph.adj(v_start))
    {
        if (visited[vertex] == false)
        {
            if (dfs_cd(vertex, graph, visited, v_start))
                return true;
        }
        else if (visited[vertex] == true && vertex != parent)
        {
            return true;
        }
    }
    return false;
}

bool circuit_detect(Graph &graph)
{
    vector<bool> visited(graph.V, false);

    for (int v = 0; v < graph.V; v++)
    {
        if (visited[v] == false)
        {
            if (dfs_cd(v, graph, visited, -1))
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {

        int N, e;
        cin >> N >> e;
        vector<set<int>> edges(N);
        Graph graph = Graph(N, edges);

        while (e--)
        {
            int v1, v2;
            cin >> v1 >> v2;
            graph.add_edge(v1, v2);
        }

        if (circuit_detect(graph))
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
        // graph.print_edges();
    }
    return 0;
}