#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N(nums.size());
        vector<int> A(N);

        auto merge_ = [&](int l, int r) {
            auto mid = l + (r - l) / 2;
            int i = l, j = mid + 1, k = 0;
            while (i <= mid && j <= r) A[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
            while (i <= mid) A[k++] = nums[i++];
            while (j <= r) A[k++] = nums[j++];

            for (int i = 0; i < r - l + 1; ++i) nums[l + i] = A[i];
        };

        // [l, r]
        function<void(int, int)> sort_ = [&](int l, int r) {
            if (l >= r) return;

            auto mid = l + (r - l) / 2;
            sort_(l, mid);
            sort_(mid + 1, r);
            merge_(l, r);
        };

        sort_(0, N - 1);

        return nums;
    }
};