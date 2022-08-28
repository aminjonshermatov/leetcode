#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        const int N(nums.size());
        const int M(q.size());

        sort(nums.begin(), nums.end());
        vector<int> pf(N), res(M);
        for (int i = 0, acc = 0; i < N; ++i) {
            pf[i] = acc += nums[i];
        }

        for (int i = 0; i < M; ++i) {
            res[i] = upper_bound(pf.begin(), pf.end(), q[i]) - pf.begin();
        }
        return res;
    }
};
