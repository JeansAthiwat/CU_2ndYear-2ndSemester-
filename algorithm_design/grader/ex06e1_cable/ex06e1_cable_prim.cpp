#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
class Graph
{
public:
    // adj matrix
    int V;
    vector<vector<int>> E;
    vector<vector<int>> W;

    Graph(int v) : V(v)
    {
        E = vector<vector<int>>(v, vector<int>(v));
        W = vector<vector<int>>(v, vector<int>(v));
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
        E[to][from] = 1;
    }

    void add_cost(int from, int to, int w)
    {
        W[from][to] = w;
        W[to][from] = w;
    }
};

int main()
{
    int N;
    cin >> N;
    Graph G(N);

    for (int from = 0; from < N - 1; from++)
    {
        for (int to = from + 1; to < N; to++)
        {
            int cost;
            cin >> cost;
            G.add_cost(from, to, cost);
            G.add_edge(from, to);
        }
    }

    vector<int> node_cost(G.V, INF);
    vector<int> prev(G.V, -1);
    vector<bool> taken(G.V, false);

    set<pair<int, int>> pickable;
    pickable.insert({0, 0});
    node_cost[0] = 0;
    while (!pickable.empty())
    {
        pair<int, int> min_cost_node = *pickable.begin();
        int cost = min_cost_node.first;
        int node = min_cost_node.second;
        pickable.erase(min_cost_node);
        taken[node] = true;

        for (auto &vertex : G.adj(node))
        {
            if (node_cost[vertex] > G.W[node][vertex] && taken[vertex] == false)
            {
                pickable.erase({node_cost[vertex], vertex});
                node_cost[vertex] = G.W[node][vertex];
                prev[vertex] = node;
                pickable.insert({node_cost[vertex], vertex});
            }
        }
    }
    int total_cost = 0;
    for (auto &value : node_cost)
    {
        total_cost += value;
    }
    cout << total_cost;

    return 0;
}
