#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> ss, tt;
        int sC = 0, tC = 0;

        int i = s.size() - 1;
        while (i >= 0) {
            if (s[i] == '#') {
                ++sC;
            } else {
                if (sC > 0) --sC;
                else ss.push_back(s[i]);
            }
            --i;
        }

        i = t.size() - 1;
        while (i >= 0) {
            if (t[i] == '#') {
                ++tC;
            } else {
                if (tC > 0) --tC;
                else tt.push_back(t[i]);
            }
            --i;
        }

        return ss == tt;
    }
};