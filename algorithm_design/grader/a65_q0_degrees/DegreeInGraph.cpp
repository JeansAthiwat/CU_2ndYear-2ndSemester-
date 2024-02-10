#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> degCount(n);
    int maxDegree = 0;

    // find maxDegree and deal with degCount
    for (int i = 0; i < n; i++)
    {

        int deg = 0;

        // calculate the total degree of the node
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;

            deg += input;
        }

        degCount[deg]++;
        maxDegree = max(deg, maxDegree);
    }

    for (int i = 0; i < maxDegree + 1; i++)
    {
        cout << degCount[i] << " ";
    }

    return 0;
}