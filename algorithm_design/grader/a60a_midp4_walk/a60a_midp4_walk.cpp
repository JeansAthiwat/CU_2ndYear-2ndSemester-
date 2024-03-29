#include <bits/stdc++.h>
using namespace std;
int n, m;

void print_vecvec(vector<vector<int>> &vecvec)
{
    cout << "-----------vecvec--------------\n";
    for (auto &vec : vecvec)
    {
        for (auto &x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------\n";
}
void fill_base_case(vector<vector<int>> &forest, vector<vector<int>> &best)
{
    best[1][1] = forest[1][1];

    for (int r = 2; r <= n; r++)
    {
        best[r][1] = best[r - 1][1] + forest[r][1];
    }
    for (int c = 2; c <= m; c++)
    {
        best[1][c] = best[1][c - 1] + forest[1][c];
    }

    //print_vecvec(best);
}

int solve(vector<vector<int>> &forest, vector<vector<int>> &best, int n, int m)
{
    fill_base_case(forest, best);

    for (int r = 2; r <= n; r++)
    {
        for (int c = 2; c <= m; c++)
        {

            best[r][c] = max({best[r - 1][c] + forest[r][c],
                              best[r][c - 1] + forest[r][c],
                              best[r - 1][c - 1] + (2 * forest[r][c])});
        }
    }
    // cout << "cocaine is bad for you";
    //print_vecvec(best);
    return best[n][m];
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> forest(n + 1, vector<int>(m + 1));
    vector<vector<int>> best(n + 1, vector<int>(m + 1));

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= m; c++)
        {
            cin >> forest[r][c];
        }
    }

    int max_score = solve(forest, best, n, m);
    cout << max_score << "\n";
    return 0;
}