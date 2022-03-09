#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> procede(n, 0);

        for (const auto edge : edges) ++procede[edge[1]];

        vector<int> res;

        for (int i = 0; i < n; ++i) {
            if (procede[i] == 0) res.push_back(i);
        }

        return res;
    }
};