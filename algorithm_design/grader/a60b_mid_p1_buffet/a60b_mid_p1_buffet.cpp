#include <bits/stdc++.h>
using namespace std;
int f, w, n;

int main()
{
    cin >> f >> w >> n;

    int lightSpan = w + w + 1;

    // vector<bool> table(n + 1, false);
    vector<int> pos(f + 1, 0);
    for (int i = 1; i <= f; i++)
    {
        int foodPos;
        cin >> foodPos;
        pos[i] = foodPos;
    }

    sort(pos.begin() + 1, pos.end());

    int bulbCount = 0;
    int lightReached = 0;
    for (int i = 1; i <= f; i++)
    {
        if (lightReached < pos[i])
        {
            bulbCount++;
            lightReached = pos[i] + lightSpan - 1;
        }
    }

    cout << bulbCount;

    return 0;
}