
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>> mm;
        for (auto &m : matches) ++mm[m[0]].first, ++mm[m[1]].second;

        vector<vector<int>> ans(2);
        for (auto [p, info] : mm) {
            if (info.second <= 0) ans[0].emplace_back(p);
            else if (info.second == 1) ans[1].emplace_back(p);
        }
        for (auto &cont : ans) sort(cont.begin(), cont.end());
        return ans;
    }
};