#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5; // 200 000
const int INF = 1e9 + 7;   // 1 000 000 000

int w;
int a[MAX_N];
int s[MAX_N + 1];

int cal_sum(int start_index, int stop_index)
{
    int sum = s[stop_index] - s[start_index - 1];
    return sum;
}

int solve(int start, int stop)
{
    if (start == stop)
        return a[start];

    int res = -INF;
    // D and C
    // divide
    int mid = (start + stop) / 2;

    res = max(res, solve(start, mid));
    res = max(res, solve(mid + 1, stop));

    int max_index_left = mid - (w - 1 - 1);
    int max_index_right = (mid + 1) + (w - 1 - 1);
    vector<int> l_max;
    l_max.push_back(-INF);
    for (int i = mid; i >= (max(start, max_index_left)); i--)
    {
        int sum = cal_sum(i, mid);
        l_max.push_back(max(l_max.back(), sum));
    }

    int maxRight = 0;
    for (int i = mid + 1; i < min(max_index_right, stop); i++)
    {
        int sum = cal_sum(mid + 1, i);
        maxRight = max(maxRight, sum);
        int lMax_max_possible_index = min(w - (i - mid), mid - start);
        res = max(res, l_max[lMax_max_possible_index] + maxRight);
    }

    return res;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    s[0] = 0;

    int n;
    cin >> n >> w;

    for (int i = 1; i <= n; i++)
    {
        int in;
        cin >> in;
        a[i] = in;
        s[i] = s[i - 1] + in;
    }

    cout << solve(1, n);
    return 0;
}