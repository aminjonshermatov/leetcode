#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> st;
        int min_ = nums.front();
        bool res = false;

        for_each(next(nums.begin()), nums.end(), [&](const int n) {
            while (!st.empty() && n >= st.top().first) st.pop();

            if (!st.empty() && n > st.top().second) res = true;

            st.push({n, min_});
            min_ = min(min_, n);
        });

        return res;
    }
};