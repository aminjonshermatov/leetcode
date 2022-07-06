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
};