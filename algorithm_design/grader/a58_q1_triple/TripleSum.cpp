#include <bits/stdc++.h>

using namespace std;

template <typename T>
bool combinations(int total_index, std::vector<bool> &areSol, int current_index, vector<T> &candidateSolution, int k, int chosen, vector<int> &outvalues, int need)
{
    // recursive At ith step, we decides if the ith item is selected
    if (current_index < total_index)
    {
        // preorder traversal
        // if we are not gonnapick currect_index we must make sure that the remaining index is more to k
        if (chosen + (total_index - current_index) > k)
        {
            areSol[current_index] = false;
            if (combinations(total_index, areSol, current_index + 1, candidateSolution, k, chosen, outvalues, need))
                return true;
        }

        // if we pick we must check that the sol len is not more that k (aka chosen < k)
        if (chosen < k)
        {
            areSol[current_index] = true;
            outvalues[chosen] = candidateSolution[current_index];
            if (combinations(total_index, areSol, current_index + 1, candidateSolution, k, chosen + 1, outvalues, need))
                return true;
        }
    }
    else
    {
        int sum = outvalues[0] + outvalues[1] + outvalues[2];
        // cout << "sum: " << sum << "\n ";
        if (sum == need)
        {
            // cout << " " << outvalues[0] << " " << outvalues[1] << " " << outvalues[2];
            return true;
        }
        // cout << endl;
    }
    return false;
}

int main()
{
    int k = 3;
    int n, m;
    cin >> n >> m;

    vector<int> candidateSolution(n);
    for (int i = 0; i < n; i++)
    {
        cin >> candidateSolution[i];
    }

    int total_index = candidateSolution.size();
    vector<bool> areSol(total_index);
    vector<int> outvalues(k);

    for (int i = 0; i < m; i++)
    {
        int ans;
        cin >> ans;
        bool sex = combinations(total_index, areSol, 0, candidateSolution, k, 0, outvalues, ans);
        if (sex)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}