#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        list<char> mapped;

        const int n = static_cast<int>(s.size());

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '#') {
                auto ord{(s[i - 2] - '0') * 10 + (s[i - 1] - '0') - 10};
                i -= 2;
                mapped.push_front('j' + ord);
            } else mapped.push_front('a' + (s[i] - '1'));
        }

        return {mapped.begin(), mapped.end()};
    }
};