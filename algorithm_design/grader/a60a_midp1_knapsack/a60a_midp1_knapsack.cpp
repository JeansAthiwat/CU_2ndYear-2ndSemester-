#include <bits/stdc++.h>
using namespace std;

vector<int> solve_back(vector<int> &v, vector<int> &w, vector<vector<int>> &dp, int total_items, int total_weights)
{
    vector<int> picked;
    // fill trivial
    int index = total_items;
    int remaining_weight = total_weights;
    while (index > 0 && remaining_weight > 0)
    {
        if (remaining_weight - w[index] < 0)
        {
            // can not add only see next item 'case'
            index--;
        }
        else
        {
            if (dp[index - 1][remaining_weight] >= (dp[index - 1][remaining_weight - w[index]] + v[index]))
            {
                // wont add that item cuz not profit
                index--;
            }
            else
            {
                remaining_weight = remaining_weight - w[index];
                picked.push_back(index);
                index--;
            }
        }
    }
    return picked;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> v(n + 1);
    vector<int> w(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    for (int r = 0; r <= n; r++)
    {
        for (int c = 0; c <= m; c++)
        {
            cin >> dp[r][c];
        }
    }

    vector<int> picked_ans = solve_back(v, w, dp, n, m);
    cout << picked_ans.size() << "\n";
    for (auto &x : picked_ans)
    {
        cout << x << " ";
    }
}