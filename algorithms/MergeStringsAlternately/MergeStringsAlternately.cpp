#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        list<char> merged;

        bool isFirst = true;
        const int n = static_cast<int>(word1.size());
        const int m = static_cast<int>(word2.size());

        auto i{0};
        auto j{0};

        while (i < n and j < m) {
            if (isFirst) merged.push_back(word1[i++]);
            else merged.push_back(word2[j++]);

            isFirst = not isFirst;
        }

        while (i < n) merged.push_back(word1[i++]);
        while (j < m) merged.push_back(word2[j++]);

        return {merged.begin(), merged.end()};
    }
};