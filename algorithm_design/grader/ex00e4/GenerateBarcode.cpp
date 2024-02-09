#include <bits/stdc++.h>

using namespace std;

int A, B;

template <typename T>
void permutation(int len, vector<T> &res, vector<T> &solCandidate, int oneCount)
{
    if (len < B)
    {
        for (auto color : solCandidate)
        {
            if (color == 0) // black
            {
                if (B-len > A - oneCount)
                {
                    res[len] = 0;
                    permutation(len + 1, res, solCandidate, oneCount);
                }
            }
            else if (color == 1)
            {
                if (oneCount < A)
                {
                    res[len] = 1;
                    permutation(len + 1, res, solCandidate, oneCount + 1);
                }
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
    cin >> A >> B;
    vector<int> solCandidate({0, 1});
    vector<int> barCode(B); // 0 is black 1 is white
    permutation(0, barCode, solCandidate, 0);

    return 0;
}