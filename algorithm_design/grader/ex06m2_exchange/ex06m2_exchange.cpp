// thelast one alhorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Kuestion;
    cin >> Kuestion;
    while (Kuestion--)
    {
        int N;
        cin >> N;
        vector<vector<double>> exchangeRate(N, vector<double>(N));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> exchangeRate[i][j];
                // a[i][j] = -log2(a[i][j]); ?
            }
        }

        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    exchangeRate[i][j] = max(exchangeRate[i][j], exchangeRate[i][k] * exchangeRate[k][j]);
                }
            }
        }

        // check if exchange back to the same currency is < 1;
        double ratio = 1.0;
        bool OK = true;
        for (int node = 0; node < N; node++)
        {
            if (exchangeRate[node][node] > ratio)
            {
                OK = false;
                break; // Exit loop early if a negative value is found
            }
        }

        if (OK)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
/*
2
3
1 0.7 1.2
1.1 1 2
0.75 0.7 1 2
1 0.7
1.2 1
*/