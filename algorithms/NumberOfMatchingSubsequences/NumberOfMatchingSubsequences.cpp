#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> idxs[26];

        for (size_t i = 0; i < s.size(); ++i) idxs[s[i] - 'a'].push_back(i);

        int res = 0;
        for (const auto &word : words) {
            int si = -1, ok = 1;
            for (auto ch : word) {
                auto &cur = idxs[ch - 'a'];
                auto it = lower_bound(cur.begin(), cur.end(), si);

                if (it == cur.end()) { ok = 0; break; }
                si = *it + 1;
            }

            res += ok;
        }

        return res;
    }
};
