#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = static_cast<int>(rooms.size());

        vector<bool> seen(n, false);
        seen[0] = true;
        queue<int> q;
        q.push(0);

        while (not q.empty()) {
            int sz = static_cast<int>(q.size());

            while (sz-- > 0) {
                auto it{q.front()}; q.pop();

                seen[it] = true;

                for (const auto idx : rooms[it]) {
                    if (not seen[idx]) q.push(idx);
                }
            }
        }

        for (const auto seek : seen) {
            if (not seek) return false;
        }

        return true;
    }
};