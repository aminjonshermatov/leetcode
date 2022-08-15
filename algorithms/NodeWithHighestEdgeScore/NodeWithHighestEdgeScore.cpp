#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        const int N(edges.size());
        vector<int64_t> A(N, 0);

        for (size_t i = 0; i < N; ++i) A[edges[i]] += i;

        auto max_ = *max_element(A.begin(), A.end());
        for (size_t i = 0; i < N; ++i) if (A[i] == max_) return i;
        return -1;
    }
};