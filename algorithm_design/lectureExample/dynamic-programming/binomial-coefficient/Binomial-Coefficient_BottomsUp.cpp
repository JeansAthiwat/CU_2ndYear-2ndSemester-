#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 31;
const int MAX_K = 31;
// matrix 31x31 (index starts at 1 lol)
vector<vector<int>> combinations(MAX_N, vector<int>(MAX_K, 0));

int solve_BU(int N, int K)
{
    // construct a table
    for (int i = 0; i < combinations.size(); i++)
    {
        // fill the trivial cases (N == K and K == 0)
        combinations[i][0] = 1;
        combinations[i][i] = 1;
    }

    for (int k = 1; k <= K; k++)
    {
        for (int n = k + 1; n <= k + (N - K); n++)
        {
            combinations[n][k] = combinations[n - 1][k - 1] + combinations[n - 1][k];
        }
    }

    return combinations[N][K];
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << solve_BU(N, K);

    return 0;
}