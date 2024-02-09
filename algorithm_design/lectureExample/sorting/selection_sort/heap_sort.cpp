#include <bits/stdc++.h>

using namespace std;

template <typename T>
void fix_down(vector<T> &A, size_t index, size_t size)
{
    T tmp = A[index];
    size_t c;
    while ((c = 2 * index + 1) < size)
    {
        if (c + 1 <= size && A[c] < A[c + 1])
            c++;
        if (A[c] < tmp)
            break;
        A[index] = A[c];
        index = c;
    }
    A[index] = tmp;
}

template <typename T>
void heap_sort(vector<T> &A)
{
    // selecting last position
    size_t pos = A.size() - 1;

    // make a psudoHeap
    for (int i = A.size() / 2; i >= 0; i--)
    {
        fix_down(A, i, A.size());
    }

    // loop to swap the max of unsorted (first index of heap with last index of heap)
    while (pos > 0)
    {
        swap(A[0], A[pos]);
        pos--;
        fix_down(A, 0, pos);
    }
}

int main()
{
    vector<int> test({1, 4, 6, 8, 7, 5, 2, 3, 9});

    heap_sort(test);
    for (auto x : test)
    {

        cout << x << " ";
    }
    return 0;
}