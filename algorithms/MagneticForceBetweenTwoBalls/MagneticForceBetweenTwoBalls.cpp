#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        function<int(int)> good = [&](int k) {
            int s = -1e9;

            int c = 0;
            for (const auto p : position) {
                if (p - s >= k) {
                    s = p;
                    ++c;
                }
            }

            return c >= m;
        };

        int lo = 1, hi = 1e9 + 1;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (good(mid + 1)) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};