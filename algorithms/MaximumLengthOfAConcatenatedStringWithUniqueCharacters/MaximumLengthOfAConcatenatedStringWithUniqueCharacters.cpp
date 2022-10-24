#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        const int N(arr.size());
        vector<bool> uniq(N, false);

        array<int, 26> cnt{};
        for (int i = 0; i < N; ++i) {
            fill(cnt.begin(), cnt.end(), 0);
            for (auto ch : arr[i]) ++cnt[ch - 'a'];

            uniq[i] = all_of(cnt.begin(), cnt.end(), [](auto c) { return c < 2; });
        }

        int ans = 0;
        for (int mask = 0; mask < (1 << N); ++mask) {
            int cur = 0;
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i) && uniq[i]) {
                    if (all_of(arr[i].begin(), arr[i].end(), [&cnt](auto ch) {
                        return cnt[ch - 'a'] == 0;
                    })) {
                        cur += (int)arr[i].size();
                        for (auto ch : arr[i]) ++cnt[ch - 'a'];
                    }
                }
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};