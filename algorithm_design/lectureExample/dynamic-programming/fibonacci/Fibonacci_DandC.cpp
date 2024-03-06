#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    // trivial case f(0) = 0 and f(1) = 1
    if (n == 0 || n == 1)
        return n;

    // divide and conquer parts
    return solve(n - 1) + solve(n - 2);
}

int main()
{
    int N;
    cin >> N;

    cout << solve(N);

    return 0;
}