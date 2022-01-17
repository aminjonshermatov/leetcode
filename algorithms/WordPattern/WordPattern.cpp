#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> store;
        unordered_set<string> uniq;
        int psz = pattern.size(), ssz = s.size();

        int i{0}, j{0};

        while (i < psz) {
            string curS;

            while (j < ssz and s[j] != ' ') curS.push_back(s[j++]);

            if (store.count(pattern[i]) > 0 and store[pattern[i]] != curS or store.count(pattern[i]) == 0 and uniq.count(curS) > 0) return false;
            store[pattern[i]] = curS;
            uniq.insert(curS);
            ++i;
            ++j;
        }

        return i == psz and j == ssz + 1;
    }
};