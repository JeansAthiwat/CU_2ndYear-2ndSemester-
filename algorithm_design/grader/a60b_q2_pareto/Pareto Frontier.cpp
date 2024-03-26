#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int X[MAX_N], Y[MAX_N];

vector<int> pareto(int l, int r)
{
    if (l == r)
        return {l};

    int m = (l + r) / 2;
    vector<int> l_res = pareto(l, m);
    vector<int> r_res = pareto(m + 1, r);

    int i = 0;
    int j = 0;
    vector<int> results;
    while (i < l_res.size() || j < r_res.size())
    {
        if (i == l_res.size())
            results.push_back(r_res[j++]);
        else if (j == r_res.size())
            results.push_back(l_res[i++]);
        else
        {
            // ai not comsumed by aj
            if (!((X[l_res[i]] <= X[r_res[j]]) && (Y[l_res[i]] <= Y[r_res[j]])))
                results.push_back(l_res[i++]);
            else
            {
                // while ai is consumed by aj skip
                while ((i < l_res.size()) && ((X[l_res[i]] <= X[r_res[j]]) && (Y[l_res[i]] <= Y[r_res[j]])))
                    i++;
                results.push_back(r_res[j++]);
            }
        }
    }

    return results;
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> points;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];

        points.emplace_back(X[i], Y[i]);
    }

    sort(points.begin(), points.end());

    for (int i = 0; i < N; i++)
        X[i] = points[i].first, Y[i] = points[i].second;

    cout << pareto(0, N - 1).size();
    return 0;
}