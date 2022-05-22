#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        function<void(int, int)> check = [&s, &res](int l, int r) -> void {
            while (l >= 0 && r < s.size() && l <= r) {
                if (s[l--] != s[r++]) break;
                ++res;
            }
        };

        for (int i = 0; i < s.size(); ++i) {
            check(i, i);
            check(i, i + 1);
        }

        return res;
    }
};

class Solution {
    bool dp[1001][1001];

public:
    int countSubstrings(string s) {
        memset(dp, 0, sizeof(dp));

        int ans = 0;
        for (int k = 0; k < s.size(); ++k) {
            for (int i = 0, j = k; i < s.size() && j < s.size(); ++i, ++j) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    ++ans;
                    dp[i][j] = true;
                }
            }
        }

        return ans;
    }
};