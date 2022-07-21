#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;

        for (int l = 0, r = static_cast<int>(height.size()) - 1; l < r;) {
            ans = max(ans, (r - l) * min(height[l], height[r]));

            if (height[l] < height[r]) ++l;
            else --r;
        }

        return ans;
    }
};
