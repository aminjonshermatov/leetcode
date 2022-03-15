#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        auto dx{coordinates[0][0] - coordinates[1][0]};
        auto dy{coordinates[0][1] - coordinates[1][1]};

        for (int i = 2; i < coordinates.size(); ++i) {
            auto newDx{coordinates[0][0] - coordinates[i][0]};
            auto newDy{coordinates[0][1] - coordinates[i][1]};

            if (dy * newDx != dx * newDy) return false;
        }

        return true;
    }
};