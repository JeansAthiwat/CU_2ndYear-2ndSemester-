#include <bits/stdc++.h>

using namespace std;

int modulo_recur(int a, int power, int m) //
{
    // split in half + half + 1
    // find the mod res of each half

    // base case
    if (power == 1)
    {
        return a % m;
    }
    int tmp = modulo_recur(a, power / 2, m);
    if (power % 2 == 0)
    {
        return (tmp * tmp) % m;
    }
    else
    {
        return (((tmp * tmp) % m) * (a % m)) % m;
    }
}

int main()
{
    int x, n, k;
    cin >> x >> n >> k;

    int res = modulo_recur(x, n, k);
    cout << res;
    return 0;
}
