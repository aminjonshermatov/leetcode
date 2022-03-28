#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int n = static_cast<int>(nums.size());

        auto lo{0};
        auto hi{n - 1};

        while (lo < hi) {
            while (lo + 1  < n and nums[lo] == nums[lo + 1]) ++lo;
            while (hi - 1 >= 0 and nums[hi] == nums[hi - 1]) --hi;

            if (lo > hi) break;

            auto mid{lo + ((hi - lo) >> 1)};

            //cout << lo << ' ' << mid << ' ' << hi << '\n';
            if (nums[mid] < nums.front()) hi = mid;
            else lo = mid + 1;
        }

        //cout << lo << ' ' << hi << '\n';

        return binary_search(nums.begin(), next(nums.begin(), hi), target)
               or binary_search(next(nums.begin(), hi), nums.end(), target);
    }
};