#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        const int n(nums.size());

        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                auto prev = st.top(); st.pop();

                res[prev] = i - prev;
            }

            st.push(i);
        }

        return res;
    }
};