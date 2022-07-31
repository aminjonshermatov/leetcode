#include "bits/stdc++.h"

using namespace std;

class NumArray {
    vector<int> s_tree;
    size_t n;

public:
    NumArray(vector<int>& nums) : n{nums.size()} {
        s_tree.resize(n << 1);

        for (size_t i = 0; i < n; ++i)
            s_tree[i + n] = nums[i];
        for (int i = n - 1; i > 0; --i)
            s_tree[i] = s_tree[i << 1] + s_tree[i << 1 | 1];
    }

    void update(int idx, int val) {
        assert(idx >= 0 && idx < n);

        for (s_tree[idx += n] = val; idx > 0; idx >>= 1)
            s_tree[idx >> 1] = s_tree[idx] + s_tree[idx ^ 1];
    }

    int sumRange(int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += s_tree[l++];
            if (r & 1) res += s_tree[--r];
        }

        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */