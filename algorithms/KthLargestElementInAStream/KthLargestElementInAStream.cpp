#include "bits/stdc++.h"

using namespace std;

class KthLargest {
    int size_;
    priority_queue<int, vector<int>, greater<>> heap;

    void push(int num) {
        heap.push(num);
        if (heap.size() > size_) heap.pop();
    }

public:
    KthLargest(int k, vector<int>& nums) {
        size_=  k;

        for (const auto num : nums) push(num);
    }

    int add(int val) {
        push(val);

        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */