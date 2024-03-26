#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
const int INF = 1e9 + 7;

int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    // Loop through each entry of the matrix from left to right and top to bottom
    // and calculate dp[i][j] = max(dp[i-1][j-1] + a[i][j], a[i][j])
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i-1][j-1] + a[i][j], a[i][j]);
        }
    }

    // Find the maximum value in dp
    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';
    return 0;
}
