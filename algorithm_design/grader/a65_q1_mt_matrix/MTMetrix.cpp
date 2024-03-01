#include <bits/stdc++.h>
using namespace std;

int u, v, w, p;

int solve(long long n, long long target_row, long long target_col)
{

    // base case
    if (n == 2)
    {
        if (target_row == 1 and target_col == 1)
            return u;
        if (target_row == 1 and target_col == 2)
            return v;
        if (target_row == 2 and target_col == 1)
            return w;
        return p;
    }

    // divide into four quadrant
    long long half_size = n / 2;

    if (target_row <= half_size and target_col <= half_size) // Q1
        return solve(half_size, target_row, target_col);
    if (target_row <= half_size and target_col > half_size) // Q2 must transpose
        return solve(half_size, target_col - half_size, target_row);
    if (target_row > half_size and target_col <= half_size) // Q3 must negative
        return -solve(half_size, target_row - half_size, target_col);
    return -solve(half_size, target_col - half_size, target_row - half_size);
    // conqour is actually do nothing O(1)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m >> u >> v >> w >> p;

    long long total_len = 1LL << n;
    while (m--)
    {
        long long row, col;
        cin >> row >> col;

        // index starts at 1

        cout << solve(total_len, row, col) << "\n";
    }

    return 0;
}