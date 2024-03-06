#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> triangle(1, vector<int>(1, 0));
vector<vector<int>> ans_triangle(1, vector<int>(1, 0));

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

void take_input()
{
    cin >> N;

    for (int level = 1; level <= N; level++)
    {
        vector<int> tmp(1);
        vector<int> ans_tmp(1);
        for (int index = 1; index <= level; index++)
        {
            int number_input;
            cin >> number_input;
            tmp.push_back(number_input);
            ans_tmp.push_back(-1);
        }
        triangle.push_back(tmp);
        ans_triangle.push_back(ans_tmp);
    }
}
int solve_max(int level, int index)
{
    // divide and zoinker
    if (level == N)
        return triangle[level][index];

    // solved case
    if (ans_triangle[level][index] > -1)
    {
        return ans_triangle[level][index];
    }

    // div and conq
    int cur_index_max = triangle[level][index] + max(solve_max(level + 1, index), solve_max(level + 1, index + 1));
    ans_triangle[level][index] = cur_index_max;
    return cur_index_max;
}
int main()
{
    take_input(); // print(triangle);
    cout << solve_max(1, 1);
    return 0;
}