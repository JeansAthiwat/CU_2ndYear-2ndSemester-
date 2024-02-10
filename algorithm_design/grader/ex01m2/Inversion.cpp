#include <bits/stdc++.h>

using namespace std;

int getCombinations(const std::vector<int> &arr)
{
    int count = 0;

    // Use nested loops to generate combinations
    for (size_t i = 0; i < arr.size(); ++i)
    {
        for (size_t j = i + 1; j < arr.size(); ++j)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }

    return count;
}

int main()
{
    // Example array
    int n;
    cin >> n;

    std::vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // Get combinations
    int count = getCombinations(A);

    // Display the result
    std::cout << count;

    return 0;
}
