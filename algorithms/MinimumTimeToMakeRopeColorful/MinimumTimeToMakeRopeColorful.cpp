#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int N(colors.size());

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int max_ = neededTime[i], sum = neededTime[i];
            while (i + 1 < N && colors[i] == colors[i + 1]) {
                max_ = max(max_, neededTime[i + 1]);
                sum += neededTime[++i];
            }

            ans += sum - max_;
        }

        return ans;
    }
};