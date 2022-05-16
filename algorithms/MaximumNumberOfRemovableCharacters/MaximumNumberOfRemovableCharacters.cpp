#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        function<bool(int)> can_remove = [&](int k) {
            for (int i = 0; i < k; ++i) s[removable[i]] ^= ' ';

            int j = 0;
            for (int i = 0; i < s.size() && j < p.size(); ++i) {
                if (s[i] == p[j]) ++j;
            }

            for (int i = 0; i < k; ++i) s[removable[i]] ^= ' ';

            // cout << k << ' ' << j << '\n';
            return j == p.size();
        };

        int lo = 0, hi = (int)removable.size() + 1, ans = 0;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (can_remove(mid)) {
                ans = max(ans, mid);
                lo = mid + 1;
            }
            else hi = mid;
        }

        return ans;
    }
};