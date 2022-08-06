#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // O(log(r + c)) - TC, O(1) - SC
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(),
            c = matrix[0].size();

        if (matrix[0][0] > target or matrix[r - 1][c - 1] < target) return false;

        int lo = 0, hi =r * c;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (matrix[mid / c][mid % c] < target) lo = mid + 1;
            else if (matrix[mid / c][mid % c] > target) hi = mid;
            else return true;
        }

        return false;
    }

    // O(log(r) + log(c)) - TC, O(1) - SC
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        const int n = static_cast<int>(mat.size());
        const int m = static_cast<int>(mat[0].size());

        auto lo{0};
        auto hi{n};

        while (lo < hi) {
            const auto mid{lo + ((hi - lo) >> 1)};

            if (mat[mid][0] > target) hi = mid;
            else lo = mid + 1;
        }

        const auto it{hi - 1};

        if (it >= 0 and it < n) {
            lo = 0;
            hi = m;

            while (lo < hi) {
                const auto mid{lo + ((hi - lo) >> 1)};

                if (mat[it][mid] > target) hi = mid;
                else if (mat[it][mid] < target) lo = mid + 1;
                else return true;
            }
        }

        return false;
    }
};

class Solution {
    inline bool low_b(const vector<int> &row, int t) const {
        if (auto lo = lower_bound(row.begin(), row.end(), t); lo == row.end() || *lo != t) return false;
        return true;
    }
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        auto up = upper_bound(mat.begin(), mat.end(), t, [](auto tt, const auto &row) { return tt < row.front(); });

        if (up == mat.begin() || up == mat.end()) return low_b(mat.back(), t);
        return low_b(*prev(up), t);
    }
};