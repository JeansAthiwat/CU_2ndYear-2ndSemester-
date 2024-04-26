#include <bits/stdc++.h>
using namespace std;
int N, M;

int main()
{
    cin >> N >> M;
    vector<double> taskTime(M);
    vector<double> doerSubTime(N, 0);
    double totalSumbissionTime = 0;

    for (int i = 0; i < M; i++)
        cin >> taskTime[i];

    /*
    ค่าเฉลี่ย = sum of (totalSumbissionTime)  / N
    ค่าเฉลี่ย is min when start doing task from the lowest taskTime
    when assign like this the student 1 will always finish before 2 and 3 and 4
    and when student N finish student 1 will finishv before N
    so we can asssign task
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 ... M - 1
    to Mr.
    0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 ... M - 1 % N  circularly
    */

    sort(taskTime.begin(), taskTime.end());

    // start greedy
    for (int taskIndex = 0; taskIndex < M; taskIndex++)
    {
        int doer = taskIndex % N;
        doerSubTime[doer] += taskTime[taskIndex];
        totalSumbissionTime += doerSubTime[doer];
    }

    double ค่าเฉลี่ย = totalSumbissionTime / M;
    cout << fixed << setprecision(3) << ค่าเฉลี่ย;
    return 0;
}