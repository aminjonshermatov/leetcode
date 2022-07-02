#include "bits/stdc++.h"

using namespace std;

class Solution {
    inline static constexpr int MOD = 1e9 + 7;

public:
    int maxArea(int h, int w, vector<int>& hh, vector<int>& vv) {

        auto helper = [](vector<int> &c, int last) {
            sort(c.begin(), c.end());

            if (c.front() != 0) c.insert(c.begin(), 1, 0);
            if (c.back() != last) c.push_back(last);
        };

        helper(hh, h);
        helper(vv, w);

        uint64_t hmx = 1ull, vmx = 1ull;

        for (int i = 1; i < hh.size(); ++i) hmx = max<uint64_t>(hmx, hh[i] - hh[i - 1]);
        for (int i = 1; i < vv.size(); ++i) vmx = max<uint64_t>(vmx, vv[i] - vv[i - 1]);

        return static_cast<int>(hmx * vmx % MOD);
    }
};