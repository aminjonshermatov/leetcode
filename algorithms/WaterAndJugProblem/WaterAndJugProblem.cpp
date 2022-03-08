#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        array<int, 4> dk = {x, -x, y, -y};
        queue<int> q;
        unordered_set<int> uniq;
        q.push(x + y);

        uniq.insert(x + y);
        while (not q.empty()) {
            auto cur{q.front()}; q.pop();

            if (cur == z) return true;

            for (const auto k : dk) {
                auto next{cur + k};

                next = max(next, 0);
                next = min(next, x + y);

                if (uniq.count(next) > 0) continue;

                uniq.insert(next);
                q.push(next);
            }
        }

        return false;
    }
};