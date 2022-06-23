#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> f;
        unordered_set<char> b;

        for (int i = 0; i < s.size(); ++i) {
            if (f.count(s[i]) == 0 && b.count(t[i]) == 0) f[s[i]] = t[i], b.insert(t[i]);
            else if (f[s[i]] != t[i]) return false;
        }

        return true;
    }
};