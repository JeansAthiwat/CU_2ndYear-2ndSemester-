#include <bits/stdc++.h>

using namespace std;

int n, a;

long long solve(vector<long long> &chefTime, long long minTime, long long maxTime, long long customerIndex)
{
    /*
    we try to use binary search for finding the time customer with this index will get served
    */
    if (minTime == maxTime)
    {
        return minTime;
    }

    long long midTime = (minTime + maxTime) / 2;

    long long totalDishServed = 0;
    for (size_t chefIndex = 0; chefIndex < n; chefIndex++)
    {
        totalDishServed += midTime / chefTime[chefIndex];
    }

    if (totalDishServed >= customerIndex)
    {
        return solve(chefTime, minTime, midTime, customerIndex);
    }
    else
    {
        return solve(chefTime, midTime + 1, maxTime, customerIndex);
    }
}

int main()
{
    cin >> n >> a;
    vector<long long> chefTime(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> chefTime[i];
    }

    // solve using binary search for the time customer will be served

    while (a--)
    {
        long long customerIndex;
        cin >> customerIndex;

        // first n customer starts at 0
        long long time = solve(chefTime, 0, 1e12, customerIndex - n);
        cout << time << "\n";
    }

    return 0;
}
