#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k, w;

    cin >> n >> m >> k >> w;

    int totalHealth = 0;
    int usedPos = 0;
    int turretLeft = k;
    vector<int> p(m + 1);
    vector<int> h(m + 1);

    for (int i = 1; i <= m; i++)
        cin >> p[i];

    for (int i = 1; i <= m; i++)
    {
        int health;
        cin >> health;
        h[i] = health;
        totalHealth += health;
    }

    vector<pair<int, int>> mix(m + 1);

    for (int i = 1; i <= m; i++)
    {
        mix[i] = {p[i], h[i]};
    }

    sort(mix.begin() + 1, mix.end());

    for (int i = 1; i <= m; i++)
    {
        p[i] = mix[i].first;
        h[i] = mix[i].second;
    }

    for (int i = 1; i <= m; i++)
    {
        if (turretLeft == 0)
            break;

        if (usedPos < min(n, p[i] + w) && usedPos <= n)
        {
            int range = min(n, p[i] + w) - max({1, p[i] - w, usedPos + 1}) + 1;
            int damage = min({turretLeft, h[i], range});

            turretLeft -= damage;
            totalHealth -= damage;
            h[i] -= damage;
            usedPos = max({1, p[i] - w, usedPos + 1}) + damage - 1;
        }

        /*for (auto x = max(1, p[i] - w); x <= min(n, p[i] + w); x++)
        {
            if (turretLeft == 0 || h[i] == 0)
                break;

            if (x > usedPos)
            {
                turretLeft--;
                totalHealth--;
                h[i]--;
                usedPos = x;
            }
        }*/
    }

    cout << totalHealth;

    return 0;
}