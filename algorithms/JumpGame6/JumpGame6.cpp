#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int n(nums.size());
        
        if (n < 3) return accumulate(nums.begin(), nums.end(), 0);
        
        vector<int> dp(n, 0);
        dp.back() = nums.back();
        
        deque<int> dq;
        dq.push_back(n - 1);
        
        for (int i = n - 2; i >= 0; --i) {
            int cur = nums[i];
            
            while (!dq.empty() && dq.front() > i + k) dq.pop_front();
            
            int next = dp[dq.front()];
            dp[i] += cur + next;
            
            while (!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();
            
            dq.push_back(i);
        }
        
        return dp.front();
    }
};
