#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> preceded;

        for (const auto edge : edges) ++preceded[edge[1]];

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (preceded[i] == 0) res.push_back(i);
        }

        return res;
    }
};