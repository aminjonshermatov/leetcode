#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numSplits(string s) {
        int f1[26] = {0}, f2[26] = {0};

        function<int()> same = [&]() -> int {
            int l = 0, r = 0;
            for (int i = 0; i < 26; ++i) {
                if (f1[i] > 0) ++l;
                if (f2[i] > 0) ++r;
            }

            return l == r ? 1 : 0;
        };

        for (const auto ch : s) ++f2[ch - 'a'];

        int res = 0;
        for (int i = 0; i + 1 < s.size(); ++i) {
            ++f1[s[i] - 'a'];
            --f2[s[i] - 'a'];
            res += same();
        }

        return res;
    }
};