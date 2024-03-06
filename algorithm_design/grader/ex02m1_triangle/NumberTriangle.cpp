#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> triangle(1, vector<int>(1, 0));

void print(vector<vector<int>> &el_triangle)
{
    for (auto level : el_triangle)
    {
        for (auto index : level)
        {
            cout << index << " ";
        }
        cout << "\n";
    }
}

int solve_max(int level, int index)
{
    // divide and zoinker
    if (level == N)
        return triangle[level][index];

    // for topdown
    if (false)
    {
        return 0;
    }

    // div and conq
    return triangle[level][index] + max(solve_max(level + 1, index), solve_max(level + 1, index + 1));
}
int main()
{

    cin >> N;

    for (int level = 1; level <= N; level++)
    {
        vector<int> tmp(1);
        for (int index = 1; index <= level; index++)
        {
            int number_input;
            cin >> number_input;
            tmp.push_back(number_input);
        }
        triangle.push_back(tmp);
    }
    // print(triangle);
    cout << solve_max(1, 1);
    return 0;
}