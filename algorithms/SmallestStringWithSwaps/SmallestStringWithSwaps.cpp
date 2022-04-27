#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int n = static_cast<int>(s.size());

        vector<int> parent(n), rank(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;

        const function<int(const int)> find_ = [&](const int x) {
            if (x != parent[x]) parent[x] = find_(parent[x]);
            return parent[x];
        };

        const function<void(const int, const int)> union_ = [&](const int a, const int b) {
            auto pA = find_(a);
            auto pB = find_(b);

            if (rank[pA] < rank[pB]) {
                parent[pA] = pB;
                rank[pB] = max(rank[pB], rank[pA] + 1);
            } else {
                parent[pB] = pA;
                rank[pA] = max(rank[pA], rank[pB] + 1);
            }
        };

        for (const auto &pair : pairs) union_(pair[0], pair[1]);

        unordered_map<int, pair<size_t, vector<char>>> hmap;
        for (int i = 0; i < n; ++i) hmap[find_(i)].second.push_back(s[i]);

        for (auto &it : hmap) {
            it.second.first = 0;
            sort(it.second.second.begin(), it.second.second.end());
        }

        string res;
        res.reserve(n);
        for (int i = 0; i < n; ++i) {
            auto it = &hmap[find_(i)];
            res.push_back(it->second[it->first++]);
        }

        return res;
    }
};