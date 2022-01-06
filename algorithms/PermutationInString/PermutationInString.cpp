#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);

        for (int i = 0; i < s1.size(); ++i)  {
            ++s1Count[s1[i] - 'a'];
            ++s2Count[s2[i] - 'a'];
        }

        int matchCount = 0;

        for (int i = 0; i < 26; ++i)
            if (s1Count[i] == s2Count[i]) ++matchCount;

        int l = 0, r = s1.size();

        while (r < s2.size()) {
            if (matchCount == 26) return true;

            ++s2Count[s2[r] - 'a'];
            if (s2Count[s2[r] - 'a'] == s1Count[s2[r] - 'a'])
                ++matchCount;
            else if (s2Count[s2[r] - 'a'] == s1Count[s2[r] - 'a'] + 1)
                --matchCount;

            --s2Count[s2[l] - 'a'];
            if (s2Count[s2[l] - 'a'] == s1Count[s2[l] - 'a'])
                ++matchCount;
            else if (s2Count[s2[l] - 'a'] == s1Count[s2[l] - 'a'] - 1)
                --matchCount;

            ++l;
            ++r;
        }

        return matchCount == 26;
    }
};