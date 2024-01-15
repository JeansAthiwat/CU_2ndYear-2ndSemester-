#include <bits/stdc++.h>

using namespace std;

/*
TASK: find all possible COMBINATION from the letter "ilovecat<3" that CONTAIN the substring C, A ,T
INPUT: an array (vector in this case) of English alphabets
OUTPUT: All possible combination for the input array CONTAIN the substring C A T

candidate solution : { i l o v e c a t < 3}
Set of candidate solution : set  { i ....a..c  t ......}
Satisfaction condition : all the possible combi   CONTAIN the substring C A T
*/
int comb_count = 0;  // combinations count
int recur_count = 0; // number of times the function is called

bool checkConstraint(std::vector<bool> &areSol, int current_index)
{
    // get c a and t index
    if (current_index > 7)
        return (areSol[5] && areSol[6] && areSol[7]);
}
void combinations(int total_index, std::vector<bool> &areSol, int current_index, vector<char> &candidateSolution)
{
    // recursive At ith step, we decides if the ith item is selected
    if (current_index < total_index)
    {
        // preorder traversal
        if (checkConstraint(areSol, current_index))
        {
            areSol[current_index] = false;
            combinations(total_index, areSol, current_index + 1, candidateSolution);
            areSol[current_index] = true;
            combinations(total_index, areSol, current_index + 1, candidateSolution);
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
    combinations(total_index, areSol, 0, candidateSolution);

    cout << total_index << endl;
    cout << endl
         << comb_count << endl;
    cout << endl
         << recur_count << endl;
}