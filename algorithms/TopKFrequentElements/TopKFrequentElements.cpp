#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;

        for (const auto &n : nums) ++hashMap[n];

        auto cmp = [&hashMap](int lhs, int rhs) -> bool { return hashMap[lhs] > hashMap[rhs]; };
        priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);

        for (const auto [key, _] : hashMap) {
            heap.push(key);

            if (heap.size() > k) heap.pop();
        }

        vector<int> res(k--);

        for (; k >= 0; --k) {
            res[k] = heap.top();
            heap.pop();
        }

        return res;
    }
};