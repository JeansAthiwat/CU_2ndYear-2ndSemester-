// midified djik's where lots of starting node?
#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;

class Graph
{
public:
    // adj matrix
    int V;
    vector<vector<int>> E;
    vector<int> time_until_hacked;
    vector<int> node_hack_time;

    Graph(int v) : V(v)
    {
        E = vector<vector<int>>(v);
        time_until_hacked = vector<int>(v, INF);
        node_hack_time = vector<int>(v);
    }

    vector<int> adj(int from)
    {
        vector<int> vec;
        for (auto &to : E[from])
        {
            vec.push_back(to);
        }
        return vec;
    }

    void add_edge(int from, int to)
    {
        E[from].push_back(to);
        E[to].push_back(from);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    Graph G(n);
    vector<int> attacked_node(k);

    for (int i = 0; i < k; i++)
        cin >> attacked_node[i];

    for (int node = 0; node < n; node++)
        cin >> G.node_hack_time[node];

    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        G.add_edge(from, to);
    }

    // start da djik;

    // {hackedTime, node}
    vector<int> prev(n, -1);
    vector<bool> picked(n, false);
    set<pair<int, int>> pickable;

    // put all initial nodes in
    for (int i = 0; i < k; i++)
    {
        G.time_until_hacked[attacked_node[i]] = G.node_hack_time[attacked_node[i]];
        pickable.insert({G.node_hack_time[attacked_node[i]], attacked_node[i]});
    }

    while (!pickable.empty())
    {
        auto tmp = *pickable.begin();
        int timetilhacked = tmp.first;
        int node = tmp.second;
        pickable.erase(tmp);
        picked[node] = true;

        for (auto &adj_node : G.adj(node))
        {
            if (!picked[adj_node] && G.time_until_hacked[adj_node] > G.time_until_hacked[node] + G.node_hack_time[adj_node])
            {
                pickable.erase({G.time_until_hacked[adj_node], adj_node});
                G.time_until_hacked[adj_node] = G.time_until_hacked[node] + G.node_hack_time[adj_node];
                prev[adj_node] = node;
                pickable.insert({G.time_until_hacked[adj_node], adj_node});
            }
        }
    }

    int min_time = -INF;
    for (auto &x : G.time_until_hacked)
    {
        min_time = max(min_time, x);
    }
    cout << min_time;
    return 0;
}
