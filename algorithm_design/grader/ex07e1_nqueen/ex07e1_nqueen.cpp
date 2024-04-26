#include <bits/stdc++.h>
using namespace std;

int totalPossibleWays = 0;

void printdaboard(vector<int> &sol)
{

    for (auto &x : sol)
    {
        cout << x << " ";
    }
    cout << "\n";
}

bool checkConstrain(vector<int> &sol, int len)
{
    // cout << "HI\n";
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            // cout << i << " " << j << " " << sol[i] << " " << sol[j] << " \n";
            if (abs(i - j) == abs(sol[i] - sol[j]))
            {
                return false;
            }
        }
    }
    return true;
}

void permutateEachRow(int len, vector<int> &sol, vector<bool> &used, int total)
{
    if (len < total)
    {
        for (int c = 0; c < total; c++)
        {
            // backtracking
            if (used[c] == true)
            {
                continue;
            }
            else
            {
                if (checkConstrain(sol, len))
                {
                    sol[len] = c;
                    used[c] = true;
                    permutateEachRow(len + 1, sol, used, total);
                    used[c] = false;
                }
            }
        }
    }
    else
    {

        if (checkConstrain(sol, total))
        {
            totalPossibleWays++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> solution(n);
    vector<bool> used(n);
    permutateEachRow(0, solution, used, n);
    cout << totalPossibleWays;
    return 0;
}
