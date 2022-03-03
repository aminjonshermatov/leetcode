#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int res = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

        int overl[4];

        overl[0] = max(ax1, bx1);
        overl[1] = max(ay1, by1);
        overl[2] = min(ax2, bx2);
        overl[3] = min(ay2, by2);

        if (overl[0] < overl[2] and overl[1] < overl[3]) res -= (overl[2] - overl[0]) * (overl[3] - overl[1]);

        return res;
    }
};