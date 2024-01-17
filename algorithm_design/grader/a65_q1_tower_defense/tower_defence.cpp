#include <bits/stdc++.h>

using namespace std;

void permutate(int k, vector<int> sol, int len, int min_health, vector<vector<int>> shootable_pos)
{
}

int main()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> p(m);
    vector<int> h(m);
    vector<int> t(k);

    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int inp;
        cin >> inp;
        h[i] = inp;
        sum += inp;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> t[i];
    }

    // matrix of turret's shootable monsterindex
    vector<vector<int>> shootable_pos(k);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (t[i] + w >= p[j] && p[j] >= t[i] - w)
            {
                shootable_pos[i].push_back(j);
            }
        }
    }

    for (auto &turret : shootable_pos)
    {
        for (auto &pos : turret)
        {
            cout << pos << " ";
        }
        cout << endl;
    }

    vector<int> sol; // [which mon, which mon, which mon , ..., 8th turret]
    permutate(k, sol, len, min_health, shootable_pos);
}