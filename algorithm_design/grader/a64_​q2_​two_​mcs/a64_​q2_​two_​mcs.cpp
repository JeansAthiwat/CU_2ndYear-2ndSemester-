#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
int globalMax[2];
int localMax[2];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    fill(globalMax, globalMax + 2, -INF);
    fill(localMax, localMax + 2, -INF);

    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;

        localMax[1] = max(localMax[1] + x, globalMax[0] + x);
        globalMax[1] = max(globalMax[1], localMax[1]);
        localMax[0] = max(localMax[0] + x, x);
        globalMax[0] = max(localMax[0], globalMax[0]);
    }

    cout << max(globalMax[0], globalMax[1]) << '\n';
}
