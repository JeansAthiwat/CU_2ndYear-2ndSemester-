#include <bits/stdc++.h>
using namespace std;
vector<int> w(505);
vector<int> v(505);

int solve_max_value(int item_index, int remaining_weight)
{
    // trivial case
    if (item_index < 0 || remaining_weight < 0)
        return 0;

    if (w[item_index] <= remaining_weight)
    {
        int pick = v[item_index] + solve_max_value(item_index - 1, remaining_weight - w[item_index]);
        int dont_pick = solve_max_value(item_index - 1, remaining_weight);

        return max(pick, dont_pick);
    }

    else
    {
        return solve_max_value(item_index - 1, remaining_weight);
    }
}

int main()
{
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    int max_weight = solve_max_value(n, m);
    cout << max_weight;
}