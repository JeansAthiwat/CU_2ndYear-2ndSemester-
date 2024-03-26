#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int solve(int n, vector<int> &cuttable) {
    vector<int> ans(n + 1, -INF);
    ans[0] = 0; // Base case: no cuts, no pieces

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < cuttable.size(); j++) {
            if (i - cuttable[j] >= 0) {
                ans[i] = max(ans[i], ans[i - cuttable[j]] + 1);
            }
        }
    }
    return ans[n];
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> cuttable({a, b, c});
    int maxPieces = solve(n, cuttable);
    cout << maxPieces << endl;

    return 0;
}
