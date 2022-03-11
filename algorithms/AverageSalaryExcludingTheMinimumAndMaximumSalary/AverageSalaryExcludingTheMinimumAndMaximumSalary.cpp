#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());

        return 1.0 * accumulate(salary.begin() + 1, salary.end() - 1, 0) / (salary.size() - 2);
    }
};