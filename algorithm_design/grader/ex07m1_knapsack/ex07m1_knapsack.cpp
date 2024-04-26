#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MAX_N = 101;
double W;
int N;

vector<double> v(MAX_N);
vector<double> w(MAX_N);
vector<tuple<double, double, double>> rat(MAX_N);

double currBest = -INF;

void printRatio(const vector<double> &v, const vector<double> &w, const vector<tuple<double, double, double>> &rat)
{
    cout << "Value   Weight   Ratio (Value/Weight)" << endl;
    for (int i = 0; i < rat.size(); i++)
    {
        cout << v[i] << "\t" << w[i] << "\t" << get<0>(rat[i]) << endl;
    }
    cout << "----------------------------------------" << endl;
}

double heuristic(vector<bool> &solComb, int len, double weight, double values)
{
    // TODO: rational knapsack
    int index = len;
    while (index <= N && get<0>(rat[index]) * w[index] + weight <= W)
    {
        weight += w[index];
        values += v[index];
        index++;
    }

    while (index <= N && weight < W)
    {
        double takeRatio = min(1.0, (W - weight) / w[index]);
        weight += w[index] * takeRatio;
        values += v[index] * takeRatio;
        index++;
    }

    return values;
}

bool isPossible(vector<bool> &solComb, int len, double weight, double values)
{
    if (weight + w[len] > W)
        return false;
    return true;
}

bool checkConstrain()
{
    return true;
}

void combination(vector<bool> &solComb, int len, double weight, double values)
{
    if (len <= N)
    {
        // pick as much first bro
        // check if too much weight if put item in
        if (values + heuristic(solComb, len, weight, values) > currBest)
        {
            solComb[len] = true;

            if (isPossible(solComb, len, weight, values))
            {
                combination(solComb, len + 1, weight + w[len], values + v[len]);
            }

            solComb[len] = false;
            combination(solComb, len + 1, weight, values);
        }
    }
    else
    {
        currBest = max(currBest, values);
    }
}

double solve()
{
    vector<bool> solComb(N, false);
    // combination problem
    //  isPossible by checking currweight to W
    //  heuristic by checking max of possible rat knapsack
    combination(solComb, 1, 0, 0);

    return currBest;
}

int main()
{

    cin >> W;
    cin >> N;
    v.resize(N + 1);
    w.resize(N + 1);
    rat.resize(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> v[i];
    for (int i = 1; i <= N; i++)
        cin >> w[i];

    for (int i = 1; i <= N; i++)
    {
        rat[i] = {v[i] / w[i], v[i], w[i]};
    }

    sort(rat.begin() + 1, rat.end(), greater<tuple<double, double, double>>());

    for (int i = 1; i <= N; i++)
    {
        v[i] = get<1>(rat[i]);
        w[i] = get<2>(rat[i]);
    }

    // printRatio(v, w, rat);

    cout << fixed << setprecision(4) << solve();
}