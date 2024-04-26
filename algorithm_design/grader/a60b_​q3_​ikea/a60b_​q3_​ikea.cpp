#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> prereq_list; // (prereq, this)
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b; // 1-index
        a--;
        b--; // make 0-index
        prereq_list.push_back({a, b});
    }

    // process each of the 5 plans separately
    for (int plan = 0; plan < 5; plan++)
    {
        vector<int> node_timestamp(n);
        for (int time = 0; time < n; time++)
        {
            int node;
            cin >> node; // 1-index
            node--;      // make 0-index
            node_timestamp[node] = time;
        }

        bool isSuccessful = true;

        for (auto [from, to] : prereq_list)
        {
            if (node_timestamp[from] > node_timestamp[to])
            {
                isSuccessful = false;
                break;
            }
        }

        // the plan will succeed only if for every prerequisite (a,b),
        // a's time comes before b's time
        if (isSuccessful)
            cout << "SUCCESS" << endl;
        else
            cout << "FAIL" << endl;
    }

    return 0;
}
