#include <bits/stdc++.h>
using namespace std;
int N;

struct Lecture
{
    // from start to end(excluded)
    int start;
    int end;

    Lecture()
    {
        start = 0;
        end = 0;
    }

    bool operator<(const Lecture &other)
    {
        return this->end < other.end;
    }
};

bool checkOverlap(Lecture &a, Lecture &b)
{
    return a.start >= b.end || a.end <= b.start;
}

int main()
{
    cin >> N;
    vector<Lecture> lectures(N);

    for (int i = 0; i < N; i++)
        cin >> lectures[i].start;
    for (int i = 0; i < N; i++)
        cin >> lectures[i].end;

    sort(lectures.begin(), lectures.end());

    // greedy chose the least stop time first
    vector<int> chosen;
    chosen.push_back(0);

    for (int i = 1; i < N; i++)
    {
        if (lectures[chosen.back()].end <= lectures[i].start)
        {
            chosen.push_back(i);
        }
    }

    cout << chosen.size();
    return 0;
}