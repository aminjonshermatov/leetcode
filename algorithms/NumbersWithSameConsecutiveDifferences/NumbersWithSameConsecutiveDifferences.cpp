#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;

        for (int i = 1; i < 10; ++i) q.push(i);

        int len = 1;
        while (len < n) {
            int sz = (int)(q.size());

            while (sz-- > 0) {
                auto it = q.front(); q.pop();
                auto rem = it % 10;

                if (rem + k < 10) q.push(it * 10 + rem + k);
                if (k != 0 && rem - k >= 0) q.push(it * 10 + rem - k);
            }
            ++len;
        }

        vector<int> res;
        res.reserve(q.size());
        while (!q.empty()) res.emplace_back(q.front()), q.pop();

        return res;
    }
};