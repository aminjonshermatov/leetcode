#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size(),
            l = 0,
            r = len - 1,
            maxSpace = 0;

        while (l < r) {
            maxSpace = max(maxSpace, min(height[l], height[r]) * (r - l));

            if (height[l] < height[r]) ++l;
            else --r;
        }

        return maxSpace;
    }
};