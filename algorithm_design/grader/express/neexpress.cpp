// thelast one alhorithm

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{

    int N, cost12;
    cin >> N >> cost12;

    vector<vector<int>> travel_cost(N + 2, vector<int>(N + 2, INF));
    for (int i = 0; i <= N + 1; i++)
        travel_cost[i][i] = 0;

    travel_cost[1][2] = cost12;
    travel_cost[2][1] = cost12;

    for (int i = 3; i <= N + 1; i++)
    {
        int ki;
        cin >> ki;

        for (int e = 0; e < ki; e++)
        {
            int t, p;
            cin >> t >> p;
            travel_cost[i][t] = p;
            travel_cost[t][i] = p;
        }
    }

    for (int k = 3; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                travel_cost[i][j] = min(travel_cost[i][j], travel_cost[i][k] + travel_cost[k][j]);
            }
        }

        cout << travel_cost[1][2] << " ";
    }
    return 0;
}
/*
5 5000
2 1 657 2 63
2 1 16 2 212
2 1 227 2 874
2 1 977 2 418


*/