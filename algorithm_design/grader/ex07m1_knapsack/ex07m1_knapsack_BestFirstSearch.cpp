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

double heuristic(int len, double weight, double values)
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

bool isPuttable(vector<bool> &solComb, int len, double weight, double values)
{
    if (weight + w[len] > W)
        return false;
    return true;
}

class CustomCompare
{
public:
    bool operator()(const std::tuple<double, std::vector<bool>, int, double, double> &a,
                    const std::tuple<double, std::vector<bool>, int, double, double> &b) const
    {
        // Compare only the first element of the tuples
        return std::get<0>(a) < std::get<0>(b); // Put maximum first
    }
};

void bestFirstSearch(vector<bool> &solComb, int len, double weight, double values)
{
    // initial [f,f,f,f,f,f,f,f]
    priority_queue<
        tuple<double, vector<bool>, int, double, double>,
        vector<tuple<double, vector<bool>, int, double, double>>,
        CustomCompare>
        pq;

    pq.push({0, solComb, 1, 0, 0});
    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();

        auto tmp_heuristic_score = get<0>(tmp);
        auto tmp_solComb = get<1>(tmp);
        auto tmp_len = get<2>(tmp);
        auto tmp_weight = get<3>(tmp);
        auto tmp_values = get<4>(tmp);
        //&& weight < W
        if (tmp_len <= N && tmp_weight < W)
        {
            // pick as much first bro
            // check if too much weight if put item in
            double est_score = heuristic(tmp_len, tmp_weight, tmp_values);
            if (est_score > currBest)
            {
                tmp_solComb[tmp_len] = true;

                if (isPuttable(tmp_solComb, tmp_len, tmp_weight, tmp_values))
                {
                    pq.push({est_score, tmp_solComb, tmp_len + 1, tmp_weight + w[tmp_len], tmp_values + v[tmp_len]});
                }

                tmp_solComb[tmp_len] = false;
                pq.push({est_score, tmp_solComb, tmp_len + 1, tmp_weight, tmp_values});
            }
        }
        else
        {
            currBest = max(currBest, tmp_values);
            // cout << "enter else" << tmp_values << " " << currBest << "\n";
        }
    }
}

double solve()
{
    vector<bool> solComb(N + 1, false);
    // combination problem
    //  isPuttable by checking currweight to W
    //  heuristic by checking max of possible rat knapsack
    // combination(solComb, 1, 0, 0);
    bestFirstSearch(solComb, 1, 0, 0);

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

    //printRatio(v, w, rat);

    cout << fixed << setprecision(4) << solve();
}