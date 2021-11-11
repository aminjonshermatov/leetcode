#include "bits//stdc++.h"

using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = INT_MAX, sum = 0;

        for (const int n : nums) {
            sum += n;
            minVal = min(minVal, sum);
        }

        return minVal >= 0 ? 1 : -minVal + 1;
    }
};
