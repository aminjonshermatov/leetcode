#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int total = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

        array<int, 4> overlap = {
                max(ax1, bx1),
                max(ay1, by1),
                min(ax2, bx2),
                min(ay2, by2)
        };

        if (overlap[0] <= overlap[2] && overlap[1] <= overlap[3]) total -= (overlap[2] - overlap[0]) * (overlap[3] - overlap[1]);
        return total;
    }
};