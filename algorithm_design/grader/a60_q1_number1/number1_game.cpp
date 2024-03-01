#include <bits/stdc++.h>
using namespace std;
int n, l, r;

int solve(int number, int l, int r, int start, int stop)
{
    int one_count = 0;
    // div and zoinker

    // optimize calculate range
    if (stop < l || start > r)
        return 0;

    // trivial cases
    if (start == stop)
    {
        return number;
    }

    // divide
    int mid = (start + stop) / 2;

    int left_count = solve(number / 2, l, r, start, mid - 1);
    int mid_count = solve(number % 2, l, r, mid, mid);
    int right_count = solve(number / 2, l, r, mid + 1, stop);

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
    int arr_size = cal_size(n);
    int total_ones = solve(n, l, r, 1, arr_size);
    cout << total_ones;

    return 0;
}