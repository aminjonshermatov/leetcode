#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto res{0};
        int l = 0, r = static_cast<int>(height.size()) - 1;

        while (l < r) {
            res = max(res, (r - l) * min(height[l], height[r]));

            if (height[l] < height[r]) ++l;
            else --r;
        }

        return res;
    }
};