#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    inline auto getRandom(int min, int max) -> int {
        assert(min <= max);
        return static_cast<int>(rand()) % (max - min) + min;
    }

public:
    vector<int> nums_, cur_;
    const int n_;

    Solution(vector<int>& nums) : nums_{nums}, cur_{nums}, n_{static_cast<int>(nums.size())} { }

    vector<int> reset() {
        cur_ = nums_;
        return nums_;
    }

    vector<int> shuffle() {

        for (int i = 0; i < n_; ++i) {
            swap(cur_[i], cur_[getRandom(i, n_)]);
        }

        return cur_;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */