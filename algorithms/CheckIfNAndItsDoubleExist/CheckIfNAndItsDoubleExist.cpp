#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> uniq;

        for (const auto num : arr) {
            if (uniq.count(num * 2) > 0
                or ((num & 1) == 0 and uniq.count(num >> 1) > 0)) return true;
            uniq.insert(num);
        }

        return false;
    }
};