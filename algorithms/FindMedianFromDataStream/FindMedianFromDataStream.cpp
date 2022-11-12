#include "bits/stdc++.h"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

class MedianFinder {
    tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> o_set;
public:
    MedianFinder() = default;

    void addNum(int num) {
        o_set.insert(num);
    }

    double findMedian() {
        const int sz = (int)o_set.size();
        if (sz & 1) return *o_set.find_by_order(sz >> 1);
        else return double(*o_set.find_by_order((sz >> 1) - 1) + *o_set.find_by_order(sz >> 1)) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */