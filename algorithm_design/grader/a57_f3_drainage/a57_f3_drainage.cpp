#include <bits/stdc++.h>
using namespace std;
int N, L;

int solve1(vector<int> &holes)
{
    int total_cap = 0;
    int closed_to = 0;
    for (int i = 0; i < N; i++)
    {
        if (closed_to < holes[i])
        {
            total_cap++;
            closed_to = holes[i] + L-1;
        }
    }

    return total_cap;
}

int main()
{
    cin >> N >> L;
    vector<int> holes(N, false);

    for (int i = 0; i < N; i++)
        cin >> holes[i];

    sort(holes.begin(), holes.end());

    cout << solve1(holes);
    return 0;
}