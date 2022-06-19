#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;

        sort(products.begin(), products.end());
        int l = 0, r(products.size() - 1);
        for (int i = 0; i < searchWord.size(); ++i) {

            while (l <= r && (products[l].size() < i + 1 || products[l][i] != searchWord[i])) ++l;
            while (l <= r && (products[r].size() < i + 1 || products[r][i] != searchWord[i])) --r;

            res.push_back({});

            int toAdd = min(r - l + 1, 3);
            for (int j = 0; j < toAdd; ++j) res.back().push_back(products[l + j]);
        }

        return res;
    }
};