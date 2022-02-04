#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        unordered_map<int, int> last_oc;
        last_oc[0] = -1;
        int acc = 0, res = 0;

        for (int i = 0; i < n; ++i) {
            acc += (nums[i] == 1 ? 1 : -1);

            if (last_oc.count(acc) > 0) res = max(res, i - last_oc[acc]);
            else last_oc[acc] = i;
        }

        return res;
    }
};