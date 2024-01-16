#include <bits/stdc++.h>

using namespace std;

bool pass_constraint(std::vector<int> &a, std::vector<int> &b, int m, int current_value, std::vector<bool> &used)
{
    // check if any number in array b has come before a in the answer or not?

    // loops through array b
    // if and B[i] equals to the current value to permutate, check for value of A[i] in sol
    for (int i = 0; i < m; i++)
    {
        if (b[i] == current_value)
        {
            //if a[i] is used then it passes the constains ( a[i] must come before b[i])
            if (used[a[i]])
            {
                return true;
            }else{
                return false;
            }
        }
    }

    //no b[i] equals to the current value so no problem
    return true;
}

void perm_with_constaint(int n, std::vector<int> &sol, int curr_sol_len, std::vector<bool> &used, std::vector<int> &a, std::vector<int> &b, int m)
{
    // permutate from lowest value to highest
    if (curr_sol_len < n)
    {
        for (int current_value = 0; current_value < n; current_value++)
        {
            if (!used[current_value] && pass_constraint(a, b, m, current_value, used))
            {
                sol[curr_sol_len] = current_value;
                used[current_value] = true;
                perm_with_constaint(n, sol, curr_sol_len + 1, used, a, b, m);
                used[current_value] = false;
            }
        }
    }
    else
    {
        for (int &x : sol)
            std::cout << x << " ";
        std::cout << "\n";
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    // define needed variables
    std::vector<int> a(m);
    std::vector<int> b(m);

    // fill in constaints for vec a and b
    for (int i = 0; i < m; i++)
    {
        std::cin >> a[i] >> b[i];
    }

    // define pass to fn variable (prevent copy and construct in each recursion)
    std::vector<int> sol(n);
    std::vector<bool> used(n);
    int starting_recur_index = 0;

    perm_with_constaint(n, sol, starting_recur_index, used, a, b, m);

    return 0;
}