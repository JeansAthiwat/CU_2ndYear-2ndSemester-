#include <bits/stdc++.h>
using namespace std;

class DAG
{
public:
    // adj matrix
    int V;
    vector<vector<int>> E;
    vector<int> in_deg;

    DAG(int v) : V(v)
    {
        E = vector<vector<int>>(v, vector<int>(v));
        in_deg = vector<int>(v, 0);
    }

    vector<int> adj(int from)
    {
        vector<int> vec;
        for (int to = 0; to < V; to++)
        {
            if (E[from][to] == 1)
                vec.push_back(to);
        }
        return vec;
    }

    void add_edge(int from, int to)
    {
        E[from][to] = 1;
    }

    void delete_edge(int from, int to)
    {
        E[from][to] = 0;
    }
};
void topo_sort_khan(DAG &G, vector<int> &order)
{
    queue<int> q;
    for (int node = 0; node < G.V; node++)
    {
        if (G.in_deg[node] == 0)
        {
            q.push(node);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        order.push_back(node);

        vector<int> tmp;
        for (auto &vertex : G.adj(node))
        {
            tmp.push_back(vertex);
        }

        for (auto &vertex : tmp)
        {
            //G.delete_edge(node, vertex);
            G.in_deg[vertex]--;

            if (G.in_deg[vertex] == 0)
            {
                q.push(vertex);
            }
        }
    }

    // check error here
}
int main()
{
    int N;
    cin >> N;
    DAG G(N);

    for (int to = 0; to < N; to++)
    {
        int M;
        cin >> M;
        while (M--)
        {
            int from;
            cin >> from;
            G.add_edge(from, to);
            G.in_deg[to]++;
        }
    }

    vector<int> order;

    topo_sort_khan(G, order);

    for (auto &x : order)
    {
        cout << x << " ";
    }

    return 0;
}