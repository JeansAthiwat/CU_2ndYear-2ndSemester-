#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;

int N, D, maxHeight;
int maxDays = 1;
int findBestK(vector<int> &camps, int start, int stop, int totalDays = 1)
{
    // terminate case

    if (start == stop)
        return start;

    // recursion case
    int midK = (start + stop) / 2;

    int dayCount = 1;
    int currHeight = 0;
    for (int i = 1; i <= N; i++)
    {

        if (camps[i] - camps[i - 1] > midK)
        {
            dayCount = INF;
            break;
        }

        if (camps[i] - currHeight > midK)
        {
            currHeight = camps[i - 1];
            dayCount++;
            // currHeight += midK;
        }
    }

    if (dayCount <= D)
    {
        maxDays = max(maxDays, dayCount);
        return findBestK(camps, start, midK, dayCount);
    }
    else
    {
        return findBestK(camps, midK + 1, stop, dayCount);
    }
}

int main()
{
    cin >> N >> D;
    vector<int> camps(N + 1);

    for (int h = 1; h <= N; h++)
        cin >> camps[h];

    maxHeight = camps[N];

    /*
    Insight:
    1. K must be more than  the max dist from camp to camp
    2. K must be more than  the totalDist/D
    */

    int K = maxHeight / D;
    auto ans = findBestK(camps, K, maxHeight, 1);
    cout << ans << " " << maxDays;

    return 0;
}
/*
9 3
10 30 50 70 90 110 120 170 180
*/