#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        const int n = static_cast<int>(people.size());

        sort(people.begin(), people.end());

        auto l{0};
        auto r{n - 1};
        auto count{0};

        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                ++count;
                ++l;
                --r;
            } else {
                --r;
                ++count;
            }
        }

        return count;
    }
};