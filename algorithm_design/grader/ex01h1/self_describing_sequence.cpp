#include <bits/stdc++.h>
using namespace std;
int N;
int binary_solve()
{
    int result = 0;

    return result;
}
int main()
{
    cin >> N;
    while (N--)
    {
        int i;
        int value = 1;
        cin >> i;
        while (i > ((value * (value + 1)) / 2))
        {
            value++;
        }
        cout << value << "\n";
    }

    return 0;
}