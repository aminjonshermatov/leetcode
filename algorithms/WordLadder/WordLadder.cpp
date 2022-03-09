#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wordList) {
        unordered_set<string> wList;

        for (const auto &s : wordList) wList.insert(s);

        if (wList.count(e) == 0) return 0;

        unordered_set<string> uniq;
        queue<pair<string, int>> q;
        q.push({b, 0});
        uniq.insert(b);

        while (not q.empty()) {
            auto [cur, step] = q.front(); q.pop();

            if (cur == e) return step + 1;

            for (int i = 0; i < cur.size(); ++i) {
                for (char k = 'a'; k <= 'z'; ++k) {
                    auto orig{cur[i]};

                    cur[i] = k;

                    if (wList.count(cur) > 0 and uniq.count(cur) == 0) {
                        uniq.insert(cur);
                        q.push({cur, step + 1});
                    }

                    cur[i] = orig;
                }
            }
        }

        return 0;
    }
};