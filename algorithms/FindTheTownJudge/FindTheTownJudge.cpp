#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> hash;

        for (int i = 1; i <= n; ++i) hash[i] = 0;

        for (const auto& p : trust) {
            if (hash.count(p[1]) > 0) ++hash[p[1]];
            hash.erase(p[0]);
        }

        for (const auto [idx, count] : hash)
            if (count == n - 1) return idx;

        return -1;
    }
};