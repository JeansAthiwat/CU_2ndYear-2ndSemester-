#include <bits/stdc++.h>
using namespace std;
int INF = 2e9;
vector<int> dimensions;
int mcm(int start_matrix, int stop_matrix)
{
    if (start_matrix < stop_matrix)
    {
        int min_cost = INF;
        for (int matrix_index = start_matrix; matrix_index < stop_matrix; matrix_index++)
        {
            int curr_cost = +(dimensions[start_matrix] * dimensions[matrix_index + 1] * dimensions[stop_matrix + 1]);
            int sub_problems_cost = (mcm(start_matrix, matrix_index) + mcm(matrix_index + 1, stop_matrix));
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
    {
        int dim;
        cin >> dim;
        dimensions[i] = dim;
    }

    cout << mcm(1, N);

    return 0;
}