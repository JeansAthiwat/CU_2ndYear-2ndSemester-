#include <bits/stdc++.h>
using namespace std;

int N;
const int INF = 2e9;
vector<int> A;
vector<int> max_suffix_ans;

int mss(vector<int> &max_suffix_ans)
{
    // divide by (n-1) and 1
    // find max of n-1 element vs last element vs between n-1 and last element
    max_suffix_ans[1] = A[1];
    for (int i = 2; i <= N; i++)
    {
        max_suffix_ans[i] = max(max_suffix_ans[i - 1] + A[i], A[i]);
    }

    int max_mss = max_suffix_ans[1];
    for (int i = 2; i <= N; i++)
    {
        max_mss = max(max_mss, max_suffix_ans[i]);
    }

    return max_mss;
}

int main()
{
    cin >> N;
    A.resize(N + 5);
    max_suffix_ans.resize(N + 5);

    for (size_t i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        A[i] = x;
    }

    int sum = mss(max_suffix_ans);
    cout << sum;
    return 0;
}
