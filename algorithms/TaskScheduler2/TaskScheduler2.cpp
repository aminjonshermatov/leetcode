#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<uint64_t, uint64_t> last;
        uint64_t cur = 1;
        for (int i = 0; i < tasks.size(); ++i) {
            if (last.count(tasks[i]) > 0 && last.at(tasks[i]) + space >= cur) {
                cur = last.at(tasks[i]) + space + 1;
            }
            last[tasks[i]] = cur++;
        }

        return --cur;
    }
};