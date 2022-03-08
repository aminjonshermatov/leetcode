#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> f;

        for (const auto pos : forbidden) f.insert(pos);

        queue<pair<int, bool>> q;
        q.push({0, false});
        f.insert(0);

        int step = 0;
        while (not q.empty()) {
            int sz = q.size();

            while (sz-- > 0) {
                auto [cur, status] = q.front(); q.pop();

                if (cur == x) return step;

                if (status and cur - b >= 0 and f.count(cur - b) == 0) {
                    f.insert(cur - b);
                    q.push({cur - b, false});
                }
                if (cur <= b + 2e3 and f.count(cur + a) == 0) {
                    f.insert(cur + a);
                    q.push({cur + a, true});
                }
            }

            ++step;
        }

        return -1;
    }
};