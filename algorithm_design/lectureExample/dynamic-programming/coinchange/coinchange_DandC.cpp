#include <bits/stdc++.h>
using namespace std;
int coin_value[25];
int money[10005];

int solve(int N, int to_change, int current_coin)
{
    if (current_coin == N)
    {
        // change amount equalls to number of 1's coin needed
        return to_change;
    }

    if (coin_value[current_coin] > to_change)
        return solve(N, to_change, current_coin + 1);

    int min_used = min(solve(N, to_change - coin_value[current_coin], current_coin) + 1, solve(N, to_change, current_coin + 1));
    return min_used;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> coin_value[i];

    cout << solve(N, M, 1);
}