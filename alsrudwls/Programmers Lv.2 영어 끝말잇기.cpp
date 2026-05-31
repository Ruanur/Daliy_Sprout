
// ["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]
// [1,1], [2,1], [3,1], [1,2], [2,2], [3,2], [1,3], [2,3], [3,3]
// 

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> used;

    used.insert(words[0]);

    for (int i = 1; i < words.size(); i++)
    {
        string prev = words[i - 1];
        string cur = words[i];

        if (prev.back() != cur.front())
        {
            int person = (i % n) + 1;
            int turn = (i / n) + 1;

            return { person, turn };
        }

        if (used.find(cur) != used.end())
        {
            int person = (i % n) + 1;
            int turn = (i / n) + 1;

            return { person, turn };
        }
        used.insert(cur);
    }

    return { 0,0 };
}