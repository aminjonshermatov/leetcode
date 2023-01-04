#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> cnt{};
        for (auto x: tasks) ++cnt[x];

        int ans = 0;
        for (auto [_, c] : cnt) {
            if (c < 2) return -1;
            auto [q, r] = div(c, 3);
            ans += q;
            if (r != 0) ++ans;
        }

        return ans;
    }
};