#include "bits/stdc++.h"

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        for (int lo = 1, hi = n; lo <= hi;) {
            int mid = lo + ((hi - lo) >> 1);

            int res{guess(mid)};
            if (res == -1) hi = mid - 1;
            else if (res == 1) lo = mid + 1;
            else return mid;
        }

        return {};
    }
};