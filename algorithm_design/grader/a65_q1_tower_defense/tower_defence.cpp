#include <bits/stdc++.h>

using namespace std;

int main()
{

    /*
    bokuno algoritemu

    -take a turret array , sort in in accending order.
    -for each turret from left to right "shoot the left most target that the hp is not 0"
    */

    // --------------------------------take input
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> t(k);

    // create a moster (pos,hp) pair
    vector<pair<int, int>> monster(m);
    for (int i = 0; i < m; i++)
    {
        cin >> monster[i].first;
    }
    int total_health = 0;
    for (int i = 0; i < m; i++)
    {
        int inp;
        cin >> inp;
        monster[i].second = inp;
        total_health += inp;
    }

    // take turret pos
    for (int i = 0; i < k; i++)
    {
        cin >> t[i];
    }

    // sort the turret position array
    sort(t.begin(), t.end());
    sort(monster.begin(), monster.end());


    //print sortedturretarray
    /*
    cout << "sorted turrets";
    for (auto &x : t)
    {
        cout << x << " ";
    }
    cout << endl;*/

    /*cout << "monster pos,health: ";
    for (auto &mon : monster)
    {
        cout << mon.first << ":" << mon.second << " ";
    }
    cout << endl;*/

    // loop through each turret
    // shoot the leftmost monster in tile (monster is in range and hp > 0)
    int damage = 0;
    for (int tI = 0; tI < k; tI++)
    {
        for (int mI = 0; mI < m; mI++)
        {
            // monster in turrent range
            if (t[tI] + w >= monster[mI].first && monster[mI].first >= t[tI] - w)
            {
                if (monster[mI].second > 0)
                {
                    //cout << "turret at pos" << t[tI] << " damaged monster at" << monster[mI].first << endl;
                    damage++;
                    break;
                }
            }
        }
    }

    int remaining_health = total_health-damage;
    cout << remaining_health;

}