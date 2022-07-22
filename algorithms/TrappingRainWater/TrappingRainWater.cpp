#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // O(n) - TC, O(1) - SC
    int trap(vector<int>& height) {
        int l = 0,
                r = height.size() - 1,
                maxL = height[l],
                maxR = height[r],
                res = 0;

        while (l < r) {
            if (maxL < maxR) {
                ++l;
                maxL = max(maxL, height[l]);
                res += maxL - height[l];
            } else {
                --r;
                maxR = max(maxR, height[r]);
                res += maxR - height[r];
            }
        }

        return res;
    }

    // O(n) - TC, O(n) - SC
    int trap(vector<int>&& height) {
        int len = height.size();

        vector<int> maxL(len, height[0]), maxR(len, height[len - 1]);

        for (int i = 1; i < len; ++i) maxL[i] = max(maxL[i - 1], height[i]);
        for (int i = len - 2; i >= 0; --i) maxR[i] = max(maxR[i + 1], height[i]);

        int res = 0;

        for (int i = 1; i + 1 < len; ++i) {
            res += max(0, min(maxL[i - 1], maxR[i + 1]) - height[i]);
        }

        return res;
    }

    int trap(vector<int>& nums) {
        const int n(nums.size());

        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                auto t = st.top(); st.pop();
                if (st.empty()) break;

                ans += (i - st.top() - 1) * (min(nums[i], nums[st.top()]) - nums[t]);
            }
            st.push(i);
        }

        return ans;
    }
};
