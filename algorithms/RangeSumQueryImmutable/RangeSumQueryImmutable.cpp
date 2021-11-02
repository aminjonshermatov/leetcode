#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    vector<int> _prefixSum, _nums;

    NumArray(vector<int>&& nums) {
        this->_nums = nums;

        size_t len = nums.size();
        this->_prefixSum.resize(len);

        this->_prefixSum[0] = nums[0];
        for (size_t i = 1; i < len; ++i) {
            this->_prefixSum[i] = this->_prefixSum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return this->_prefixSum[right] - this->_prefixSum[left] + this->_nums[left];
    }
};