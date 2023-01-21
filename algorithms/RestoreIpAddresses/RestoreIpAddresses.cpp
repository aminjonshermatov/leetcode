#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        const int n(s.size());
        vector<string> res;

        auto ok = [&](string_view ss) -> bool {
            int val = 0;
            char prev = '.';
            for (auto ch : ss) {
                if (ch == '.') {
                    val = 0;
                    prev = ch;
                    continue;
                }
                if (prev == '0' && val == 0) return false;
                val = val * 10 + (ch - '0');
                if (val > 255) return false;
                prev = ch;
            }
            return true;
        };

        auto split = [&](int i, int j, int k) -> pair<bool, string_view> {
            string cur;
            int ii = 0;
            for (auto x : {i, j, k, n - 1}) {
                for (; ii <= x; ++ii) cur.push_back(s[ii]);
                if (x != n - 1) cur.push_back('.');
            }
            return make_pair(ok(cur), cur);
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k + 1 < n; ++k) {
                    auto [ok, ss] = split(i, j, k);
                    if (ok) res.emplace_back(ss);
                }
            }
        }

        return res;
    }
};