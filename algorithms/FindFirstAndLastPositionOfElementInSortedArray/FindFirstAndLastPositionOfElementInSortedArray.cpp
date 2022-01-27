#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        function<int()> first = [&]() -> int {
            int lo = 0, hi = nums.size() - 1;

            while (lo <= hi) {
                int mid = lo + ((hi - lo) >> 1);

                if (target > nums[mid]) lo = mid + 1;
                else hi = mid - 1;
            }

            return lo < nums.size() and nums[lo] == target ? lo : -1;
        };

        function<int()> last = [&]() -> int {
            int lo = 0, hi = nums.size() - 1;

            while (lo <= hi) {
                int mid = lo + ((hi - lo) >> 1);

                if (target < nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            }

            return hi < nums.size() and nums[hi] == target ? hi : -1;
        };

        return {first(), last()};
    }
};