#include <bits/stdc++.h>

using namespace std;

/*
TASK: find all possible COMBINATION of the letter "ilovecat<3"
INPUT: an array (vector in this case) of English alphabets
OUTPUT: All possible combination for the input array

candidate solution : { i l o v e c a t < 3}
Set of candidate solution : powerset of { i l o v e c a t < 3}
Satisfaction condition : all the possible combi
*/
int comb_count = 0;  // combinations count
int recur_count = 0; // number of times the function is called
void combinations(int total_index, std::vector<bool> &areSol, int current_index, vector<char> &candidateSolution, int k, int chosen)
{
    // recursive At ith step, we decides if the ith item is selected
    if (current_index < k)
    {
        // preorder traversal

        areSol[current_index] = false;
        combinations(total_index, areSol, current_index + 1, candidateSolution, k, chosen);
        // if we pick we must check that the sol len is not more that k (aka chosen < k)
        if (chosen < k)
        {
            areSol[current_index] = true;
            combinations(total_index, areSol, current_index + 1, candidateSolution, k, chosen+1);
        }
    }
    else
    {
        // reaches the leaf
        for (int i = 0; i < total_index; i++)
        {
            if (areSol[i] == true)
            {
                cout << candidateSolution[i] << "";
            }
        }
        cout << endl;
        comb_count++;
    }
    recur_count++;
}

int main()
{
    int k = 7;
    vector<char> candidateSolution({'I', 'L', 'O', 'V', 'E', 'C', 'A', 'T', 'S', '<', '3'});
    for (char &x : candidateSolution)
    {
        cout << x;
    }
    cout << endl;

    int total_index = candidateSolution.size();

    vector<bool> areSol(total_index);
    // define vector<bool> pickToSol to prevent recreation in recursion (instead pass the cerrect solution's lengths)
    int count = 0;
    int chosen = 0;
    combinations(total_index, areSol, 0, candidateSolution, k, chosen);

    cout << total_index << endl;
    cout << endl
         << comb_count << endl;
    cout << endl
         << recur_count << endl;
}