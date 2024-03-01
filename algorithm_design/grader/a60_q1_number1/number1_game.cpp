#include <bits/stdc++.h>
using namespace std;
int n, l, r;

int solve(int number, int &len, int l, int r)
{
    int one_count = 0;
    // div and zoinker
    // trivial cases
    if (len > r)
        return 0;
    if (number == 0 || number == 1)
    {
        if (l <= len && len <= r)
        {
            len++;
            return number;
        }
        len++;
        return 0;
    }

    // divide
    int left_count = solve(number / 2, len, l, r);
    int mid_count = solve(number % 2, len, l, r);
    int right_count = solve(number / 2, len, l, r);

    // zoinker
    one_count = left_count + mid_count + right_count;

    return one_count;
}

int cal_size(int number)
{
    int size = 1;
    while (number > 1)
    {
        size = 2 * size + 1;
        number /= 2;
    }

    return size;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> l >> r;
    cout << cal_size(n) << endl;
    int len = 1;
    int total_ones = solve(n, len, l, r);
    cout << total_ones;

    return 0;
}