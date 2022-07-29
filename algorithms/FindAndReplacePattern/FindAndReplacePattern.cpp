#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        const int n(p.size());

        vector<string> res;
        uint8_t pf[26] = {0u,}, temp[26];
        int8_t mir[26];

        for (auto ch : p) ++pf[ch - 'a'];

        for (const auto &w : words) {
            if (w.size() != n) continue;

            uint32_t seen = 0u;
            memset(temp, 0, sizeof(temp) / sizeof(temp[0]));
            memset(mir, -1, sizeof(mir) / sizeof(mir[0]));

            for (auto ch : w) ++temp[ch - 'a'];

            bool ok = true;
            for (size_t i = 0; i < n && ok; ++i) {
                if (mir[w[i] - 'a'] == -1) {
                    if ((seen >> (p[i] - 'a')) & 1) { ok = false; break; }

                    mir[w[i] - 'a'] = p[i] - 'a';
                    seen |= 1 << (p[i] - 'a');
                } else if (temp[w[i] - 'a'] != pf[mir[w[i] - 'a']]) ok = false;
            }

            if (ok) res.push_back(w);
        }

        return res;
    }
};