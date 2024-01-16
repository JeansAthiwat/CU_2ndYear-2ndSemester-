#include <bits/stdc++.h>

using namespace std;

/*
TASK: find all possible PERMUTATIONs for the letter "Tom Marvolo Riddle"
INPUT: an array (vector in this case) of English alphabets
OUTPUT: All possible permutation for the input array

candidate solution : { Tom Marvolo Riddle }
Set of candidate solution : lot of set of 12 character
Satisfaction condition : all the possible combi
*/

/*
At ith step, we decides if the item for the ith position of the answer
• There are N choices at each step (recursion tree is N-ary tree)
• Do not pick item that is already included
• If it’s permutation with replacement(duplicate), we can skip this one*/
int perm_count = 0;  // combinations count
int recur_count = 0; // number of times the function is called
void permutations_kn(int total_index, std::vector<char> &areSol, int current_index, vector<bool> &used, vector<char> &candidateSolution,int k)
{
    // recursive until reaches to total_index needed
    if (current_index < k) // CHANGED***-------------------****
    {
        // check which character can be used to continue to permutate
        for (int i = 0; i < total_index; i++) // possible choice for n_th depth = total_index - n
        {
            // if the candidateSolution at index i_th hasnt been used, append to Sol and continue.
            if (used[i] == false)
            {
                used[i] = true;
                areSol[current_index] = candidateSolution[i];
                permutations_kn(total_index, areSol, current_index + 1, used, candidateSolution,k);
                used[i] = false;
            }
        }
    }
    // display sol after corrected length
    else
    {
        for (char &x : areSol)
        {
            cout << x;
        }
        cout << endl;
        perm_count++;
    }
    recur_count++;
}

int main()
{
    int k = 6; // PICK K ITEMS
    //vector<char> candidateSolution({'T', 'O', 'M', 'M', 'A', 'R', 'V', 'O', 'L', 'O', 'R', 'I', 'D', 'D', 'L', 'E'});
    vector<char> candidateSolution({'L', 'I', 'S', 'T', 'E', 'N','H','A','R','D'});
    for (char &x : candidateSolution)
    {
        cout << x;
    }
    cout << endl;

    int total_index = candidateSolution.size();
    // define vector<bool> pickToSol to prevent recreation in recursion (instead pass the cerrect solution's lengths)
    vector<char> areSol(total_index, '_'); /*for(char x : areSol){cout << x;}*/
    vector<bool> used(total_index, false);

    permutations_kn(total_index, areSol, 0, used, candidateSolution,k);

    cout << total_index << endl;
    cout << endl
         << perm_count << endl;
    cout << endl
         << recur_count << endl;
    return 0;
}
