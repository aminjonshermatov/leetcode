#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bank_s;

        for (const auto b : bank) bank_s.insert(b);

        array<char, 4> dCh = {'A', 'C', 'G', 'T'};

        queue<string> q;
        unordered_set<string> uniq;
        q.push(start);
        uniq.insert(start);
        int step = 0;

        while (not q.empty()) {
            int sz = q.size();
            bool same = false;

            while (sz-- > 0) {
                auto cur = q.front(); q.pop();

                if (cur == end) return step;

                for (int i = 0; i < cur.size(); ++i) {
                    auto orig{cur[i]};
                    for (const auto ch : dCh) {
                        cur[i] = ch;

                        if (bank_s.count(cur) > 0 and uniq.count(cur) == 0) {
                            q.push(cur);
                            uniq.insert(cur);
                        }
                    }
                    cur[i] = orig;

                }
            }

            if (not same) ++step;
        }

        return -1;
    }
};