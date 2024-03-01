#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 5;
int n, m, k;
vector<long long> A;

int solve(int l, int r, long long x)
{
    if (l == r)
        return l;

    int mid = (l + r) / 2;
    if (A[mid] <= x)
        return solve(mid + 1, r, x);
    return solve(l, mid, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    A.resize(n + 1);

    for (size_t i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        A[i] = A[i - 1] + x + k; // sum of price per tile
    }

    while (m--)
    {
        int l;
        long long b;
        cin >> l >> b;

        l++;
        int r = solve(l - 1, n, b + A[l - 1]);
        cout << A[r] - A[l - 1] - (r - l + 1) * k << '\n';
    }

    return 0;
}