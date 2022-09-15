#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        const int N(changed.size());

        if (N & 1) return {};

        unordered_map<int, int> fr;

        for (const auto num : changed) ++fr[num];
        sort(changed.rbegin(), changed.rend());

        vector<int> res;
        for (int i = 0; res.size() < N >> 1; ++i) {
            if (fr[changed[i]] == 0) continue;
            if ((changed[i] & 1) == 0 && fr[changed[i] >> 1] > 0) {
                res.push_back(changed[i] >> 1);
                --fr[changed[i] >> 1];
                --fr[changed[i]];
            }
            else return {};
        }

        return res;
    }
};