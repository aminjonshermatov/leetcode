#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int N(nums.size());
        if (N < 2) return 0;

        auto mx = *max_element(nums.begin(), nums.end()), max_r = 0;
        while (mx > 0) {
            mx /= 10;
            ++max_r;
        }

        if (max_r == 0) return 0;

        vector<int> A(nums), B(N);
        array<int, 10> fr;

        auto sort_by_r = [&](int r) {
            auto p = 1;
            while (r--) p *= 10;

            fill(fr.begin(), fr.end(), 0);

            for (auto a : A) ++fr[(a / p) % 10];
            for (int i = 1; i < 10; ++i) fr[i] += fr[i - 1];

            for (int i = N - 1; i >= 0; --i) B[--fr[(A[i] / p) % 10]] = A[i];
            A = B;
        };

        for (int r = 0; r < max_r; ++r) sort_by_r(r);

        int ans = 0;
        for (int i = 1; i < N; ++i) ans = max(ans, A[i] - A[i - 1]);

        return ans;
    }
};