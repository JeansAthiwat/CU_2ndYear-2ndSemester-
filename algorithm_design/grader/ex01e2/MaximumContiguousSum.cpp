#include <bits/stdc++.h>

using namespace std;

int sub_sum(vector<int> &A, vector<int> &S, int start, int stop)
{
    if (start == stop)
        return A[start];

    // divde and conquer
    // keep in mid sum[i][j] = sum[i][m] + sum[m+1][j];
    int mid = (start + stop) >> 1;

    int max_left_sum = S[mid] - S[start-1];
    // calculate cross_max
    for (size_t l = start; l < mid; l++)
    {
        int left_sum = S[mid] - S[l-1];
        max_left_sum = left_sum > max_left_sum ? left_sum : max_left_sum;
    }

    int max_right_sum = S[stop] - S[mid + 1-1];
    for (size_t r = mid + 2; r < stop; r++)
    {
        int right_sum = S[r] - S[mid + 1-1];
        max_right_sum = right_sum > max_right_sum ? right_sum : max_right_sum;
    }

    int cross_max = max_left_sum + max_right_sum;

    return max(max(sub_sum(A, S, start, mid), sub_sum(A, S, mid + 1, stop)), cross_max);
}

int main()
{
    int N;
    cin >> N;

    vector<int> S(N + 5);
    vector<int> A(N + 5);

    for (size_t i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        A[i] = x;
        S[i] = S[i - 1] + x;
    }

    int sum = sub_sum(A, S, 1, N);
    cout << sum;
    return 0;
}