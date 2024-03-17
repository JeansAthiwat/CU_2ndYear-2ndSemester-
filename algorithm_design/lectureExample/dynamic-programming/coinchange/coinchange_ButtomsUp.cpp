#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MAX_N = 25;
const int MAX_M = 10005;

int coin_value[MAX_N];
int ans[MAX_N][MAX_M];

int solve(int N, int to_change)
{
    // Trivial cases
    for (int i = 0; i <= MAX_M; i++)
        ans[0][i] = INF;

    for (int i = 1; i <= N; i++)
        ans[i][0] = 0;

    // Bottom-up DP
    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= to_change; col++)
        {
            if (coin_value[row] > col)
                ans[row][col] = ans[row - 1][col];
            else
                ans[row][col] = min(ans[row - 1][col], ans[row][col - coin_value[row]] + 1);
        }
    }

    return ans[N][to_change];
}

void printTable(int N, int to_change)
{
    cout << "DP Table:" << endl;
    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j <= to_change + 1; j++)
        {
            cout << setw(3) << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> coin_value[i];

    cout << "Minimum number of coins needed: " << solve(N, M) << endl;

    printTable(N, M);

    return 0;
}
