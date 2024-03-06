#include <bits/stdc++.h>
using namespace std;

vector<int> construct_table(int n)
{
    // construct the solution table form smaller sub-prob
    vector<int> f_res(n+1);
    f_res[0] = 0;
    f_res[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f_res[i] = f_res[i - 1] + f_res[i - 2];
    }
    return f_res;
}

int main()
{
    int N;
    cin >> N;

    vector<int> f_res = construct_table(N);

    cout << f_res[N];

    return 0;
}