#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> dolist(k + 1);
    for (int i = 1; i <= k; i++)
    {
        int d, e, l;
        cin >> d >> e >> l;
        dolist[d] = make_pair(e, l);
    }

    queue<int> demand;
    queue<int> supply;

    for (int day = 1; day <= k; day++)
    {
        pair<int, int> todo = dolist[day];
        if (todo.first == 0)
        {
            // A action produce ting
            if (!demand.empty())
            {
                int shopNumber = demand.front();
                demand.pop();
                cout << shopNumber;
            }
            else
            {
                supply.push(todo.second);
                cout << 0;
            }
        }
        else
        {
            // B action
            if (!supply.empty())
            {
                int plantNumber = supply.front();
                supply.pop();
                cout << plantNumber;
            }
            else
            {
                demand.push(todo.second);
                cout << 0;
            }
        }
        cout << "\n";
    }

    return 0;
}