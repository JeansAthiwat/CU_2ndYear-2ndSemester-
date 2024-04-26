#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

char table[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
        cin >> table[i];

    // sets every index to -1 dist
    memset(dist, -1, sizeof(dist));

    // starts bfs
    queue<pair<int, int>> q;

    // case drop and found obstacle
    if (table[0][0] == '.')
    {
        q.push({0, 0});
        dist[0][0] = 0;
    }
    while (!q.empty())
    {
        auto [ux, uy] = q.front();
        q.pop();

        // check four possible walking ways .. left right up down
        for (int i = 0; i < 4; i++)
        {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 0 or vy < 0 or vx >= R or vy >= C)
                continue;

            if (dist[vx][vy] == -1 and table[vx][vy] != '#')
            {
                dist[vx][vy] = dist[ux][uy] + 1;
                q.push({vx, vy});
            }
        }
    }
    std::cout << dist[R - 1][C - 1];
    return 0;
}