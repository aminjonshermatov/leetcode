#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n(s.size());
        const int k(p.size());

        int f1[26] = {0,}, f2[26] = {0,};

        for (const auto ch : p) ++f2[ch - 'a'];

        const function<bool()> isEq = [&]() {
            for (int i = 0; i < 26; ++i) {
                if (f1[i] != f2[i]) return false;
            }

            return true;
        };

        vector<int> res;
        for (int ss = 0, ee = 0; ee < n; ++ee) {
            ++f1[s[ee] - 'a'];

            if (ee - ss >= k) --f1[s[ss++] - 'a'];

            if (isEq()) res.push_back(ss);
        }

        return res;
    }
};