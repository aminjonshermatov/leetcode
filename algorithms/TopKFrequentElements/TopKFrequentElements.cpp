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

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (const int num : nums) ++freq[num];

        vector<pair<int, int>> paired;
        for (const auto [k, v] : freq) paired.emplace_back(v, k);
        sort(paired.begin(), paired.end(), greater<>());
        paired.resize(k);

        vector<int> res;
        res.reserve(k);
        transform(paired.begin(), paired.end(), back_inserter(res), [](const auto kv) { return kv.second; });

        return res;
    }
};