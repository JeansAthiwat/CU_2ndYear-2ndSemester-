#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i].first >> num[i].second;
    }

    sort(num.begin(), num.end());
    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n - 1; i++)
    {
        num[i + 1].second += num[i].second;
        ans[i] = {num[i].second,
                  num[i].first};
    }
    ans[n - 1] = {num[n - 1].second,
                  num[n - 1].first}; /*
     printf("-------------------\n");
     for (auto x : ans)
     {
         printf("(%d,%d)\n", x.first, x.second);
     }
     printf("-------------------");*/
    while (q--)
    {
        int index;
        cin >> index;
        auto p = lower_bound(ans.begin(), ans.end(), make_pair(index, 0));
        cout << p->second << "\n";
    }

    return 0;
}