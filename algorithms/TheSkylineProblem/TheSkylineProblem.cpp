#include "bits/stdc++.h"

using namespace std;

class Solution {
    struct Evt {
        int x, h;
        bool isStart;

        Evt(int a, int b, bool c) : x{a}, h{b}, isStart{c} {}
    };

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Evt> evts;
        evts.reserve(2 * buildings.size());

        for (const auto &b : buildings) {
            evts.emplace_back(b[0], b[2], true);
            evts.emplace_back(b[1], b[2], false);
        }

        sort(evts.begin(), evts.end(), [](auto &l, auto &r) {
            if (l.x != r.x) return l.x < r.x;
            if (l.isStart && r.isStart) return l.h > r.h;
            if (l.isStart) return true;
            if (r.isStart) return false;
            return l.h < r.h;
        });

        map<int, int> pq;
        int prev_max = 0;
        pq[0] = 1;
        vector<vector<int>> res;

        for (auto &e : evts) {
            if (e.isStart) {
                ++pq[e.h];
            } else {
                if (--pq[e.h] == 0) {
                    pq.erase(e.h);
                }
            }

            auto [max_, _] = *pq.rbegin();

            if (prev_max != max_) {
                res.push_back({e.x, max_});

                prev_max = max_;
            }
        }

        return res;
    }
};