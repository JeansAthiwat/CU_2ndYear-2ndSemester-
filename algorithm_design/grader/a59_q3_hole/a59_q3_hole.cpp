#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;

int walkable[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // right down left up

vector<vector<int>> field_min_w(1001, vector<int>(1001, INF));
vector<vector<int>> hole_depth(1001, vector<int>(1001, 0)); // 0 is no holes 1 is hoels

// solve with djik's but sucks ass cuz of queue wojak
int main()
{

    int N, homeX, HomeY;
    cin >> N >> homeX >> HomeY;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        hole_depth[x][y] = 1;
    }

    int ans = INF;
    // starts the shortest weight problem
    queue<tuple<int, int, int>> q;
    q.push({0, homeX, HomeY});
    field_min_w[homeX][HomeY] = 0;

    while (!q.empty())
    {
        int weight = get<0>(q.front());
        int currX = get<1>(q.front());
        int currY = get<2>(q.front());
        q.pop();

        // check if current pos is the edge
        if (currX == 1 || currY == 1 || currX == 1000 || currY == 1000)
        {
            ans = min(ans, field_min_w[currX][currY]);
            continue;
        }

        // calculate the next walkable position
        for (int direction = 0; direction < 4; direction++)
        {
            int nextX = currX + walkable[direction][0];
            int nextY = currY + walkable[direction][1];

            if (field_min_w[nextX][nextY] == INF)
            {
                field_min_w[nextX][nextY] = field_min_w[currX][currY] + hole_depth[nextX][nextY];
                q.push({field_min_w[nextX][nextY], nextX, nextY});
            }
            else if (field_min_w[nextX][nextY] != INF)
            {
                if (field_min_w[nextX][nextY] > field_min_w[currX][currY] + hole_depth[nextX][nextY])
                {
                    field_min_w[nextX][nextY] = field_min_w[currX][currY] + hole_depth[nextX][nextY];
                    q.push({field_min_w[nextX][nextY], nextX, nextY});
                }
            }
        }
    }
    cout << ans;
    return 0;
}
