#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        const int n(target.size());

        if (any_of(target.begin(), target.end(), [=](auto cur) { return cur != 1 && cur < n; })) return false;

        priority_queue<int> pq;
        int64_t total = accumulate(target.begin(), target.end(), 0ll);
        for (const auto num : target) pq.push(num);

        while (!pq.empty() && pq.top() != 1) {
            int64_t cur = pq.top(); pq.pop();
            int64_t rest = total - cur;

            if (rest <= 0 || cur <= rest) return false;
            int64_t prev = cur % rest;
            if (rest != 1 && prev == 0) return false;
            pq.push(prev);
            total -= cur;
            total += prev;
        }

        return pq.size() == n;
    }
};