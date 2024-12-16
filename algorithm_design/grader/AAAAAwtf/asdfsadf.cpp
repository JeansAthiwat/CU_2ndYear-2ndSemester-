#include <bits/stdc++.h>
using namespace std;
int N, L;

int solve1(vector<bool> &haveholes)
{
    int total_cap = 0;
    int cor = 1;
    while (cor <= N)
    {
        if (haveholes[cor])
        {
            total_cap++;
            cor += L;
        }
        else
        {
            cor++;
        }
    }

    return total_cap;
}
int main()
{
    cin >> N >> L;
    vector<bool> haveholes(N + 1, false);

    for (int i = 1; i <= N; i++)
    {
        int pi;
        cin >> pi;
        haveholes[pi] = true;
    }

    cout << solve1(haveholes);
    return 0;
}