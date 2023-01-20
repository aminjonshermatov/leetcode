#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int n(nums.size());

        auto get_hash = [P = 131](vector<int> &A) -> uint64_t {
            uint64_t h = 0u;
            for (auto x : A) h = (h * P) + x;
            return h;
        };

        vector<vector<int>> res;
        set<pair<uint64_t, size_t>> used;
        for (auto mask = 0; mask < (1 << n); ++mask) {
            vector<int> cur;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0) continue;
                if (!cur.empty() && cur.back() > nums[i]) { ok = false; break; };
                cur.emplace_back(nums[i]);
            }
            if (!ok || cur.size() < 2) continue;
            auto H = get_hash(cur);
            auto it = pair(H, cur.size());
            if (used.count(it) > 0) continue;
            res.emplace_back(cur);
            used.insert(it);
        }

        return res;
    }
};