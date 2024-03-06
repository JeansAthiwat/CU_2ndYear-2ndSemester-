#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &f_res, int n)
{
    // trivial case f(0) = 0 and f(1) = 1
    if (n == 0 || n == 1)
        return n;

    // divide and conquer parts

    // if already solved use results from f_res
    if (f_res[n] > 0)
        return f_res[n];

    // solve if not solve yet
    int n_th_result = solve(f_res, n - 1) + solve(f_res, n - 2);

    // store the solved value(s) and return
    f_res[n] = n_th_result;
    return n_th_result;
}

int main()
{

    int N;
    cin >> N;
    vector<int> f_res(50);
    // f_res[0] = 0;
    // f_res[1] = 1;
    cout << solve(f_res, N);

    return 0;
}