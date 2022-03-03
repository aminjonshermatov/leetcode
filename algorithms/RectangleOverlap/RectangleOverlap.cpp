#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int res[4];

        res[0] = max(rec1[0], rec2[0]);
        res[1] = max(rec1[1], rec2[1]);
        res[2] = min(rec1[2], rec2[2]);
        res[3] = min(rec1[3], rec2[3]);

        return res[0] < res[2] and res[1] < res[3];
    }
};