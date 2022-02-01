#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int   ss = static_cast<int>(s.size()),
                    ts = static_cast<int>(t.size());

        int i = 0, j = 0;

        while (i < ss and j < ts) {
            if (s[i] == t[j]) ++i;
            ++j;
        }

        return i == ss;
    }
};