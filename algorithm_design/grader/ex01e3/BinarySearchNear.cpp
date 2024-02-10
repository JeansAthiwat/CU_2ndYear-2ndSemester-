#include <bits/stdc++.h>

using namespace std;

int first_index = 0;
template <typename T>
int modified_binary_search(vector<T> &a, int target, int start, int stop, int last_index)
{
    if (start == stop)
    {
        if (a[start] == target || (start == last_index && a[last_index] < target))
            return start;

        // if we cant find it there are some possible case
        // 1. the value we are looking for is 1 index less
        // 2. it is target index < start
        return start - 1;
    }

    // divide and conqour parttt

    int mid = (start + stop) >> 1;

    if (target <= a[mid])
    {
        return modified_binary_search(a, target, start, mid, last_index);
    }
    else
    {
        return modified_binary_search(a, target, mid + 1, stop, last_index);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (size_t i = 0; i < m; i++)
    {
        int query;
        cin >> query;

        int index = modified_binary_search(a, query, 0, a.size() - 1, a.size() - 1);
        if (index == -1)
        {
            cout << -1 << "\n";
            continue;
        }
        cout << a[index] << "\n";
    }

    return 0;
}