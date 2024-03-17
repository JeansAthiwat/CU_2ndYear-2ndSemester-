#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e8 + 7;

int countBitStrings(int n) {
    vector<int> endingWith0(n + 1, 0);
    vector<int> endingWith1(n + 1, 0);

    endingWith0[1] = 1;
    endingWith1[1] = 1;

    for (int i = 2; i <= n; ++i) {
        endingWith0[i] = (endingWith0[i - 1] + endingWith1[i - 1]) % MOD;
        endingWith1[i] = endingWith0[i - 1];
    }

    return (endingWith0[n] + endingWith1[n]) % MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long n;
    cin >> n;

    int result = countBitStrings(n);

    cout << result;

    return 0;
}
