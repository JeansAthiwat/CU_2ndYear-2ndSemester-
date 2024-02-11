#include <bits/stdc++.h>
using namespace std;

int N;

int dist(pair<int, int> &A, pair<int, int> &B)
{
    return pow((A.first - B.first), 2) + pow((A.second - B.second), 2);
}

int closest_pair(vector<pair<int, int>> &sortByX, vector<pair<int, int>> &sortByY)
{
    int min_dist;
    int X_len = sortByX.size();

    // base case
    if (X_len == 2)
        return dist(sortByX[0], sortByX[1]);
    if (X_len == 3)
        return min({dist(sortByX[0], sortByX[1]), dist(sortByX[0], sortByX[2]), dist(sortByX[1], sortByX[2])});

    // divide
    int mid = X_len / 2;
    vector<pair<int, int>> lHalfX, rHalfX, lHalfY, rHalfY;

    for (size_t i = 0; i <= mid; i++)
        lHalfX.push_back(sortByX[i]);
    for (size_t i = mid + 1; i < X_len; i++)
        rHalfX.push_back(sortByX[i]);

    for (size_t i = 0; i < X_len; i++)
    {
        if (lHalfX.back().first >= sortByY[i].first)
        {
            lHalfY.push_back(sortByY[i]);
        }
        else
        {
            rHalfY.push_back(sortByY[i]);
        }
    }

    int minl = closest_pair(lHalfX, lHalfY);
    int minr = closest_pair(rHalfX, rHalfY);
    min_dist = min(minl, minr);

    // conquer
    vector<pair<int, int>> striped;
    for (auto [x, y] : sortByY)
    {
        if (pow((x - lHalfX.back().first), 2) < min_dist)
            striped.emplace_back(x, y);
    }

    for (int i = 0; i < striped.size(); i++)
    {
        for (int j = i + 1; j < striped.size(); j++)
        {
            if ((striped[j].second - striped[i].second) * (striped[j].second - striped[i].second) >= min_dist)
                break;

            min_dist = min(min_dist, dist(striped[i], striped[j]));
        }
    }

    return min_dist;
}

int main()
{
    cin >> N;
    vector<pair<int, int>> sortByX(N);
    vector<pair<int, int>> sortByY(N);

    for (size_t i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        sortByX[i] = {x, y};
        sortByY[i] = {y, x};
    }

    sort(sortByX.begin(), sortByX.end());
    sort(sortByY.begin(), sortByY.end());
    for (auto &[y, x] : sortByY)
        swap(y, x);

    int distac = closest_pair(sortByX, sortByY);
    cout << distac;

    return 0;
}