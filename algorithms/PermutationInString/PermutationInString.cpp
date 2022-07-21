#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int k(s1.size());
        const int n(s2.size());

        uint32_t s1_mask = 0u, s1_freq[26] = {0u,};
        for (auto ch : s1) {
            ++s1_freq[ch - 'a'];
            s1_mask |= 1 << (ch - 'a');
        }

        uint32_t w_mask = 0u, w_freq[26] = {0u,};
        for (size_t l = 0, r = 0; r < n; ++r) {
            w_mask |= 1 << (s2[r] - 'a');
            ++w_freq[s2[r] - 'a'];

            if (r - l + 1 > k) {
                --w_freq[s2[l++] - 'a'];
                if (w_freq[s2[l - 1] - 'a'] == 0) w_mask &= ~(1u << (s2[l - 1] - 'a'));
            }


            if ((w_mask & s1_mask) == s1_mask) {
                bool ok = true;
                for (size_t i = 0; i < 26 && ok; ++i) ok = s1_freq[i] == w_freq[i];

                if (ok) return true;
            }
        }
        return false;
    }
};
