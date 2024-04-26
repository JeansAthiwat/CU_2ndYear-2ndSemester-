#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

class Graph
{
public:
    ull V;
    vector<ull> code;
    vector<vector<ull>> edge_score;
    vector<vector<ull>> E;

    Graph(ull v, vector<ull> &bs) : V(v)
    {
        edge_score = vector<vector<ull>>(v, vector<ull>(v));
        E = vector<vector<ull>>(v, vector<ull>(v));
        code = bs;

        for (ull r = 0; r < V - 1; r++)
        {
            for (ull c = r + 1; c < V; c++)
            {
                edge_score[r][c] = code[r] ^ code[c];
                edge_score[c][r] = code[r] ^ code[c];

                E[r][c] = 1;
                E[c][r] = 1;
            }
        }
    }

    vector<int> adj(int node)
    {
        vector<int> adj_nodes;
        for (int i = 0; i < V; i++)
        {
            if (E[node][i] >= 1)
            {
                adj_nodes.push_back(i);
            }
        }
        return adj_nodes;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ull> codes(n);
    for (ull i = 0; i < n; i++)
    {
        ull c;
        cin >> c;
        codes[i] = c;
    }

    Graph G(n, codes);

    vector<ull> node_score(G.V, 0);
    vector<int> prev(G.V, -1);
    vector<bool> taken(G.V, false);

    set<pair<ull, ull>, greater<>> pickable;
    pickable.insert({0, 0});
    node_score[0] = 0;

    while (!pickable.empty())
    {
        auto node_max_score = *pickable.begin();
        ull score = node_max_score.first;
        ull node = node_max_score.second;
        pickable.erase(node_max_score);
        taken[node] = true;

        for (auto &vertex : G.adj(node))
        {
            if (!taken[vertex] && node_score[vertex] < G.edge_score[node][vertex])
            {
                pickable.erase({node_score[vertex], vertex});
                node_score[vertex] = G.edge_score[node][vertex];
                prev[vertex] = node;
                pickable.insert({node_score[vertex], vertex});
            }
        }
    }

    ull total_score = 0;
    for (ull &x : node_score)
    {
        total_score += x;
    }

    cout << total_score;
    return 0;
}
