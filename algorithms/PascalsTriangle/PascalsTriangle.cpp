#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        res.reserve(n);
        res.push_back({1});
        for (int i = 2; i <= n; ++i) {
            vector<int> temp;
            temp.reserve(i);
            for (int j = 0; j < i; ++j) {
                temp.push_back(j == 0 || j + 1 == i ? 1 : res[i - 2][j - 1] + res[i - 2][j]);
            }
            res.emplace_back(move(temp));
        }

        return res;
    }
};
