#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        const int n = endTime.size();

        int count{0};
        for (int i = 0; i < n; ++i) {
            if (startTime[i] <= queryTime and queryTime <= endTime[i]) ++count;
        }

        return count;
    }
};