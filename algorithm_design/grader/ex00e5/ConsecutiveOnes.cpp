#include <bits/stdc++.h>

using namespace std;
int n, k;

template <typename T>
void permutation(int len, vector<T> &res, int consecutive, bool satisfied)
{
    if (consecutive >= k)
        satisfied = true;
    if (len < n)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == 0 && (satisfied || n - len > k))
            {
                res[len] = i;
                permutation(len + 1, res, 0, satisfied);
            }
            else if (i == 1 && (satisfied || n - len + consecutive >= k))
            {
                res[len] = i;
                permutation(len + 1, res, consecutive + 1, satisfied);
            }
        }
    }
    else
    {
        for (auto x : res)
        {
            cout << x;
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> k;

    vector<int> binaryString(n);
    permutation(0, binaryString, 0, false);

    return 0;
}