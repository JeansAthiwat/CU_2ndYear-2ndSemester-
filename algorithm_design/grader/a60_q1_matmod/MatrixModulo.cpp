#include <bits/stdc++.h>

using namespace std;

int N, K;

vector<vector<int>> metrix_mod_mul(vector<vector<int>> &P, vector<vector<int>> &Q)
{
    vector<vector<int>> C(2, vector<int>(2, 0)); // create a 2 by 2 metrix

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                C[i][j] = (C[i][j] + P[i][k] * Q[k][j]) % K;
            }
        }
    }

    return C;
}

vector<vector<int>> mod_recur(vector<vector<int>> &A, int n)
{
    if (n == 1)
    {
        return A;
    }

    int half = n / 2;

    vector<vector<int>> HALFA = mod_recur(A, half);
    vector<vector<int>> Apawa = metrix_mod_mul(HALFA, HALFA);
    if (n % 2 == 0)
    {
        return Apawa;
    }
    else
    {
        Apawa = metrix_mod_mul(Apawa, A);
        return Apawa;
    }
}

vector<vector<int>> metrix_mod(vector<vector<int>> &A)
{
    return mod_recur(A, N);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<vector<int>> A(2, vector<int>(2, 0));

    cin >> N >> K;
    cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];

    vector<vector<int>> C = metrix_mod(A);

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            cout << C[i][j] << " ";
        }
        
    }
    
    return 0;
}