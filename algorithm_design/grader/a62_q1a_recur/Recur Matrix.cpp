#include <bits/stdc++.h>
using namespace std;

int a, b;

void recur(vector<vector<int>> &M, int a, int b, int r1, int r2, int c1, int c2)
{
    // div and conq
    // starts at H(a,b)
    // then divide into 4 quadrant ans store basecase results in M;

    // base case
    if (a == 0)
    {
        M[r1][c1] = b;
        return;
    }

    int rm = (r1 + r2) / 2;
    int cm = (c1 + c2) / 2;

    recur(M, a - 1, b, r1, rm, c1, cm);         // q1
    recur(M, a - 1, b - 1, r1, rm, cm + 1, c2); // q2
    recur(M, a - 1, b + 1, rm + 1, r2, c1, cm); // q3
    recur(M, a - 1, b, rm + 1, r2, cm + 1, c2); // q4
}

int main()
{
    cin >> a >> b;
    int El_tamano = pow(2, a);
    vector<vector<int>> M(El_tamano, vector<int>(El_tamano));
    recur(M, a, b, 0, El_tamano - 1, 0, El_tamano - 1);

    for (size_t i = 0; i < M.size(); i++)
    {
        for (size_t j = 0; j < M.size(); j++)
        {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}