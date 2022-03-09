#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> bad;

        for (const auto &s : deadends) bad.insert(s);

        queue<pair<string, int>> q;
        string start = "0000";

        if (bad.count(start) == 0) {
            q.push({start, 0});
            bad.insert(start);
        }

        while (not q.empty()) {
            auto [cur, step] = q.front(); q.pop();

            if (cur == target) return step;

            for (int i = 0; i < cur.size(); ++i) {
                for (const auto k : {-1, 1}) {
                    auto orig{cur[i]};

                    cur[i] += k;

                    if (cur[i] > '9') cur[i] = '0';
                    if (cur[i] < '0') cur[i] = '9';

                    if (bad.count(cur) == 0) {
                        bad.insert(cur);
                        q.push({cur, step + 1});
                    }

                    cur[i] = orig;
                }
            }
        }

        return -1;
    }
};