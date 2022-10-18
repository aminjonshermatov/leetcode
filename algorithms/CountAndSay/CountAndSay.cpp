#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        auto s = countAndSay(n - 1);
        const int len(s.size());
        char prev = s.front();
        int c = 1;

        string ans;
        for (int i = 1; i < len; ++i) {
            if (prev == s[i]) ++c;
            else {
                ans += to_string(c) + prev;
                prev = s[i];
                c = 1;
            }
        }

        if (c != 0) ans += to_string(c) + prev;

        //cout << "n=" << n << ' ' << s << ' ' << ans << '\n';
        return ans;
    }
};