#include <bits/stdc++.h>
using namespace std;
int N, M;
int circularDist = 0;

int min_dist_no_portal(vector<int> &accDistClockWise, int from, int to)
{
    int diff = abs(accDistClockWise[to] - accDistClockWise[from]);
    int counterClockWise = circularDist - diff;
    return min(diff, counterClockWise);
}

int min_dist_with_portal(vector<int> &accDistClockWise, int from, int to, int p1, int p2)
{
    // min of
    /*
    1.direct a to b
    2. a to p1 to p2 to b
    3. a to p2 to p1 to b
    */
    int direct = min_dist_no_portal(accDistClockWise, from, to);
    int toP1 = min_dist_no_portal(accDistClockWise, from, p1) + min_dist_no_portal(accDistClockWise, p2, to);
    int toP2 = min_dist_no_portal(accDistClockWise, from, p2) + min_dist_no_portal(accDistClockWise, p1, to);

    return min({direct, toP1, toP2});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<int> order(M + 1);
    vector<int> dist(M);
    vector<int> accDistClockWise(M);

    for (int i = 0; i < M; i++)
        cin >> order[i];

    order[M] = order[0];
    for (int i = 0; i < M; i++)
    {
        cin >> dist[i];
        accDistClockWise[i] = circularDist;
        circularDist += dist[i];
    }

    for (int day = 0; day < N; day++)
    {
        int p1, p2;
        cin >> p1 >> p2;

        int total_dist = 0;
        for (int i = 0; i < M; i++)
        {
            total_dist += min_dist_with_portal(accDistClockWise, order[i], order[i + 1], p1, p2);
        }
        cout << total_dist << "\n";
    }
    return 0;
}