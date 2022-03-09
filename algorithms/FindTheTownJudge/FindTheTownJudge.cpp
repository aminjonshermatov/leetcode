#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // people trusts to these, these trusts
        unordered_map<int, pair<int, int>> trusts;

        for (int i = 1; i <= n; ++i) trusts[i] = {0, 0};

        for (const auto &t : trust) {
            ++trusts[t[1]].first;
            ++trusts[t[0]].second;
        }

        for (const auto [label, info] : trusts) {
            if (info.second == 0 and info.first >= n - 1) return label;
        }

        return -1;
    }
};