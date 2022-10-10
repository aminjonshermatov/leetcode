#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string breakPalindrome(string s) {
        const int N(s.size());

        if (N == 1) return "";
        if (all_of(s.begin(), s.end(), [](auto ch) -> bool { return ch == 'a'; })) {
            s.back() = 'b';
            return s;
        }

        for (int i = 0; i < N; ++i) {
            if (s[i] == 'a' || (N % 2 == 1 && i == N / 2)) continue;
            s[i] = 'a';
            return s;
        }
        s.back() = (s.back() - 'a' + 1) % 26 + 'a';
        return s;
    }
};