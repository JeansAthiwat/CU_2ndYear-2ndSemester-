#include <bits/stdc++.h>

using namespace std;

template <typename T>
int my_merge_sort(vector<T> &a, T &target, int start, int stop)
{

    // trivial case
    if (start == stop)
    {
        if (a[start] == target)
            return start;
        return -1;
    }

    // devide and conquer
    int mid = (start + stop) >> 1; // divide by 2
    if (target <= a[mid])
    {
        return my_merge_sort(a, target, start, mid);
    }
    else
    {
        return my_merge_sort(a, target, mid + 1, stop);
    }
}

int main()
{
    vector<int> a({0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200});

    for (int i = 0; i < 10; i++)
    {
        cout << "\n-------------------------------------------\n";
        int target;
        cin >> target;

        int index = my_merge_sort(a, target, 0, a.size() - 1);
        cout << index;
        cout << "\n-------------------------------------------\n";
    }

    return 0;
}