#include <bits/stdc++.h>
using namespace std;

int walkable[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main()
{
    int r, c, T;
    cin >> r >> c >> T;
    int total_infected = 0;
    int time = 0;
    vector<vector<int>> provinces(r, vector<int>(c));
    vector<vector<int>> visited_date(r, vector<int>(c, -1));

    queue<pair<int, int>> queue;

    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            cin >> provinces[row][col];
            if (provinces[row][col] == 1)
            {
                visited_date[row][col] = time;
                if (visited_date[row][col] < T)
                {
                    queue.push({row, col});
                }
                total_infected++;
            }
        }
    }

    while (!queue.empty())
    {
        pair<int, int> tmp = queue.front();
        queue.pop();
        int v_r = tmp.first;
        int v_c = tmp.second;
        for (int direction = 0; direction < 4; direction++)
        {
            int new_r = v_r + walkable[direction][0];
            int new_c = v_c + walkable[direction][1];
            if (new_r < 0 || new_c < 0 || new_r >= r || new_c >= c)
            {
                // out of bound
                continue;
            }

            if (provinces[new_r][new_c] == 2)
            {
                continue;
            }

            if (visited_date[new_r][new_c] == -1)
            {
                visited_date[new_r][new_c] = visited_date[v_r][v_c] + 1;
                if (visited_date[new_r][new_c] < T)
                {
                    queue.push({new_r, new_c});
                }
                total_infected++;
            }
        }
    }

    cout << total_infected;
}
/*
5 4 3
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 1

*/