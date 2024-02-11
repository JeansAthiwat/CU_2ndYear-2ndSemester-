#include <bits/stdc++.h>

using namespace std;
int n, k;

bool solve(vector<int> &dna, int start, int stop)
{
    // base case of len 2
    if (start + 1 == stop)
        return (dna[start] == 0 && dna[stop] == 1);

    int mid = (start + stop) / 2;

    // divde in 2 two half first half is correct both wehn reversed and non reverse

    vector<int> reversed_a(dna);
    reverse(reversed_a.begin() + start, reversed_a.begin() + mid + 1);

    if (!solve(dna, mid + 1, stop))
        return false;

    return solve(dna, start, mid) || solve(reversed_a, start, mid);
}

int main()
{
    cin >> n >> k;

    int dna_len = pow(2, k);
    while (n--)
    {
        vector<int> dna(dna_len);
        for (size_t i = 0; i < dna_len; i++)
        {
            cin >> dna[i];
        }

        bool isSatisfied = solve(dna, 0, dna_len - 1);
        if (isSatisfied)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}