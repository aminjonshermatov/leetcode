#include "bits/stdc++.h"

using namespace std;

class Solution {
    static inline constexpr array<char, 4> pos = {'A', 'C', 'G', 'T'};

public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> good(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        set<string> seen;
        q.emplace(start, 0);
        seen.insert(start);

        while (!q.empty()) {
            auto [s, c] = q.front(); q.pop();

            if (s == end) return c;

            for (int i = 0; i < 8; ++i) {
                for (auto ch : pos) {
                    auto p = s[i];
                    if (ch == p) continue;
                    s[i] = ch;
                    if (good.count(s) > 0 && seen.count(s) == 0) {
                        seen.insert(s);
                        q.emplace(s, c + 1);
                    }
                    s[i] = p;
                }
            }
        }

        return -1;
    }
};