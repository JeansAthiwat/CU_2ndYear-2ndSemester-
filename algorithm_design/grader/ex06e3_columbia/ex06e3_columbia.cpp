#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int walkable[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

int main()
{
    int R, C;
    cin >> R >> C;

    vector<vector<int>> entry_cost(R, vector<int>(C));

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cin >> entry_cost[r][c];
        }
    }
    vector<vector<int>> path_cost(R, vector<int>(C, INF));
    vector<vector<pair<int, int>>> prev(R, vector<pair<int, int>>(C, {-1, -1}));
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    set<pair<int, pair<int, int>>> pickable;

    pickable.insert({0, {0, 0}});
    path_cost[0][0] = 0;
    visited[0][0] = true;

    while (!pickable.empty())
    {
        auto tmp = *pickable.begin();
        auto price = tmp.first;
        auto coor = tmp.second;
        auto x = coor.first;
        auto y = coor.second;
        visited[x][y] = true;
        pickable.erase(tmp);

        for (int direction = 0; direction < 4; direction++)
        {
            int next_x = x + walkable[direction][0];
            int next_y = y + walkable[direction][1];

            // dont check if out of vound
            if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C)
                continue;

            if (!visited[next_x][next_y] && (path_cost[next_x][next_y] > path_cost[x][y] + entry_cost[next_x][next_y]))
            {
                pickable.erase({path_cost[next_x][next_y], {next_x, next_y}});
                path_cost[next_x][next_y] = path_cost[x][y] + entry_cost[next_x][next_y];
                prev[next_x][next_y] = {x, y};
                pickable.insert({path_cost[next_x][next_y], {next_x, next_y}});
            }
        }
    }

    for (auto &vec : path_cost)
    {
        for (auto &value : vec)
        {
            cout << value << " ";
        }
        cout << "\n";
    }

    return 0;
}