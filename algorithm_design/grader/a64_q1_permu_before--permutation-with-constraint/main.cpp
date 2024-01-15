#include <iostream>
#include <vector>
using namespace std;

bool checkConstraint(int a_in, vector<pair<int,int>> &comeBefore, vector<bool> &used) {
    // a must always cum before b
    //take in used vector to check wheteher of not the b[i] uas already been used before a[i]
    for(pair<int,int> thePair : comeBefore) {
        if(a_in == thePair.first) {
            if(used[thePair.second] == true) return false;
        }
    }
    return true;

}

void permu(int n,vector<int> &sol,int len, vector<bool> &used, vector<pair<int,int>> comeBefore) {
    if(len < n) {
        for(int i = 0 ; i<n; i++) {
            if(used[i] == false) {

                if(checkConstraint(i,comeBefore,used)) {
                    used[i] = true;
                    sol[len] = i;
                    permu(n,sol,len+1,used,comeBefore);
                    used[i] = false;
                }
            }
        }
    } else {
        for(auto &x : sol) cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n,m; // n,m <= 20
    cin >> n >> m;

    vector<pair<int,int> > comeBefore(m);
    for(int i = 0 ; i < m ; i++) {
        cin >> a[i] >> b[i];
        comeBefore[i] = {a,b};
    }

    vector<int> sol(n);
    vector<bool> used(n);
    permu(n,sol,0,used);

    return 0;
}
// im dead bro
