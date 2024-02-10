#include <bits/stdc++.h>

using namespace std;

template <typename T>
void merge(vector<T> &a, vector<T> &tmp, int start, int mid, int stop)
{
    int li = start;
    int ri = mid + 1;

    for (int i = start; i <= stop; i++)
    {
        // careful we also need to check if li , ri is out of bound
        if (li > mid)
        {
            tmp[i] = a[ri++];
            continue;
        }
        if (ri > stop)
        {
            tmp[i] = a[li++];
            continue;
        }

        tmp[i] = (a[li] < a[ri]) ? a[li++] : a[ri++];
    }

    for (int i = start; i <= stop; i++)
    {
        a[i] = tmp[i];
    }
}

template <typename T>
void merge_recur(vector<T> &a, vector<T> &tmp, int start, int stop)
{
    // divide and conquer

    // we divide and sort smaller array
    if (start == stop)
        return;

    int mid = (start + stop) >> 1;
    merge_recur(a, tmp, start, mid);
    merge_recur(a, tmp, mid + 1, stop);
    merge(a, tmp, start, mid, stop);
}

template <typename T>
void my_merge_sort(vector<T> &a, int start, int stop)
{
    vector<T> tmp(a.size());
    merge_recur(a, tmp, start, stop);
}

int main()
{
    vector<int> a({1, 5, 4, 8, 2, 6, 7, 9, 3, 0});

    my_merge_sort(a, 0, a.size() - 1);

    for (auto &x : a)
    {
        cout << x << " ";
    }

    return 0;
}