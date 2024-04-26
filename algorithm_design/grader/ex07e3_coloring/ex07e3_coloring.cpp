#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int minColors = INF;

class Graph
{
    // adj list
public:
    int n;
    vector<vector<int>> edges;
    int maxDegree;

    Graph(int n) : n(n)
    {
        maxDegree = 0;
        edges = vector<vector<int>>(n);
    }

    vector<int> adj(int node)
    {
        vector<int> tmp;
        for (auto &v : edges[node])
        {
            tmp.push_back(v);
        }

        return tmp;
    }

    void add_edge(int from, int to)
    {
        edges[from].push_back(to);
        edges[to].push_back(from);
        maxDegree = max(max(maxDegree, (int)edges[from].size()), (int)edges[to].size());
    }

    void print_edge()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " :";
            for (auto &v : edges[i])
            {
                cout << v << " ";
            }
            cout << "\n";
        }
    }
};

bool checkConstrain(Graph &G, vector<int> &solColor, int len, int totalNode)
{
    int maxColor = 0;
    for (int from = 0; from < len; from++)
    {
        maxColor = max(maxColor, solColor[from]);

        for (auto &to : G.adj(from))
        {
            if (to <= len && solColor[from] == solColor[to])
            {
                // cout << "its false\n";
                return false;
            }
        }
    }
    // cout << "true";
    minColors = min(minColors, maxColor);
    return true;
}

void print_sol(Graph &G, vector<int> &solColor, int len, int totalNode)
{
    for (int i = 0; i < totalNode; i++)
    {
        cout << solColor[i] << "  ";
    }
}

void permutate(Graph &G, vector<int> &solColor, int len, int totalNode)
{
    if (len < totalNode)
    {
        for (int i = 0; i < G.maxDegree; i++)
        {
            solColor[len] = i;
            if (checkConstrain(G, solColor, len, totalNode))
            {
                permutate(G, solColor, len + 1, totalNode);
            }
            solColor[len] = 0;
        }
    }
    else
    {
        // print_sol(G, solColor, len, totalNode);
        // cout << " \n----------------------------------\n";
        checkConstrain(G, solColor, len, totalNode);
    }
}

int main()
{
    int N, E;
    cin >> N >> E;
    Graph G(N);
    /*
    4 6
    0 1
    0 2
    0 3
    1 2
    1 3
    2 3
    */
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        G.add_edge(u, v);
    }

    // G.print_edge();
    vector<int> solColor(N, 0);

    permutate(G, solColor, 0, N);
    minColors = G.maxDegree;
    cout << minColors + 1;

    // permutate array n = 50 [0,0,0,0,0,0,0,0,0,0,0,0,0,0] check condition of adj cenet cant

    return 0;
}