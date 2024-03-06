#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 30;
const int MAX_K = 30;
// matrix 31x31 (index starts at 1 lol)
vector<vector<int>> combinations(MAX_N + 1, vector<int>(MAX_K + 1, 0));

int solve(int n, int k)
{
    // trivial cases
    if (n == k || k == 0)
        return 1;

    // solved case
    if (combinations[n][k] > 0)
        return combinations[n][k];

    // unsolved case
    int result = solve(n - 1, k - 1) + solve(n - 1, k);
    combinations[n][k] = result;

    return result;
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << solve(N, K);

    return 0;
}