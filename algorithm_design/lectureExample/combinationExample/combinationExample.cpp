#include <bits/stdc++.h>

using namespace std;


/*
TASK: find all possible COMBINATION of the letter "ilovecat"
INPUT: an array (vector in this case) of English alphabets
OUTPUT: All possible combination for the input array

candidate solution : { i l o v e c a t}
Set of candidate solution : powerset of { i l o v e c a t}
Satisfaction condition : all the output
*/

void combinations(int total_index, std::vector<bool> &areSol, int current_index, vector<char> &candidateSolution, int &count)
{
    //recursive At ith step, we decides if the ith item is selected
    if(current_index < total_index){ 
        // preorder traversal
        areSol[current_index] = false;
        combinations(total_index, areSol, current_index+1, candidateSolution,count);
            count++;
        areSol[current_index] = true;
        combinations(total_index, areSol, current_index+1, candidateSolution,count);
            count++;

    }else{
        //reaches the leaf
        for(int i=0 ;i < total_index; i++){
            if(areSol[i] == true){
                cout << candidateSolution[i] << "";
            }
        }
        cout << endl;
    }
}

int main()
{
    vector<char> candidateSolution({'N','i','n','e','3','l','E','v','e','n','s','z'});
    for(char &x : candidateSolution){
        cout << x;
    }
    cout << endl;

    int total_index = candidateSolution.size();
    cout << total_index << endl;
    vector<bool> areSol(total_index);
    //define vector<bool> pickToSol to prevent recreation in recursion (instead pass the cerrect solution's lengths)
    int count = 0;
    combinations(total_index, areSol, 0, candidateSolution,count);

    cout << count;

}