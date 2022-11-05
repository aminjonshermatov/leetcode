#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, pair<int, int>> mp;
        for (auto &w : words1) ++mp[w].first;
        for (auto &w : words2) ++mp[w].second;

        int ans = 0;
        for (auto &[_, st] : mp) ans += st.first == st.second && st.first == 1;
        return ans;
    }
};