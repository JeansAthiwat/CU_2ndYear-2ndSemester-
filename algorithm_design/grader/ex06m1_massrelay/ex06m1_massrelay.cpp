#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;

class DisjointSet
{
public:
    int size;
    vector<int> parent;
    DisjointSet(int s)
    {
        size = s;
        parent = vector<int>(size, -1);
    }

    int findset(int x)
    {
        if (parent[x] == -1)
        {
            return x;
        }
        parent[x] = findset(parent[x]);
        return parent[x];
    }

    bool unionset(int x, int y)
    {
        int s1 = findset(x);
        int s2 = findset(y);
        if (s1 == s2)
        {
            return false;
        }
        else
        {
            parent[s1] = s2;
            return true;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> edges;
    while (m--)
    {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        edges.push({ci, ai, bi});
    }
    vector<int> max_KofD(n + 1);
    max_KofD[n] = 0;//no nneed to travel at all
    int current_d = n - 1;

    DisjointSet ds(n);

    while (!edges.empty())
    {
        auto c = get<0>(edges.top());
        auto a = get<1>(edges.top());
        auto b = get<2>(edges.top());
        edges.pop();

        if (ds.unionset(a, b))
        {
            max_KofD[current_d] = c;
            current_d--;
        }
    }
    while (q--)
    {
        int d;
        cin >> d;
        cout << max_KofD[d] << "\n";
    }

    return 0;
}