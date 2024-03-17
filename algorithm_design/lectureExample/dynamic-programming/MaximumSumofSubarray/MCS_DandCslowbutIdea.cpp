#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> S;
vector<int> A;
int max_suffix(int stop)
{
    if (stop == 1)
        return A[1];

    return max(max_suffix(stop - 1) + A[stop], A[stop]);
}

int mss(int stop)
{
    if (stop == 1)
        return A[1];

    // divide by (n-1) and 1
    int r1, r2, r3;
    r1 = mss(stop - 1);
    r2 = A[stop];
    r3 = max_suffix(stop - 1) + A[stop];

    return max({r1, r2, r3});
}

int main()
{

    cin >> N;
    S.resize(N + 5);
    A.resize(N + 5);

    for (size_t i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        A[i] = x;
        S[i] = S[i - 1] + x;
    }

    int sum = mss(N);
    cout << sum;
    return 0;
}