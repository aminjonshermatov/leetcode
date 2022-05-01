#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        list<char> ss, tt;

        for (const auto ch : s) {
            if (ch == '#') {
                if (!ss.empty()) ss.pop_back();
            } else {
                ss.push_back(ch);
            }
        }

        for (const auto ch : t) {
            if (ch == '#') {
                if (!tt.empty()) tt.pop_back();
            } else {
                tt.push_back(ch);
            }
        }

        while (!ss.empty() && !tt.empty()) {
            if (ss.front() != tt.front()) return false;
            ss.pop_front();
            tt.pop_front();
        }

        return ss.empty() && tt.empty();
    }
};