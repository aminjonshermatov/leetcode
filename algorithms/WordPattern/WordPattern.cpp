#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool wordPattern(string p, string s) {
        int pos;
        int initialPos = 0;

        array<string, 26> mp;
        set<string> used;
        for (auto ch : p) {
            pos = s.find(' ', initialPos);
            if (initialPos >= s.size()) return false;
            if (pos == string::npos) pos = s.size();
            auto cur = s.substr(initialPos, pos - initialPos);
            initialPos = pos + 1;

            if (mp[ch - 'a'].empty()) {
                if (used.count(cur) > 0) return false;
                mp[ch - 'a'] = cur;
                used.insert(cur);
            } else if (mp[ch - 'a'] != cur) return false;
        }

        return initialPos >= s.size();
    }
};