#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> uniq;
        int maxCount = 0,
            start = 0,
            n = s.size();

        for (int i = 0; i < n; ++i) {
            if (uniq.count(s[i]) > 0) {
                start = max(start, uniq[s[i]] + 1);
            }

            uniq[s[i]] = i;
            maxCount = max(maxCount, i - start + 1);
        }

        return maxCount;
    }
};