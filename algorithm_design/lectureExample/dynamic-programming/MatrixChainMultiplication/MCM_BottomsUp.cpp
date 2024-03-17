#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
vector<int> dimensions;

int mcm_bottoms_up(int number_of_matrices)
{
    // build table
    vector<vector<int>> mcm_ans(number_of_matrices + 2, vector<int>(number_of_matrices + 2, INF));

    for (int i = 1; i <= number_of_matrices; i++)
    {
        mcm_ans[i][i] = 0;
    }

    for (int diag = 1; diag <= number_of_matrices; diag++)
    {
        for (int col = 1; col <= number_of_matrices - diag; col++)
        {
            int row = col + diag;
            int min_cal = INF;

            for (int k = col; k < row; k++)
            {
                int curr_cal = mcm_ans[col][k] + mcm_ans[k + 1][row] + (dimensions[col] * dimensions[k+1] * dimensions[row + 1]);
                min_cal = min(min_cal, curr_cal);
            }

            mcm_ans[col][row] = min_cal;
        }
    }

    return mcm_ans[1][number_of_matrices];
}

int main()
{
    int N; // number of matrices
    cin >> N;
    dimensions.resize(N + 2);

    for (int i = 1; i <= N + 1; i++)
        cin >> dimensions[i];

    cout << mcm_bottoms_up(N);

    return 0;
}
