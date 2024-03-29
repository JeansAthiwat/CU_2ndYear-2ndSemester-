#include <bits/stdc++.h>
using namespace std;

class Graph
{
    // graph as adjecency lists
public:
    int V;
    vector<set<int>> E;

    Graph(int n, vector<set<int>> e)
    {
        V = n;
        E = e;
    }

    set<int> adj(int vertex1)
    {
        set<int> adj_vertices;
        for (auto &vertex2 : E[vertex1])
        {
            adj_vertices.insert(vertex2);
        }

        return adj_vertices;
    }

    bool has_edge(int vertex1, int vertex2)
    {
        for (auto &v : E[vertex1])
        {
            if (v == vertex2)
                return true;
        }
        return false;
    }

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

int main()
{
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

        graph.print_edges();
    }
    return 0;
}