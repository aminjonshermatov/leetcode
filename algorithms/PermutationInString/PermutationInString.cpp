#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n = s2.size();
        const int k = s1.size();

        if (k > n) return false;

        int s1F[26] = {0};
        for (const auto ch : s1) ++s1F[ch - 'a'];

        int s2F[26] = {0};
        for (int i = 0; i < k; ++i) ++s2F[s2[i] - 'a'];

        const function<bool()> check = [&]() -> bool {
            for (int i = 0; i < 26; ++i) {
                if (s1F[i] > s2F[i]) return false;
            }

            return true;
        };

        for (int l = 1, r = k; r < n; ++l, ++r) {
            if (check()) return true;

            --s2F[s2[l - 1] - 'a'];
            ++s2F[s2[r] - 'a'];
        }

        return check();
    }
};