#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
    // trivial cases
    if (n == k || k == 0)
        return 1;

    return solve(n - 1, k - 1) + solve(n - 1, k);
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << solve(N, K);

    return 0;
}