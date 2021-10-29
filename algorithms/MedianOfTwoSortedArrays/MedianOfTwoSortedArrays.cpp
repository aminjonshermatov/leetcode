#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t l1 = nums1.size();
        size_t l2 = nums2.size();

        if (l1 > l2) {
            return findMedianSortedArrays(nums2, nums1);
        }


        int l = l1 > -1 ? 0 : -1;
        int r = l1 - 1;

        while (l <= r) {
            int mX = (l + r) / 2;
            int mY = (l1 + l2) / 2 + (l1 + l2) % 2 - mX - 2;

            int xLeft = mX >= 0 ? nums1[mX] : INT_MIN;
            int xRight = mX + 1 < l1 ? nums1[mX + 1] : INT_MAX;
            int yLeft = mY >= 0 ? nums2[mY] : INT_MIN;
            int yRight = mY + 1 < l2 ? nums2[mY + 1] : INT_MAX;

            if (xLeft <= yRight && yLeft <= xRight) {
                if ((l1 + l2) & 1) {
                    return max(xLeft, yLeft);
                } else {
                    return (max(xLeft, yLeft) + min(xRight, yRight)) / 2.0;
                }
            } else if (xRight > yLeft) {
                r = mX - 1;
            } else {
                l = mX + 1;
            }
        }

        return 0;
    }
};