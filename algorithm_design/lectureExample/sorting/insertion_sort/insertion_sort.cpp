#include <bits/stdc++.h>
using namespace std;

template <typename T>
void insertion_sort(vector<T> &A)
{
    // try to insert each value to its proper position
    for (int pos = A.size() - 2; pos >= 0; pos--)
    {
        //loop throught unsorted part from back to front
        T tmp = A[pos]; // hold the currect probing index
        size_t i = pos + 1; // index of the next value
        while (i < A.size() && A[i] < tmp) // while the index of the larger value is not the and and is still smaller than the current probing index
        {
            A[i - 1] = A[i]; //กะเถิบๆๆๆๆๆๆๆ
            i++;
        }
        A[i - 1] = tmp; //แปะ
    }
}

int main()
{
    vector<int> vec = {1, 5, 4, 6, 2, 8, 7,2,4, 9, 3};
    insertion_sort(vec);

    for (auto &x : vec)
    {
        cout << x << " ";
    }
}