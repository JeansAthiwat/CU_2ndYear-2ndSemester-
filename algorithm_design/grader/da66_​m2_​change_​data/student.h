#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::stack<std::vector<std::queue<int>>> tmp_stack;

    while (!a.empty())
    {
        auto vec = a.top();

        a.pop();

        for (auto &q : vec)
        {
            std::queue<int> tmp_queue;

            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                if (x == from)
                {
                    tmp_queue.push(to);
                }
                else
                {
                    tmp_queue.push(x);
                }
            }

            q = tmp_queue;
        }

        tmp_stack.push(vec);
    }

    while (!tmp_stack.empty())
    {
        a.push(tmp_stack.top());
        tmp_stack.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    auto it = a.begin();
    while (it != a.end())
    {
        std::pair<std::priority_queue<int>, int> &the_pair = it->second;
        if (the_pair.second == from)
        {
            the_pair.second = to;
        }

        std::priority_queue<int> &a_pq = the_pair.first;
        std::priority_queue<int> tmp_pq;

        while (!a_pq.empty())
        {
            int x = a_pq.top();
            a_pq.pop();

            if (x == from)
            {
                tmp_pq.push(to);
            }
            else
            {
                tmp_pq.push(x);
            }
        }

        a_pq = tmp_pq;
        it++;
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> tmpSet;

    for (auto it = a.begin(); it != a.end(); it++)
    {
        std::list<int> theList = it->first;
        std::map<int, std::pair<int, string>> the_map = it->second;

        std::list<int> tmpList;
        std::map<int, std::pair<int, string>> tmpMap;

        // change in list
        for (auto &l : theList)
        {
            if (l == from)
            {
                tmpList.push_back(to);
            }
            else
            {
                tmpList.push_back(l);
            }
        }

        // change in map
        for (auto &m : the_map)
        {
            int a = m.first == from ? to : m.first;
            int b = m.second.first == from ? to : m.second.first;

            tmpMap[a] = {b, m.second.second};
        }

        tmpSet.insert({tmpList, tmpMap});
    }

    a = tmpSet;
}

#endif
