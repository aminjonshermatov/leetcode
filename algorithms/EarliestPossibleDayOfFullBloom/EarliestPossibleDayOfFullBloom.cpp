#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& P, vector<int>& G) {
        const int N(P.size());
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) A[i] = make_pair(P[i], G[i]);
        sort(A.begin(), A.end(), [](auto &l, auto &r) { return l.second > r.second; });

        int cur = 0, ans = 0;
        for (int i = 0; i < N; ++i) {
            cur += A[i].first;
            ans = max(ans, cur + A[i].second);
        }

        return ans;
    }
};