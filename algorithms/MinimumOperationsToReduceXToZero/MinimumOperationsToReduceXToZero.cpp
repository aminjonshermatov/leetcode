#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> pf, sf;

        pf[0] = sf[0] = 0;
        int cur = 0, ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i];
            pf[cur] = i + 1;
            if (cur == x) ans = min(ans, i + 1);
        }
        cur = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            cur += nums[i];
            int len = (int)nums.size() - i;
            sf[cur] = len;
            if (cur == x) ans = min(ans, len);
            if (pf.count(x - cur) > 0 && pf[x - cur] < i) ans = min(ans, len + pf[x - cur]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};