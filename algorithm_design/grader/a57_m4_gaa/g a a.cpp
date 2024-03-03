#include <bits/stdc++.h>
using namespace std;

char solve(int mid_term_len, int total_len, int N)
{
    int first_of_third = (total_len - mid_term_len) / 2;
    int second_of_third = first_of_third + mid_term_len;
    if (N <= first_of_third)
        return solve(mid_term_len - 1, first_of_third, N);
    if (second_of_third < N)
        return solve(mid_term_len - 1, first_of_third, N - second_of_third);
    if (N == first_of_third + 1)
        return 'g';
    return 'a';
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >> N;

    int total_len = 3, mid_term_len = 3;
    while (total_len < N)
    {
        mid_term_len++;
        total_len = (2 * total_len) + mid_term_len;
    }
    cout << solve(mid_term_len, total_len, N);
    return 0;
}