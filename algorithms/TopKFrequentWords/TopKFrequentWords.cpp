#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (const auto ss : words) ++freq[ss];

        vector<pair<int, string>> poss;
        poss.reserve(k);

        for (const auto [w, fr] : freq) {
            poss.emplace_back(fr, w);
        }

        sort(poss.begin(),
             poss.end(),
             [](auto &lhs, auto &rhs) { return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first > rhs.first; });

        vector<string> res;
        res.reserve(k);

        for (int i = 0; i < k; ++i) res.emplace_back(poss[i].second);

        return res;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        for (auto &w : words) ++freq[w];

        auto cmp = [&](auto &l, auto &r) {
            auto lf = freq[l];
            auto rf = freq[r];
            return lf == rf ? l < r : lf > rf;
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

        for (auto &[w, _] : freq) {
            pq.push(w);
            if (pq.size() > k) pq.pop();
        }

        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};