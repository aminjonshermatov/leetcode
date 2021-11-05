#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>&& letters, char target) {
        int l = 0, r = letters.size();

        char ub;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (letters[mid] <= target) {
                l = mid + 1;
            } else {
                ub = letters[mid];
                r = mid - 1;
            }

            if (l == letters.size())
                return letters[0];
        }

        return ub;
    }
};