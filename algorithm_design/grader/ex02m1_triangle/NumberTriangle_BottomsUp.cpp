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

int solve_max_BU()
{
    // divide and zoinker
    for (int lastLevelIndex = 1; lastLevelIndex <= N; lastLevelIndex++)
    {
        ans_triangle[N][lastLevelIndex] = triangle[N][lastLevelIndex];
    }

    for (int level = N; level > 1; level--)
    {
        for (int index = 1; index < level; index++)
        {
            //(i have 1 unused level last one in ans)
            ans_triangle[level - 1][index] = triangle[level - 1][index] + max(ans_triangle[level][index], ans_triangle[level][index + 1]);
        }
    }

    return ans_triangle[1][1];
}
int main()
{
    take_input(); // print(triangle);
    cout << solve_max_BU();
    return 0;
}