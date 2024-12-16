#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int n;
int current_best = -INF - 1;

struct Graph
{
    int V;
    vector<vector<int>> E;
    Graph(int n) : V(n), E(n, vector<int>(n, -INF)) {}

    vector<int> adj(int from)
    {
        vector<int> tmp;
        for (int to = 0; to < V; to++)
        {
            if (E[from][to] != -INF)
                tmp.push_back(to);
        }
        return tmp;
    }

    void add_edge(int from, int to, int weight)
    {
        E[from][to] = weight;
    }

    void printWeight()
    {
        cout << "-------------------------\n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << E[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "-------------------------\n";
    }
};

struct State
{
    Graph g;
    vector<bool> visited; // visited node or not plus hapiness
    vector<int> path;     // path walked
    int cum_happiness;    // cumulative hapiness so far
    int heuristic_score;  // try to maximize (should be more than ans)

    State(const Graph &graph) : g(graph), path(), cum_happiness(0), heuristic_score(-INF)
    {
        visited = vector<bool>(g.V, false);
        path = vector<int>(1, 0);
    }

    int calculate_cum_happiness()
    {
        int happ = 0;
        int last_node = -1;
        for (auto &node : path)
        {
            if (last_node != -1)
            {
                happ += g.E[last_node][node];
            }
            last_node = node;
        }
        return happ;
    }

    int calculate_heuristic()
    {
        // GREADY CHOOSE THE BEST PLACE TO GO FOR EACH unvisited node IN FORNT OF YOU
        int score = cum_happiness;
        for (int v = 1; v < g.V; v++)
        {
            if (visited[v])
                continue;

            int best_u_to_v = -INF;
            for (int u = 0; u < g.V - 1; u++)
            {
                if (u != v && (!visited[u] || path.back() == u))
                    best_u_to_v = max(best_u_to_v, g.E[u][v]);
            }
            score += best_u_to_v;
        }
        return score;
    }

    bool operator<(const State &other) const
    {
        return heuristic_score < other.heuristic_score;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    Graph g(n);

    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < n; j++)
        {
            int w;
            cin >> w;
            g.add_edge(i, j, w);
        }
    }

    // g.printWeight();

    // do lc_search
    priority_queue<State> pq;
    State starting_state(g);
    pq.push(starting_state);

    while (!pq.empty())
    {
        auto s = pq.top();
        pq.pop();

        if (s.path.size() == n)
        {
            // walk to everytown already
            // cout << "entered";
            current_best = max(current_best, s.cum_happiness);
        }
        else if (s.path.size() == n - 1)
        {
            // last town must be n-1
            s.path.push_back(n - 1);
            s.visited[n - 1] = true;
            s.cum_happiness = s.calculate_cum_happiness();
            s.heuristic_score = s.calculate_heuristic();
            pq.push(s);
        }
        else
        {
            for (int node = 1; node < n - 1; node++)
            {
                if (s.visited[node])
                    continue;

                auto new_s = s;
                new_s.path.push_back(node);
                new_s.visited[node] = true;
                new_s.cum_happiness = new_s.calculate_cum_happiness();
                new_s.heuristic_score = new_s.calculate_heuristic();
                if (new_s.heuristic_score > current_best)
                {
                    pq.push(new_s);
                }
            }
        }
    }

    cout << current_best;
    // greedy
    // check backtrack by check da containsave vertex before that and still lower la

    return 0;
}