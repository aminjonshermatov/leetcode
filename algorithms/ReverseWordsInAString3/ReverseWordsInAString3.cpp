#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0;

        while (l < s.size()) {
            while (r < s.size() && s[r] != ' ') ++r;
            int temp = r++ - 1;

            while (l < temp) swap(s[l++], s[temp--]);
            l = r;
        }

        return s;
    }
};