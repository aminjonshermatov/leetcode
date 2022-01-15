#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int side = matrix.size();

        if (k == 1 || k == side * side) return matrix[(k - 1) / side][(k - 1) % side];

        int low = matrix[0][0], high = matrix[side - 1][side - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 0; i < side; ++i) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (count < k) low = mid + 1;
            else high = mid;
        }

        return low;
    }
};