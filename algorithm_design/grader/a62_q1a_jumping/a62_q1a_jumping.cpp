#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8 + 7;

int solve(int n, int k)
{
    // sum of possible ways on each lenght
    int total_ways = 1;

    vector<int> bstring_possible_count(n + 1, 0);
    bstring_possible_count[0] = 0;
    for (int blen = 1; blen <= n; blen++)
    {

        // the first cases can be comprized from xxx...xxx00001 (this k = 5) (bit string ends with 1)
        // so bit 1 to n-k can be anything but the last k bit must be 0000then 1
        //(ways to create bit string with length L) where L range from 1 to length n-k plus the case of 000000....0001
        int endsWithOne_sum = 0;
        for (int index = 1; index < max(1, blen - k+1); index++)
        {
            endsWithOne_sum = (endsWithOne_sum + bstring_possible_count[index]) % MOD;
        }
        // A case of binary length are all 0
        bstring_possible_count[blen] = 1;
        bstring_possible_count[blen] = (bstring_possible_count[blen] + endsWithOne_sum) % MOD;

        total_ways = (total_ways + bstring_possible_count[blen]) % MOD;
    }

    return total_ways;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    cout << solve(n, k);
    return 0;
}