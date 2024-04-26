#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int totalSeqPossible = 0;

int heuristic(vector<int> &sol, int len, int target, int sum)
{
    // dont know bro
    int estimate = 0;

    return estimate;
}

bool backtrack(vector<int> &sol, int index, int input)
{
    if (sol[index - 1] > input)
        return false;

    return true;
}

void permutate(vector<int> &sol, int len, int target, int sum)
{
    if (sum > target)
        return;

    if (sum < target)
    {
        for (int i = 1; i <= target; i++)
        {
            if (backtrack(sol, len, i))
            {
                sol[len] = i;
                permutate(sol, len + 1, target, sum + i);
                sol[len] = -INF;
            }
        }
        return;
    }

    if (sum == target)
    {
        totalSeqPossible++;
        /*for (int i = 1; i < len; i++)
        {
            cout << sol[i] << " ";
        }
        cout << " : " << totalSeqPossible << " \n";*/
        return;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> sol(100 + 1, -INF);

    permutate(sol, 1, N, 0);

    cout << totalSeqPossible;
    return 0;
}
