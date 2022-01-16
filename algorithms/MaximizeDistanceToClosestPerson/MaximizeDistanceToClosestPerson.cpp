#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();

        vector<int> leftToRight(n, -1), rightToLeft(n, -1);

        int lastIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                leftToRight[i] = 0;
                lastIdx = i;
            } else {
                if (lastIdx != -1) leftToRight[i] = i - lastIdx;
            }
        }

        lastIdx = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (seats[i] == 1) {
                rightToLeft[i] = 0;
                lastIdx = i;
            } else {
                if (lastIdx != -1) rightToLeft[i] = lastIdx - i;
            }
        }

        int maxDis = INT_MIN;

        for (int i = 0; i < n; ++i) {
            if (leftToRight[i] == -1 and rightToLeft[i] != -1) {
                maxDis = max(maxDis, rightToLeft[i]);
            } else if (leftToRight[i] != -1 and rightToLeft[i] == -1) {
                maxDis = max(maxDis, leftToRight[i]);
            } else {
                maxDis = max(maxDis, min(leftToRight[i], rightToLeft[i]));
            }
        }

        return maxDis;
    }
};