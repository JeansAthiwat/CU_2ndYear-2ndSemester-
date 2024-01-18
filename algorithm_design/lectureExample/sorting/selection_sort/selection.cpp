#include <bits/stdc++.h>
using namespace std;

template <typename T>
void selection_sort(vector<T> &V)
{

    // in each loop
    // find the maximum value in the array
    // put it at the back(before the last max value) of array

    size_t pos = V.size() - 1; // last index of an array
    for (; pos > 0; pos--)     // loop until all value are swapped (from back to front)
    {
        size_t max_idx = 0;
        for (size_t i = 0; i <= pos; i++) // loop to find max value of unsorted part
        {
            if (V[i] > V[max_idx])
            {
                // if current index is MAX then that is the new max_index
                max_idx = i;
            }
        }
        // put the max value next to the sorted (to the left)
        swap(V[pos], V[max_idx]);
    }
}

int main()
{
    vector<int> vec = {1, 5, 4, 6, 2, 8, 7, 9, 3};
    selection_sort(vec);

    for (auto &x : vec)
    {
        cout << x << " ";
    }
}