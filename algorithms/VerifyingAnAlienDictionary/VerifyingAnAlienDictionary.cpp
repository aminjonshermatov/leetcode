#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> orders;
        for (int i = 0; i < 26; ++i) orders[order[i]] = i;

        const int n = static_cast<int>(words.size());
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= words[i + 1].size()) return false;

                if (words[i][j] != words[i + 1][j]) {
                    if (orders[words[i][j]] > orders[words[i + 1][j]]) return false;
                    break;
                }
            }
        }

        return true;
    }
};