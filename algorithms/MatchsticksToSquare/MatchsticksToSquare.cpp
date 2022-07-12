#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        const int n(nums.size());
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if ((sum & 3) != 0 || n < 4) return false;
        int side = sum >> 2;
        
        if (any_of(nums.begin(), nums.end(), [side](auto &el) { return el > side; })) return false;
        
        array<int, 4> state = {0,0,0,0};
        const function<bool(int)> dfs = [&](int idx) -> bool {
            if (idx >= n) {
                return state[0] == state[1] && state[1] == state[2] && state[2] == state[3];
            }
            
            for (int i = 0; i < 4; ++i) {
                if (state[i] + nums[idx] <= side) {
                    state[i] += nums[idx];
                    if (dfs(idx + 1)) return true;
                    state[i] -= nums[idx];
                }
            }
            
            return false;
        };
        
        sort(begin(nums), end(nums), greater<>());
        return dfs(0);
    }
};
