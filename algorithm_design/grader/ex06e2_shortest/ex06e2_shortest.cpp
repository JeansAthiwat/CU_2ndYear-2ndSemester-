#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
// directed graph class
class DG
{
public:
    int V;
    vector<vector<int>> edges;
    vector<vector<int>> weight;
    DG(int n)
    {
        V = n;
        edges = vector<vector<int>>(n);
        weight = vector<vector<int>>(n, vector<int>(n));
    }

    vector<int> adj(int from)
    {
        vector<int> adj_nodes;
        for (auto &node : edges[from])
        {
            adj_nodes.push_back(node);
        }
        return adj_nodes;
    }

    void add_edge(int from, int to, int w)
    {
        edges[from].push_back(to);
        weight[from][to] = w;
    }

    vector<pair<int, int>> getAllEdges()
    {
        vector<pair<int, int>> tmp;
        for (int from = 0; from < V; from++)
        {
            for (auto &to : edges[from])
            {
                tmp.push_back({from, to});
            }
        }
        return tmp;
    }
};

int main()
{
    int N, E, s;
    cin >> N >> E >> s;
    DG G(N);

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G.add_edge(a, b, c);
    }

    // using bell man ford imp
    vector<int> prev(G.V, -1);
    vector<vector<int>> dp(G.V + 1, vector<int>(G.V, INF));
    for (int r = 0; r < G.V; r++)
        dp[r][s] = 0;

    for (int path_len = 1; path_len <= G.V; path_len++)
    {
        for (int node = 0; node < G.V; node++)
        {
            dp[path_len][node] = dp[path_len - 1][node];
        }

        for (auto &edge : G.getAllEdges())
        {
            int from = edge.first;
            int to = edge.second;

            if (dp[path_len][to] > dp[path_len - 1][from] + G.weight[from][to])
            {
                dp[path_len][to] = dp[path_len - 1][from] + G.weight[from][to];
                prev[to] = from;
            }
        }
    }
    // check negative cycle
    for (int node = 0; node < G.V; node++)
    {
        if (dp[G.V][node] < dp[G.V - 1][node])
        {
            cout << -1;
            return 0;
        }
    }

    vector<int> ans_dist(G.V);
    for (int node = 0; node < G.V; node++)
    {
        ans_dist[node] = dp[G.V - 1][node];
    }

    for (auto &x : ans_dist)
    {
        cout << x << " ";
    }

    return 0;
}