#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &a, int left, int right, int &k)
{
    /*
    swap any 2 index between 2 half of subproblem recursively
    this is actually genius
    keep in mind non include end
    */

    // if fn call out of quota or is the smallest possible partition (1)
    if (k <= 0 || left == right - 1)
    {
        return;
    }

    // recursive to swap any 2 index in the same sub problem
    int mid = (left + right) / 2;

    swap(a[mid - 1], a[mid]);
    k--;

    solve(a, left, mid, k);
    solve(a, mid, right, k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    /*
    impossible case
    1. the k value exceed the max possible fn call aka worst case of node and leaf combined
    2. the k value is even (first call + two half + 4 half +++++)
    */
    if (k > (n * 2) || k % 2 == 0)
    {
        cout << -1;
    }
    else
    {
        vector<int> num(n);
        for (int i = 0; i < n; i++)
            num[i] = i + 1;

        // k - 1 remove first call
        int cnt = (k - 1) / 2;
        solve(num, 0, n, cnt);
        for (auto &x : num)
            cout << x << " ";
    }
}
