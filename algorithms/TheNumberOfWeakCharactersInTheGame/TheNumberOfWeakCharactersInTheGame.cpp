#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<pair<int, int>> p;
        p.reserve(properties.size());

        for (auto v : properties) p.emplace_back(v[0], v[1]);

        sort(p.begin(), p.end(), [](auto &lhs, auto &rhs) -> bool {
            if (lhs.first == rhs.first) return lhs.second > rhs.second;
            return lhs.first < rhs.first;
        });

        multiset<int> ends;
        int ans = 0;
        for (int i = (int)p.size() - 1; i >= 0; --i) {
            if (ends.upper_bound(p[i].second) != ends.end()) ++ans;

            ends.insert(p[i].second);
        }

        return ans;
    }
};