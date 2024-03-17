#include <bits/stdc++.h>
using namespace std;
int INF = 2e9;
vector<int> dimensions;

int mcm(int start_matrix, int stop_matrix, vector<vector<int>> &mcm_ans)
{
    if (start_matrix < stop_matrix)
    {
        int min_cost = INF;
        for (int matrix_index = start_matrix; matrix_index < stop_matrix; matrix_index++)
        {
            int curr_cost = (dimensions[start_matrix] * dimensions[matrix_index + 1] * dimensions[stop_matrix + 1]);

            int left_sub_problems_cost;
            if (mcm_ans[start_matrix][matrix_index] != -1)
            {
                left_sub_problems_cost = mcm_ans[start_matrix][matrix_index];
            }
            else
            {
                left_sub_problems_cost = mcm(start_matrix, matrix_index, mcm_ans);
                mcm_ans[start_matrix][matrix_index] = left_sub_problems_cost;
            }

            int right_sub_problems_cost;
            if (mcm_ans[matrix_index + 1][stop_matrix] != -1)
            {
                right_sub_problems_cost = mcm_ans[matrix_index + 1][stop_matrix];
            }
            else
            {
                right_sub_problems_cost = mcm(matrix_index + 1, stop_matrix, mcm_ans);
                mcm_ans[matrix_index + 1][stop_matrix] = right_sub_problems_cost;
            }

            int sub_problems_cost = left_sub_problems_cost + right_sub_problems_cost;
            min_cost = min(min_cost, curr_cost + sub_problems_cost);
        }
        return min_cost;
    }
    // start == stop -> A = A same matrix no nneed for mult. cost is 0
    return 0;
}

int main()
{
    int N; // number of matrices
    cin >> N;
    dimensions.resize(N + 1 + 1);

    for (int i = 1; i <= N + 1; i++)
        cin >> dimensions[i];

    vector<vector<int>> mcm_ans(N + 2, vector<int>(N + 2, -1));
    cout << mcm(1, N, mcm_ans);

    return 0;
}