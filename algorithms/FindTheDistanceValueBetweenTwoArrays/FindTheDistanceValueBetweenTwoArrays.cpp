#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;

        for (const auto a : arr1) {
            bool all = true;
            for (const auto b : arr2) {
                if (abs(a - b) <= d) {
                    all = false;
                    break;
                }
            }

            if (all) ++res;
        }

        return res;
    }
};