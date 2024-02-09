#include <bits/stdc++.h>

using namespace std;

// solve using 2 pointers techniques as the vector are already sorted if it is not hashing may begud
bool find3Numbers(vector<int> &A, int arr_size, int target)
{
    int left, right;

    // we use i <= arr_size - 3 here as we have to pick 3
    for (int i = 0; i <= arr_size - 3; i++)
    {
        // ปัก pointer
        left = i + 1;
        right = arr_size - 1;

        // loop through the remaining 2 with Sigma tech
        while (left < right)
        {
            // if sum is equals to the targetreturn true
            int sum = A[i] + A[left] + A[right];
            if (sum == target)
            {
                return true;
            }
            // if it is more than the target move the right pointer to the right (decrease value)
            else if (sum > target)
            {
                right--;
            }
            // if it is less than the target move the left pointer to the left (increase value)
            else if (sum < target)
            {
                left++;
            }
        }
    }
    return false;
}
/* Driver code */
int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;

        bool isItPwossibwleUWU = find3Numbers(A, n, target);
        if (isItPwossibwleUWU)
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
