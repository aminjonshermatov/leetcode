#include "bits/stdc++.h"

using namespace std;

class Solution {
    set<char> ss = {'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    bool halvesAreAlike(string S) {
        const int n = int(S.size());
        int l = 0, r = 0;
        for (int i = 0, h = n/2; i < h; ++i) {
            if (ss.count(S[i]) > 0) ++l;
            if (ss.count(S[h+i]) > 0) ++r;
        }

        return l == r;
    }
};