#include <bits/stdc++.h>

using namespace std;
/*
THE OTHER varient
is just sort  1 index per round
*/

vector<int> GAPS = {4, 2, 1};

template <typename T>
void shell_sort(vector<T> &A)
{
    for (auto gap : GAPS)
    {

        for (int round = A.size() - 1; round > A.size() - 1 - gap; round--)
        {
            // do insertion sort
            int pos = round - gap;
            while (pos >= 0)
            {
                T tmp = A[pos];
                int index = pos + gap;

                while (index < A.size() - 1 && tmp > A[index])
                {
                    A[index - gap] = A[index];
                    index = index + gap;
                }
                A[index - gap] = tmp;
                pos -= 1;

                for (auto x : A)
                {
                    cout << x << ",";
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    vector<int> test = {7, 4, 6, 8, 5, 2, 9, 1, 3, 11, 0, 10};

    for (auto x : test)
    {
        cout << x << ",";
    }
    cout << endl;
    shell_sort(test);
    cout << "RES : ";
    for (auto x : test)
    {
        cout << x << ",";
    }
    cout << endl;
}