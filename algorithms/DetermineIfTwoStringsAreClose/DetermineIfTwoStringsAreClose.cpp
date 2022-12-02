#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2) return true;

        map<char, int> s1_cnt, s2_cnt;
        for (auto ch : s1) ++s1_cnt[ch];
        for (auto ch : s2) ++s2_cnt[ch];

        if (s1_cnt.size() != s2_cnt.size()) return false;
        vector<int> l1, l2;
        for (auto [ch, c] : s1_cnt) {
            if (s1_cnt.count(ch) == 0) return false;
            l1.emplace_back(c);
        }
        for (auto [ch, c] : s2_cnt) {
            if (s1_cnt.count(ch) == 0) return false;
            l2.emplace_back(c);
        }
        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());
        for (int i = 0; i < l1.size(); ++i) if (l1[i] != l2[i]) return false;

        return true;
    }
};