#include <bits/stdc++.h>
using namespace std;
int N;
const int INF = 2e9;
vector<int> S;
vector<int> A;
vector<int> max_suffix_ans(N);
int max_suffix(int stop)
{
    // trivial case
    if (stop == 1)
        return A[1];

    if (max_suffix_ans[stop] > -INF)
        return max_suffix_ans[stop];

    int max_curr = max(max_suffix(stop - 1) + A[stop], A[stop]);
    max_suffix_ans[stop] = max_curr;
    return max_curr;
}

int mss(int stop)
{
    // trivial case
    if (stop == 1)
        return A[1];

    // divide by (n-1) and 1
    // find max of n-1 element vs last element vs  between n-1 and last element
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
    max_suffix_ans.resize(N + 5, -INF);

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