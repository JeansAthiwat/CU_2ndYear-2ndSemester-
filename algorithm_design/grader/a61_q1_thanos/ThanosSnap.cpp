#include <bits/stdc++.h>

using namespace std;

long long p, k, A, B;

long long min_power(vector<long long> &avenger_pos, long long start_pos, long long stop_pos)
{
    // 1 base index only

    /*if (start_pos == stop_pos)
        return A; // A  < B for sure*/

    // calculate power it would takes if detroy all

    // find all avenger in range
    auto it_left = lower_bound(avenger_pos.begin(), avenger_pos.end(), start_pos);
    auto it_right = upper_bound(avenger_pos.begin(), avenger_pos.end(), stop_pos);
    long long count = it_right - it_left;

    if (count == 0)
        return A;

    long long full_power = B * count * (stop_pos - start_pos + 1);

    // calculate power it would take if split inhalf
    if (start_pos < stop_pos)
    {
        long long mid_pos = (start_pos + stop_pos) / 2;

        long long lmin = min_power(avenger_pos, start_pos, mid_pos);
        long long rmin = min_power(avenger_pos, mid_pos + 1, stop_pos);

        full_power = min((lmin + rmin), full_power);
    }
    return full_power;
}

int main()
{
    cin >> p >> k >> A >> B;
    long long base_len = pow(2, p);
    vector<long long> avenger_pos(k);

    for (size_t i = 0; i < k; i++)
    {
        cin >> avenger_pos[i];
    }

    sort(avenger_pos.begin(), avenger_pos.end());
    long long power = min_power(avenger_pos, 1, base_len);
    cout << power;
    return 0;
}