#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};

        int pCounts[26] = {};
        int sCounts[26] = {};
        vector<int> indices;

        for (int i = 0; i < p.size(); ++i) {
            ++pCounts[p[i] - 'a'];
            ++sCounts[s[i] - 'a'];
        }

        function<bool()> check = [&]() -> bool {
            bool isSame = true;

            for (int i = 0; i < 26 and isSame; ++i) {
                if (pCounts[i] != sCounts[i]) isSame = false;
            }

            return isSame;
        };

        if (check()) indices.push_back(0);

        int l = 1, r = static_cast<int>(p.size());

        while (r < s.size()) {
            --sCounts[s[l - 1] - 'a'];
            ++sCounts[s[r] - 'a'];

            if (check()) indices.push_back(l);
            ++l;
            ++r;
        }

        return indices;
    }
};