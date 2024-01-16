#include <bits/stdc++.h>

int tile_count, monster_count, turret_count, turret_range;
std::vector<int> monster_pos;
std::vector<int> monster_health;
std::vector<int> turret_pos;

void perms_target(int curr_turret, int remaining_health,std::vector<int> target_sol) {
    //purmutate till kth turret if found min remaining_health use it 
    if(curr_turret < turret_count){

    }

}

int main()
{
    // taking inputs
    std::cin >> tile_count >> monster_count >> turret_count >> turret_range; // n , m, k , w
    monster_pos.resize(m);
    monster_health.resize(m);
    turret_pos.resize(k);

    int total_health = 0;
    for (int i = 0; i < m; i++)
        std::cin >> p[i];
    for (int i = 0; i < m; i++)
    {
        int inp = 0;
        std::cin >> inp;
        total_health += inp;
        h[i] = inp;
    }
    for (int i = 0; i < k; i++)
        std::cin >> t[i];

    // pass in target_sol to prevent constructing new one on every recur
    std::vector<int> target_sol(k);


    return 0;
}

/*
IDEA:
permutate through all possible target monster for each terret [t1,t2,t3,t4,t5,t6,t7,t8] and find the min sum


*/

// brute forces through every combination of possible outcum
// Find the MINIMUM value

/*
USEFUL: number of turrent and monster < 8

MY WAY: permutate through each turrets position
*/