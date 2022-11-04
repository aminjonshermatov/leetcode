#include "bits/stdc++.h"

using namespace std;

class Solution {
    set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
public:
    string reverseVowels(string s) {
        const int N(s.size());

        for (int l = 0, r = N - 1; l < r; ++l, --r) {
            while (l < N && vowels.count(s[l]) == 0) ++l;
            while (r >= 0 && vowels.count(s[r]) == 0) --r;

            if (l < r) swap(s[l], s[r]);
        }

        return s;
    }
};