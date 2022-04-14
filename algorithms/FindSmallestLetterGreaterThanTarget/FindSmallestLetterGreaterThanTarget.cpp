#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const int n = static_cast<int>(letters.size());

        int lo = 0, hi = n;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (letters[mid] <= target) lo = mid + 1;
            else hi = mid;
        }

        return hi == n
               ? letters.front()
               : letters[hi];
    }
};