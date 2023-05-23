#include "bits/stdc++.h"

using namespace std;

class KthLargest {
  int k;
  priority_queue<int, vector<int>, greater<>> pq;
public:
  KthLargest(int k_, vector<int>& nums) : k(k_) {
    for_each(nums.begin(), nums.end(), bind(&KthLargest::add, this, placeholders::_1));
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > k) pq.pop();
    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */