#include <bits/stdc++.h>
using namespace std;
int N;
int totalSwap = 0;

void print_mat(vector<vector<int>> &to_move)
{
    cout << totalSwap << " _________________________ \n";
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            cout << to_move[i][j] << " ";
        }
        cout << "\n";
    }
    cout << " _________________________ \n";
}

int main()
{
    cin >> N;
    vector<int> arr(N);
    vector<vector<int>> to_move(4, vector<int>(4, 0)); // row is , col real should
    vector<int> presenceCount(4, 0);
    // number ar 1,2 or 3

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        presenceCount[num]++;
        arr[i] = num;
    }

    int j = 1;
    for (int i = 0; i < N; i++)
    {
        while (presenceCount[j] == 0)
            j++;
        to_move[arr[i]][j]++;
        presenceCount[j]--;
    }

    //print_mat(to_move);

    for (int i = 1; i <= 2; i++)
    {
        for (int j = i + 1; j <= 3; j++)
        {
            int op_count = min(to_move[i][j], to_move[j][i]);
            totalSwap += op_count;
            to_move[i][j] -= op_count;
            to_move[j][i] -= op_count;
        }
    }

    //print_mat(to_move);

    totalSwap += 2 * (to_move[1][2] + to_move[2][1]);

    cout << totalSwap;
    /*
    2 2 1 3 2 1 3
    1 1 2 2 2 3 3
    */

    // greedy
    // count 1 2 and 3
    //  find out of position 1 2 and 3 and it correstponding error state i guess

    return 0;
}