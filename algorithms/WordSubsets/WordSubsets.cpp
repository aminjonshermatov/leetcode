#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        const int n(w1.size());
        const int m(w2.size());

        vector<array<uint8_t, 26>> f1(n);
        uint8_t f2[26] = {0u,}, temp[26];

        for (size_t i = 0u; i < n; ++i)
            for (auto ch : w1[i]) ++f1[i][ch - 'a'];

        size_t len = sizeof(temp) / sizeof(temp[0]);
        for (size_t i = 0u; i < m; ++i) {
            memset(temp, 0, len);
            for (auto ch : w2[i])
                ++temp[ch - 'a'];

            for (size_t j = 0; j < 26; ++j)
                f2[j] = max(f2[j], temp[j]);
        }

        vector<string> res;
        for (size_t i = 0u; i < n; ++i) {
            bool ok = true;

            for (size_t k = 0u; k < 26 && ok; ++k)
                ok = f2[k] <= f1[i][k];

            if (ok) res.push_back(w1[i]);
        }

        return res;
    }
};