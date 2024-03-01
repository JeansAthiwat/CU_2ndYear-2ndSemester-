#include <bits/stdc++.h>
using namespace std;

int L, X, Y;
vector<tuple<int, int, int>> ans;

void solve(int x1, int x2, int y1, int y2, int target_x, int target_y)
{
    // div and conq

    // base case
    if (x1 == x2 && y1 == y2)
        return;

    // divide
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    int tile_type;

    if (target_x <= xm && target_y <= ym) // empty in Q1
    {
        tile_type = 0;
        solve(x1, xm, y1, ym, target_x, target_y);     // solve q1
        solve(xm + 1, x2, y1, ym, xm + 1, ym);         // solve q2
        solve(x1, xm, ym + 1, y2, xm, ym + 1);         // solve q3
        solve(xm + 1, x2, ym + 1, y2, xm + 1, ym + 1); // solve q4
    }
    else if (target_x > xm && target_y <= ym) // empty in Q2
    {
        tile_type = 1;
        solve(x1, xm, y1, ym, xm, ym);                 // solve q1
        solve(xm + 1, x2, y1, ym, target_x, target_y); // solve q2
        solve(x1, xm, ym + 1, y2, xm, ym + 1);         // solve q3
        solve(xm + 1, x2, ym + 1, y2, xm + 1, ym + 1); // solve q4
    }
    else if (target_x <= xm && target_y > ym) // empty in Q3
    {
        tile_type = 2;
        solve(x1, xm, y1, ym, xm, ym);                 // solve q1
        solve(xm + 1, x2, y1, ym, xm + 1, ym);         // solve q2
        solve(x1, xm, ym + 1, y2, target_x, target_y); // solve q3
        solve(xm + 1, x2, ym + 1, y2, xm + 1, ym + 1); // solve q4
    }
    else // empty in Q4
    {
        tile_type = 3;
        solve(x1, xm, y1, ym, xm, ym);                     // solve q1
        solve(xm + 1, x2, y1, ym, xm + 1, ym);             // solve q2
        solve(x1, xm, ym + 1, y2, xm, ym + 1);             // solve q3
        solve(xm + 1, x2, ym + 1, y2, target_x, target_y); // solve q4
    }

    return ans.push_back({tile_type, xm, ym});
}
int main()
{

    // room length (x,y) missing tile
    cin >> L >> X >> Y;

    solve(0, L - 1, 0, L - 1, X, Y);

    cout << ans.size() << "\n";
    for (auto &res : ans)
    {
        printf("%d %d %d\n", get<0>(res), get<1>(res), get<2>(res));
    }

    return 0;
}