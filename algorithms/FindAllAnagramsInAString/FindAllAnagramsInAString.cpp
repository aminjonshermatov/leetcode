#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pF[26] = {0};
        int window[26] = {0};

        function<bool()> check = [&]() -> bool {
            for (int i = 0; i < 26; ++i) {
                if (pF[i] != window[i]) return false;
            }

            return true;
        };

        const int n = static_cast<int>(s.size());
        const int m = static_cast<int>(p.size());

        if (m > n) return {};

        for (int i = 0; i < m; ++i) {
            ++pF[p[i] - 'a'];
            ++window[s[i] - 'a'];
        }

        vector<int> res;

        auto l{0};
        if (check()) res.push_back(l);

        for (int r = m; r < n; ++r) {
            --window[s[l++] - 'a'];
            ++window[s[r] - 'a'];

            if (check()) res.push_back(l);
        }

        return res;
    }
};