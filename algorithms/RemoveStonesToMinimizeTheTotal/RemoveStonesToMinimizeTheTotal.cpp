#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());

        for (int i = 0; i < k; ++i) {
            auto t = pq.top(); pq.pop();
            pq.push(t - t / 2);
        }

        int ans = 0;
        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            ans += t;
        }

        return ans;
    }
};