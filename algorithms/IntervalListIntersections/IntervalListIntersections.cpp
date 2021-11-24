#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;

        int i = 0,
            lenF = firstList.size(),
            j = 0,
            lenS = secondList.size();

        while (i < lenF && j < lenS) {
            int l = max(firstList[i][0], secondList[j][0]),
                r = min(firstList[i][1], secondList[j][1]);

            if (l <= r) res.push_back({l, r});

            if (firstList[i][1] < secondList[j][1]) ++i;
            else ++j;
        }

        return res;
    }
};