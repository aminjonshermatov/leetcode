#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int64_t> sqr;

        for (int64_t i = 0; i * i <= c; ++i) sqr.insert(i * i);

        for (int64_t i = 0; i * i <= c; ++i) {
            if (sqr.count(c - i * i) > 0) return true;
        }

        return false;
    }
};
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long int i = 0; i * i <= c; ++i)
        {
            int b = c - i * i;

            if (this->binary_search(0, b, b))
                return true;
        }

        return false;
    }

    bool binary_search(int s, int e, int c) {
        if (s > e)
            return false;

        long int mid = (s + e) / 2 + (s + e) % 2;

        if (mid * mid == c)
            return true;
        if (mid * mid < c)
            return this->binary_search(mid + 1, e, c);

        return this->binary_search(s, mid - 1, c);
    }
};