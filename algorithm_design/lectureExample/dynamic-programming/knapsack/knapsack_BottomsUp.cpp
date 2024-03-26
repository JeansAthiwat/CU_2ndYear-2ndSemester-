#include <bits/stdc++.h>
using namespace std;
vector<int> v(505);
vector<int> w(505);

void print_ans(vector<vector<int>> &ans)
{
    cout << "las respuesta son : \n";
    for (auto &vec : ans)
    {
        for (auto &v : vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

int solve_max_value(int total_items, int total_weights)
{
    vector<vector<int>> dp(total_items + 1, vector<int>(total_weights + 1));
    // fill trivial
    for (int value = 0; value <= total_items; value++)
    {
        dp[value][0] = 0;
        for (int remaining = 0; remaining <= total_weights; remaining++)
        {
            dp[0][remaining] = 0;
        }
    }
    

    for (int item_index = 1; item_index <= total_items; item_index++)
    {
        for (int weight = 1; weight <= total_weights; weight++)
        {
            if (weight - w[item_index] >= 0)
            {
                // V(a,b) = max( V(a-1,b), V(a-1,b-w[a]) + v[a] )
                dp[item_index][weight] =
                    max(dp[item_index - 1][weight - w[item_index]] + v[item_index], dp[item_index - 1][weight]);
            }
            else
            {
                dp[item_index][weight] = dp[item_index - 1][weight];
            }
        }
    }
    print_ans(dp);
    return dp[total_items][total_weights];
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
/*
5 5
3 10 6 3 5
5 5 3 1 1
*/