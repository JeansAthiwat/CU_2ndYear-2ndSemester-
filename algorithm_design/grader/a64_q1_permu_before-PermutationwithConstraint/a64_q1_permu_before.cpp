#include <bits/stdc++.h>


void perm_with_constaint(int n, std::vector<int> &sol, int current_len, std::vector<bool> &used, std::vector<int> &a,std::vector<int>&b){

}

int main() {
    int n,m;
    std::cin >> n >> m;
    
    //define needed variables 
    std::vector<int> a(m);
    std::vector<int> b(m);

    //fill in constaints for vec a and b
    for(int i = 0 ; i< m;i++){
        std::cin >> a[i] >> b[i];
    }

    //define pass to fn variable (prevent copy and construct in each recursion)
    std::vector<int> sol(n);
    std::vector<bool> used(n);
    int starting_recur_index = 0;

    perm_with_constaint(n,sol,starting_recur_index,used,a,b);

    return 0;
}