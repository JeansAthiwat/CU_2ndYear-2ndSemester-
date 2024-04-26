#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // adj matrix
    int V;
    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>>,
                   greater<>>
        cost;

    Graph(int v) : V(v)
    {
    }

    void add_cost(int from, int to, int w)
    {
        cost.push({w, from, to});
    }
};

class DisjointSet
{
    vector<int> parent;
    vector<int> tree_size;

public:
    DisjointSet(int n)
    {
        parent = vector<int>(n, -1);
        tree_size = vector<int>(n, 1);
    }

    int findset(int x)
    {
        // basecase
        if (parent[x] == -1)
            return x;
        // recurcase
        parent[x] = findset(parent[x]);
        return parent[x];
    }

    void unionset(int s1, int s2)
    {
        int x = findset(s1);
        int y = findset(s2);
        if (tree_size[x] > tree_size[y])
        {
            parent[y] = x;
            tree_size[x] = tree_size[x] + tree_size[y];
        }
        else
        {
            parent[x] = y;
            tree_size[y] = tree_size[y] + tree_size[x];
        }
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
        }
    }

    DisjointSet ds(N);
    vector<pair<int, int>> ans_edges;
    int total_cost = 0;

    while (!G.cost.empty())
    {
        int weight = get<0>(G.cost.top());
        int from = get<1>(G.cost.top());
        int to = get<2>(G.cost.top());
        G.cost.pop();

        if (ds.findset(from) != ds.findset(to))
        {
            ans_edges.push_back({from, to});
            ds.unionset(from, to);
            total_cost += weight;
        }
    }

    cout << total_cost;

    return 0;
}