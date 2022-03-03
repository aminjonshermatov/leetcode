#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        visited.insert(0);
        queue<int> q;
        q.push(0);

        while (not q.empty()) {
            auto cur{q.front()}; q.pop();

            for (const auto room : rooms[cur]) {
                if (visited.count(room) == 0) {
                    visited.insert(room);
                    q.push(room);
                }
            }
        }

        return visited.size() == rooms.size();
    }
};