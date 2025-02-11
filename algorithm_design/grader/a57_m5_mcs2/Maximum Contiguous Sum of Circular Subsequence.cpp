// C++ program for maximum contiguous circular sum problem
#include <bits/stdc++.h>
using namespace std;

// The function returns maximum
// circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
    // Corner Case
    if (n == 1)
        return a[0];

    // Initialize sum variable which store total sum of the array.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    // Initialize every variable with first value of array.
    int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];

    // Concept of Kadane's Algorithm
    for (int i = 1; i < n; i++)
    {
        // Kadane's Algorithm to find Maximum subarray sum.
        curr_max = max(curr_max + a[i], a[i]);
        max_so_far = max(max_so_far, curr_max);

        // Kadane's Algorithm to find Minimum subarray sum.
        curr_min = min(curr_min + a[i], a[i]);
        min_so_far = min(min_so_far, curr_min);
    }

    //in case everytin is 0
    if (min_so_far == sum)
        return max_so_far;

    // returning the maximum value
    return max(max_so_far, sum - min_so_far);
}

/* Driver program to test maxCircularSum() */
int main()
{
    int N;
    cin >> N;
    int a[N];
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    cout << maxCircularSum(a, N) << endl;
    return 0;
}
