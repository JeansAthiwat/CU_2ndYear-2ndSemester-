#include <bits/stdc++.h>

using namespace std;
int n, k;

int count_one(vector<int> &dna, int start, int stop)
{
    int count = 0;
    for (size_t i = start; i <= stop; i++)
    {
        if (dna[i] == 1)
            count++;
    }
    return count;
}

bool solve(vector<int> &dna, int start, int stop)
{
    // when len = 2**1
    if (stop == start)
    {
        return true;
    }

    // divde in half and to recursive sheck sub seq
    int mid = (start + stop) >> 1;
    if (!solve(dna, start, mid))
        return false;
    if (!solve(dna, mid + 1, stop))
        return false;

    // checkdiff both half
    int lh_one = count_one(dna, start, mid);
    int rh_one = count_one(dna, mid + 1, stop);

    if (abs(lh_one - rh_one) <= 1)
    {
        return true;
    }

    return false;
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